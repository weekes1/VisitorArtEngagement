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

// class for accessing and communicating with databse
class visDB {
public:
    visDB();
    vector<userEntry> findByLocation(string location); // returns vector of userEntry that are in the location searched
    vector<userEntry> findByColor(string color); // returns vector of userEntry that are of the color searched

    userEntry fetchEntry(string id); // returns userEntry of the id searched
    void addEntry(string color, string location); // adds an entry with that color and location
    void rmLoc(string location); // removes all the entries of the location
    
private:
    const string db_url=DB_URL;
    const string user=USER;
    const string pass=PASS;
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;

};

#endif /* CHATDB_H */
