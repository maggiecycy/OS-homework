#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   // 控制文件（open）
#include <unistd.h>  // 系统调用接口（read, write, close）

int main() {
    // 1. 系统调用 open: 返回一个文件描述符 (fd)
    int fd = open("README.md", O_RDONLY); 
    if (fd == -1) {
        perror("Error opening README.md"); // 严谨：处理异常
        exit(1);
    }

    char buffer[100];
    ssize_t num_read;

    // read 返回读到的字节数。如果读到文件末尾，返回 0。
    while ( (num_read = read(fd, buffer, 100)) > 0 ) {
        // 将读到的内容写出到标准输出 (1)
        if (write(1, buffer, num_read) != num_read) {
            perror("Write error");
            exit(1);
        }
    }

    // 3. 系统调用 write: 将 buffer 内容写到 1 号文件描述符 (标准输出)
    if (num_read > 0) {
        write(1, buffer, (size_t)num_read); 
    }
    // 4. 关闭文件
    close(fd);

    return 0;
}