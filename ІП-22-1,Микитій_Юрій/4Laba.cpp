#include <iostream>

using namespace std;

// ��������� ��� ������������� �������� ������
struct Node {
    int data;
    Node* next;
};

// ������� ��� ��������� �������� � ������� ������
Node* addToBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// ������� ��� ��������� �������� � ����� ������
Node* addToEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// ������� ��� ��������� �������� � �������� ������
Node* insertAfterValue(Node* head, int valueToInsertAfter, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    Node* current = head;
    while (current != nullptr && current->data != valueToInsertAfter) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "������� � ��������� " << valueToInsertAfter << " �� �������� � ������." << endl;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// ������� ��� ��������� �������� � ������
Node* deleteNode(Node* head, int valueToDelete) {
    if (head == nullptr) {
        cout << "������ �������." << endl;
        return head;
    }

    if (head->data == valueToDelete) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != valueToDelete) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "������� � ��������� " << valueToDelete << " �� �������� � ������." << endl;
        return head;
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
}

// ������� ��� ������ �������� �� ���������
Node* findNode(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// ������� ��� ������������� ������
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// ������� ��� ��������� ������ ������, �� ������ ���� �������� � ���� ������� ������
Node* createMergedEvenList(Node* list1, Node* list2) {
    Node* mergedList = nullptr;
    Node* current1 = list1;
    Node* current2 = list2;

    while (current1 != nullptr || current2 != nullptr) {
        if (current1 != nullptr && current1->data % 2 == 0) {
            mergedList = addToEnd(mergedList, current1->data);
        }
        if (current2 != nullptr && current2->data % 2 == 0) {
            mergedList = addToEnd(mergedList, current2->data);
        }

        if (current1 != nullptr) {
            current1 = current1->next;
        }
        if (current2 != nullptr) {
            current2 = current2->next;
        }
    }

    return mergedList;
}

// ������� ��� ��������� ������ ������, �� ������ �������� ����� �� ������ ����� � ���� ������� ������
Node* createMergedListLessThanValue(Node* list1, Node* list2, int value) {
    Node* mergedList = nullptr;
    Node* current1 = list1;
    Node* current2 = list2;

    while (current1 != nullptr || current2 != nullptr) {
        if (current1 != nullptr && current1->data < value) {
            mergedList = addToEnd(mergedList, current1->data);
        }
        if (current2 != nullptr && current2->data < value) {
            mergedList = addToEnd(mergedList, current2->data);
        }

        if (current1 != nullptr) {
            current1 = current1->next;
        }
        if (current2 != nullptr) {
            current2 = current2->next;
        }
    }

    return mergedList;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // ���������� ������ ������
    int n1;
    cout << "������ ������� �������� ������� ������: ";
    cin >> n1;
    cout << "������ �������� ������� ������: ";
    for (int i = 0; i < n1; i++) {
        int value;
        cin >> value;
        list1 = addToEnd(list1, value);
    }

    // ���������� ������ ������
    int n2;
    cout << "������ ������� �������� ������� ������: ";
    cin >> n2;
    cout << "������ �������� ������� ������: ";
    for (int i = 0; i < n2; i++) {
        int value;
        cin >> value;
        list2 = addToEnd(list2, value);
    }

    cout << "������ ������: ";
    printList(list1);
    cout << "������ ������: ";
    printList(list2);

    // �������� 1: �������� ����� ������ � ������� ����������
    Node* evenList = createMergedEvenList(list1, list2);
    cout << "������ � ������� ����������: ";
    printList(evenList);

    // �������� 7: �������� ����� ������ � ���������� ������� �� ������ �����
    int valueToCompare;
    cout << "������ ����� ��� ���������: ";
    cin >> valueToCompare;
    Node* mergedListLessThanValue = createMergedListLessThanValue(list1, list2, valueToCompare);
    cout << "������ � ���������� ������� �� " << valueToCompare << ": ";
    printList(mergedListLessThanValue);

    // ��������� ���'��
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    while (evenList != nullptr) {
        Node* temp = evenList;
        evenList = evenList->next;
        delete temp;
    }

    while (mergedListLessThanValue != nullptr) {
        Node* temp = mergedListLessThanValue;
        mergedListLessThanValue = mergedListLessThanValue->next;
        delete temp;
    }

    return 0;
}

