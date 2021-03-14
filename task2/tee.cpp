#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>

using namespace std;

void write_to_file(int* fds, int N)
{
    char ch;
    while (true)
    {
        ssize_t temp = read(0, &ch, 1);
        if (temp == 0) break;
        if (temp == -1)
        {
            perror("Error read stdin ");
            return;
        }

        for (int i = 0; i < N; ++i)
        {
            if (fds[i] == -2) continue;
            if (fds[i] == -1)
            {
                perror("Error open file");
                return;
            }

            temp = write(fds[i], &ch, 1);
            if (temp == 0)
            {
                cerr << "Can not write to file!\n";
                cerr << "This may happen for example because the disk device was filled.\n";
                return;
            }
            if (temp == -1)
            {
                perror("Error write file");
                return;
            }
        }
    }

    for (int i = 1; i < N; ++i)
        close(fds[i]);
}

void help_manual()
{
    cout << "Использование: tee [КЛЮЧ]… [ФАЙЛ]…\n\
Копирует стандартный ввод в каждый ФАЙЛ, а также в стандартный вывод.\n\
-a, --append              дописать в заданные ФАЙЛЫ\n\
--help     показать эту справку и выйти\n\
--version  показать информацию о версии и выйти\n";
}

void print_version()
{
    cout <<"Copyright (C) 2021 Samorosenko Artem.\n\
Это свободное ПО: вы можете изменять и распространять его.\n\
Нет НИКАКИХ ГАРАНТИЙ до степени, разрешённой законом.\n";
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "RUS");

    bool append = false;
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            if (!strcmp(argv[i], "--help")) {
                help_manual();
                return 0;
            }
            else if (!strcmp(argv[i], "-a")) append = true;
            else if (!strcmp(argv[i], "--version")) {
                print_version();
                return 0;
            }
            else {
                cout << "Неверный ключ.\n";
                cout << "Дополнительную информацию можно получить по команде --help\n";
                return 0;
            }
        }
    }

    int fds[argc];
    fds[0] = 1;
    int counter = 0;
    for (int i = 1; i < argc; ++i)
    {
        int fd = -1;
        if (argv[i][0] == '-')
        {
            fds[i] = -2;
            continue;
        }

        if (append)
            fd = open(argv[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
        else
            fd = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        fds[i] = fd;
    }

    write_to_file(fds, sizeof(fds)/sizeof(fds[0]));

    return 0;
}
