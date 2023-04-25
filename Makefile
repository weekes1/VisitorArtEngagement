# VIsitor Art Engagement
# Color Display Box Team, Kenyon College 2022

CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -std=c++14  -Wno-deprecated-declarations

RM= /bin/rm -f

#all: testcontact contactApp PutHTML 
all: PutHTML console

userEntry.o: userEntry.cpp userEntry.h
	$(CC) -c $(CFLAGS) userEntry.cpp

db.o: db.cpp db.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn db.cpp

console.o: console.cpp userEntry.h db.h
	$(CC) -c $(CFLAGS) console.cpp

console: console.o db.o userEntry.o
	$(CC) console.o db.o userEntry.o -L/usr/lib -o console -L/usr/local/lib -lmariadbcpp

#contactApp.o: contactApp.cpp httplib.h
#	$(CC) -c $(CFLAGS) contactApp.cpp

#contactApp: contactApp.o contactDB.o contactEntry.o 
#	$(CC) contactApp.o contactDB.o contactEntry.o -o contactApp -L/usr/local/lib -lmariadbcpp

PutHTML:
	sudo cp userinterface.html /var/www/html/visitorArtEngagement/
#	sudo cp contactApp.js /var/www/html/VisitorArtEngagement/
	sudo cp userinterface.css /var/www/html/visitorArtEngagement/
	sudo cp Color-emotion-wheel.PNG /var/www/html/visitorArtEngagement/


	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/visitorArtEngagement

#clean:
#	rm -f *.o  contactApp testcontact
