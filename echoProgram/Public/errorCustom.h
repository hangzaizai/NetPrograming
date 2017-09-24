//
//  error.h
//  EchoServerV2
//
//  Created by 陈行 on 17/9/19.
//  Copyright © 2017年 陈行. All rights reserved.
//

#ifndef error_h
#define error_h


/**
 错误处理文件
 */
#include <stdio.h>
#include <stdlib.h>

void err_sys(const char *fmt,...);
void err_msg(const char *fmt,...);
void err_quit(const char *fmt,...);

#endif /* error_h */
