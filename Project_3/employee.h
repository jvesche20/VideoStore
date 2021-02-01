#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person
{
protected:

	string employeeNumber;
	float  wage;

public:
	void setEmployeeNumber(const string str)
	{
		employeeNumber = str;
	}
	string getEmployeeName()
	{
		return employeeNumber;
	}

	Employee()
	{
		employeeNumber = "";
		wage = 0.0;
	}


	/* 2nd constructor to initialize class */
	Employee(string id, string lname, string fname, string address, string city, string state, string phone, string zip, float pay) :
		Person(lname, fname, address, city, state, zip, phone)
	{
		Employee * e = this;    /* point to the Customer class*/

		employeeNumber = id;
		wage = pay;
	}

	bool operator < (const Employee & right)
	{
		bool status = false;

		if (employeeNumber < right.employeeNumber)
		{
			status = true;
		}
		return status;
	}

	bool operator == (const Employee & right)
	{
		bool status = false;

		if (employeeNumber == right.employeeNumber)
		{
			status = true;
		}
		return status;
	}

	bool operator != (const Employee & right)
	{
		bool status = false;

		if (employeeNumber != right.employeeNumber)
		{
			status = true;
		}
		return status;
	}

	Employee  operator = (string str)
	{
		Employee employee;
		employee.employeeNumber = str;
		return employee;
	}

	friend ifstream & operator >> (ifstream & infile, Employee & e);
	friend ofstream & operator << (ofstream & outfile, Employee * e);
	friend ostream  & operator << (ostream  & strm, Employee & e);
};


ifstream & operator >> (ifstream & infile, Employee & e)
{
	Person * p = &e;

	string strWage;      // read hourly wage as a string

	infile >> e.employeeNumber;

	infile >> p;

	infile >> strWage;

	//e.wage = stof(strWage);

	return infile;
}

ofstream & operator << (ofstream & outfile, Employee * e)
{
	Person * p = e;

	outfile << e->employeeNumber << SPACE;
	outfile << p;
	outfile << e->wage << endl;

	return outfile;
}

ostream & operator << (ostream & strm, Employee & e)
{
	Person * p = &e;

	strm << e.employeeNumber << SPACE;
	strm << p;
	strm << e.wage << endl;

	return strm;
}

#endif