#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
#include "httplib.h"
#include "db.h"
#include "userEntry.h"

using namespace httplib;
using namespace std;

int main() {
    visDB vdb;
    bool running = true;
    int resp=0;
    cout << "Please choose from the following." << endl;
    cout << "1: New Entry, 2: Search by Location, 3: Search by Color, 4: Quit" << endl;
    cin >> resp;
    

    while(resp != 4) {     
        if(resp==1) {
            string color = "";
            string loc = "";
            cout << "Input color: ";
            cin >> color;
            cout << "Input location: ";
            cin >> loc;

            vdb.addEntry(color, loc);
        }
        else if (resp==2) {
            string loc = "";
            cout << "Input location to search for: ";
            cin >> loc;
            vector<userEntry> respVec;
            respVec = vdb.findByLocation(loc);

            for(int i = 0; i < respVec.size(); i++) {
                cout << respVec[i].ID << " " << respVec[i].color << " " << respVec[i].timestamp << " " << respVec[i].location << endl;
            }
        } 
        else if (resp==3) {
            string col = "";
            cout << "Input color to search for: ";
            cin >> col;
            vector<userEntry> respVec;
            respVec = vdb.findByColor(col);

            for(int i = 0; i < respVec.size(); i++) {
                cout << respVec[i].ID << " " << respVec[i].color << " " << respVec[i].timestamp << " " << respVec[i].location << endl;
            }
        } 
        cout << "1: New Entry, 2: Search by Location, 3: Search by Color, 4: Quit" << endl;
        cin >> resp;
        cout << resp << endl;
    }
}