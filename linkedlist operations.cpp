#include<iostream>

using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    // Function to check if a node with the given key exists
    Node* nodeExists(int k) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->key == k) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void printList() {
        if (head == NULL) {
            cout << "Singly Linked List is empty." << endl;
        } else {
            Node* temp = head;
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->data << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

     // 1. Search
    Node* searchNode(int k) {
        Node* ptr = nodeExists(k);
        if (ptr != NULL) {
            cout << "Node found with key value: " << k << endl;
        } else {
            cout << "Node doesn't exist with key value: " << k << endl;
        }
        return ptr;
    }

    // 2. Update at any n point
    void updateNodeAtPosition(int n, int d) {
        int count = 1;
        Node* ptr = head;
        while (ptr != NULL && count < n) {
            ptr = ptr->next;
            count++;
        }

        if (ptr != NULL) {
            ptr->data = d;
            cout << "Node at position " << n << " updated successfully" << endl;
        } else {
            cout << "Position " << n << " does not exist in the list" << endl;
        }
    }

    // 3. Insert at any n position
void insertNodeAtPosition(int n, Node* newNode) {
    if (n < 1) {
        cout << "Invalid position. Please enter a position greater than or equal to 1." << endl;
        return;
    }

    if (n == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at position " << n << endl;
        return;
    }

    int count = 1;
    Node* ptr = head;
    while (ptr != NULL && count < n - 1) {
        ptr = ptr->next;
        count++;
    }

    if (ptr != NULL) {
        newNode->next = ptr->next;
        ptr->next = newNode;
        cout << "Node inserted at position " << n << endl;
    } else {
        cout << "Position " << n << " does not exist in the list" << endl;
    }
}
    // 4. Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "Singly Linked List is already empty. Cannot delete." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted from the beginning" << endl;
        }
    }

    // 5. Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "Singly Linked List is already empty. Cannot delete." << endl;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Node deleted from the end" << endl;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            cout << "Node deleted from the end" << endl;
        }
    }

    // 6. Delete from any n position
    void deleteFromPosition(int n) {
        int count = 1;
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && count < n) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp != NULL) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Node deleted from position " << n << endl;
        } else {
            cout << "Position " << n << " does not exist in the list" << endl;
        }
    }

    // 7. Search and update any point
    void searchAndUpdate(int k, int d) 
	{
        Node* ptr = searchNode(k);
        if (ptr != NULL) {
            ptr->data = d;
            cout << "Node data updated successfully" << endl;
        }}
};

int main() {
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Search Node" << endl;
        cout << "2. Update Node at any position" << endl;
        cout << "3. Insert Node at any position" << endl;
        cout << "4. Delete Node from the beginning" << endl;
        cout << "5. Delete Node from the end" << endl;
        cout << "6. Delete Node from any position" << endl;
        cout << "7. Search and Update Node at any point" << endl;
        cout << "8. Print List" << endl;
        cout << "9. Clear Screen" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        Node* n1 = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Search Node Operation - Enter key to be searched: " << endl;
            cin >> k1;
            s.searchNode(k1);
            break;

        case 2:
            cout << "Update Node at any position - Enter position & new data: " << endl;
            cin >> k1;
            cin >> data1;
            s.updateNodeAtPosition(k1, data1);
            break;

        case 3:
            cout << "Insert Node at any position - Enter position, key & data of the New Node: " << endl;
            cin >> k1;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAtPosition(k1, n1);
            break;

        case 4:
            s.deleteFromBeginning();
            break;

        case 5:
            s.deleteFromEnd();
            break;

        case 6:
            cout << "Delete Node from any position - Enter position to be deleted: " << endl;
            cin >> k1;
            s.deleteFromPosition(k1);
            break;

        case 7:
            cout << "Search and Update Node at any point - Enter key & new data: " << endl;
            cin >> key1;
            cin >> data1;
            s.searchAndUpdate(key1, data1);
            break;

        case 8:
            s.printList();
            break;

        case 9:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
