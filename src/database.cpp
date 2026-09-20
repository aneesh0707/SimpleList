#include "include/database.h"

void Database::write(vector<vector<string>> mainList) {
    ofstream db("db/lists.sl", ios::trunc);
    if (db.is_open()) {
        for (auto& i : mainList) {
            if (i.empty()) {
                continue;
            }
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
}
vector<vector<string>> Database::read(){
    string line;
    ifstream db("db/lists.sl");

    mainList.clear();
    vector<string> userList;
    bool readingUser = false;

    if (db.is_open()) {
        while (getline(db, line, '\n')) {
            if (line.empty()) {
                continue;
            }

            if (line[0] == '#') {
                line.erase(line.begin());
                userList.push_back(line);
                readingUser = true;
            }
            else if (line[0] == '%' && readingUser) {
                mainList.push_back(userList);
                userList.clear();
                readingUser = false;
            }
            else if (readingUser) {
                userList.push_back(line);
            }
        }
    }
    else {
        cout << "cannot open file for reading.";
    }
    return mainList;

}