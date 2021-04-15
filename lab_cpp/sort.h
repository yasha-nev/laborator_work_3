#ifndef SORT_H
#define SORT_H
#include "list.h"

class Sort
{
public:
    Sort();
    void SortList(List *l, int value, int opt);
    Excursion* CompareName(Excursion * tmp, Excursion *tmp_next, int opt);
    Excursion* ComparePrice(Excursion * tmp, Excursion *tmp_next, int opt);
    Excursion* CompareLengthWay(Excursion * tmp,Excursion *tmp_next, int opt);
    Excursion* CompareTime(Excursion * tmp, Excursion *tmp_next, int opt);
    Excursion* ComparePlaces(Excursion * tmp, Excursion *tmp_next, int opt);
    Excursion* Compare(Excursion * tmp, Excursion *tmp_next, int opt, int value);
};

#endif // SORT_H
