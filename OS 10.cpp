#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define QUEUE_NAME "/test_queue"

int main(int argc, char *argv[]) {
    mqd_t mq;
    char buffer[MAX_SIZE];
    struct mq_attr attr;
    int msg_len, nbytes;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }

    strcpy(buffer, "Hello, world!");
    msg_len = strlen(buffer);
    if (mq_send(mq, buffer, msg_len, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    nbytes = mq_receive(mq, buffer, MAX_SIZE, NULL);
    if (nbytes == -1) {
        perror("mq_receive");
        exit(1);
    }
    buffer[nbytes] = '\0';
    printf("Received message: %s\n", buffer);

    mq_close(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}

