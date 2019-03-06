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
    pid_t pid;
    printf("The ritual has begun \n");
    pid = fork();

    if(pid<0)
        return errno;

    if (pid > 0)
    {
        printf("The sacrifice has been made \n");
        return 0;
    }

    setsid();
    printf("It surfaces \n");

    umask(0);
    printf("Cthulhu is here!\n");


    //MAKE LIST SHM

    char shm_name_LIST[]="LIST";
    int shm_fd_LIST;
    size_t shm_size_LIST = 1000;

    shm_fd_LIST = shm_open( shm_name_LIST, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if(shm_fd_LIST < 0 )
    {
        perror(NULL);
        return errno;
    }

    if(ftruncate( shm_fd_LIST, shm_size_LIST ) == -1)
    {
        perror(NULL);
        shm_unlink( shm_name_LIST);
        return errno;
    }

    void *shm_ptr_LIST = mmap( 0, shm_size_LIST, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_LIST, 0 );
    if(shm_ptr_LIST==MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_LIST);
        return errno;
    }

    int *nr=shm_ptr_LIST;
    nr[0]=0;


    //MAKE COMAND SHM

    char shm_name_COMAND[]="COMAND";
    int shm_fd_COMAND;
    size_t shm_size_COMAND = 100;

    shm_fd_COMAND = shm_open( shm_name_COMAND, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if( shm_fd_COMAND <0)
    {
        perror(NULL);
        return errno;
    }

    if(ftruncate( shm_fd_COMAND, shm_size_COMAND ) == -1)
    {
        perror(NULL);
        shm_unlink( shm_name_COMAND);
        return errno;
    }

    void *shm_ptr_COMAND = mmap( 0, shm_size_COMAND, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_COMAND,0);
    if(shm_ptr_COMAND==MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_COMAND);
        return errno;
    }


    //MAKE OUT SHM

    char shm_name_OUT[]="OUT";
    int shm_fd_OUT;
    size_t shm_size_OUT =4;

    shm_fd_OUT = shm_open( shm_name_OUT, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR ) ;
    if( shm_fd_OUT <0)
    {
        perror(NULL);
        return errno;
    }

    if( ftruncate( shm_fd_OUT, shm_size_OUT ) == -1 )
    {
        perror(NULL);
        shm_unlink( shm_name_OUT);
        return errno;
    }

    int *shm_ptr_OUT = mmap( 0, shm_size_OUT, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd_OUT,0);
    if(shm_ptr_OUT==MAP_FAILED)
    {
        perror(NULL);
        shm_unlink(shm_name_OUT);
        return errno;
    }


    //OUT
    //0-valoarea default
    //1-are grant
    //2-nu are grant

    //COMAND
    //0- val default
    //1- cauta daca are GRANT
    //2-moare cthulhu


    shm_ptr_OUT[0]=0;
    int *p_comand=(int*) shm_ptr_COMAND;
    p_comand[0]=0;

    while(p_comand[0]!=2)
    {

        if(p_comand[0]==1)
        {

            pthread_mutex_t **p_mtx=(pthread_mutex_t**)shm_ptr_COMAND;
            int *p=(int*)shm_ptr_LIST;
            pthread_mutex_t **p_mtx_list=(pthread_mutex_t**)shm_ptr_LIST;
            int i,ok=0;

            for(i=0; i<p[0]; i++)
            {
                if(p_mtx_list[i+1]==p_mtx[1])
                    ok=1;
            }

            if(ok==1)
                shm_ptr_OUT[0]=1;
            else
                shm_ptr_OUT[0]=2;

            p_comand[0]=0;

        }
    }


    printf("Cthulhu has been vanquished\n");

    shm_unlink(shm_name_OUT);
    shm_unlink(shm_name_COMAND);
    shm_unlink(shm_name_LIST);

    return 0;
}
