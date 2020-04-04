/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 19时47分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/shm.h>



int main() {
    int shmid;
    key_t key = ftok(".",198);
    if((shmid = shmget(key,4096,IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 0;
    }
    if((share_memory = shmat(shmid,NULL,0)) < 0){
        perror("shmat");
        return 0;
    }
    while(1) {
        sleep(5);
        printf("%s",share_memory);
        memset(share_memory,0,sizeof(share_memory));
    }
    return 0;
}

