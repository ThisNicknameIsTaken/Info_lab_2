#include "Station.h"
#include <cmath>

class Railwaystation : public Station
{
public:
	Railwaystation();
	Railwaystation(int, int, float, int, int, const char*);
	Railwaystation(Railwaystation &);
	virtual ~Railwaystation();

	void setRailwaysQuantity(int);
	void setIndex(int);
	void setStopTimeSeconds(float);


	inline int	 const getRailwaysQuantity() { return railwaysQuantity; };
	inline int	 const getIndex() {return index; };
	inline float const getStopTimeSeconds() { return stopTimeSeconds; };

	virtual void view();

	Railwaystation operator = (Railwaystation &);
	friend Railwaystation operator + (Railwaystation &,const Railwaystation &);

	friend ostream & operator << (ostream &str, Railwaystation &obj);
	friend istream & operator >> (istream &str, Railwaystation &obj);

private:
	int railwaysQuantity = 0;
	float stopTimeSeconds = 0;
	int index = 0;

};


