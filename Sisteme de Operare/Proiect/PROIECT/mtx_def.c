#include "mtx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

int adunare(int x,int y)
{

    printf("%d\n", x+y);
    return 1;
}


/*------------------------------------------------------------------------------------------------------------------*/


void  mtxopen( pthread_mutex_t *mtx)
{
    pthread_mutex_init(mtx,NULL);
}


/*------------------------------------------------------------------------------------------------------------------*/


void mtxclose( pthread_mutex_t *mtx)
{
    pthread_mutex_destroy(mtx);
}


/*------------------------------------------------------------------------------------------------------------------*/


void mtxlock( pthread_mutex_t *mtx)
{
    char shm_name_OUT[]="OUT";
    int shm_fd_OUT;
    size_t shm_size_OUT =4;

    shm_fd_OUT = shm_open( shm_name_OUT, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if (shm_fd_OUT < 0)
    {
        perror(NULL);
        return errno;
    }

    int *shm_ptr_OUT = mmap( 0, shm_size_OUT, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_OUT,0);
    if (shm_ptr_OUT == MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_OUT);
        return errno;
    }


    char shm_name_COMAND[]="COMAND";
    int shm_fd_COMAND;
    size_t shm_size_COMAND =1000 ;

    shm_fd_COMAND = shm_open( shm_name_COMAND, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if (shm_fd_COMAND < 0 )
    {
        perror(NULL);
        return errno;
    }

    void *shm_ptr_COMAND = mmap( 0, shm_size_COMAND, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_COMAND,0);
    if (shm_ptr_COMAND == MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_COMAND);
        return errno;
    }


    pthread_mutex_t **p_mtx=(pthread_mutex_t**) shm_ptr_COMAND;
    p_mtx[1]=mtx;

    int *start=(int*) shm_ptr_COMAND;
    start[0]=1;

    while(start[0]!=0)
    {
        int a=1;
    }

    if(shm_ptr_OUT[0]==1)
        pthread_mutex_lock(mtx);
    else if(shm_ptr_OUT[0]==2)
        printf("MUTEXUL NU ARE ACCES \n");

}


/*------------------------------------------------------------------------------------------------------------------*/


void mtxunlock( pthread_mutex_t *mtx)
{
    pthread_mutex_unlock(mtx);
}


/*------------------------------------------------------------------------------------------------------------------*/


void mtxgrant( pthread_mutex_t *mtx)
{

    char shm_name_LIST[]="LIST";
    int shm_fd_LIST;
    size_t shm_size_LIST =1000 ;

    shm_fd_LIST = shm_open( shm_name_LIST, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if (shm_fd_LIST < 0 )
    {
        perror(NULL);
        return errno;
    }

    void *shm_ptr_LIST = mmap( 0, shm_size_LIST, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_LIST,0);
    if (shm_ptr_LIST == MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_LIST);
        return errno;
    }

    int *p=(int*)shm_ptr_LIST;
    pthread_mutex_t **p_mtx=(pthread_mutex_t**) shm_ptr_LIST;

    p_mtx[ p[0]+1 ] = mtx;
    p[0]++;

}


/*------------------------------------------------------------------------------------------------------------------*/


void mtxlist( pthread_mutex_t *mtx)
{

    char shm_name_LIST[]="LIST";
    int shm_fd_LIST;
    size_t shm_size_LIST =1000 ;

    shm_fd_LIST = shm_open( shm_name_LIST, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if (shm_fd_LIST < 0 )
    {
        perror(NULL);
        return errno;
    }

    void *shm_ptr_LIST = mmap( 0, shm_size_LIST, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_LIST,0);
    if (shm_ptr_LIST == MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_LIST);
        return errno;
    }


    int *p=(int*)shm_ptr_LIST;
    printf("%d <- nr de elemente\n",p[0]);
    pthread_mutex_t *p_mtx=(pthread_mutex_t*)shm_ptr_LIST;

    int i;
    for(i=0; i<p[0]; i++)
        printf("%d  ",&p_mtx[i+1]);

    printf("\n");

}


