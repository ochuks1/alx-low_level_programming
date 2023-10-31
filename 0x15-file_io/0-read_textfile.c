#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    int fd;
    char *buf;
    ssize_t n_read, n_written;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(letters);
    if (buf == NULL) {
        close(fd);
        return (0);
    }

    n_read = read(fd, buf, letters);
    if (n_read == -1) {
        free(buf);
        close(fd);
        return (0);
    }

    n_written = write(STDOUT_FILENO, buf, n_read);
    if (n_written == -1 || n_written != n_read) {
        free(buf);
        close(fd);
        return (0);
    }

    free(buf);
    close(fd);
    return (n_written);
}
