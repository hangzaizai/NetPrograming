//
//  main.c
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//

#include <stdio.h>
#include "wrapSock.h"
#include "errorCustom.h"
#include "unp.h"

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
        
        if ( childPid = fork ) {
            <#statements#>
        }
    }
    
    return 0;
    
}
