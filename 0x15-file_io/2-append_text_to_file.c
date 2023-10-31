#include <stdio.h>
#include <fcntl.h>
#include "main.h"

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len;
    if (!filename)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        len = 0;
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
