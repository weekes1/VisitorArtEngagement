#include "userEntry.h"

userEntry::userEntry() {
}


// constructor
userEntry::userEntry(sql::SQLString I, sql::SQLString c, sql::SQLString t, sql::SQLString l) {
    ID = I;
    color = c;
    timestamp = t;
    location = l;
}

// returns the user info in a string
string userEntry::text() {
	string result = ID + ". ";
	result += color + " ";
	result += timestamp + " ";
	result += location + " ";
	return result;

}

// returns user info in a valid JSON string
string userEntry::json() {
	string result = "{\"ID\":\"" + ID + "\",";
	result += "\"color\":\"" + color + "\",";
	result += "\"timestamp\":\"" + timestamp + "\",";
	result += "\"location\":\"" + location + "\"}";
	
	return result;

}
