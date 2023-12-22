#ifndef LIST_H
#define LIST_H

#include "geometrys.h"

struct Node
{
    FlatFigure* fig;
    Node* next;
    Node* prev;
};

class List
{
private:
    Node *head;
    Node *tail;
    int size;
public:
    List();
    ~List();

    void addList(FlatFigure* new_obj);
    FlatFigure* getElem(int ind);
    Node* getNode(int ind);
    int getSize();
    void deleteElem(int i);
    void deleteNode(Node* toDel);
    void deleteList();
    int printList();
    Node *getHead() const;
    Node *getTail() const;
};

#endif // LIST_H
