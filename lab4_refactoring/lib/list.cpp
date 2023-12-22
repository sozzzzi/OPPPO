#include "list.h"
#include "maincycle.h"

Node *List::getHead() const
{
    return head;
}

Node *List::getTail() const
{
    return tail;
}

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List()
{
    deleteList();
}

void List::addList(FlatFigure* new_obj)
{
    Node *tmp = new Node;
    tmp->next = head;
    tmp->prev = tail;
    tmp->fig = new_obj;

    if (head != nullptr)
    {
        tail->next = tmp;
        tail = tmp;
        head->prev = tail;
    }
    else
    {
        head = tmp;
        tail = tmp;
        head->prev = tail;
    }
    size++;
}

void List::deleteElem(int i)
{
    if (size <= i)
    {
        throw std::out_of_range("Out of range");
    }

    Node* toDel = getNode(i);

    deleteNode(toDel);
}

void List::deleteNode(Node *toDel)
{
    if (toDel == head && toDel == tail)
    {
        delete toDel;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    if (toDel == head)
    {
        head = head->next;
        head->prev = tail;
    }
    else if (toDel == tail)
    {
        tail = tail->prev;
        tail->next = head;
    }
    else
    {
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
    }

    delete toDel;

    size--;
}

void List::deleteList()
{
    if (size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    while (size != 0)
    {
        Node *tmp_head = head->next;
        tmp_head->prev = tail;
        delete head;
        head = tmp_head;
        size--;
    }
    head = nullptr;
    tail = nullptr;
}

int List::printList()
{
    Node *tmp_head = head;
    int tmp_size = size;

    if (tmp_size == 0)
    {
        std::wcout << L"Список пуст!" << std::endl;
        return EmptyList;
    }

    while (tmp_size != 0)
    {
        tmp_head->fig->print();
        tmp_head = tmp_head->next;
        tmp_size--;
    }

    return Ok;
}

FlatFigure* List::getElem(int ind)
{
    FlatFigure* obj = nullptr;

    Node *tmp_elem = head;
    for (int i = 0; i < ind; i++)
    {
        tmp_elem = tmp_elem->next;
    }

    obj = tmp_elem->fig;
    return obj;
}

Node* List::getNode(int ind)
{
    FlatFigure* obj = nullptr;

    Node *tmp_elem = head;
    for (int i = 0; i < ind; i++)
    {
        tmp_elem = tmp_elem->next;
    }

    return tmp_elem;
}

int List::getSize()
{
    return size;
}
