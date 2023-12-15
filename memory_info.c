#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

int main()
{
    struct utsname unameData;
    if (uname(&unameData) == -1)
    {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    printf("Kernel version: %s\n", unameData.release);

    struct sysinfo sysInfo;
    if (sysinfo(&sysInfo) == -1)
    {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }
    printf("Total configured memory: %lu MB\n", sysInfo.totalram / 1024 / 1024);
    printf("Amount of free memory: %lu MB\n", sysInfo.freeram / 1024 / 1024);
    printf("Amount of used memory: %lu MB\n", (sysInfo.totalram - sysInfo.freeram) / 1024 / 1024);

    return 0;
}
