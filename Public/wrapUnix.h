//
//  wrapUnix.h
//  EchoServerV2
//
//  Created by xtkj20170918 on 22/9/17.
//  Copyright © 2017年 陈行. All rights reserved.
//
/*
 unix 一些包裹函数比如Fork
 */
#ifndef wrapUnix_h
#define wrapUnix_h

#include <stdio.h>


pid_t Fork();

void Close( int fd );

#endif /* wrapUnix_h */
