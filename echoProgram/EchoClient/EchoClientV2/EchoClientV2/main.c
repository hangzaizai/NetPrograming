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
}
