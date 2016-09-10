//
//  Sender.c
//  Assignment3
//
//  Created by Admin on 5/18/16.
//  Copyright © 2016 Admin. All rights reserved.
//
//
//extern "C" {
//#include "MessageQueue.h"
//}
#include "MessageQueue.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    
    int rv;
    struct cs550_MQ mq;
    
    rv = cs550_MQOpen(&mq, "/tmp/mq", 5); assert(rv == 0);
    
    for (int i = 0; i < 5; i++) {
        char buf[1024];//="hello message";
        sprintf(buf, "Hello %d from process %d!", i,
                (int) getpid());
        
        
        rv = cs550_MQSend(&mq, buf, strlen(buf));
        sleep(1);
    }
    rv = unlink("/tmp/mq1");assert(rv == 0);
    rv = cs550_MQClose(&mq); assert(rv == 0);
}
