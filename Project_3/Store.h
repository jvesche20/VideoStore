#ifndef STORE_H
#define STORE_H

#include <string>
#include <fstream>

#include "template_linked_list.h"
#include "company.h" 
#include "customer.h"

class Store : public Company
{
	protected:

		Customer customer;
		LinkedList <Customer> customerList;

	public:


		Store() : Company()
		{
			ifstream customerInputFile("customers.txt");
	
			while (!customerInputFile.eof())
			{
				customerInputFile >> customer;
				customerList.appendNode(customer);
			}
			customerInputFile.close();
		}


		friend ofstream & operator << (ofstream & out, Store *s);

		Customer & getCustomer (char * customerId) { ; }
		RetCode Add(Customer & c) { ; }
		RetCode RemoveCustomer(const char * id) { ; }
		Customer * LookupId(const char * id) { ; }

};



ofstream & operator << (ofstream & outfile, Store *s)
{
	Company * c = s;


	/* output all the company attributes which includes the employees */
	outfile << c;

	outfile << "STORE: " << endl;
	outfile << "---------" << endl;

	outfile << "Customers:" << endl;
	outfile << "----------" << endl;

	/* output all of the customers */
	s->customerList.printListToFile (outfile);
	s->customerList.displayList();

	return outfile;
}


#endif