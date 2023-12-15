#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main()
{
    struct utsname unameData;
    if (uname(&unameData) == -1)
    {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    printf("Kernel version: %s\n", unameData.release);
    printf("CPU type and model: ");
    system("cat /proc/cpuinfo | grep 'model name' | uniq | cut -d ':' -f 2-");
    return 0;
}
