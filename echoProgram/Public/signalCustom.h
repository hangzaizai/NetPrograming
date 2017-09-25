//
//  signal.h
//  EchoServerV2
//
//  Created by xtkj20170918 on 25/9/17.
//  Copyright © 2017年 陈行. All rights reserved.
//

#ifndef signal_h
#define signal_h

typedef void Sigfunc(int);

#include <stdio.h>


Sigfunc *signal( int signo,Sigfunc *func);

Sigfunc *Singal( int signo,Sigfunc *func);

#endif /* signal_h */
