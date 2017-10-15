//
//  unp.h
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//

#ifndef unp_h
#define unp_h

#include <sys/socket.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include "errorCustom.h"
#include "wrapSock.h"
#include "wrapUnix.h"
#include "writen.h"
#include "wrapStdio.h"
#include "tcp_connect.h"
#include "tcp_listen.h"
#include <arpa/inet.h>
#include <sys/signal.h>
#include <signal.h>
#include "signalCustom.h"
#include <sys/types.h>
#include <math.h>
#include <sys/_select.h>
#include <sys/select.h>
#include <netdb.h>


#ifndef MAXLINE 
#define MAXLINE 1024
#endif

#ifndef LISTENQ
#define LISTENQ 1024
#endif

#ifndef INET_ADDRSLEN
#define INET_ADDRSLEN 16
#endif

#endif /* unp_h */
