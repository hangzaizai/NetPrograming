//
//  main.c
//  oobrcv
//
//  Created by xtkj20170918 on 13/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unp.h"

int listenfd,connfd;

void sig_urg(int);

int main(int argc, const char * argv[]) {
    
    size_t n;
    char buff[100];
    
    listenfd = tcp_listen(NULL, "9999", NULL);
    connfd = Accept(listenfd, NULL, NULL);
    Singal(SIGURG, sig_urg);
    Fcntl(connfd, F_SETOWN, getpid());
    
    for (; ; ) {
        if ( (n = read(connfd,buff ,sizeof(buff)-1 ))==0 ) {
            printf("received EOF\n");
            exit(0);
        }
        buff[n] = 0;
        printf("read %ld bytes:%s\n",n,buff);
    }
    
    return 0;
}

void sig_urg(int signo)
{
    size_t n;
    char buff[100];
    
    printf("SIGURG received\n");
    n = Recv(connfd, buff, sizeof(buff)-1, MSG_OOB);
    buff[n] = 0;
    printf("read %ld OOB byte:%s\n",n,buff);
}
