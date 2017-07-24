#ifndef My_string
#define My_string
#pragma once

class MySTLString
{
public:
	MySTLString();
	MySTLString(std::string::size_type count, char ch);
	MySTLString(const MySTLString&&);
	MySTLString(const char* s);
	MySTLString(const MySTLString&);

	MySTLString& operator=(const MySTLString&);
	MySTLString& operator=(const MySTLString&&);

	const char& front() const;
	const char& back() const;

	bool empty() const;

	iterator begin();
	iterator end();

	~MySTLString();
private:
	char* data_;
};

MySTLString :: MySTLString() : data_(new char[1]) {
	*data_ = '\0';
}

MySTLString::MySTLString(std::string::size_type count, char ch) : data_(new char[count + 1]){
	*data_ = ch;
}

MySTLString :: MySTLString(const char* s) : data_(new char[strlen(s) + 1]){
    strcpy(data_, s);
}

MySTLString& MySTLString::operator=(const MySTLString& str) {
	data_ = str.data_;
	return *this;
}

const char& MySTLString::front() const {
	return data_[0];
}

const char & MySTLString::back() const {
	return data_[4];
}

bool MySTLString::empty() const{
	if (this->begin() == this->end())
		return true;
	else
		return false;
}

MySTLString::~MySTLString() {
	delete data_;
}
#endif