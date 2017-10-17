//
//  main.c
//  oobrcvSelect
//
//  Created by xtkj20170918 on 17/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unp.h"


int main(int argc, const char * argv[]) {
    
    int             listenfd,connfd;
    ssize_t         n;
    char            buff[100];
    fd_set rset,xset;
    
    listenfd = Tcp_listen(NULL, "9999", NULL);
    
    connfd = Accept(listenfd, NULL, NULL);
    
    FD_ZERO(&rset);
    FD_ZERO(&xset);
    
    for ( ; ; ) {
        
        FD_SET(connfd,&rset);
        FD_SET(connfd,&xset);
        Select( connfd + 1 , &rset, NULL, &xset, NULL);
        
        if ( FD_ISSET(connfd,&xset) ) {
            n = Recv( connfd + 1, buff, sizeof(buff)-1,MSG_OOB);
            buff[n] = 0;
            printf("read %ld OOB byte:%s",n,buff);
        }
        
        if ( FD_ISSET(connfd,&rset) ) {
            if ( (n = read(connfd, buff, sizeof(buff)-1)) == 0 ) {
                printf("received EOF\n");
            }
            buff[n] = 0;
            printf("read %ld bytes:%s\n",n,buff);
        }
        
    }
    
    return 0;
}
