//
//  main.m
//  getHostByName
//
//  Created by xtkj20170918 on 28/9/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//
/*
 gethostbyname通过域名查找主机信息，比如ip地址等
 */
#import <Foundation/Foundation.h>
#include "unp.h"


int main(int argc, char * argv[]) {
    
    char *ptr,**pptr;
    char str[INET_ADDRSTRLEN];
    struct hostent *hptr;
    
    while ( --argc ) {
        
        ptr = *(++argv);
        if ( ( hptr = gethostbyname(ptr) ) == NULL ) {
            err_msg("gethostbyname error for host:%s : %s",ptr,hstrerror(h_errno));
            
            continue;
        }
        printf("official hostname:%s\n",hptr->h_name);
        
        for ( pptr = hptr->h_aliases ; *pptr!=NULL ; pptr++ ) {
            printf("\talias:%s\n",*pptr);
        }
        
        switch ( hptr->h_addrtype ) {
                case AF_INET:
                    pptr = hptr->h_addr_list;
                    for ( ; *pptr!=NULL; pptr++ ) {
                        printf("\taaddress:%s\n",inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
                    }
                    break;
                    
                default:
                    printf("unknown address type");
                    break;
            }

        
    }
    
    return 0;
}
