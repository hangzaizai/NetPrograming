//
//  main.c
//  EchoClientV2
//
//  Created by xtkj20170918 on 22/9/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unp.h"
#include <arpa/inet.h>

//定义client的类型
#define __Normal 1
#define __Select 2

//设置当前类型
#ifndef ClientType
#define ClientType __Select
#endif

void str_cli(FILE *fd,int sockfd);

int main(int argc, const char * argv[]) {
    
    //int sockfd[5];
    int sockfd;
    struct sockaddr_in sockaddr;
    
//    for ( int i = 0 ; i < 5 ; i++ ) {
//        sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);
//        bzero(&sockaddr, sizeof(sockaddr));
//        sockaddr.sin_port = htons(9999);
//        sockaddr.sin_family = AF_INET;
//        inet_pton(AF_INET,"127.0.0.1",&sockaddr.sin_addr);
//
//        Connect(sockfd[i], (struct sockaddr *)&sockaddr, sizeof(sockaddr));
//
//    }

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&sockaddr, sizeof(sockaddr));
    sockaddr.sin_port = htons(9999);
    sockaddr.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&sockaddr.sin_addr);
    
    Connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    str_cli(stdin, sockfd);
    return 0;
}

void str_cli(FILE *fd,int sockfd)
{
#if (ClientType==__Normal)
    char sendline[MAXLINE],recvline[MAXLINE];
    ssize_t status;
    while ( Fgets(sendline, MAXLINE, fd)!=NULL  ) {
        Writen(sockfd, sendline, strlen(sendline));
        
        
        status = read(sockfd, recvline, MAXLINE);
        if (  status< 0  ) {
            err_sys("read error");
        }
        puts(recvline);
        
    }
#elif ( ClientType==__Select )
    int maxfdp1;
    fd_set rset;
    ssize_t status;
    char sendline[MAXLINE],recvline[MAXLINE];
    
    FD_ZERO(&rset);
    for (; ;) {
        FD_SET(fileno(fd),&rset);
        FD_SET(sockfd,&rset);
        maxfdp1 = (int)( fmax(fileno(fd),sockfd) ) + 1;
        Select(maxfdp1, &rset, NULL, NULL, NULL);
        
        if ( FD_ISSET(sockfd,&rset) ) {
            status = read(sockfd, recvline, MAXLINE);
            if ( status == 0 ) {
                err_quit("str_cli:server terminal");
            }
            if (  status< 0  ) {
                err_sys("read error");
            }
            
            puts(recvline);
        }
        
        if ( FD_ISSET(fileno(fd),&rset) ) {
            if ( Fgets(sendline, MAXLINE, fd)==NULL ) {
                return;
            }
            Writen(sockfd, sendline, strlen(sendline));
        }
        
    }
    
#endif
}
