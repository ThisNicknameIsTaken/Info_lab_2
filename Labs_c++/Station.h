
#include <cstring> 
#include <iostream>

using namespace std;

class Station
{
public:
	Station();
	Station(int x, int y, const char *name);
	Station(Station &obj);
	virtual ~Station();

	void setName(const char*);
	void setX(int x);
	void setY(int y);

	inline char *getName() const { return name; };
	inline int getX() const { return x; };
	inline int getY() const { return y; };

	Station operator = (Station &);

	friend ostream & operator << (ostream &str, Station &obj);
	friend istream & operator >> (istream &str, Station &obj);

	virtual void view();


private:
	int x, y = NULL;
	char *name = nullptr;
};

