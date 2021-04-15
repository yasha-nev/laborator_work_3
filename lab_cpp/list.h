#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "excursion.h"

using namespace std;

class List
{
private:
    int size;
    Excursion *head;

public:
    List();
    ~List();

    void Print();
    void Push();//string nm, int pr, int lw, int t, int pp);
    void Del(int index);
    int Size();
    void AddNew();
    void Swap(Excursion *left, Excursion *rigth);

    Excursion *Find(int index);
    Excursion *GetHead();
    void SetHead(Excursion *h);
};

#endif // LIST_H
