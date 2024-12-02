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

	void addbooks(string name, string a, int i)
	{
		books.insert(books.end(), Book(name, a, i));
	}

	void deletebooks(int bookId)
	{
		books.remove_if([bookId](const Book &b) { return b.id == bookId; });
	}

	void updatebooks(int bookId, string newName, string newAuthor)
	{
		for (auto &book : books)
		{
			if (book.id == bookId)
			{
				book.name = newName;
				book.author = newAuthor;
				break;
			}
		}
	}

	void searchbooks(int bookId)
	{
		for (const auto &book : books)
		{
			if (book.id == bookId)
			{
				cout << "Book found: " << book.name << " by " << book.author << endl;
				return;
			}
		}
		cout << "Book not found" << endl;
	}
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
