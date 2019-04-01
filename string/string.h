#ifndef BASICSTRING_STRING_H_
#define BASICSTRING_STRING_H_

#include<iostream>
#include<iterator>

namespace test {

//Implement of basic_string of C++
class BasicString {
 public:
  typedef char *iterator;
  typedef const char *const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  //Constructs function
  BasicString(); 
  BasicString(const BasicString &s);
  BasicString(const char *s);
  BasicString(BasicString &&s);
  BasicString& operator=(const BasicString &s);
  BasicString& operator=(BasicString &&s);
  BasicString& operator=(const char *s);
  
  ~BasicString() {};  //destructor

  //Element access
  char &operator[](unsigned pos);
  const char &operator[](unsigned pos) const;
  char &front();
  const char &front() const;
  char &back();
  const char &back() const;
  const char *data() const;
  const char *c_str() const;

  //Iterator
  iterator begin();
  const_iterator cbegin() const;
  reverse_iterator rbegin();
  const_reverse_iterator crbegin() const;
  iterator end();
  const_iterator cend() const;
  reverse_iterator rend();
  const_reverse_iterator crend() const;

  //Capacity
  bool empty() const;
  unsigned size() const;
  unsigned length() const;
  unsigned capacity() const;

  BasicString &operator+=(const BasicString &s);

  //Search
  unsigned find(const BasicString &s, unsigned pos) const;
  unsigned find(const char *s, unsigned pos, unsigned cout) const;

  //Non-menber function
  friend BasicString operator+(const BasicString &lhs, const BasicString &rhs);
  friend BasicString operator+(const char *lhs, const BasicString &rhs);
  friend BasicString operator+(const BasicString &lhs, const char *rhs);
  friend bool operator==(const BasicString &lhs, const BasicString &rhs);
  friend bool operator==(const char *lhs, const BasicString &rhs);
  friend bool operator==(const BasicString &lhs, const char *rhs);
  friend bool operator!=(const BasicString &lhs, const BasicString &rhs);
  friend bool operator!=(const char *lhs, const BasicString &rhs);
  friend bool operator!=(const BasicString &lhs, const char *rhs);
  friend bool operator<(const BasicString &lhs, const BasicString &rhs);
  friend bool operator<(const char *lhs, const BasicString &rhs);
  friend bool operator<(const BasicString &lhs, const char *rhs);
  friend bool operator>(const BasicString &lhs, const BasicString &rhs);
  friend bool operator>(const char *lhs, const BasicString &rhs);
  friend bool operator>(const BasicString &lhs, const char *rhs);
  friend bool operator<=(const BasicString &lhs, const BasicString &rhs);
  friend bool operator<=(const char *lhs, const BasicString &rhs);
  friend bool operator<=(const BasicString &lhs, const char *rhs);
  friend bool operator>=(const BasicString &lhs, const BasicString &rhs);
  friend bool operator>=(const char *lhs, const BasicString &rhs);
  friend bool operator>=(const BasicString &lhs, const char *rhs);

  friend std::ostream& operator << (std::ostream &is, const BasicString &s);
  friend std::istream& operator >> (std::istream &os, BasicString &s);

 private:
  char *data_;
  unsigned len_;
};
}  // namespace test

#endif