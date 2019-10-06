#include "Radiostation.h"




Radiostation::Radiostation(){
	cout << "\nRadiostation counstructor\n";
}

Radiostation::Radiostation(double value, float frequency, const char* modulation, int x, int y, const char* name) : Station(x, y, name){
	cout << "\nRadiostation counstructor\n";

	setModulation(modulation);
	setPrice(value);
	setFrequency(frequency);
}

Radiostation::Radiostation(Radiostation &obj)
{
	setX(obj.getX());
	setY(obj.getY());
	setName(obj.getName());

	setModulation(obj.getModulation());
	setFrequency(obj.getFrequency());
	setPrice(obj.getPrice());

}

Radiostation::~Radiostation() {
	cout << "\nRadiostation destructor\n";
}

void Radiostation::setPrice(double value) {
	this->price = value;
}

void Radiostation::setFrequency(float frequency) {
	this->frequency = frequency;
}

void Radiostation::setModulation(const char * modulation)
{
	if (this->modulation != nullptr) delete[] this->modulation;

	this->modulation = new char[strlen(modulation) + 1];
	strcpy_s(this->modulation, strlen(modulation) + 1, modulation);
}

void Radiostation::view() {
	if (getName() != nullptr) {
		cout << "\nName " << getName() << "\nCoordinates:\n x = " <<getX() << ", y = " << getY() << "\n Frequency: " << getFrequency() << "\t Price: " << getPrice() << "\t Modulation " << getModulation() << "\n";
	}
	else {
		cout << "\nName: Unnamed" << "\nCoordinates:\n x = " << getX() << ", y = " << getY();

	}
}

ostream & operator << (ostream &str, Radiostation &obj) {
	return (str << "\nName " << obj.getName() << "\nCoordinates:\n x = " << obj.getX() << ", y = " << obj.getY() << "\nPrice = " << obj.getPrice() << "\nFrequency " << obj.getFrequency() << "\t Modulation " << obj.getModulation() << "\n");
}

istream & operator >> (istream &str, Radiostation &obj) {
	int x, y;
	cout << "\nInput x and y\n";

	str >> x >> y;
	obj.setX(x);
	obj.setY(y);

	cout << "\nInput frequency and price\n";
	double price;
	float frequency;

	str >> frequency >> price;
	obj.setPrice(price);
	obj.setFrequency(frequency);

	return str;
}


Radiostation Radiostation::operator=(Radiostation &st)
{
	Radiostation station(st.getPrice(), st.getFrequency(), st.getModulation(), st.getX(), st.getY(), st.getName());
	return station;
}

Radiostation Radiostation::operator + (Radiostation &st) {
	double minPrice;
	if (st.getPrice() > getPrice()) {
		minPrice = getPrice();
	}
	else {
		minPrice = st.getPrice();
	}

	Radiostation station(minPrice, getFrequency() + st.getFrequency(), getModulation(), getX(), getY(), getName());
	return station;
}
