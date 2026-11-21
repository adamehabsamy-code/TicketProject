#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Customer {
private:
    string name;
public:
    Customer(string n) { name = n; }
    string getName() { return name; }
};

class Waitlist {
private:
    queue<Customer> line;
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
        queue<Customer> copy = line;
        int spot = 1;
        cout << "--- Waitlist ---" << endl;
        while (!copy.empty()) {
            cout << spot << ". " << copy.front().getName() << endl;
            copy.pop();
            spot++;
        }
    }

    void position(string name) {
        queue<Customer> copy = line;
        int spot = 1;
        while (!copy.empty()) {
            if (copy.front().getName() == name) {
                cout << name << " is #" << spot << " on the waitlist" << endl;
                return;
            }
            copy.pop();
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
    return 0;
}