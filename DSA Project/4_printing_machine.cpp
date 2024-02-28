#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int timeNeeded;
    Node* next;

    Node(int id, int timeNeeded) : id(id), timeNeeded(timeNeeded), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* printer;
    int printerTime;
    int currentTime;
    int roundCount;

public:
    CircularLinkedList(int printerTime) : printer(nullptr), printerTime(printerTime), currentTime(0), roundCount(0) {}

    void addUser(int id, int timeNeeded) {
        Node* newUser = new Node(id, timeNeeded);

        if (!printer) {
            printer = newUser;
            newUser->next = printer;
        } else {
            newUser->next = printer->next;
            printer->next = newUser;
        }
    }

    void printStatus() {
        Node* current = printer;

        do {
            cout << "User " << current->id << ": " << current->timeNeeded << " mins remaining\n";
            current = current->next;
        } while (current != printer);

        cout << "--------------------------\n";
    }

    void rotatePrinter() {
        if (printer) {
            currentTime += 5;

            if (currentTime >= printer->timeNeeded) {
                Node* temp = printer;
                printer = printer->next;
                currentTime = 0;
                delete temp;
            }
        }
    }

    bool isPrinterAvailable() {
        return printer && currentTime == 0;
    }

    bool allUsersPrinted() {
        return printer == nullptr;
    }

    void simulatePrinting() {
        roundCount = 0;  

        while (!allUsersPrinted()) {
            if (isPrinterAvailable()) {
                printStatus();
                rotatePrinter();
            } else {
                rotatePrinter();
            }

            if (printerTime >= 5) {
                printerTime -= 5;
            } else {
                printerTime = 0;
            }

            roundCount++;
        }

        cout << "Total Rounds: " << roundCount << endl;
    }
};

int main() {
    int printerTime, numUsers;
    
    cout << "Enter the printer available time (in mins): ";
    cin >> printerTime;

    cout << "Enter the number of printer users: ";
    cin >> numUsers;

    CircularLinkedList circularList(printerTime);

    for (int i = 1; i <= numUsers; ++i) {
        int timeNeeded;
        cout << "Enter time needed for User " << i << " (in mins): ";
        cin >> timeNeeded;
        circularList.addUser(i, timeNeeded);
    }

    cout << "Simulation Results:\n";
    circularList.simulatePrinting();

    return 0;
}