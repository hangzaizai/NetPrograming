//
//  main.c
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//

#include <stdio.h>
#include "unp.h"

void str_echo(int sockfd);

int main(int argc, const char * argv[]) {
    
    int listenfd,connfd;
    pid_t childPid;
    socklen_t clilen;
    struct sockaddr_in cliaddr,seraddr;
    
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_port = htons(9999);
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    seraddr.sin_family = AF_INET;
    
    Bind(listenfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    
    Listen(listenfd,LISTENQ);
    
    for ( ; ; ) {
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
      
        //等于0表示子进程
        if ( ( childPid = Fork() ) == 0 ) {
            Close( listenfd );
            str_echo(connfd);
            exit(0);
        }
        
        Close(connfd); /* 父进程应当关闭连接 */
    }
    return 0;
}

void str_echo(int sockfd)
{
    ssize_t n;
    char buf[MAXLINE];
    
again:
    while ( (n = read(sockfd, buf, MAXLINE)) > 0 ) {
        Writen(sockfd, buf, n);
    }
    
    if ( n < 0 && errno == EINTR )
        goto again;
    else if (n < 0)
        err_sys("str_echo: read error");
}
