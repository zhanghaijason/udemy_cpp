#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;
 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

Mystring operator-(const Mystring &obj){
	char *buff = new char[strlen(obj.str)+1];
	for(size_t i = 0; i < strlen(obj.str); ++i){
		buff[i] = tolower(obj.str[i]);
	}
    Mystring temp{buff};
	delete [] buff;
	return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
	char *buff = new char[strlen(lhs.str)+strlen(rhs.str)+1];
	strcpy(buff, lhs.str);
	strcat(buff, rhs.str);
	Mystring temp{buff};
	delete [] buff;
	return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs){
	return strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const Mystring &lhs, const Mystring &rhs){
	return strcmp(lhs.str, rhs.str) != 0;
}

bool operator>(const Mystring &lhs, const Mystring &rhs){
	return strcmp(lhs.str, rhs.str) > 0;
}

bool operator<(const Mystring &lhs, const Mystring &rhs){
	return strcmp(lhs.str, rhs.str) < 0;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs){
	lhs = lhs+rhs;
	return lhs;
}

Mystring operator*(const Mystring &lhs, int n){
	Mystring temp = lhs;
	while(--n)
		temp = temp+lhs;
	return temp;
}

Mystring &operator*=(Mystring &lhs, int n){
	Mystring temp = lhs;
	while(--n)
		lhs = lhs+temp;
	return lhs;
}

Mystring &operator++(Mystring &obj){
	for(int i = 0; i < strlen(obj.str); ++i){
		obj.str[i] = toupper(obj.str[i]);
	}

	return obj;
}

Mystring operator++(Mystring &obj, int){
	Mystring temp = obj;
	for(int i = 0; i < strlen(obj.str); ++i){
		obj.str[i] = toupper(obj.str[i]);
	}

	return temp;
}
