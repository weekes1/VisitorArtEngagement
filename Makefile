# VIsitor Art Engagement
# Color Display Box Team, Kenyon College 2022

CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -std=c++14  -Wno-deprecated-declarations

RM= /bin/rm -f

#all: testcontact contactApp PutHTML 
all: PutHTML console visEngage

userEntry.o: userEntry.cpp userEntry.h
	$(CC) -c $(CFLAGS) userEntry.cpp

db.o: db.cpp db.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn db.cpp

console.o: console.cpp userEntry.h db.h
	$(CC) -c $(CFLAGS) console.cpp

console: console.o db.o userEntry.o
	$(CC) console.o db.o userEntry.o -L/usr/lib -o console -L/usr/local/lib -lmariadbcpp

visEngage.o: visEngage.cpp httplib.h
	$(CC) -c $(CFLAGS) visEngage.cpp

visEngage: visEngage.o db.o userEntry.o 
	$(CC) visEngage.o db.o userEntry.o -o visEngage -L/usr/local/lib -lmariadbcpp

PutHTML:
	sudo cp userinterface.html /var/www/html/VisitorArtEngagement/
	sudo cp visEngage.js /var/www/html/VisitorArtEngagement/
	sudo cp colorOutput.js /var/www/html/VisitorArtEngagement/
	sudo cp userinterface.css /var/www/html/VisitorArtEngagement/
	sudo cp Color-emotion-wheel.PNG /var/www/html/VisitorArtEngagement/
	sudo cp Gund_gal_pic.jpg /var/www/html/VisitorArtEngagement/
	sudo cp colorOutputVisEngage.html /var/www/html/VisitorArtEngagement/


	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/VisitorArtEngagement

#clean:
#	rm -f *.o  contactApp testcontact
