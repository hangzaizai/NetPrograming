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
    
    int n;
    char buff[100];
    
    listenfd = tcp_listen(NULL, "9999", NULL);
    
    
    
    return 0;
}
