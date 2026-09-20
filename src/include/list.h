#include <iostream>
#include <vector>

using namespace std;

class List {
    public:
        vector<string> list;
        string name;
        vector<vector<string>> mainList;
        unsigned int currentUserIndex;
        void print_menu();
        void print_list();
        void add_item();
        void delete_item();
        bool find_user_list();
        void save_list();

};