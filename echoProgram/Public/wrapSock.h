//
//  wrapSock.h
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//
/*
 sock的包裹函数
 */
#ifndef wrapSock_h
#define wrapSock_h

#include "unp.h"

/* socket */
int Socket(int family,int type ,int protocol );

/* listen */
void Listen(int fd,int backlog);

/* connect */
void Connect(int fd,const struct sockaddr *sa,socklen_t len);

/* acceot */
int Accept(int fd,struct sockaddr *sa,socklen_t *salenptr);

/* 绑定 */
void Bind(int fd,const struct sockaddr *sa,socklen_t len);

/* select 包裹函数，用于IO复用 */
int Select( int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout );

#endif /* wrapSock_h */
