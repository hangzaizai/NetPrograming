//
//  wrapStdio.c
//  EchoClientV2
//
//  Created by 陈行 on 17/9/24.
//  Copyright © 2017年 mySelf. All rights reserved.
//

#include "wrapStdio.h"
#include "unp.h"

char *Fgets(char *ptr,int n,FILE *stream)
{
    char *rptr;
    
    if ( (rptr = fgets(ptr, n, stream))== NULL && ferror(stream) ) {
        err_sys("fgets error");
    }
    
    return (rptr);
}
