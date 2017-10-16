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

/* select 函数 nfds设置为要观察的描述符的最大值+1 ,如果我们对读、写、异常
   不关心，则传NULL即可，最后一个参数如果传NULL则表示无限等待
 */
int Select( int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout );


/**
  send函数
 */
void Send( int fd,const void *ptr,size_t nbytes,int flags);

/*
 recv函数
 */
ssize_t Recv( int fd,void *ptr,size_t nbytes,int flags);

#endif /* wrapSock_h */
