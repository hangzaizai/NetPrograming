//
//  wrapSock.c
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//

#include "wrapSock.h"
#include "errorCustom.h"
#include "unp.h"


int Accept(int fd,struct sockaddr *sa,socklen_t *salenptr)
{
    int n;
again:
    if ( (n = accept(fd, sa, salenptr)) < 0 ) {
#ifdef EPROT
        if ( errno == EPROTO || errno==ECONNABORTED )
#else
        if ( errno == ECONNABORTED )
#endif
            goto again;
        else
            err_sys("accept error");
    }
    return n;
}

void Bind(int fd,const struct sockaddr *sa,socklen_t len)
{
    if ( bind(fd, sa, len) < 0 ) {
        err_sys("bind error");
    }
}

void Connect(int fd,const struct sockaddr *sa,socklen_t len)
{
    if ( connect(fd, sa, len) ) {
        err_sys("connect error");
    }
}

void Listen(int fd,int backlog)
{
    char *ptr;
    if ( (ptr=getenv("LISTENQ") ) != NULL ) {
        backlog = atoi(ptr);
    }
    
    if ( listen(fd, backlog) < 0 ) {
        err_sys("listen error");
    }
}

int Socket(int family,int type ,int protocol )
{
    int n;
    if (  (n = socket(family, type, protocol) ) < 0 ) {
        err_sys("socket error");
    }
    return n;
}

int Select( int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout )
{
    int n;
    if ( (n = select(nfds,readfds,writefds,exceptfds,timeout)) < 0 ) {
        err_sys("select error");
    }
    
    return (n);
}

void Send( int fd,const void *ptr,size_t nbytes,int flags)
{
    if ( send( fd, ptr, nbytes, flags) != (ssize_t)nbytes ) {
        err_sys("send error");
    }
}

ssize_t Recv( int fd,void *ptr,size_t nbytes,int flags)
{
    ssize_t n;
    
    if ( (n = recv(fd, ptr, nbytes, flags)) < 0 ) {
        err_sys("rect error");
    }
    
    return (n);
}
