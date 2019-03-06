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

int main()
{

pthread_mutex_t mtx, mtx2;

mtxopen(&mtx);
mtxopen(&mtx2);

mtxgrant(&mtx);
mtxgrant(&mtx2);

mtxlist(&mtx);

mtxlock(&mtx);
mtxunlock(&mtx);

mtxlock(&mtx2);
mtxunlock(&mtx2);

mtxclose(&mtx);
mtxclose(&mtx2);

//MAKE OUT SHM, USED ONLY FOR KILLING THE DAEMON
char shm_name_COMAND[]="COMAND";

int shm_fd_COMAND;
size_t shm_size_COMAND =100 ;
shm_fd_COMAND = shm_open( shm_name_COMAND , O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
if (shm_fd_COMAND < 0)
{
perror(NULL);
return errno;
}

int *shm_ptr_COMAND = mmap( 0 , shm_size_COMAND , PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_COMAND,0);
if(shm_ptr_COMAND == MAP_FAILED)
{
perror(NULL);
shm_unlink(shm_name_COMAND);
return errno;
}


shm_ptr_COMAND[0]=2;


return 0;

}
