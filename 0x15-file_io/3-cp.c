#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void error_exit(int code, const char *message, const char *arg)
{
    dprintf(STDERR_FILENO, message, arg);
    exit(code);
}

int main(int argc, char *argv[])
{
    int from_fd, to_fd;
    ssize_t rcount, wcount;
    char buffer[1024];

    if (argc != 3)
    {
        error_exit(97, "Usage: cp file_from file_to\n", "");
    }

    from_fd = open(argv[1], O_RDONLY);
    if (from_fd == -1)
    {
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (to_fd == -1)
    {
        error_exit(99, "Error: Can't write to file %s\n", argv[2]);
    }

    while ((rcount = read(from_fd, buffer, 1024)) > 0)
    {
        wcount = write(to_fd, buffer, rcount);
        if (wcount != rcount)
        {
            error_exit(99, "Error: Can't write to file %s\n", argv[2]);
        }
    }

    if (rcount == -1)
    {
        error_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    if (close(from_fd) == -1 || close(to_fd) == -1)
    {
        error_exit(100, "Error: Can't close fd\n", "");
    }

    return 0;
}
