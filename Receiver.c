//
//  Receiver.c
//  Assignment3
//
//  Created by Admin on 5/18/16.
//  Copyright © 2016 Admin. All rights reserved.
//

//
//extern "C" {
//#include "MQ.h"
//}
#include "MessageQueue.h"
#include <assert.h>
#include <stdio.h>

int main() {
    
    int rv, localMessegeIndex;
    struct cs550_MQ mq;
    localMessegeIndex = 0;
    
    // rv = unlink("/tmp/mq");
    
    rv = cs550_MQOpen(&mq, "/tmp/mq1", 5); assert(rv == 0);
    
    mq.infop->pid = (int) getpid();
    mq.infop->localMessagIndex = 0;
    
    while (1) {
        char msg[1024];
        rv = cs550_MQRecv(&mq, msg, 1024); assert(rv >= 0);
        //if(localMessegeIndex < )
        msg[rv] = '\0';
        printf("Received %s\n", msg);
    }
    rv = unlink("/tmp/mq1");assert(rv == 0);
    rv = cs550_MQClose(&mq); assert(rv == 0);
}
