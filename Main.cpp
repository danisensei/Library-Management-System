#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;
class Book
{
public:
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

class User {
public:
	string name;
	int id;
	User* next;
	string username;
	string password;

public:
	User(string n, int i, string u, string p) : name(n), id(i), username(u), password(p), next(nullptr) {} // Constructor

	bool signIn(string u, string p) {
		return (username == u && password == p);
	}

	static User* signUp(User*& head, string name, int id, string username, string password) {
		User* newUser = new User(name, id, username, password);
		newUser->next = head;
		head = newUser;
		return newUser;
	}

public:
	User(string n, int i) : name(n), id(i), next(nullptr) {} // Constructor
	~User() {} // Destructor

	void addUser(User*& head, string name, int id) {
		User* newUser = new User(name, id);
		newUser->next = head;
		head = newUser;
	}

	void removeUser(User*& head, int id) {
		User* temp = head;
		User* prev = nullptr;

		if (temp != nullptr && temp->id == id) {
			head = temp->next;
			delete temp;
			return;
		}

		while (temp != nullptr && temp->id != id) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == nullptr) return;

		prev->next = temp->next;
		delete temp;
	}

	void printUsers(User* head) {
		User* temp = head;
		while (temp != nullptr) {
			cout << "User: " << temp->name << ", ID: " << temp->id << endl;
			temp = temp->next;
		}
	}
};

class BorrowandReturn {
private:
	unordered_map<int, list<int>> userBorrowedBooks; // user id -> list of borrowed book ids

public:
	void borrowbook(User& user, Book& book) {
		userBorrowedBooks[user.id].push_back(book.id);
		cout << "User " << user.name << " borrowed book: " << book.name << endl;
	}

	void returnbook(User& user, Book& book) {
		auto& borrowedBooks = userBorrowedBooks[user.id];
		borrowedBooks.remove(book.id);
		cout << "User " << user.name << " returned book: " << book.name << endl;
	}

	void overdue(User& user) {
		cout << "User " << user.name << " has overdue books: ";
		for (int bookId : userBorrowedBooks[user.id]) {
			cout << bookId << " ";
		}
		cout << endl;
	}
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
