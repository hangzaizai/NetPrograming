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
    
    int sockfd;
    struct sockaddr_in sockaddr;
    
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
    while ( Fgets(sendline, MAXLINE, fd)!=NULL  ) {
        Writen(sockfd, sendline, strlen(sendline));
        read(sockfd, recvline, MAXLINE);
        puts(recvline);
        
    }
}
