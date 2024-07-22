#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

template <class T>
class ListNode {
public:
    T data;

public:
    ListNode *next;

    ListNode(T value): data(value), next(NULL) {}

    T getData() {
        return data;
    }
};

#endif //LISTNODE_H