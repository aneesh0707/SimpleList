#include "include/list.h"

void List::print_list() {
    cout << "\n\n\n";
    cout << "*********** List ************\n";
    for (auto& i : list) {
        cout << " * " << i << "\n";
    }

    cout << "M - Menu\n";
    char choice;
    cin >> choice;

    if (choice == 'M' || choice == 'm') print_menu();
    else cout << "Invalid Choice. Quitting..\n";

}

void List::add_item() {
    cout << "\n\n\n";
    cout << "*********** Add Item ************\n";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "Successfully added an item to the list \n";
    cin.clear();

    print_menu();
}

void List::delete_item() {
    cout << "\n\n\n";
    cout << "*********** Delete Item ************\n";
    cout << "Type in an item index number to delete:\n";

    // if something exists in the list
    if (list.size()) {
        for (unsigned int i = 0; i < list.size(); i++) {
            cout << i << ": " << list[i] << "\n";
        }
        int choiceNum;
        cin >> choiceNum;
        list.erase(list.begin() + choiceNum);
    }
    else {
        cout << "No items in the list currently.";
    }
    print_menu();
}

void List::print_menu() {
    int choice;
    cout << "*********************************\n";
    cout << " 1 - Print List.\n";
    cout << " 2 - Add to list.\n";
    cout << " 3 - Delete from list.\n";
    cout << " 4 - Quit.\n";
    cout << " Enter your choice and press enter.\n";

    cin >> choice;

    switch (choice) {
        case 1:
            print_list();
            break;
        case 2:
            add_item();
            break;
        
        case 3:
            delete_item();
            break;

        case 4:
            return;
        
        default:
            cout << "Select a correct choice.\n";
    }
}