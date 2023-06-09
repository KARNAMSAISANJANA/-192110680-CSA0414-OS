#include <stdio.h>
#include <pthread.h>

void *print_hello(void *arg) {
    printf("Hello, world!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    return 0;
}

(ii)Joining a thread
#include <stdio.h>
#include <pthread.h>

void *print_hello(void *arg) {
    printf("Hello, world!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    pthread_join(thread, NULL);
    return 0;
}

(iii)Comparing two threads
#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print_hello, NULL);
    pthread_create(&thread2, NULL, print_hello, NULL);

    if (pthread_equal(thread1, thread2)) {
        printf("thread1 and thread2 are equal\n");
    } else {
        printf("thread1 and thread2 are not equal\n");
    }

    return 0;
}

(iv) Exit a Thread
#include <stdio.h>
#include <pthread.h>

void *print_hello(void *arg) {
    printf("Hello, world!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    pthread_join(thread, NULL);
    return 0;
}
