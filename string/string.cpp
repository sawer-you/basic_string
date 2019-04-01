#include<iostream>
#include<iterator>
//#include<utility> std::move();
#include"string.h"

namespace test {
	BasicString::BasicString() : len_(0), data_(new char[len_ + 1]) { data_ = '\0'; }
	BasicString::BasicString(const BasicString &s) : len_(s.len_), data_(new char[s.len_ + 1]) { memcpy(data_, s.data_, len_ + 1 ); }
	BasicString::BasicString(const char *s) : len_(strlen(s)), data_(new char[len_ + 1]) { memcpy(data_, s, len_ + 1); } //if s == NULL
	BasicString::BasicString(BasicString &&s) : data_(std::move(s.data_)) {  } //fix
	
	BasicString &BasicString::operator=(const BasicString &s) {
	  if (*this == s)
	    return;
	  len_ = s.len_;
	  data_ = new char[len_ + 1]; // len_ + 1 or len_
	  memcpy(data_, s.data_, len_ + 1);
	}

	BasicString &BasicString::operator=(BasicString &&s) {
		if (*this == s)
			return;
		len_ = s.len_;
		data_ = std::move(s.data_);
		memcpy(data_, s.data_, len_);
	}

	BasicString &BasicString::operator=(const char *s) {
		len_ = strlen(s);
		data_ = new char[len_ + 1];
		memcpy(data_, s, len_ + 1);
	}

	BasicString::~BasicString() {
		delete[] data_;
	}

	char &BasicString::operator[](unsigned pos) { // definition of operator
		if (pos == len_) return; //the behavior is undefined
		return data_[pos];
	}

	const char &BasicString::operator[](unsigned pos) const {
		if (pos == len_) return data_[len_ + 1];
		return data_[pos];
	}

	char &BasicString::front() {
		if (empty() == true) return; //The behavior is undefined
		return data_[0];
	}

	const char &BasicString::front() const {
		if (empty() == true) return; //The behavior is undefined
		return data_[0];
	}

	char &BasicString::back() {
		if (empty() == true) return; //The behavior is undefined
		return data_[size() - 1];
	}

	const char &BasicString::back() const {
		if (empty() == true) return; //The behavior is undefined
		return data_[size() - 1];
	}

	const char *BasicString::data() const {
		if (empty() == true) return '\0';
		return data_;
	}

	const char *BasicString::c_str() const {
		return data_;
	}

	BasicString::iterator BasicString::begin() { //iterator to the first character
		return data_;
	}

	BasicString::const_iterator BasicString::cbegin() const {
		return data_;
	}

	BasicString::reverse_iterator BasicString::rbegin() {
		return BasicString::reverse_iterator(data_ + len_);
	}

	BasicString::const_reverse_iterator BasicString::crbegin() const {
		return BasicString::const_reverse_iterator(data_ + len_);
	}

	BasicString::iterator BasicString::end() {
		return (data_ + len_);
	}

	BasicString::const_iterator BasicString::cend() const {
		return (data_ + len_);
	}

	BasicString::reverse_iterator BasicString::rend() {
		return BasicString::reverse_iterator(data_);
	}

	BasicString::const_reverse_iterator BasicString::crend() const {
		return BasicString::const_reverse_iterator(data_);
	}

	bool BasicString::empty() const {
		if (cbegin() == cend()) return true; //begin() == end() have a mistake
		return false;
	}
  
  unsigned BasicString::size() const {
    return len_ ;
  }

  unsigned BasicString::length() const {
    return len_;
  }

  unsigned BasicString::capacity() const {
    return len_;
  }

  BasicString &BasicString::operator+=(const BasicString &s) {
    /*auto i = len_;
    len_ += s.len_;
    data_ = new char[len_ + 1];
    memcpy(data_ + i,s.data_,s.len_ );*/
    //should append BasicString s
    return *this = *this + s;
  }

  unsigned BasicString::find(const BasicString &s, unsigned pos) const {
    unsigned xpos;
    if (xpos >= pos)
      if (xpos + s.size() <= size())
        ;
  }

  unsigned BasicString::find(const char *s, unsigned pos, unsigned count) const {

  }

  BasicString operator+(const BasicString &lhs, const BasicString &rhs) {

  }
}
