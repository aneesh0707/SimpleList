#include "include/database.h"

void Database::write(vector<string> list) {
    ofstream db;
    db.open("db/lists.sl");
    if (db.is_open()) {
        for (auto& i : list) {
            db << i << "\n";
        }
    }
    else {
        cout << "cannot open file for writing.";
    }
    db.close();
}
void Database::read(){
    string line;
    ifstream db;
    db.open("db/lists.sl");
    if (db.is_open()) {
        while (getline(db, line, '\n')) {
            cout << line << "\n";
        }
    }
    else {
        cout << "cannot open file for reading.";
    }
    db.close();

}