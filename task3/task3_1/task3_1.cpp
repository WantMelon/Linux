#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void stat_print(char* file_path) {

    struct stat sb;

    if (stat(file_path, &sb) == -1) {
        perror("stat");
        exit(1);
    }
    cout << "ID of device containing file: " << sb.st_dev << endl;
    cout << "Inode number: " << sb.st_ino << endl;
    cout << "File type and mode: " << sb.st_mode << endl;
    cout << "Number of hard links: " << sb.st_nlink << endl;
    cout << "User ID of owner: " << sb.st_uid << endl;
    cout << "Group ID of owner: " << sb.st_gid << endl;
    cout << "Device ID (if special file): " << sb.st_rdev << endl;
    cout << "Total size, in bytes: " << sb.st_size << endl;
    cout << "Block size for filesystem I/O: " << sb.st_blksize << endl;
    cout << "Number of 512B blocks allocated: " << sb.st_blocks << endl;
    cout << endl;
}

void statvfs_print(char* file_path) {
    struct statvfs sv;

    if (statvfs(file_path, &sv) == -1) {
        perror("statvfs");
        exit(1);
    }
    cout << "FILE SYSTEM\n";
    cout << "Filesystem block size: " << sv.f_bsize << endl;
    cout << "Fragment size: " << sv.f_frsize << endl;
    cout << "Size of fs in f_frsize units: " << sv.f_blocks << endl;
    cout << "Number of free blocks: " << sv.f_bfree << endl;
    cout << "Number of free blocks for unprivileged users : " << sv.f_bavail << endl;
    cout << "Number of inodes: " << sv.f_files << endl;
    cout << "Number of free inodes: " << sv.f_ffree << endl;
    cout << "Number of free inodes for unprivileged users: " << sv.f_favail << endl;
    cout << "Filesystem ID: " << sv.f_fsid << endl;
    cout << "Mount flags: " << sv.f_flag << endl;
    cout << "Maximum filename length: " << sv.f_namemax << endl;
    cout << endl;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Expacted one argument\n";
        return 1;
    }

    stat_print(argv[1]);
    statvfs_print(argv[1]);

    return 1;
}
