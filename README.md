# VisitorArtEngagement
sudo mkdir /var/www/html/VisitorArtEngagement/  
sudo chown ubuntu /var/www/html/VisitorArtEngagement/ 

# SQL Table
Create table "visitorEngagement" in database "scmp318"

**Columns**
* ID (integer - auto increment, primary key)
* Color (varchar 10)
* Timestamp (datetime - default current\_timestamp())
* Location (varchar 40)

# IP Address
Make sure to change the ip address to match your own in the following files:
* visEngage.js
* outputKenyon.js
* outputVisit.js
* outputVideo.js

# SQL Setup
Ensure that you have MariaDB and the C++ MariaDB connector downloaded

In db.h change the USER and PASS macros to be your own username and password for your MariaDB
