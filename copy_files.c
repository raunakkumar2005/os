#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int input_fd, output_fd;
    ssize_t ret_in, ret_out;
    char buffer[BUF_SIZE];

    if (argc != 3)
    {
        printf("Usage: %s file_origin file_destination\n", argv[0]);
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
    {
        perror("open");
        return 2;
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1)
    {
        perror("open");
        return 3;
    }

    while ((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0)
    {
        ret_out = write(output_fd, &buffer, (ssize_t)ret_in);
        if (ret_out != ret_in)
        {
            perror("write");
            return 4;
        }
    }

    close(input_fd);
    close(output_fd);

    return 0;
}
