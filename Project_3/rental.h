#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
#include "project3.h"
#include <vector>

using namespace std;

class Rental {

protected:
	string customerID;
	string filmCode;
	Date dateRented;
	string timeRented;
	Date dateDue;


public:
	Rental() {

	}

	void setCustomerID(string str) { customerID = str; }
	void setFilmCode(string str) { filmCode = str; }
	void setDateRented(string str) {

		string date;
		size_t position1;
		size_t position2;

		date = str;
		date.shrink_to_fit();
		position1 = date.find("/", 0);
		dateRented.month = date.substr(0, position1);
		position2 = date.find("/", position1 + 1);
		dateRented.day = date.substr(position1 + 1, position2 - position1 - 1);
		dateRented.year = date.substr(position2 + 1, date.length() - position2);

	}

	void setTimeRented(string str) { timeRented = str; }
	void SetDateDue(string str) {

		string date;
		size_t position1;
		size_t position2;

		date = str;
		date.shrink_to_fit();
		position1 = date.find("/", 0);
		dateRented.month = date.substr(0, position1);
		position2 = date.find("/", position1 + 1);
		dateRented.day = date.substr(position1 + 1, position2 - position1 - 1);
		dateRented.year = date.substr(position2 + 1, date.length() - position2);
	}
	
	friend ofstream &operator<<(ofstream & outfile, Rental & r);
	friend ifstream &operator>>(ifstream & infile, Rental & r);
	friend ostream &operator<<(ostream & strm, Rental & r);

	string getCustomerID() { return customerID; }
	string getFileCode() { return filmCode; }
	Date * getDateRented() { return &dateRented; }
	string getTieRented() { return timeRented; }
	Date * getDateDue() { return &dateDue; }

};

	
	ifstream &operator>>(ifstream & infile, Rental & r) {
		string date;
		
		infile >> r.customerID;
		infile >> r.filmCode;
		infile >> date;

		r.setDateRented(date);
		infile >> r.timeRented;
		
		infile >> date;
		r.SetDateDue(date);
		

		return infile;
	}

	
	ofstream & operator<< (ofstream & out, Rental & r) {

		out << r.customerID << SPACE;
		out << r.filmCode << SPACE;
		out << r.dateRented.month << '/';
		out << r.dateRented.day << '/';
		out << r.dateRented.year << SPACE;
		out << r.timeRented << SPACE;
		out << r.dateDue.month << '/';
		out << r.dateDue.day << '/';
		out << r.dateDue.year << endl;
		return out;
	}
	ostream &operator<<(ostream & out, Rental & r) {
		out << r.customerID << SPACE;
		out << r.filmCode << SPACE;
		out << r.dateRented.month << '/';
		out << r.dateRented.day << '/';
		out << r.dateRented.year << SPACE;
		out << r.timeRented << SPACE;
		out << r.dateDue.month << '/';
		out << r.dateDue.day << '/';
		out << r.dateDue.year << endl;
		return out;
	}

#endif