#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[100] = "Hello, World!\n";

    //creating a file
    fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if(fd == -1) {
        printf("Error creating file\n");
        return 1;
    }
    else {
        printf("File created\n");
    }

    //writing to file
    int bytes = write(fd, buffer, sizeof(buffer));
    if(bytes == -1) {
        printf("Error writing to file\n");
        return 1;
    }
    else {
        printf("Wrote %d bytes to file\n", bytes);
    }

    //reading from file
    lseek(fd, 0, SEEK_SET);
    bytes = read(fd, buffer, sizeof(buffer));
    if(bytes == -1) {
        printf("Error reading from file\n");
        return 1;
    }
    else {
        printf("Read %d bytes from file: %s\n", bytes, buffer);
    }

    //closing file
    if(close(fd) == -1) {
        printf("Error closing file\n");
        return 1;
    }
    else {
        printf("File closed\n");
    }

    return 0;
}
