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

string getUserJSON(vector<userEntry> userVec) {
  string resJSON = "{\"users\": [";
  for (int i = 0; i < userVec.size(); i++) {
    resJSON += "[\""+userVec[i].ID+"\",";
    resJSON += "\""+userVec[i].color+"\",";
    resJSON += "\""+userVec[i].timestamp+"\",";
    if (i < userVec.size()-1){
      resJSON += "\""+userVec[i].location+"\"],";
    }
    else {
      resJSON += "\""+userVec[i].location+"\"]";
    }
  }
  resJSON += "]}";

  return resJSON;
}

int main(void) {
  Server svr;
  
  visDB vdb;
	
  /* "/" just returnsAPI name */
  svr.Get("/", [](const Request & /*req*/, Response &res) {
    res.set_header("Access-Control-Allow-Origin","*");
    res.set_content("Visitor Art Engagement", "text/plain");
  });

   svr.Get(R"(/engage/add/(.*)/(.*))", [&](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin","*");
    string color = req.matches[1];
    string location = req.matches[2];
    string result; 
    
    vdb.addEntry(color, location);
    
    result = "{\"status\":\"success\"}";
    res.set_content(result, "text/json");
  });
  
   svr.Get(R"(/engage/findLoc/(.*))", [&](const Request& req, Response& res) {
    string location = req.matches[1];
    res.set_header("Access-Control-Allow-Origin","*");
    string result;
    vector<userEntry> locCols = vdb.findByLocation(location);
    result = getUserJSON(locCols);
    res.set_content(result, "text/json");
  });

  svr.Get(R"(/engage/findCol/(.*))", [&](const Request& req, Response& res) {
    string color = req.matches[1];
    res.set_header("Access-Control-Allow-Origin","*");
    string result;
    vector<userEntry> cols = vdb.findByLocation(color);
    result = getUserJSON(cols);
    res.set_content(result, "text/json");
  });

  svr.Get(R"(/engage/clearLoc/(.*))", [&](const Request& req, Response& res) {
    string loc = req.matches[1];
    res.set_header("Access-Control-Allow-Origin","*");
    string result;
    vdb.rmLoc(loc);

    result = "{\"status\":\"success\"}";
    res.set_content(result, "text/json");
  });
    
  cout << "Server listening on port " << port << endl;
  svr.listen("0.0.0.0", port);

}
