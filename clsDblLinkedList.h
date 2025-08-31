#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename T>
class clsDblLinkedList
{
private:
    int _Size = 0;

public:

    static class Node {
    public:
        Node* prev;
        T value;
        Node* next;
    };

    Node* head = NULL;

	void InsertAtBeginning(T value) {
        // Create a new node
        Node* new_node = new Node();

        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = head;

        if (head != NULL)
        {
            head->prev = new_node;
        }

        head = new_node;

        _Size++;
	}

    Node* Find(T value) {
        Node* CurrentNode = head;
        while (CurrentNode != NULL)
        {
            if (CurrentNode->value == value)
            {
                return CurrentNode;
            }

            CurrentNode = CurrentNode->next;
        }

        return NULL;
    }

    void InsertAfter(Node* CurrentNode, T value)
    {

        Node* new_node = new Node();

        new_node->value = value;
        new_node->prev = CurrentNode;
        new_node->next = CurrentNode->next;

        if (CurrentNode->next != NULL)
        {
            CurrentNode->next->prev = new_node;
        }
        CurrentNode->next = new_node;
        _Size++;
    }

    void InsertAtEnd(T value)
    {
        Node* new_node = new Node();

        new_node->value = value;
        new_node->next = NULL;

        if (head == NULL)
        {
            new_node->prev = NULL;
            head = new_node;
            _Size++;
            return;
        }

        Node* LastNode = head;
        while (LastNode->next != NULL)
        {
            LastNode = LastNode->next;
        }

        new_node->prev = LastNode;
        LastNode->next = new_node;
        _Size++;
    }

    void DeleteNode(Node* &NodeToDelete)
    {

        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        Node* CurrentNode = head, * PrevNode = head;

        if (head == NULL)
            return;

        if (CurrentNode->next == NULL)
        {
            head = NULL;
            delete CurrentNode;
            _Size--;
            return;
        }

        while (CurrentNode != NULL && CurrentNode->next != NULL)
        {
            PrevNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }

        PrevNode->next = NULL;
        delete CurrentNode;
        _Size--;
    }

    void PrintList()
    {
        Node* CurrentNode = head;

        cout << "\n";
        while (CurrentNode != NULL)
        {
            cout << CurrentNode->value << " ";
            CurrentNode = CurrentNode->next;
        }
        cout << "\n";
    }

    int Size() {
        return _Size;
    }

    bool IsEmpty() {
        return _Size == 0;
    }

    void Clear() {
        while (_Size > 0) {
            DeleteFirstNode();
        }
    }

    void Reverse() {
        Node* CurrentNode = head;
        Node* temp = nullptr;
        while (CurrentNode != nullptr) {
            temp = CurrentNode->prev;
            CurrentNode->prev = CurrentNode->next;
            CurrentNode->next = temp;
            CurrentNode = CurrentNode->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* GetNode(int Index) {
        int Counter = 0;

        if (Index > _Size - 1 || Index < 0) return NULL;

        Node* CurrentNode = head;
        while (CurrentNode != NULL && CurrentNode->next != NULL) {
            if (Counter == Index) break;

            CurrentNode = CurrentNode->next;
            Counter++;
        }

        return CurrentNode;
    }

    T GetItem(int Index) {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL) {
            return NULL;
        }
        else {
            return ItemNode->value;
        }
    }

    bool UpdateItem(int Index, T value) {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL) {
            return false;
        }
        else {
            ItemNode->value = value;
            return true;
        }
    }

    bool InsertAfter(int Index, T value) {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL) {
            InsertAfter(ItemNode, value);
            return true;
        }
        else return false;
    }

};

