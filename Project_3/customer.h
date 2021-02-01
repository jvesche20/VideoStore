#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include "project3.h"

#include "person.h"

using namespace std;

class Customer : public Person
{
protected:
	string customerNumber;
	Date   regDate;

public:

	Customer()
	{
		customerNumber = "";
	}

	Customer(string id, string lname, string fname, string address, string city, string state, string phone, string zip, string registration_date) : Person(lname, fname, address, city, state, zip, phone)
	{

		Person * p = this;


		customerNumber = id;

		string date;

		date = registration_date;

		int position1;
		int position2;
		date.shrink_to_fit();
		position1 = date.find("/", 0);
		regDate.month = date.substr(0, position1);
		position2 = date.find("/", position1 + 1);
		regDate.day = date.substr(position1 + 1, position2 - position1 - 1);
		regDate.year = date.substr(position2 + 1, date.length() - position2);

	}
	~Customer()
	{

	}

	friend ifstream & operator>> (ifstream & infile, Customer & c);
	friend ofstream & operator<< (ofstream & outfile, Customer & c);
	friend ostream  & operator<< (ostream  & strm, Customer & c);


	void setCustomerNumber(const string str)
	{
		customerNumber = str;
	}
	string getCustomerName()
	{
		return customerNumber;
	}
};

ifstream & operator >> (ifstream & infile, Customer & c)
{
	Customer customer;
	Person * p = &customer;

	string date;

	while (!infile.eof())
	{
		infile >> customer.customerNumber;
		infile >> p;
		infile >> date;

		int position1;
		int position2;

		date.shrink_to_fit();
		position1 = date.find("/", 0);
		customer.regDate.month = date.substr(0, position1);
		position2 = date.find("/", position1 + 1);
		customer.regDate.day = date.substr(position1 + 1, position2 - position1 - 1);
		customer.regDate.year = date.substr(position2 + 1, date.length() - position2);

		

	}
	return infile;
}

ofstream & operator<< (ofstream & outfile, Customer & c)
{
	Customer customer;
	Person * p = &customer;

	// Use an iterator to display the vector contents.
	
		//customer = *it;
		outfile << customer.customerNumber << SPACE;
		outfile << p;
		outfile << customer.regDate.month << '/';
		outfile << customer.regDate.day << '/';
		outfile << customer.regDate.year << endl;
	

	return outfile;
}

ostream  & operator<< (ostream  & strm, Customer & c)
{
	Customer customer;
	Person * p = &customer;

	// Use an iterator to display the vector contents.
	//for (auto it = c.begin(); it != c.end(); it++)
	//{
		//customer = *it;

		strm << customer.customerNumber << SPACE;
		strm << p;
		strm << customer.regDate.month << '/';
		strm << customer.regDate.day << '/';
		strm << customer.regDate.year << endl;
	//}
	return strm;
}

#endif
