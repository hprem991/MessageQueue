//
//  MessageQueue.h
//  Assignment3
//
//  Created by Admin on 5/18/16.
//  Copyright © 2016 Admin. All rights reserved.
//

#ifndef MessageQueue_h
#define MessageQueue_h

#include <stdio.h>

//#endif /* MessageQueue_h */

//#ifndef CS550_MQ_H
//#define CS550_MQ_H



#include <unistd.h>
#include <stddef.h>
#include <pthread.h>



struct Msg {
    int index, counter;
    size_t size;
    char buf[1024];
};
struct Info {
    int registered;
    pthread_mutex_t mutex;
    pthread_cond_t condvar;
    size_t n, in, out, qlength;
    struct Msg msgs[10];
    int  pid,localMessagIndex;
};
struct cs550_MQ {
    struct Info *infop;
};

int cs550_MQOpen(struct cs550_MQ *, const char *path, int queue_length);
int cs550_MQClose(struct cs550_MQ *);
int cs550_MQSend(struct cs550_MQ *, const char *msg, size_t size);
ssize_t cs550_MQRecv(struct cs550_MQ *, char *msg, size_t size);
ssize_t cs550_MQPeek(struct cs550_MQ *);
int cs550_MQNotify(struct cs550_MQ *, void (*cb)(const char *msg, size_t sz));



#endif
