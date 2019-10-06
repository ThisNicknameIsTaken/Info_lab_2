
#include "Station.h"


Station::Station() {
	cout << "Station counstructor";

	x = y = 0;
}

Station::Station(int x, int y, const char *name) {
	cout << "Station counstructor";

	setX(x);
	setY(y);
	setName(name);
}


Station::Station(Station &obj) {
	cout << "\nStation counstructor \n";

	setName(obj.getName());
	setX(obj.getX());
	setY(obj.getY());
}


Station::~Station() {
	cout << "\nStation destructor \n";

	delete [] name;
}

void Station::setName(const char* name) {
	if (this->name != nullptr) delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1 ,name);
}

void Station::setX(int x) {
	this->x = x;
}

void Station::setY(int y) {
	this->y = y;
}



void Station::view() {
	 if (name != nullptr) {
		 cout << "\nName: " << name << "\nCoordinates:\n x = " << x << ", y = " << y;
	 }
	 else {
		 cout << "\nName: Unnamed"  << "\nCoordinates:\n x = " << x << ", y = " << y;

	 }
}

ostream & operator << (ostream &str, Station &obj) {
	return (str << "\nName " << obj.getName() << "\nCoordinates:\n x = " << obj.getX() << ", y = " << obj.getY());
}

istream & operator >> (istream &str, Station &obj) {
	int x, y;
	cout << "\nInput x and y\n";

	str >> x >> y;
	obj.setX(x);
	obj.setY(y);

	return str;
}


Station Station::operator=(Station &st)
{
	Station station(st.getX(),st.getY(), st.getName());
	return station;
}