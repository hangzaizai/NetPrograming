//
//  tcp_listen.c
//  oobsend
//
//  Created by xtkj20170918 on 13/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "tcp_listen.h"
#include "unp.h"

int tcp_listen(const char *host,const char*serv,socklen_t *addrlenp)
{
    int         listenfd,n;
    struct addrinfo hints,*res,*reasave;
    
    bzero(&hints, sizeof(struct addrinfo));
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    if ( ( n = getaddrinfo(host, serv, &hints, &res))!=0 ) {
        err_quit("tcp_listen error for %s,%s:%s",host,serv,gai_strerror(h_errno));
    }
    
    reasave = res;
    
    do {
        
        listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if ( listenfd < 0 ) {
            continue;
        }
        
        if ( bind(listenfd, res->ai_addr, sizeof(struct sockaddr)) ==0 ) {
            
            printf("bind 完成");
            break;
        }
        
        Close(listenfd);
        
    } while ( (res = res->ai_next) );
    
    if ( res==NULL ) {
        err_sys("tcp_listen error for %s,%s",host,serv);
    }
    
    Listen(listenfd, LISTENQ);
    
    if ( addrlenp ) {
        *addrlenp = res->ai_addrlen;
    }
    
    freeaddrinfo(reasave);
    
    return (listenfd);
}


int Tcp_listen(const char *host,const char*serv,socklen_t *addrlenp)
{
    return tcp_listen(host, serv, addrlenp);
}
