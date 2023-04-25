//
//  namesAPI.cc - a microservice demo program
//
// James Skon
// Kenyon College, 2022
//

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

const int port = 5010;

void addMessage(string username, string message, map<string,vector<string>> &messageMap) {
	/* iterate through users adding message to each */
	string jsonMessage = "{\"user\":\""+username+"\",\"message\":\""+message+"\"}";
	for (auto userMessagePair : messageMap) {
		username = userMessagePair.first;
		messageMap[username].push_back(jsonMessage);
	}
}

string getMessagesJSON(string username, map<string,vector<string>> &messageMap) {
	/* retrieve json list of messages for this user */
	bool first = true;
	string result = "{\"messages\":[";
	for (string message :  messageMap[username]) {
		if (not first) result += ",";
		result += message;
		first = false;
	}
	result += "]}";
	messageMap[username].clear();
	return result;
}


int main(void) {
  Server svr;
  
  visDB vdb;
	
  /* "/" just returnsAPI name */
  svr.Get("/", [](const Request & /*req*/, Response &res) {
    res.set_header("Access-Control-Allow-Origin","*");
    res.set_content("Chat API", "text/plain");
  });

   svr.Get(R"(/chat/send/(.*)/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
    string token = req.matches[1];
    string message = req.matches[2];
    string result; 
    if(tokenMap.count(token)){
      string username = tokenMap.at(token);
      if (!messageMap.count(username)) {
        result = "{\"status\":\"baduser\"}";
      } else {
        addMessage(username,message,messageMap);
        result = "{\"status\":\"success\"}";
      }
    }
    else {
      result = "{\"status\":\"Invalid Token\"}";
    }
      res.set_content(result, "text/json");
    });
  
   svr.Get(R"(/chat/fetch/(.*))", [&](const Request& req, Response& res) {
    string token = req.matches[1];
    res.set_header("Access-Control-Allow-Origin","*");
    string result;
    if(tokenMap.count(token)){
    	string username= tokenMap.at(token);
    	vector<string> messges = messageMap.find(username)->second;
		result = getMessagesJSON(username,messageMap);
    	
    }
    else{
   		result= "{\"Error\":\"Invalid Token\"}";
    }	
    res.set_content(result, "text/json");
  });

  svr.Get(R"(/chat/users)", [&](const Request& req, Response& res) {
    vector<string> users;
    for(map<string, vector<string>>::iterator i = messageMap.begin(); i!=messageMap.end(); ++i){
      users.push_back(i->first);
    }

    string usersJSON = "{\"users\":[";
    for(int i = 0; i < users.size(); i++){
      if(i!=0) usersJSON += ",";
      usersJSON += "\""+users[i]+"\"";
    }
    usersJSON+="]}";
    res.set_header("Access-Control-Allow-Origin","*");
    res.set_content(usersJSON, "text/json");
  });

  svr.Get(R"(/chat/leave/(.*))", [&](const Request& req, Response& res) {
    string token = req.matches[1];
    if (tokenMap.count(token)){
      string username = tokenMap.at(token);
      int erase = messageMap.erase(username);
      tokenMap.erase(token);
      udb.changeActive(username, "False");
      res.set_header("Access-Control-Allow-Origin","*");
      if(erase==1) {
        res.set_content("Success", "text/plain");
        cout << username << " has left" << endl;
      }
      if(erase!=1) {
        res.set_content("Failed to find username", "text/plain");
        cout << "could not find " << username << endl;
      }
    }
    else {
      res.set_content("Invalid token", "text/plain");
    }
    cout << "check tokenMap for token" << tokenMap.count(token) << endl;
    
  });


  // Register users into userMap and throw error if user/email already exists and if password is less than 6 characters
  svr.Get(R"(/chat/register/(.*)/(.*)/(.*))", [&](const Request& req, Response& res) {
    string username = req.matches[1];
    string email = req.matches[2];
    string password = req.matches[3];
    // User chat_user= User(username, email, password, false);
    // order of errors username taken > email taken > invalid password
    res.set_header("Access-Control-Allow-Origin","*");
    if (udb.findByUsername(username).size() != 0){
      res.set_content("{\"result\": \"error\", \"message\": \"Username already exists\"}", "text/json");
    }
    else if (udb.findByEmail(email).size() != 0){
      res.set_content("{\"result\": \"error\", \"message\": \"Email already exists\"}", "text/json");
    }
    else if (password.size() < 6){
      res.set_content("{\"result\": \"error\", \"message\": \"Password is too short - must be at least 6 characters\"}", "text/json");
    }
    else {
      udb.addEntry(username, email, password, "False", "False");
      res.set_content("{\"result\": \"success\", \"message\": \"Successfully created user\"}", "text/json");
    }

  });

  // Altered join endpoint that requires password from register
  svr.Get(R"(/chat/join/(.*)/(.*)/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
    string username = req.matches[1];
    string password = req.matches[2];
    string token = req.matches[3];
    tokenMap[token] = username;
    string result;
    vector<string> empty;
 //   map<string, User>::iterator it = userMap.find(username);
    vector<userEntry> registeredUser = udb.findByUsername(username);
     
    if (registeredUser.size()!=0) {
    
      if (registeredUser[0].password == password) {
        if (udb.isActive(username)) {
          result = "{\"status\":\"exists\"}";
        } 
        else {
          // Add user to messages map
          udb.changeActive(username, "True");
          messageMap[username]=empty;
          result = "{\"status\":\"success\",\"user\":\"" + username + "\"}";
	  	    cout << username << " joins" << endl;
        }   
      }
      else{
        result = "{\"status\":\"error\", \"message\": \"Incorrect password\"}";
      }
    }
    else {
      result = "{\"status\":\"error\", \"message\": \"User does not exist\"}";
    }
    
    // Check if user with this name exists
    
    res.set_content(result, "text/json");
  });
  
 //------------------------------------------------------------------------------- 
  
