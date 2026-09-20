#include "include/list.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        List simpleList;
        simpleList.name = string(argv[1]);
        simpleList.print_menu();
    }
    else {
        cout << "Username not supplied. Exiting the program" << endl;
    }
    return 0;
}

