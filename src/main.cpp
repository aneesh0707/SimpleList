#include "include/list.h"
#include "include/database.h"
using namespace std;

int main(int argc, char *argv[]) {
    List simpleList;
    Database data;
    if (argc > 1) {
        
        simpleList.name = string(argv[1]);
        simpleList.mainList = data.read();
        simpleList.find_user_list();
        simpleList.print_menu();
        data.write(simpleList.mainList);
        
    }
    else {
        cout << "Username not supplied. Exiting the program" << endl;
    }

    data.read();
    return 0;
}

