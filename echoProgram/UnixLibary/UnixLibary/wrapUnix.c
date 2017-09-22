//
//  wrapUnix.c
//  EchoServerV2
//
//  Created by xtkj20170918 on 22/9/17.
//  Copyright © 2017年 陈行. All rights reserved.
//

#include "wrapUnix.h"
#include "unp.h"

pid_t Fork()
{
    pid_t pid;
    if ( ( pid = fork() ) == -1 ) {
        err_sys("fork error");
    }
    return (pid);
}

void Close( int fd )
{
    if ( close(fd) == -1 ) {
        err_sys("close err");
    }
}
