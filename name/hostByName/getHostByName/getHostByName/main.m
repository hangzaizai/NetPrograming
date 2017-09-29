//
//  main.m
//  getHostByName
//
//  Created by xtkj20170918 on 28/9/17.
//  Copyright © 2017年 mySelf. All rights reserved.
//
/*
 gethostbyname通过域名查找主机信息，比如ip地址等
 */
#import <Foundation/Foundation.h>
#include "unp.h"


int main(int argc, char * argv[]) {
    
    char *ptr,**pptr;
    char str[INET_ADDRSTRLEN];
    struct hostent *htpr;
    
    while ( --argc ) {
        //第一次ptr指向命令行参数的第一个命令字符串
        ptr = *++argv;
        
        //当没有网络连接的时候应该怎么处理?
        if ( ( htpr = gethostbyname(ptr) ) == NULL ) {
            err_msg("gethostbyname error for host:%s:%s",ptr,hstrerror(h_errno));
            continue;
        }
        //将主机名字打印出来
        printf("offical hostname:%s\n",htpr->h_name);
        
        //遍历主机别名
        for ( pptr = htpr->h_addr_list ; *pptr!=NULL ; pptr++ ) {
            printf("\t alias:%s",*pptr);
        }
        
        //根据地址类型打印地址
        switch ( htpr->h_addrtype ) {
            case AF_INET:
                //遍历地址列表
                pptr = htpr->h_addr_list;
                for (; *pptr != NULL ; pptr++ ) {
                    printf("\t address:%s\n",inet_ntop(htpr->h_addrtype, *pptr,str , sizeof(str)));
                }
        }
        
    }
    return 0;
}
