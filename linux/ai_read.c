#include <aio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

const int FILE_SIZE = 100;
const char pathname[20] = "open-file.txt";

int main () {
    int fd = open(pathname, O_RDONLY);
    if (fd == -1) {
        printf("ERROR - %s.\n", stderror(errno));
        return 1;
    }

    char *buff = (char *)calloc(FILE_SIZE, sizeof(char));
    struct aiocb cb = {
        .aio_fildes = fd,
        .aio_offset = 0,
        .aio_buf = buff,
        .aio_nbytes = FILE_SIZE;
    };   

    if (aio_read(&cb) == -1) {
        printf("ERROR - %s.\n", stderror(errno));
    }
    printf("Request is enqueued. \n");

    while (aio_error(&cb) == EINPROGRESS) {
        printf("Request is being handled... \n");
    }

    int read_return = aio_return(&cb); 
    if (!read_return) {
        printf("Read successfully. \n");
    }

    else if (read_return == -1) {
        printf("ERROR - %s.\n", stderror(errno));
    }
    free(buff);
    close(fd);
}