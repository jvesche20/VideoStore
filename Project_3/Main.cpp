// Jacob Vesche
// "I have neither given nor received unauthorized aid in completing this work, 
// nor have I presented someone else's work as my own."



#include <fstream>
#include <iomanip>

#include "person.h"
#include "film.h"
#include "rental.h"
#include "company.h"
#include "VideoStore.h"


using namespace std;

int main()
{

	ofstream outputFile("project3.out", ios::out);
	
	VideoStore videostore;
	

	outputFile << videostore;

	cout << "\n The output has been written to project3.out" << endl;

	outputFile.close();

	system("pause");

	return 0;
}