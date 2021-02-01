#ifndef FILM_CLASS
#define FILM_CLASS

#include <iostream>
#include <string>
#include <fstream>
#include "project3.h"

using namespace std;

class Film
{
protected:
	string filmCode;
	string title;
	string year;
	FilmRating MPAA;
	FilmCategory category;

public:
	Film()
	{
		filmCode = "";
		title = "";
		year = "";
		MPAA = NR;
		category = NoCategory;
	}

	friend ifstream & operator >> (ifstream & in, Film & f);
	friend ostream  & operator << (ostream & strm, Film & f);
	friend ofstream & operator << (ofstream & outfile, Film & f);

	void setFilmCode(const char * str) { filmCode = str; }
	void setFilmTitle(const char * str) { title = str; }
	void setFilmYear(const char * str) { year = str; }
	void setFilmRating(FilmRating r) { MPAA = r; }
	void setFilmCategory(FilmCategory c) { category = c; }

	string getFilmCode() { return filmCode; }
	string getFilmTitle() { return title; }
	string getFilmYear() { return year; }
	string getFilmRating() { return FilmRatingString[MPAA]; }
	string getFilmCategory() { return FilmCategoryString[category]; }
};

ifstream & operator>> (ifstream & in, Film & f)
{

	string temp;

	in >> f.filmCode;
	in >> f.title;
	in >> f.year;
	in >> temp;
	f.setFilmRating(getFilmRatingEnum(temp));
	in >> temp;
	f.setFilmCategory(getFilmCategoryEnum(temp));
	return in;
}

// overloading <<

ostream & operator << (ostream & strm, Film & f)
{
	strm << f.filmCode << SPACE;
	strm << f.title << SPACE;
	strm << f.year << SPACE;
	strm << FilmRatingString[f.MPAA] << SPACE;
	strm << FilmCategoryString[f.category] << endl;
	return strm;
}

ofstream & operator << (ofstream & outfile, Film & f) {
	string temp;



	outfile << f.filmCode << SPACE;
	outfile << f.title << SPACE;
	outfile << f.year << SPACE;
	outfile << FilmRatingString[f.MPAA] << SPACE;
	outfile << FilmCategoryString[f.category] << SPACE;
	outfile << endl;

	return outfile;
}



#endif