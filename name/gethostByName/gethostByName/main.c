//
//  main.c
//  gethostByName
//
//  Created by xtkj20170918 on 29/9/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unp.h"
/*
 根据名字获取服务器的信息
 */
int main(int argc, const char * argv[]) {
    
    struct hostent *hp;
    struct servent *serverp;
    struct in_addr **pptr;
    struct in_addr inetaddr;
    struct in_addr *inetaddrp[2];
    //char *serveraddr ;
    char str[MAXLINE];
    
    if ( argc!=2 ) {
        err_quit("arguments error");
    }
    
    if ( (hp = gethostbyname(argv[1]))==NULL ) {
        if ( inet_aton(argv[1], &inetaddr)==0 ) {
            err_quit("hostname error for %s: %s", argv[1], hstrerror(h_errno));
        }else {
            inetaddrp[0] = &inetaddr;
            inetaddrp[1] = NULL;
            pptr = inetaddrp;
        }
    }else{
        //获取ip地址列表
        pptr = (struct in_addr **)hp->h_addr_list;
        
        for ( ; *pptr!=NULL ; pptr++ ) {
            inet_ntop(hp->h_addrtype, *pptr,str , sizeof(str));
            printf("server address :%s\n",str);
        }
        
    }
    
    if ( ( serverp = getservbyname(argv[1], NULL) ) == NULL ) {
        err_quit("getserbyname error for %s",argv[2]);
    }
    
    printf("port number = %d",ntohs(serverp->s_port));
    printf("protocol = %s",serverp->s_proto);
    
    return 0;
}
