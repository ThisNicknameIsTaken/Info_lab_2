#include "Railwaystation.h"


Railwaystation::Railwaystation() {
	cout << "\n Railwaystation constructor \n";
	railwaysQuantity = index = 0;
	stopTimeSeconds = 0;
}

Railwaystation::Railwaystation(int rails, int index, float time, int x, int y, const char* name) : Station(x,y,name) {
	cout << "\n Railwaystation constructor \n";

	setRailwaysQuantity(rails);
	setIndex(index);
	setStopTimeSeconds(time);
}

Railwaystation::Railwaystation(Railwaystation &obj)
{
	setX(obj.getX());
	setY(obj.getY());
	setName(obj.getName());

	setIndex(obj.getIndex());
	setRailwaysQuantity(obj.getRailwaysQuantity());
	setStopTimeSeconds(obj.getStopTimeSeconds);
}

Railwaystation::~Railwaystation() {
	cout << "\n Railwaystation destructor \n";
}

void Railwaystation::setRailwaysQuantity(int quantity) {
	railwaysQuantity = quantity;
}

void Railwaystation::setIndex(int index) {
	this->index = index;
}

void Railwaystation::setStopTimeSeconds(float seconds) {
	stopTimeSeconds = seconds;
}


void Railwaystation::view() {
	if (getName() != nullptr) {
		cout << "\nName " << getName() << "		Coordinates:\n x = " << getX() << ", y = " << getY() << "\n Index: " << getIndex() << ", \tRails Quantity: " << getRailwaysQuantity() << " \t Stop Time: " << getStopTimeSeconds();
	}
	else {
		cout << "\nName: Unnamed" << "		Coordinates:\n x = " << getX() << ", y = " << getY() << "\nIndex: " << getIndex() << ", \tRails Quantity: " << getRailwaysQuantity() << " \t Stop Time: " << getStopTimeSeconds();

	}
}

ostream & operator << (ostream &str, Railwaystation &obj) {
	return (str << "\nName " << obj.getName() << "\nCoordinates:\n x = " << obj.getX() << ", y = " << obj.getY() << "\nIndex = " << obj.getIndex() << "\nRails = " << obj.getRailwaysQuantity() << "\nStop time: " << obj.getStopTimeSeconds() << "\n");
}

istream & operator >> (istream &str, Railwaystation &obj) {
	int x, y;
	cout << "\nInput x and y\n";

	str >> x >> y;
	obj.setX(x);
	obj.setY(y);

	cout << "\nInput idex, rails quantity, stop time\n";
	int index, rails;
	float time;

	str >> index >> rails >> time;
	obj.setIndex(index);
	obj.setRailwaysQuantity(rails);
	obj.setStopTimeSeconds(time);

	return str;
}


Railwaystation Railwaystation::operator=(Railwaystation &st)
{
	Railwaystation station(st.getRailwaysQuantity(), st.getIndex(),st.getStopTimeSeconds(), st.getX(), st.getY(), st.getName());
	return station;
}

 Railwaystation operator + (Railwaystation &lst,  Railwaystation &rst)
{
	float maxTime = fmax(lst.getStopTimeSeconds(), rst.getStopTimeSeconds( ));
	int maxIndex = fmax(lst.getIndex(), rst.getIndex());
	int cols = lst.getRailwaysQuantity() + rst.getRailwaysQuantity();

	Railwaystation station(cols,maxIndex,maxTime, lst.getX(), lst.getY(), lst.getName());
	return station;
}
