#include <iostream>
#include <string>
#include <sys/statvfs.h>

using namespace std;

void decrease(int decrease_number) {
    if (decrease_number < 0) {
        cerr << "Decrease number mast be > 0\n";
        exit(-1);
    }

    for (int i = 1; i <= decrease_number; ++i) {
        string command = "touch temp/file-" + to_string(i);
        system(command.c_str());
    }
}

void check_inode(char* file_path) {
    struct statvfs sv;
    statvfs(file_path, &sv);
    cout << "inods number: " << sv.f_favail << endl << endl;
}

void increase(int increase_number) {
    if (increase_number < 0) {
        cerr << "Increase number mast be > 0\n";
        exit(-1);
    }

    for (int i = 1; i <= increase_number; ++i) {
        string command = "rm temp/file-" + to_string(i);
        system(command.c_str());
    }
}

int main(int argc, char** argv) {
    system("rm -r -f temp");
    system("mkdir temp");

    check_inode(argv[0]);

    int increase_number;
    int decrease_number;
    cout << "How many inodes do you want to decrease?\n";
    cin >> decrease_number;
    decrease(decrease_number);

    check_inode(argv[0]);

    while (true) {
        cout << "How many inodes do you want to increase?\n";
        cin >> increase_number;
        if (increase_number > decrease_number) {
            cout << "Increase number can not be more than decrease number\n";
            cout << "Try again\n";
        } else {
            increase(increase_number);
            break;
        }
    }

    check_inode(argv[0]);

    return 0;
}
