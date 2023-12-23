#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

// ��������� ��� ��������� �����
struct Stack {
    vector<int> data;

    // ������� ��������� �������� � ����
    void push(int value) {
        data.push_back(value);
    }

    // ������� ��������� ���������� �������� � �����
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    // ������� ��������� ���������� �������� �����
    int top() {
        if (!data.empty()) {
            return data.back();
        }
        else {
            return -1;  // ���� ���� �������, ��������� -1 (����� ������ ��������� �������)
        }
    }

    // ������� ��������, �� ���� �������
    bool empty() {
        return data.empty();
    }
};

// ��������� ��� ��������� �����
struct Queue {
    vector<int> data;

    // ������� ��������� �������� � �����
    void push(int value) {
        data.push_back(value);
    }

    // ������� ��������� ������� �������� � �����
    void pop() {
        if (!data.empty()) {
            data.erase(data.begin());
        }
    }

    // ������� ��������� ������� �������� �����
    int front() {
        if (!data.empty()) {
            return data.front();
        }
        else {
            return -1;  // ���� ����� �������, ��������� -1 (����� ������ ��������� �������)
        }
    }

    // ������� ��������, �� ����� �������
    bool empty() {
        return data.empty();
    }
};

// ��������� ��� ������������� ����� �������� ������
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ������� ��� ����������� ������������� �������� � �������� �����
int findMax(TreeNode* root) {
    if (root == nullptr) {
        return INT_MIN; // ��������� �������� ������� �������� �� �������
    }

    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > max) {
        max = leftMax;
    }

    if (rightMax > max) {
        max = rightMax;
    }

    return max;
}

// ������� ��� ��������� ������� ��������� ������������� �������� � �������� �����
int countMax(TreeNode* root, int max) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;
    if (root->data == max) {
        count = 1;
    }

    int leftCount = countMax(root->left, max);
    int rightCount = countMax(root->right, max);

    return count + leftCount + rightCount;
}

int main() {
    Stack muStack;

    const int N = 5; // ����� ������
    int array[N] = { 1, 2, 3, 4, 5 };
    cout << "Array:";
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }

    cout << "\nArray in reverse order using a stack: ";
    for (int i = 0; i < N; i++) {
        muStack.push(array[i]);
    }

    while (!muStack.empty()) {
        cout << muStack.top() << " ";
        muStack.pop();
    }

    cout << std::endl;
    cout << "\n------------------------------------------------------------------\n";

    double C = 26.0;

    std::ifstream inputFile("input.txt");

    if (inputFile.is_open()) {
        double number;
        Queue lowerQueue, greaterQueue;

        while (inputFile >> number) {
            if (number < C) {
                lowerQueue.push(number);
            }
            else {
                greaterQueue.push(number);
            }
        }

        std::cout << "Numbers less than " << C << ": ";
        while (!lowerQueue.empty()) {
            std::cout << lowerQueue.front() << " ";
            lowerQueue.pop();
        }

        std::cout << "\nNumbers greater than or equal to " << C << ": ";
        while (!greaterQueue.empty()) {
            std::cout << greaterQueue.front() << " ";
            greaterQueue.pop();
        }

        std::cout << std::endl;

        inputFile.close();
    }
    else {
        std::cerr << "Error opening the file." << std::endl;
    }

    cout << "\n------------------------------------------------------------------\n";

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(15);

    // ������ ������������ ������� �� ������� ��������� ������������� ��������.
    int max = findMax(root);
    int count = countMax(root, max);

    std::cout << "Max element in the binary tree: " << max << std::endl;
    std::cout << "Count of max element in the binary tree: " << count << std::endl;


    cout << "\n------------------------------------------------------------------\n";

        queue<int> myQueue;

        myQueue.push(11);
        myQueue.push(24);
        myQueue.push(35);
        myQueue.push(41);
        myQueue.push(54);

        // ��������� ����� ��� ��������
        myQueue.pop();
        myQueue.pop();

        // �������� ����� �������
        int thirdElement = myQueue.front();

        // ��������� �������� ��������
        std::cout << "Third Element: " << thirdElement << std::endl;


    return 0;
}
