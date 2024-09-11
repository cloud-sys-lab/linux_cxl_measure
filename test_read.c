#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void test_read(const char *filepath) {
    char buffer[11];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    ssize_t bytes_read = read(fd, buffer, 10);
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("First 10 characters read from the file: %s\n", buffer);

    close(fd);
}

int main(int argc, char *argv[]) {
    const char *filePath = "/home/cc/workspace/linux_cxl_measure/to_read.txt"; 
    if (argc >= 2) {
        filePath = argv[1]; 
    }
    sleep(2);

    test_read(filePath);
    return EXIT_SUCCESS;
}