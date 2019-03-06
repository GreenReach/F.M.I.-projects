#ifndef _MTX_H_
#define _MTX_H_
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>

extern int adunare(int x,int y);

extern void  mtxopen( pthread_mutex_t *mtx);

extern void mtxclose( pthread_mutex_t *mtx);

extern void mtxlock( pthread_mutex_t *mtx);

extern void mtxunlock( pthread_mutex_t *mtx);


#endif
