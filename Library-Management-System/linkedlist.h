#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QString>
struct User {
    QString name;
    QString email;
    QString id;
    User* next;

    User(const QString& name, const QString& email, const QString& id)
        : name(name), email(email), id(id), next(nullptr) {}
};


class LinkedList {
private:
    User* head;

public:
    User* getHead() const;

public:
    LinkedList();
    ~LinkedList();

    void addUser(const QString& name, const QString& email, const QString& id);
    bool removeUser(const QString& id);
    void saveToFile(const QString& filename) const;
    void loadFromFile(const QString& filename);
    void clearList();
};

#endif
