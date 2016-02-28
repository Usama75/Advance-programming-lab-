#include"Tests.h"

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	if (test_create())
		cout << "Create Test Passed!" <<endl ;
	else
		cout << "Create Test Failed!" << endl ;

	if (test_crt())
		cout << "crt Test Passed!" <<endl;
	else
		cout << "crt Test Failed!" << endl;

	time_t ini = time(NULL);
	cout<<"Start "<<ini<<endl;
	ini *= 1000;
	
	if (test_Iterative_algo())
		cout << "Iterative Multiplication Test Passed!" << endl ;
	else
		cout << "Iterative Multiplication Test Failed!" << endl;

	time_t finalT = time(NULL);
	cout<<"Final "<<finalT<<endl;
	 finalT *= 1000;
	
	cout<<"Time Taken "<<finalT-ini<<" sec"<<endl;
	
	
	ini = time(NULL);
	if(test_StrassenAlgo())
		cout << "StrassenAlgo Multiplication Test Passed!" << endl ;
	else
		cout << " StrassenAlgo Multiplication Test Failed!" << endl ;
		
	finalT = time(NULL);
	cout<<"Final "<<finalT<<endl;
	
	cout<<"Time Taken "<<finalT-ini<<" sec"<<endl;
}



