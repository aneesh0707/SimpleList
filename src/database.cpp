#include "include/database.h"

void Database::write(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/lists.sl");
    if (db.is_open()) {
        for (auto& i : mainList) {
            for (size_t k = 0; k < i.size(); k++) {
                auto& j = i[k];
                if (k == 0) {
                    db << "#" << j << "\n";
                }
                else {
                    db << j << "\n";
                }
            }
            db << "%" << "\n";
        }   
    }   
    else {
        cout << "cannot open file for writing.";
    }
    db.close();
}
vector<vector<string>> Database::read(){
    string line;
    ifstream db;
    db.open("db/lists.sl");

    vector<string> userList;

    if (db.is_open()) {
        while (getline(db, line, '\n')) {
            if (line.front() == '#') {
                cout << "found a hashtag" << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if (line.front() == '%') {
                cout << "found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else {
                cout << "found an item: " << line << "\n";
                userList.push_back(line);
            }
        }
    }
    else {
        cout << "cannot open file for reading.";
    }
    db.close();

    return mainList;

}