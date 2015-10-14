
#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <climits>


sfw::string::string(void)
{
		
	m_data = new char[m_size = 1]{ '\0' };	

}

sfw::string::~string()
{
	
	delete[]m_data;
	
}

size_t sfw::string::length() const
{
	
	return strlen(m_data);

}





sfw::string::string(size_t size)
{
	m_size = size;
	m_data = new char[m_size];
	m_data[0] = '\0';
}


sfw::string::string(const char *a, size_t size)
{
	m_size = size;
	m_data = new char[size];
	
	strncpy_s(m_data, m_size, a, _TRUNCATE);

	m_data[size - 1] = '\0';
}

sfw::string::string(const char *a)
{
	if (a != nullptr)
	{
		m_data = new char[m_size = strlen(a) + 1];
		strcpy_s(m_data, m_size, a);
	}

	else
	{
		m_data = new char[m_size = 1]{ '\0' };
	}
}

sfw::string::string(const string &a)
{
	if (this != &a)
	{
		m_size = a.m_size;
		m_data = new char[m_size];
		strcpy_s(m_data, m_size, a.m_data);
	}
	else
	{
		m_data = new char[m_size = 1]{ '\0' };
	}
}

sfw::string::string(string &&a)
{
	m_size = a.m_size;
	m_data = a.m_data;
	a.m_size = 1;
	a.m_data = new char[a.m_size];
	a.m_data[0] = '\0';
}

sfw::string & sfw::string::operator=(const string &a)
{
	if (this == &a) return *this;
	*this = a.m_data;
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	if (m_data != nullptr)
	{
		delete[] m_data;
	}
	
	m_data = a.m_data;
	m_size = a.m_size;

	a.m_size = 1;
	a.m_data = new char[a.m_size];
	a.m_data[0] = '\0';

	return *this;
}

sfw::string & sfw::string::operator=(const char *a)
{	
	resize(strlen(a) + 1);
	strcpy_s(m_data, m_size, a);
	return *this;
}

sfw::string & sfw::string::operator+=(const string &a)
{
	return *this = *this + a;
}

sfw::string & sfw::string::operator+=(const char *a)
{
	
	return *this = *this + a;

}

sfw::string & sfw::string::operator+=(char a)
{
	resize(a);
	return *this;
}

char & sfw::string::operator[](size_t index)
{
	return this->m_data[index];
}

const char & sfw::string::operator[](size_t index) const
{
	return this->m_data[index];
}




size_t sfw::string::size() const
{
	
	return size_t (m_size);
}

void sfw::string::resize(size_t size)
{
	if (size < 1) size = 1;
	if (size > UINT16_MAX) size = UINT16_MAX;
	char *t = new char[size];
	strncpy_s(t, size, m_data, _TRUNCATE);
	
	m_size = size;
	delete[] m_data;
	m_data = t;

	m_data[size - 1] = '\0';
	
}

void sfw::string::clear()
{
	m_data[0] = '\0';
}

bool sfw::string::empty() const
{
	if (m_data[0] == '\0')
	{
		return true;
	}

	else 
	{
		return false;
	}
}

const char * sfw::string::cstring() const
{
	
	return m_data;
}

bool sfw::operator<(const string &a, const string &b)
{
	
	if (strcmp(a.cstring(), b.cstring()) <0) { return true; }
	else { return false; }
}

bool sfw::operator<(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) <0) { return true; }
	else { return false; }
}

bool sfw::operator<(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) <0) { return true; }
	else { return false; }
}

bool sfw::operator<=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) <=0) { return true; }
	else { return false; }
}

bool sfw::operator<=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) <=0) { return true; }
	else { return false; }
}

bool sfw::operator<=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) <= 0) { return true; }
	else { return false; }
}

bool sfw::operator>(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) >0) { return true; }
	else { return false; }
}

bool sfw::operator>(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) >0) { return true; }
	else { return false; }
}

bool sfw::operator>(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) >0) { return true; }
	else { return false; }
}

bool sfw::operator>=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) >=0) { return true; }
	else { return false; }
}

bool sfw::operator>=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) >= 0) { return true; }
	else { return false; }
}

bool sfw::operator>=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) >= 0) { return true; }
	else { return false; }
}

bool sfw::operator!=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) != 0) { return true; }
	else { return false; }
}

bool sfw::operator!=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) != 0) { return true; }
	else { return false; }
}

bool sfw::operator!=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) != 0) { return true; }
	else { return false; }
}

bool sfw::operator==(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) == 0) { return true; }
	else { return false; }
}

bool sfw::operator==(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == 0) { return true; }
	else { return false; }
}

bool sfw::operator==(const char *a, const string &b)
{
	if (strcmp(a, b.cstring()) == 0) { return true; }
	else { return false; }
}

sfw::string sfw::operator+(const string &a, const string &b)
{
	int tempSize = a.length() + b.length() + 1;
	char * temp = new char[tempSize];
	
	strcpy_s(temp, tempSize, a.cstring());
	strcat_s(temp, tempSize, b.cstring());
	
	string retVal(temp);
	delete temp;
	return retVal;
}

sfw::string sfw::operator+(const string &a, const char *b)
{
	int tempSize = a.length() + strlen(b) + 1;
	char * temp = new char[tempSize];

	strcpy_s(temp, tempSize, a.cstring());
	strcat_s(temp, tempSize, b);

	string retVal(temp);
	delete temp;
	return retVal;
}

sfw::string sfw::operator+(const char *a, const string &b)
{
	int tempSize = strlen(a) + b.length() + 1;
	char * temp = new char[tempSize];

	strcpy_s(temp, tempSize, a);
	strcat_s(temp, tempSize, b.cstring());

	string retVal(temp);
	delete temp;
	return retVal;
}

sfw::string sfw::operator+(const string & a, char b)
{
	int tempSize = a.length() + sizeof(b) + 1;
	char *pB = &b;
	char * temp = new char[tempSize];

	strcpy_s(temp, tempSize, a.cstring());
	strcat_s(temp, tempSize, pB);

	string retVal(temp);
	delete temp;
	return retVal;
	
}

sfw::string sfw::operator+(char a, const string & b)
{
	int tempSize = sizeof(a) + b.length() + 1;
	char *pA = &a;
	char * temp = new char[tempSize];

	strcpy_s(temp, tempSize, pA);
	strcat_s(temp, tempSize, b.cstring());

	string retVal(temp);
	delete temp;
	return retVal;
}

std::ostream & sfw::operator<<(std::ostream &os, const string &p)
{
	os << p.cstring();
	return os;
}

std::istream & sfw::operator>>(std::istream &is, string &p)
{
	char temp[UINT16_MAX];
	is >> temp;
	p = temp;
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char *a, size_t len)
{
	 
	return string(a , len + 1);
}
