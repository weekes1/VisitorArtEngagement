#include "userEntry.h"

userEntry::userEntry() {
}

userEntry::userEntry(sql::SQLString I, sql::SQLString c, sql::SQLString t, sql::SQLString l) {
    ID = I;
    color = c;
    timestamp = t;
    location = l;
}

string userEntry::text() {
	string result = ID + ". ";
	result += color + " ";
	result += timestamp + " ";
	result += location + " ";
	return result;

}

string userEntry::json() {
	string result = "{\"ID\":\"" + ID + "\",";
	result += "\"color\":\"" + color + "\",";
	result += "\"timestamp\":\"" + timestamp + "\",";
	result += "\"location\":\"" + location + "\"}";
	
	return result;

}
