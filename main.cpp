#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    clsDblLinkedList <int> MyDblLinkedList;

    if (MyDblLinkedList.IsEmpty()) {
        cout << "\nYes, List is empty!\n";
    }
    else {
        cout << "\nNo, List is not empty.\n";
    }

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << endl;

    clsDblLinkedList<int>::Node* N;

    N = MyDblLinkedList.GetNode(4);
    cout << "\nNode Value is: " << N->value << endl;

    cout << "\nItem(2) Value is: " << MyDblLinkedList.GetItem(2) << endl;

    MyDblLinkedList.UpdateItem(2, 500);
    cout << "\nAfter Updating Item(2):\n";
    MyDblLinkedList.PrintList();

    MyDblLinkedList.InsertAfter(1, 1000);
    cout << "\nAfter Insert:\n";
    MyDblLinkedList.PrintList();


    MyDblLinkedList.Reverse();
    cout << "\nLinked List Content after reverse:\n";
    MyDblLinkedList.PrintList();

    return 0;
}
