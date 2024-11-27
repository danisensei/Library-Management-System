#include<iostream>
#include<list>
using namespace std;

class Book
{ public:
	string name;
	string author;
	int id;
	list<string> books;
	void addbooks()
	{

	}
	void deletebooks();
	void updatebooks();
	void searchbooks();
};
class User
{
public:
	string name;
	int id;


	void adduser();
	void deleteuser();
	void updateuser();
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
