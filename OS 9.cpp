#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    int *data;

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = (char*)shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    data = (int*)shmaddr;
    *data = 42;

    shmdt(shmaddr);

    shmaddr = (char*)shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    data = (int*)shmaddr;
    printf("Data read from shared memory: %d\n", *data);

    shmdt(shmaddr);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

