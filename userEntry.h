#include <mariadb/conncpp.hpp>
#include <string>
using namespace std;

#ifndef USERENTRY_H
#define USERENTRY_H

// Class that contains all the information that a user enters into database
class userEntry {
public:
     userEntry();
     userEntry(sql::SQLString I, sql::SQLString c, sql::SQLString t, sql::SQLString l);
     string text(); // returns the user info in a string
     string json(); // returns user info in a valid JSON string
     
     string ID;
     string color;
     string timestamp;
     string location;

private:

};

#endif /* USERENTRY_H */
