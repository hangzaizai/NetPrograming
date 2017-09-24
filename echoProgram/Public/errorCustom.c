//
//  error.c
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//

#include "errorCustom.h"
#include <stdarg.h>
#include "unp.h"
#include <errno.h>
#include <string.h>
#include <syslog.h>


void err_doit(int errnoflag,int level,const char *fmt,va_list ap)
{
    int errno_save;
    ssize_t n;
    char buf[MAXLINE+1];
    
    errno_save = errno;
    
    vsprintf(buf, fmt, ap);
    
    n = strlen(buf);
    if ( errnoflag ) {
        snprintf(buf+n, MAXLINE-1,": %s", strerror(errno_save));
    }
    strcat(buf, "\n");
    
    //打印输出结果
    printf("%s",buf);
    
    return;
}

void err_sys(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    err_doit(1, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(1);
}

void err_msg(const char *fmt,...)
{
    va_list ap;
    
    va_start(ap, fmt);
    err_doit(0, LOG_INFO, fmt, ap);
    va_end(ap);
    return;
}

void err_quit(const char *fmt,...)
{
    va_list ap;
    
    va_start(ap, fmt);
    err_doit(0, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(1);
}
