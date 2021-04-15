#include "sort.h"

Sort::Sort(){}

void Sort::SortList(List *l, int value, int opt)
{
    if (value > 5){
        printf("Error");
        return;
    }
    Excursion *tmp = l->GetHead();
    Excursion *header = l->GetHead();
    int n = l->Size();

    for (int i=0;i<n-1;i++){
        Excursion *max = tmp;
        Excursion *first_tmp = tmp;

        for (int j=i+1;j<n;j++){
            max = Sort::Compare(max, tmp, opt, value -1);
            tmp = tmp->GetNext();
        }
        max = Sort::Compare(max, tmp, opt, value - 1);
        l->Swap(first_tmp, max);
        tmp = max->GetNext();
        if (i==0){
            header = max;
        }
    }
    l->SetHead((header));
}

Excursion * Sort::Compare(Excursion *tmp, Excursion *tmp_next, int opt,int  value)
{
    if (value == 0){
        return Sort::CompareName(tmp, tmp_next, opt);
    }
    else if (value == 1){
        return Sort::ComparePrice(tmp, tmp_next, opt);
    }
    else if (value == 2){
        return Sort::CompareLengthWay(tmp, tmp_next, opt);
    }
    else if (value ==3){
        return Sort::CompareTime(tmp, tmp_next, opt);
    }
    else if (value == 4){
        return Sort::ComparePlaces(tmp, tmp_next, opt);
    }
    else{
        return tmp;
    }
}

Excursion *Sort::CompareName(Excursion * tmp, Excursion *tmp_next, int opt)
{
    if (((tmp->GetName() >= tmp_next->GetName()) && (opt==1)) || ((tmp->GetName() < tmp_next->GetName()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }
}

Excursion* Sort::ComparePrice(Excursion * tmp, Excursion *tmp_next, int opt)
{
    if (((tmp->GetPrice() >= tmp_next->GetPrice()) && (opt==1)) || ((tmp->GetPrice() < tmp_next->GetPrice()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }
}

Excursion* Sort::CompareLengthWay(Excursion * tmp, Excursion *tmp_next, int opt)
{
    if (((tmp->GetLengthWay() >= tmp_next->GetLengthWay()) && (opt==1)) || ((tmp->GetLengthWay() < tmp_next->GetLengthWay()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }

}

Excursion* Sort::CompareTime(Excursion * tmp, Excursion *tmp_next, int opt)
{
    if (((tmp->GetTime() >= tmp_next->GetTime()) && (opt==1)) || ((tmp->GetTime() < tmp_next->GetTime()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }
}

Excursion* Sort::ComparePlaces(Excursion * tmp, Excursion *tmp_next, int opt)
{
    if (((tmp->GetPeople() >= tmp_next->GetPeople()) && (opt==1)) || ((tmp->GetPeople() < tmp_next->GetPeople()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }

}
