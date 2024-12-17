#include "BookBST.h"

BookBST::BookBST() : root(nullptr) {}

BookBST::~BookBST() {
    clearTree(root);
}

void BookBST::addBook(const Book& book) {
    root = insert(root, book);
}

BSTNode* BookBST::insert(BSTNode* node, const Book& book) {
    if (!node) {
        return new BSTNode(book);
    }
    if (book.title < node->book.title) {
        node->left = insert(node->left, book);
    } else {
        node->right = insert(node->right, book);
    }
    return node;
}

void BookBST::searchByTitle(BSTNode* node, const QString& title, QVector<Book>& results) const {
    if (!node) return;

    if (node->book.title.contains(title, Qt::CaseInsensitive)) {
        results.push_back(node->book);
    }

    searchByTitle(node->left, title, results);
    searchByTitle(node->right, title, results);
}

void BookBST::searchByAuthor(BSTNode* node, const QString& author, QVector<Book>& results) const {
    if (!node) return;

    if (node->book.author.contains(author, Qt::CaseInsensitive)) {
        results.push_back(node->book);
    }

    searchByAuthor(node->left, author, results);
    searchByAuthor(node->right, author, results);
}

void BookBST::searchByGenre(BSTNode* node, const QString& genre, QVector<Book>& results) const {
    if (!node) return;

    if (node->book.genre.contains(genre, Qt::CaseInsensitive)) {
        results.push_back(node->book);
    }

    searchByGenre(node->left, genre, results);
    searchByGenre(node->right, genre, results);
}

QVector<Book> BookBST::searchByTitle(const QString& title) const {
    QVector<Book> results;
    searchByTitle(root, title, results);
    return results;
}

QVector<Book> BookBST::searchByAuthor(const QString& author) const {
    QVector<Book> results;
    searchByAuthor(root, author, results);
    return results;
}

QVector<Book> BookBST::searchByGenre(const QString& genre) const {
    QVector<Book> results;
    searchByGenre(root, genre, results);
    return results;
}

void BookBST::clearTree(BSTNode* node) {
    if (!node) return;

    clearTree(node->left);
    clearTree(node->right);
    delete node;
}
