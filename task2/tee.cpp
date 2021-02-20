#include <iostream>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cerr << "Too few arguments\n";
        return 1;
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error open file");
        return 1;
    }

    char ch;
    while (true)
    {
        int temp = read(0, &ch, 1);
        if (temp == 0) break;
        if (temp == -1)
        {
            perror("Error read stdin");
            return 1;
        }

        temp = write(fd, &ch, 1);
        if (temp == 0)
        {
            cerr << "Can not write to file!\n";
            cerr << "This may happen for example because the disk device was filled.\n";
            return 1;
        }
        if (temp == -1)
        {
            perror("Error write file");
            return 1;
        }

        temp = write(1, &ch, 1);
        if (temp == -1)
        {
            perror("Error write stdout");
            return 1;
        }
    }

    close(fd);
    return 0;
}
