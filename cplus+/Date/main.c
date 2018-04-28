
#include"Date.h"

int main(void)
{
	Date d(2018,3,25);
	d.Show();
	Date d1(2018,5,12);
	Date d2(2019,12,12);
//	d1=d+150;
    (d+150).Show();
    (d-150).Show();
    //d1=d2;
    Date d3(d1);
    d3.Show();
	return 0;
} 

