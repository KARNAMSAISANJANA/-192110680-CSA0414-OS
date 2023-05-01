#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd1, fd2, n;
    char buffer[BUFFER_SIZE];

    
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

   
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        printf("Error opening source file %s\n", argv[1]);
        exit(1);
    }

    
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        printf("Error creating or truncating destination file %s\n", argv[2]);
        exit(1);
    }

    while ((n = read(fd1, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd2, buffer, n) != n) {
            printf("Error writing to destination file %s\n", argv[2]);
            exit(1);
        }
    }

 
    if (n == -1) {
        printf("Error reading from source file %s\n", argv[1]);
        exit(1);
    }

    close(fd1);
    close(fd2);

    printf("File %s copied to %s\n", argv[1], argv[2]);
    return 0;
}

