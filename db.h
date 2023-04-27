#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
#include <vector>


#include <mariadb/conncpp.hpp>
#include "userEntry.h"

#ifndef CHATDB_H
#define CHATDB_H

#define DB_URL "jdbc:mariadb://localhost:3306/scmp318"
#define USER "scmp318"
#define PASS "lords"

using namespace std;

class visDB {
public:
    visDB();
    vector<userEntry> findByLocation(string location);
    vector<userEntry> findByColor(string color);

    userEntry fetchEntry(string id);
    void addEntry(string color, string location);
    void rmLoc(string location);
    
private:
    const string db_url=DB_URL;
    const string user=USER;
    const string pass=PASS;
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;

};

#endif /* CHATDB_H */