//check for typing users 
  // output should be {"typing":["Bill","Suzy"]}
  svr.Get(R"(/chat/typing)", [&](const Request& req, Response& res) {
   	vector<userEntry> typingUsers = udb.findByTyping("True");
   	vector<string> typing_users;
      for(int i=0; i < typingUsers.size(); i++) {
        typing_users.push_back(typingUsers[i].username);
      }
    string usersJSON = "{\"typing\":[";
    for(int i = 0; i < typing_users.size(); i++) {
      if(i!=0) usersJSON += ",";
      usersJSON += "\""+typing_users[i]+"\"";
    }
    usersJSON+="]}";
    res.set_header("Access-Control-Allow-Origin","*");
    res.set_content(usersJSON, "text/json");
    }); 
//-----------------------------------------------------------------------    
//change user's typing status to on   
svr.Get(R"(/chat/typingon/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
    string token = req.matches[1];
    string result;
    if(tokenMap.count(token)){
    	string username= tokenMap.at(token);
    	if(udb.isTyping(username)) {
      		result= "{\"user\":\"" + username + "\" is still typing}";
    	}
    	else {
      		udb.changeTyping(username, "True");
      	    result= "{\"user\":\"" + username + "\" is typing now}";
    	}
    }
    else {
    	result= "{\"Error\":\"Invalid Token\"}";
    }
    
    res.set_content(result, "text/json");
    });
 
//change user's typing status to off
svr.Get(R"(/chat/typingoff/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
     string token = req.matches[1];
     string result;
    if(tokenMap.count(token)){
  		string username= tokenMap.at(token);
    	if(udb.isTyping(username)) {
    		  udb.changeTyping(username, "False");
    		  result= "{\"user\":\"" + username + "\" is not typing now}";
   		}
   		 else {
     		  result= "{\"user\":\"" + username + "\" is still not typing}";
   		 }
    }
    else {	
    	result= "{\"Error\":\"Invalid Token\"}";
    }
    res.set_content(result, "text/json");
    }); 


svr.Get(R"(/chat/activeOn/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
    string token = req.matches[1];
    string result;
    if(tokenMap.count(token)){
  		string username= tokenMap.at(token);
        if(!udb.isActive(username)) {
    	    udb.changeActive(username, "True");
      		result= "{\"user\":\"" + username + "\" is now joined}";
  	    }
    	else {
      		result= "{\"user\":\"" + username + "\" is already in}";
   		 }
   	}
   	else {	
    	result= "{\"Error\":\"Invalid Token\"}";
    }
    res.set_content(result, "text/json");
    }); 
    

svr.Get(R"(/chat/activeOff/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
    string token = req.matches[1];
    string result;
    if(tokenMap.count(token)){
        string username= tokenMap.at(token);
    	if(udb.isActive(username)) {
      		udb.changeActive(username, "False");
      		result= "{\"user\":\"" + username + "\" has left}";
    	}
    	else {
      		result= "{\"user\":\"" + username + "\" is already not here}";
   		 }
    }
    else {	
    	result= "{\"Error\":\"Invalid Token\"}";
    }
    res.set_content(result, "text/json");
    }); 
        
//-------------------------------------------------------------------------------    
  cout << "Server listening on port " << port << endl;
  svr.listen("0.0.0.0", port);

}
