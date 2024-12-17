#ifndef BOOKBST_H
#define BOOKBST_H

#include <QString>
#include <QVector>

struct Book {
    QString title;
    QString author;
    QString isbn;
    QString genre;

    Book(const QString& title, const QString& author, const QString& isbn, const QString& genre)
        : title(title), author(author), isbn(isbn), genre(genre) {}
};

struct BSTNode {
    Book book;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const Book& book)
        : book(book), left(nullptr), right(nullptr) {}
};

class BookBST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, const Book& book);
    void searchByTitle(BSTNode* node, const QString& title, QVector<Book>& results) const;
    void searchByAuthor(BSTNode* node, const QString& author, QVector<Book>& results) const;
    void searchByGenre(BSTNode* node, const QString& genre, QVector<Book>& results) const;
    void clearTree(BSTNode* node);

public:
    BookBST();
    ~BookBST();

    void addBook(const Book& book);
    QVector<Book> searchByTitle(const QString& title) const;
    QVector<Book> searchByAuthor(const QString& author) const;
    QVector<Book> searchByGenre(const QString& genre) const;
};

#endif // BOOKBST_H
