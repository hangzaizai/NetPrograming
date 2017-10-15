//
//  tcp_listen.h
//  oobsend
//
//  Created by xtkj20170918 on 13/10/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#ifndef tcp_listen_h
#define tcp_listen_h

#include <stdio.h>


int tcp_listen(const char *host,const char*serv,socklen_t *addrlenp);

int Tcp_listen(const char *host,const char*serv,socklen_t *addrlenp);

#endif /* tcp_listen_h */
