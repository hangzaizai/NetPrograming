//
//  writen.h
//  EchoServerV2
//
//  Created by xtkj20170918 on 22/9/17.
//  Copyright © 2017年 陈行. All rights reserved.
//

#ifndef writen_h
#define writen_h

#include <stdio.h>

ssize_t                        /* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n);

void
Writen(int fd, void *ptr, size_t nbytes);

#endif /* writen_h */
