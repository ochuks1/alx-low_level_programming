#include <stdio.h>
#include <fcntl.h>
#include "main.h"

int create_file(const char *filename, char *text_content)
{
	int fd;
    if (!filename)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        int len = 0;
        while (text_content[len])
            len++;
        if (write(fd, text_content, len) == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
