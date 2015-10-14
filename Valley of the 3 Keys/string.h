#pragma once
/*************************************************
string.h

This file is a string class that helps make working with and 
editing strings easier. It has functions for resizing strings, 
coping strings, adding multiple strings together. It also includes
overload operators such as >, <, =, +, +=, ==, !=, <=, >=, [], <<, and >>.

Esmeralda Salamone, esmes@aie.edu.au, 9/23/2015
Modified: Kevin Moore, kevin.moore@students.aie.edu.au, 10/12/2015

All rights reserved.
***************************************************/


// This header forward declares ostream and istream
// iostream should still be included in the source file
#include <iosfwd>

namespace sfw
{
	class string
	{
	private:
		char *m_data;	// Pointer to a dynamically allocated char array.
		size_t m_size;	// How much data can our array currently store?

	public:	
		string(void); // Sets m_data and m_size to their defaults.

		string(size_t size); // Creates an empty string with a size of your choosing.
		string(const char *a, size_t size);
						// Duplicates data in character array with a size of your choosing.
		
		~string(); // Deletes the current string data.

		
		string(const char *a);		// Duplicates the data of the current character array.
		string(const string &a);	// Duplicate the data of the copied string.
		string(string &&a);			// Takes the memory address of the current string.

		// Overloads the = operator for the above functions.
		string &operator=(const string &a); 
		string &operator=(string &&a);		
		string &operator=(const char *a);	

		// Overloads the += operator for the above functions.
		//For adding multiple strings together.
		string &operator+=(const string &a);
		string &operator+=(const char *a);
		string &operator+=(char a);

		// Overloads the [] operator
		char &operator[](size_t index);				
		const char &operator[](size_t index) const; 

		size_t length() const;	// Current length of the current string.
		size_t size() const;	// Current size of the current string.

		void resize(size_t size);	// Resizes the current string.
		void clear();				// clears the current string except for '\0'
		bool empty() const;			// Tells you if the current string is empty

		const char *cstring() const;	// Gives you the current string.
	};

	// Overloads the < operators.
	bool operator<(const string &a, const string &b);
	bool operator<(const string &a, const char *b); 
	bool operator<(const char *a, const string &b);
	// Overloads the <= operator.
	bool operator<=(const string &a, const string &b);
	bool operator<=(const string &a, const char *b);
	bool operator<=(const char *a, const string &b);
	// Overloads the > operator.
	bool operator>(const string &a, const string &b);
	bool operator>(const string &a, const char *b);
	bool operator>(const char *a, const string &b);
	// Overloads the >= operator.
	bool operator>=(const string &a, const string &b);
	bool operator>=(const string &a, const char *b);
	bool operator>=(const char *a, const string &b);
	// Overloads the != operator.
	bool operator!=(const string &a, const string &b);
	bool operator!=(const string &a, const char *b);
	bool operator!=(const char *a, const string &b);
	// Overloads the == operator.
	bool operator==(const string &a, const string &b);
	bool operator==(const string &a, const char *b);
	bool operator==(const char *a, const string &b);

	
	// Overloads the + operator.
	//For adding multiple strings together.
	string operator+(const string &a, const string &b);
	string operator+(const string &a, const char *b);
	string operator+(const char *a, const string &b);

	string operator+(const string &a, char b);
	string operator+(char a, const string &b);

	//Overloads the "" operator to create a literal.
	inline namespace literals {
		const string operator""_sfw(const char *a, size_t len); }

	// Allows us to work with stream processors (cin/cout)
	//Overloads the >> & << operators to work with the stream processors cin & cout
	std::ostream &operator<<(std::ostream &os, const string& p); 
	std::istream &operator>>(std::istream &is, string& p); 

}

