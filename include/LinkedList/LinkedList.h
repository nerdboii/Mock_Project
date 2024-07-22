#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ListNode.h>
#include <iostream>

template <class T>
class LinkedList {
private:
    ListNode<T> *head;
    int size;

    ListNode<T> *getPrev(ListNode<T> *a);
    
public:
    LinkedList(): size(0), head(NULL) {}
    ~LinkedList();

    ListNode<T> *getHead() const {
        return head;
    }
    int getSize() const {
        return size;
    }

    ListNode<T> *getTail();
    void add(T value);
    ListNode<T> *operator[](const int &index);
    void swap(ListNode<T> *a, ListNode<T> *b);
    int indexOf(const T &value) const;
};

template <class T>
LinkedList<T>::~LinkedList() {
    ListNode<T> *p = head;
    while (size--) {
        if (p == NULL) break;
        head = p->next;
        delete p;
        p = NULL;
    }
}

template <class T>
ListNode<T> *LinkedList<T>::getPrev(ListNode<T> *a) {
    if (a == NULL || a == head) return NULL;
    ListNode<T> *temp = head;
    while (temp->next != NULL && temp->next != a) {
        temp = temp->next;
    }
    if (temp->next == a) return temp;
    else return NULL;
}

template <class T>
ListNode<T> *LinkedList<T>::getTail() {
    ListNode<T> *temp = head;
    while (temp->next != NULL) temp = temp->next;
    return temp;
}

template <class T>
void LinkedList<T>::add(T value) {
    ListNode<T> *newNode = new ListNode<T>(value);
    size++;
    if (head == NULL) {
        head = newNode;
        return;
    }
    ListNode<T> *tail = getTail();
    tail->next = newNode;
    tail = newNode;
}

template <class T>
ListNode<T> *LinkedList<T>::operator[](const int &index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid list member access!\n";
        return NULL;
    }
    ListNode<T> *temp = head;
    for (int i = 0; i < index; i++) temp = temp->head;
    return temp;
}

template <class T>
void LinkedList<T>::swap(ListNode<T> *a, ListNode<T> *b) {
    ListNode<T> *a_p = getPrev(a);
    ListNode<T> *b_p = getPrev(b);
    if (a->next == b) {
        a->next = b->next;
        b->next = a;
        a_p->next = b;
        return;
    }
    if (b->next == a) {
        b->next = a->next;
        a->next = b;
        b_p->next = a;
        return;
    }
    ListNode<T> *a_n = a->next;
    a->next = b->next;
    if (b_p != NULL) b_p->next = a;
    b->next = a_n;
    if (a_p != NULL) a_p->next = b;
}

template <class T>
int LinkedList<T>::indexOf(const T &value) const {
    ListNode<T> *temp = head;
    int result = 0;
    while (temp != NULL) {
        if (temp->getData() == value)
            return result;
        temp = temp->next;
    }

    std::cout << "Value does not exist in List!\n";
}

#endif //LINKEDLIST_H