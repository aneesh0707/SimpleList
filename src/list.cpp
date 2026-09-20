#include "include/list.h"
#include "include/database.h"

void List::print_list() {
    cout << "\n+------------------------------------------+\n";
    cout << "|                 YOUR LIST                |\n";
    cout << "+------------------------------------------+\n";

    if (list.empty()) {
        cout << "|  (empty)                                 |\n";
    }
    else {
        for (size_t i = 0; i < list.size(); i++) {
            cout << "|  " << i + 1 << ". " << list[i] << "\n";
        }
    }

    cout << "+------------------------------------------+\n";
    cout << "|  M - Back to menu                       |\n";
    cout << "+------------------------------------------+\n";
    cout << "Choice: ";
    char choice;
    cin >> choice;

    if (choice == 'M' || choice == 'm') print_menu();
    else cout << "Invalid choice. Exiting.\n";

}

void List::add_item() {
    cout << "\n+------------------------------------------+\n";
    cout << "|                  ADD ITEM                |\n";
    cout << "+------------------------------------------+\n";
    cout << "Item: ";

    string item;
    getline(cin >> ws, item);

    list.push_back(item);

    cout << "Added to your list.\n";
    cin.clear();

    print_menu();
}

void List::delete_item() {
    cout << "\n+------------------------------------------+\n";
    cout << "|                DELETE ITEM               |\n";
    cout << "+------------------------------------------+\n";

    if (!list.empty()) {
        for (size_t i = 0; i < list.size(); i++) {
            cout << "  " << i + 1 << ". " << list[i] << "\n";
        }
        int choiceNum;
        cout << "Item number: ";
        cin >> choiceNum;
        if (cin && choiceNum > 0 && static_cast<size_t>(choiceNum) <= list.size()) {
            list.erase(list.begin() + choiceNum - 1);
            cout << "Item deleted.\n";
        }
        else {
            cout << "Invalid item number.\n";
        }
    }
    else {
        cout << "Your list is already empty.\n";
    }
    print_menu();
}

void List::print_menu() {
    int choice;
    cout << "\n+------------------------------------------+\n";
    cout << "|              SIMPLE LIST                 |\n";
    cout << "|              User: " << name << "\n";
    cout << "+------------------------------------------+\n";
    cout << "|  1. View list                            |\n";
    cout << "|  2. Add an item                          |\n";
    cout << "|  3. Delete an item                       |\n";
    cout << "|  4. Save list                            |\n";
    cout << "|  5. Quit                                 |\n";
    cout << "+------------------------------------------+\n";
    cout << "Choice: ";

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
            save_list();
            break;
        
        case 5:
            return;
        
        default:
            cout << "Invalid choice. Please select 1-5.\n";
    }
}

bool List::find_user_list() {
    bool userFound = false;
    cout << "\n+------------------------------------------+\n";
    cout << "|             WELCOME, " << name << "\n";
    cout << "+------------------------------------------+\n";
    
    for (unsigned int i = 0; i < mainList.size(); i++) {
        if (mainList[i][0] == name) {
            currentUserIndex = i;
            list.assign(mainList[i].begin() + 1, mainList[i].end());
            userFound = true;
            break;
        }
    }

    if (userFound == false) {
        mainList.push_back(vector<string>{name});
        currentUserIndex = mainList.size() - 1;
        cout << "New list created.\n";
    }
    else {
        cout << "Your saved list is ready.\n";
    }

    return userFound;
}

void List::save_list() {
    mainList[currentUserIndex].clear();
    mainList[currentUserIndex].push_back(name);
    mainList[currentUserIndex].insert(
        mainList[currentUserIndex].end(), list.begin(), list.end());
    Database data;
    data.write(mainList);
    cout << "\nList saved successfully.\n";
    print_menu();
}