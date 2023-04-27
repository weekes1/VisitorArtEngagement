# VisitorArtEngagement
sudo mkdir /var/www/html/VisitorArtEngagement/  
sudo chown ubuntu /var/www/html/VisitorArtEngagement/ 

# VisitorArtEngagementOutput
sudo mkdir /var/www/html/colorOutputVisEngage/  
sudo chown ubuntu /var/www/html/colorOutputVisEngage/ 

# SQL Table
Create table "visitorEngagement" in database "scmp318"

**Columns**
* ID (integer - auto increment, primary key)
* Color (varchar 10)
* Timestamp (datetime - default current\_timestamp())
* Location (varchar 40)
