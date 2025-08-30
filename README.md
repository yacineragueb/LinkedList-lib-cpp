# 📚 Custom Doubly Linked-List Library in C++

## ✨ Overview
`clsDblLinkedList` is a C++ **template-based** Doubly Linked List implementation. It provides basic list operations such as insertion, deletion, searching, updating, etc.

This project is perfect for learning **Object-Oriented Programming (OOP)** in C++ and for building reusable libraries.

## 🚀 Features

- Generic (supports any data type using templates).
- Insert at the beginning, end, or after a specific node.
- Delete a specific node, the first node, or the last node.
- Search and access items by index or value.
- Update existing nodes.
- Reverse the entire list.
- Print the full list content.
- Check if the list is empty and get its size.
- Clear the entire list.

## 💻 Example Usage

```cpp
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    clsDblLinkedList <int> MyDblLinkedList;

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    MyDblLinkedList.PrintList(); // Output: 1 2 3 4 5

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << endl; // Output: 5

    clsDblLinkedList<int>::Node* N;

    N = MyDblLinkedList.GetNode(4);
    cout << "\nNode Value is: " << N->value << endl; // Output: 5

    cout << "\nItem(2) Value is: " << MyDblLinkedList.GetItem(2) << endl; // Output: 3

    MyDblLinkedList.UpdateItem(2, 500);
    cout << "\nAfter Updating Item(2):\n";
    MyDblLinkedList.PrintList(); // Output: 1 2 500 4 5

    MyDblLinkedList.InsertAfter(1, 1000);
    cout << "\nAfter Insert:\n";
    MyDblLinkedList.PrintList(); // Output: 1 2 1000 500 4 5

    MyDblLinkedList.Reverse();
    cout << "\nLinked List Content after reverse:\n";
    MyDblLinkedList.PrintList(); // Output: 5 4 500 1000 2 1

    return 0;
}

```

## 🛠️ Requirements: 
- A C++ compiler (GCC, Clang, MSVC, etc.)
