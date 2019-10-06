#include <cstdlib>

//#include "Station.h"
//#include "Radiostation.h"
#include "Railwaystation.h"



int main() {

	//Расскоментить Station.h, всё остальное закоментить
	/////////////////////STATION//////////////////////
	/*Station a(12, 23, "My station");
	a.view();

	Station st = a;
	st.setX(8);
	st.view();

	a.view();
	cin >> a;
	cout << a;*/

	/////////////////////////////////////////////////







	//Расскоментить Radiostation.h, всё остальное закоментить
	///////////////////RADIOSTATION//////////////////////
	/*Radiostation rs(12,23, "AFK",4,6,"My RADIOstation");
	rs.view();

	Radiostation rsb = rs;
	rsb.setPrice(1888);
	rsb.view();

	rs.view();
	cin >> rs;
	cout << rs;*/
	/////////////////////////////////////////////////////






	//Расскоментить Railwaystation.h, всё остальное закоментить
	////////////////////////RAILWAYSTATION///////////////////////////////
	Railwaystation rlw(12,34,5.0f,1,7,"My RAILWAYstation");
	rlw.view();

	Railwaystation rlwb = rlw;
	rlwb.setName("RAILWAYSTAR");
	rlwb.view();

	rlw.view();
	cin >> rlw;
	cout << rlw;

	Railwaystation sumRlw = (rlw + rlwb);
	/////////////////////////////////////////////////////////////////////

	system("pause");
	return 0;
}