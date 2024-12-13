#include "LinkedList.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

LinkedList::LinkedList() : head(nullptr) {}

User* LinkedList::getHead() const {
    return head;
}

LinkedList::~LinkedList() {
    clearList();
}

void LinkedList::addUser(const QString& name, const QString& email, const QString& id) {
    User* newUser = new User(name, email, id);
    newUser->next = head;
    head = newUser;
    qDebug() << "User added:" << name << email << id;
}

bool LinkedList::removeUser(const QString& id) {
    User* current = head;
    User* previous = nullptr;

    while (current) {
        if (current->id == id) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}


void LinkedList::saveToFile(const QString& filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for saving.";
        return;
    }

    QTextStream out(&file);
    User* current = head;
    while (current) {
        out << current->name << "," << current->email << "," << current->id << "\n";
        current = current->next;
    }

    file.close();
    qDebug() << "Linked list saved to file:" << filename;
}

void LinkedList::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for loading.";
        return;
    }

    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3) {
            addUser(parts[0], parts[1], parts[2]);
        }
    }

    file.close();
    qDebug() << "Linked list loaded from file:" << filename;
}

void LinkedList::clearList() {
    User* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    qDebug() << "Linked list cleared.";
}
