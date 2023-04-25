#include <mariadb/conncpp.hpp>
#include <string>
using namespace std;

#ifndef USERENTRY_H
#define USERENTRY_H

class userEntry {
public:
     userEntry();
     userEntry(sql::SQLString I, sql::SQLString c, sql::SQLString t, sql::SQLString l);
     string text();
     string json();
     
     string ID;
     string color;
     string timestamp;
     string location;

private:

};

#endif /* USERENTRY_H */
