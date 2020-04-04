/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 19时46分28秒
 ************************************************************************/
#include"head.h"

char *share_memory;

int main() {
    int shmid;
    key_t key = ftok(".",198);
    if((shmid = shmget(key, 4096,IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return 0;
    }

    if ((share_memory = shmat(shmid,NULL,0)) < 0) {
        perror("shmat");
        return 0;
    }
    while(1) {
        scanf("%[^\n]s",share_memory);
    }
    return 0;
}
