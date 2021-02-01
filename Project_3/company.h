#ifndef COMPANY_CLASS
#define COMPANY_CLASS

#include <string>
#include <iostream>

#include "project3.h"
#include "employee.h"
#include "customer.h"
#include"template_linked_list.h"

using namespace std;

class Company : public Employee {

protected:

	string companyName;
	string address;
	string city;
	StateAbbr state;
	string zipCode;
	string telephone;

	Employee e;
	LinkedList<Employee> employeeList;

public:
	Company() {

		ifstream employeeInputFile("Employees.txt");
		string stateString;

		employeeInputFile >> companyName;
		employeeInputFile >> address;
		employeeInputFile >> city;
		employeeInputFile >> stateString;
		state = getStateEnum(stateString);
		employeeInputFile >> zipCode;
		employeeInputFile >> telephone;

		while (!employeeInputFile.eof()) {
			employeeInputFile >> e;
			employeeList.appendNode(e);

		}
		employeeInputFile.close();
	}
		friend ofstream & operator << (ofstream & outfile, Company * c);

		void setCompanyName(string str) { companyName = str; }
		void setCompanyAddress(string str) { address = str; }
		void setCompanyCity(string str) { city = str; }
		void setCompanyState(StateAbbr s) { state = s; }
		void setCompanyZipcode(string str) { zipCode = str; }
		void setCompanytelephone(string str) { telephone = str; }


		string getCompanyName() { return companyName; }
		string getCompanyAddress() { return address; }
		string getCompanyCity() { return city; }
		StateAbbr getCompanyState() { return state; }
		string getCompanyZipcode() { return zipCode; }
		string getCompanytelephone() { return telephone; }

		Employee & getEmployee(string employeeId) { ; }


		RetCode Add(Employee & e) { ; }
		RetCode RemoveEmployee(string id) { ; }
		Employee * LookupId(string id) { ; }
		virtual void RemoveDate() { ; }


	
};
ofstream & operator << (ofstream & outfile, Company * c) {
	Employee *e = c;

	outfile << "Company: " << endl;
	outfile << "---------" << endl;
	outfile << c->companyName << SPACE;
	outfile << c->address << SPACE;
	outfile << c->city << SPACE;
	outfile << getStateString(c->state) << SPACE;
	outfile << c->zipCode << SPACE;
	outfile << c->telephone << SPACE;

	outfile << "Employees:" << endl;
	outfile << "----------" << endl;

	c->employeeList.printListToFile(outfile);
	c->employeeList.displayList();

	return outfile;
}
#endif