//
// Created by ezgi on 29.12.2018.
//

#ifndef RAS111_COMMON_H
#define RAS111_COMMON_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

void errorAndExit(const char *errorMessage) {
    fprintf(stderr, errorMessage);
    exit(1);
}

void log(const char* loggerName,const char *message){
    fprintf(stderr,"LOG: [%s]:%s\n", loggerName, message);
}


#endif //RAS111_COMMON_H
