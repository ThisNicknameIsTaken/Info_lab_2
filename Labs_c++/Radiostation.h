#include "Station.h"

 class Radiostation : public Station
{
public:
	Radiostation();
	Radiostation(double, float, const char*, int ,int ,const char*);
	Radiostation(Radiostation &);
	virtual ~Radiostation();

	void setPrice(double);
	void setFrequency(float);
	void setModulation(const char*);

	inline double const getPrice() { return price; };
	inline float  const getFrequency() { return frequency; };
	inline char*  const getModulation() { return modulation; };

	virtual void view();

	Radiostation operator = (Radiostation &);
	Radiostation operator + (Radiostation &);

	friend ostream & operator << (ostream &str, Radiostation &obj);
	friend istream & operator >> (istream &str, Radiostation &obj);

private:
	double price = NULL;
	float frequency = NULL;
	char *modulation = nullptr;
};

