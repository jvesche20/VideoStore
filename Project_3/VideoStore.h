#ifndef VIDEOSTORE_H
#define VIDEOSTORE_H

#include "template_linked_list.h"
#include "Store.h"

class VideoStore : public Store
{

private:

	Film film;
	Rental rental;
	LinkedList <Film> filmList;
	LinkedList <Rental> rentalList;

public:

	VideoStore()
		: Store()
	{
		ifstream filmInputFile("films.txt");
		ifstream rentalInputfile("rentals.txt");

		/* open output file*/
		ofstream outputFile("project3.out");

		while (!filmInputFile.eof())
		{
			filmInputFile >> film;
			filmList.appendNode(film);
		}
		filmInputFile.close();


		while (!rentalInputfile.eof())
		{
			rentalInputfile >> rental;
			rentalList.appendNode(rental);
		}

		rentalInputfile.close();
	}


	friend ofstream & operator<< (ofstream & outfile, VideoStore &v)
	{
		Store * s = &v;

		outfile << "The Video Store:" << endl;
		outfile << "----------------" << endl;

		// Print out the store 
		outfile << s;

		//outfile << c; // Prints Comp name/Employees
		//outfile << s; // Prints Customers
		outfile << "The Films:" << endl;
		outfile << "----------" << endl;

		v.filmList.printListToFile(outfile);
		v.filmList.displayList();

		outfile << "The Film Rentals:" << endl;
		outfile << "-----------------" << endl;
		v.rentalList.printListToFile(outfile);
		v.rentalList.displayList();


		return outfile;
	}
};

#endif