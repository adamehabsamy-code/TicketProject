#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
public:
    Customer(string n) { name = n; }
    string getName() { return name; }
};

// Our own queue, built with a linked list
class Node {
public:
    Customer data;
    Node* next;
    Node(Customer c) : data(c), next(nullptr) {}
};

class MyQueue {
private:
    Node* head;   // front of the line
    Node* tail;   // back of the line
    int count;
public:
    MyQueue() { head = nullptr; tail = nullptr; count = 0; }

    ~MyQueue() {
        while (!empty()) pop();
    }

    void push(Customer c) {
        Node* newNode = new Node(c);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void pop() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        count--;
    }

    Customer front() { return head->data; }
    bool empty() { return head == nullptr; }
    int size() { return count; }
    Node* getHead() { return head; }
};

class Waitlist {
private:
    MyQueue line;
public:
    void add(Customer c) {
        line.push(c);
        cout << c.getName() << " added to waitlist" << endl;
    }

    void next() {
        if (line.empty()) {
            cout << "Waitlist is empty" << endl;
            return;
        }
        cout << line.front().getName() << " gets the spot!" << endl;
        line.pop();
    }

    int size() { return line.size(); }

    void show() {
        if (line.empty()) {
            cout << "Waitlist is empty" << endl;
            return;
        }
        cout << "--- Waitlist ---" << endl;
        int spot = 1;
        Node* current = line.getHead();
        while (current != nullptr) {
            cout << spot << ". " << current->data.getName() << endl;
            current = current->next;
            spot++;
        }
    }

    void position(string name) {
        int spot = 1;
        Node* current = line.getHead();
        while (current != nullptr) {
            if (current->data.getName() == name) {
                cout << name << " is #" << spot << " on the waitlist" << endl;
                return;
            }
            current = current->next;
            spot++;
        }
        cout << name << " is not on the waitlist" << endl;
    }
};

int main() {
    Waitlist w;
    w.add(Customer("Adam"));
    w.add(Customer("Sara"));
    w.add(Customer("Mike"));
    w.show();

    w.position("Sara");    // test: someone in line
    w.position("John");    // test: someone NOT in line

    w.next();
    w.position("Sara");    // test: Sara moved up

    w.next();
    w.next();
    w.next();              // test: empty waitlist
    w.show();              // test: show empty waitlist

    w.add(Customer("Lina")); // test: add after it was empty
    w.show();
    return 0;
}
