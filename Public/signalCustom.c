//
//  signal.c
//  EchoServerV2
//
//  Created by xtkj20170918 on 25/9/17.
//  Copyright © 2017年 陈行. All rights reserved.
//

#include "signalCustom.h"
#include "unp.h"



Sigfunc *signal( int signo,Sigfunc *func)
{
    struct sigaction act,oact;
    
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    
    if ( signo == SIGALRM ) {
#ifdef SA_INTERRRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    }else{
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }
    
    if ( sigaction(signo, &act, &oact) < 0 ) {
        return (SIG_ERR);
    }
    
    return (oact.sa_handler);
}

Sigfunc *Singal( int signo,Sigfunc *func)
{
    Sigfunc *sigfunc;
    if ( (sigfunc = signal(signo, func)) == SIG_ERR ) {
        err_sys("signal error");
    }
    
    return (sigfunc);
}
