#include <vector>
#include <iostream>
#include <regex>
#include <mariadb/conncpp.hpp>
#include "db.h"
#include "userEntry.h"


visDB::visDB() {
  	// Instantiate Driver
  	driver = sql::mariadb::get_driver_instance();
  	
 	// Configure Connection
  	// The URL or TCP connection string format is
  	// ``jdbc:mariadb://host:port/database``.
  	sql::SQLString url(db_url);

    // Use a properties map for the other connection options
  	sql::Properties my_properties({{"user", user}, {"password",pass}});
  	// Save properties in object
  	properties = my_properties;

    // Establish Connection
  	std::unique_ptr<sql::Connection> my_conn(driver->connect(db_url, properties));
    
    // Check success
    if (!my_conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
   	
   	// Save connection in object
   	conn = std::move(my_conn);
   	
}


vector<userEntry> visDB::findByLocation(string location) {

	vector<userEntry> list;
    
    // Make sure the connection is still valid
    if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
    // Create a new Statement
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    
    // Execute query
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM visitorEngagement WHERE Location = '"+location+"'");
    
    // Loop through and print results
    while (res->next()) {
    	userEntry entry(res->getString("ID"),res->getString("Color"),
			res->getString("Timestamp"),res->getString("Location"));
	    list.push_back(entry);
    }
    return list;

}


vector<userEntry> visDB::findByColor(string color) {

	vector<userEntry> list;
    
    // Make sure the connection is still valid
    if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
    // Create a new Statement
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    
    // Execute query
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM visitorEngagement WHERE Color = '"+color+"'");
    
    // Loop through and print results
    while (res->next()) {
    	userEntry entry(res->getString("ID"),res->getString("Color"),
			res->getString("Timestamp"),res->getString("Location"));
	    list.push_back(entry);
    }
    return list;

}


void visDB::addEntry(string color, string location){

	if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
  	}

  	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
  	
  	stmnt->executeQuery("INSERT INTO visitorEngagement (Color, Location) VALUES ('"+color+"','"+location+"')");
}

userEntry visDB::fetchEntry(string id){

	userEntry entry;	
	
	if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
  	}

  	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());

  	
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM users WHERE ID = '"+id+"'");
    
    // Get first entry
    if (res->next()) {
    	entry = userEntry(res->getString("ID"),res->getString("Color"),
			res->getString("Timestamp"),res->getString("Location"));
    }
    return entry;
}

void visDB::rmLoc(string location) {
	if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
  	}
	
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());

	stmnt->executeQuery("DELETE FROM `visitorEngagement` WHERE Location = '"+location+"'");
}