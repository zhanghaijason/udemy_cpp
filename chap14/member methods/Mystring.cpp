#include"Mystring.h"
#include<iostream>
#include<cstring>

using namespace std;

Mystring::Mystring():str{nullptr}{
	str =new char[1];
	*str = '\0';
}

Mystring::Mystring(const char *s):str{nullptr}{
	if(s == nullptr){
		str = new char[1];
		*str = '\0';
	}
	else{
		str = new char[strlen(s)+1];
		strcpy(str, s);
	}
}

Mystring::Mystring(const Mystring &source){
	str = nullptr;
	str = new char[strlen(source.str)+1];
	strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source){
	str = nullptr;
	str = new char[strlen(source.str)+1];
	strcpy(str, source.str);
	source.str = nullptr;
}

Mystring::~Mystring(){
	delete [] str;
}

Mystring& Mystring::operator=(const Mystring &rhs){
	if(*this == rhs)
		return *this;
	delete [] str;
	str = new char[strlen(rhs.str)+1];
	strcpy(str, rhs.str);
	return *this;
}

Mystring& Mystring::operator=(Mystring &&rhs){
	if(*this == rhs)
		return *this;
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

void Mystring::display() const{
	std::cout<< str << ":" <<get_length() << std::endl;
}

int Mystring::get_length() const{
	return strlen(str);
}

const char* Mystring::get_str() const{
	return str;
}

std::ostream &operator <<(std::ostream &os, const Mystring &rhs){
	os<<rhs.str;
	return os;
}

std::istream &operator >>(std::istream &in, Mystring &rhs){
	char *buff = new char[1000];
	in >> buff;
	rhs = Mystring{buff};
	delete [] buff;
	return in;
}

Mystring Mystring::operator-(){
	if(str == nullptr)
			return Mystring(str);

	char *res = new char[strlen(str)+1];
	for(int i = 0; i < strlen(str); ++i){
		res[i] = str[i]+32;
	}

//	res[strlen(str)+1] = '\0';
	Mystring temp{res};
	delete [] res;
	return temp;
}

bool Mystring::operator==(const Mystring &rhs){

	return strcmp(str, rhs.str) == 0;
}

bool Mystring::operator!=(const Mystring &rhs){
	return strcmp(str, rhs.str)!=0;
}

bool Mystring::operator<(const Mystring &rhs){
	return strcmp(str, rhs.str)<0;
}

bool Mystring::operator>(const Mystring &rhs){
	return strcmp(str, rhs.str)>0;
}

Mystring Mystring::operator+(const Mystring &rhs){
	char *res = new char[strlen(str)+1+strlen(rhs.str)];
	strcpy(res, str);
	strcat(res, rhs.str);
	Mystring temp{res};
	delete [] res;
	return temp;
}

Mystring Mystring::operator*(int n){
	Mystring temp;
//	char *res = new char[strlen(str)+1];
//
//	Mystring res{str};
	while(n--){
		temp = temp+*this;
	}
	return temp;
}

Mystring & Mystring::operator+=(const Mystring &rhs){
	*this = *this+rhs;
	return *this;
}

Mystring & Mystring::operator*=(int n){
	*this = *this*n;
	return *this;
}

Mystring & Mystring::operator++(){
       for(size_t i = 0; i < strlen(str); ++i){
	      if(str[i] >=96)	
       	       	str[i] = str[i]-32;
	}
	return *this;
}

Mystring Mystring::operator++(int){
	Mystring temp(*this);
	operator++();
	return temp;
}
