#include<iostream>
#include<list>
using namespace std;

class Book
{
private:
	string name;
	string author;
	int id;
	list<Book> books;
public:
	Book(string n, string a, int i) : name(n), author(a), id(i) {} // Constructor
	~Book() {} // Destructor
	void addbooks(string name,string a,int i)
	{
		books.insert(books.end(), Book(name, a, i));
	}
	void deletebooks() {}
	void updatebooks() {}
	void searchbooks() {}
};

class User
{
private:
	string name;
	int id;
public:
	User(string n, int i) : name(n), id(i) {}// Constructor
	~User() {}// Destructor
	void adduser() {}
	void deleteuser() {}
	void updateuser() {}
};
class BorrowandReturn
{
	void borrowbook();
	void  returnbook();
	void overdue();
};
class Transcationhistory
{
	void recenttransactions();
};
class Reports
{
	void booklist();
	void userlist();
};
