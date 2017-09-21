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

