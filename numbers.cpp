#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv) {
    int fd;
    if (argc == 1) {
        fd = 0;
    } else if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
            perror("Open file");
            return 1;
        }
    } else {
        cerr << "Error argc can be 1 or 2\n";
        return 1;
    }

    //Разделяющий символ
    int tmp = write(1, "|", 1);
    if (tmp == 0) {
        cerr << "\nError write to file\n";
        return 1;
    } else if (tmp == -1) {
        perror("\nWrite");
        return 1;
    }

    while (true) {
        int chnum;
        char ch;

        chnum = read(fd, &ch, 1);
        if (chnum == -1) {
            perror("\nRead");
            return 1;
        } else if (chnum == 0) {
            break;
        }

        if (isdigit(ch)) {
            tmp = write(1, &ch, 1);
            if (tmp == 0) {
                cerr << "\nError write to file\n";
                return 1;
            } else if (tmp == -1) {
                perror("\nWrite");
                return 1;
            }
        }
    }

    //Разделяющий символ
    tmp = write(1, "|\n", 2);
    if (tmp == 0) {
        cerr << "\nError write to file\n";
        return 1;
    } else if (tmp == -1) {
        perror("\nWrite");
        return 1;
    }

    return 0;
}
