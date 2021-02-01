#ifndef PERSON_H
#define PERSON_H

#include <fstream>
#include <string>

#include "project3.h"


using namespace std;

class Person
{
protected:
	string lastName;
	string firstName;
	string address;
	string city;
	StateAbbr state;
	string zipCode;
	string telephone;

public:
	Person()
	{
		firstName = "";
		lastName = "";
		address = "";
		city = "";
		state = NOSTATE;
		zipCode = "";
		telephone = "";
	}

	Person(string lname, string fname, string addrs, string citystr, string statestr, string zip, string phone)
	{
		lastName = lname;
		firstName = fname;
		address = addrs;
		city = citystr;
		state = getStateEnum(statestr);
		zipCode = zip;
		telephone = phone;

	}


	friend ifstream & operator >> (ifstream & infile, Person * p);
	friend ofstream & operator << (ofstream & outfile, Person * p);
	friend ostream  & operator << (ostream  & strm, Person * p);

	void setLastName(const string str) { lastName = str; }
	void setFirstName(const string str) { firstName = str; }
	void setAddress(const string str) { address = str; }
	void setCity(const string str) { city = str; }
	void setState(const string str) { state = getStateEnum(str); }
	void setZipCode(const string str) { zipCode = str; }
	void setTelephone(const string str) { telephone = str; }

	string getLastName() { return lastName; }
	string getFirstName() { return firstName; }
	string getAddress() { return address; }
	string getCity() { return city; }
	const string getState() { return getStateString(state); }
	string getZipCode() { return zipCode; }
	string getTelephone() { return telephone; }
};


ifstream & operator >> (ifstream & infile, Person * p)
{
	string stateString;

	infile >> p->lastName;
	infile >> p->firstName;
	infile >> p->address;
	infile >> p->city;
	p->state = getStateEnum(stateString);
	infile >> p->zipCode;
	infile >> p->telephone;
	return infile;
}

ofstream & operator << (ofstream & outfile, Person * p)
{
	outfile << p->lastName << SPACE;
	outfile << p->firstName << SPACE;
	outfile << p->address << SPACE;
	outfile << p->city << SPACE;
	outfile << getStateString(p->state) << SPACE;
	outfile << p->zipCode << SPACE;
	outfile << p->telephone << SPACE;

	return outfile;
}

ostream  & operator << (ostream  & strm, Person * p)
{
	strm << p->lastName << SPACE;
	strm << p->firstName << SPACE;
	strm << p->address << SPACE;
	strm << p->city << SPACE;
	strm << getStateString(p->state) << SPACE;
	strm << p->zipCode << SPACE;
	strm << p->telephone << SPACE;
	return strm;
}

#endif
