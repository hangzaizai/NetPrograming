//
//  main.c
//  oobsend
//
//  Created by xtkj20170918 on 13/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include <stdio.h>
#include "unp.h"

int main(int argc, const char * argv[]) {
    
    int sockfd;
    char *hostaddr;
    char *serverport;//端口
    
    hostaddr = "127.0.0.1";
    serverport = "9999";
    
    sockfd = tcp_connect(hostaddr,serverport);
    

    write(sockfd, "123", 3);
    printf("write 3 bytes of normal data\n");
    sleep(1);
    
    //发送带外数据
    Send(sockfd, "4", 1, MSG_OOB);
    printf("write 1 byte of OOB data\n");
    sleep(1);
    
    write(sockfd, "56", 2);
    printf("write 2 byte of normal data\n");
    sleep(1);
    
    return 0;
}
