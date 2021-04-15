#include "excursion.h"
#include <iostream>
#include <string>
Excursion::Excursion(){}
Excursion::Excursion(string nm, int pr, int lw, int t, int pp)
{
    name = nm;
    price = pr;
    length_way = lw;
    time = t;
    people = pp;
}

Excursion::~Excursion()
{
    cout <<"call Distructor"<< endl;
}

string Excursion::GetName()
{
    return Excursion::name;
}

int Excursion::GetPrice()
{
    return price;
}

int Excursion::GetLengthWay()
{
    return length_way;
}

int Excursion::GetTime()
{
    return time;
}

int Excursion::GetPeople()
{
    return people;
}

Excursion *Excursion::GetNext()
{
    return next;
}

Excursion *Excursion::GetPrev()
{
    return prev;
}

void Excursion::SetName(string nm)
{
    if (nm != " "){
       name = nm;
    }
    else{
        cout << "error" << endl;
    }

}

void Excursion::SetPrice(int p)
{
    if (p >= 0){
        price = p;
    }
    else{
        cout << "error" << endl;
    }
}

void Excursion::SetLengthWay(int lw)
{
    if (lw >= 0){
        length_way = lw;
    }
    else{
        cout << "error" << endl;
    }
}

void Excursion::SetTime(int t)
{
    if (t >= 0){
        time = t;
    }
    else{
        cout << "error" << endl;
    }
}

void Excursion::SetPeople(int p)
{
    if (p >= 0){
        people = p;
    }
    else{
        cout << "error" << endl;
    }
}

void Excursion::SetNext(Excursion *n)
{
    next = n;
}

void Excursion::SetPrev(Excursion *p)
{
    prev = p;
}

ostream& operator <<(ostream &out, const Excursion &exc)
{
    out << "|Название: " << exc.name << endl;
    out << "|Цена: " << exc.price << endl;
    out << "|Длина Маршрута: " << exc.length_way << endl;
    out << "|Длительность: " << exc.time << endl;
    out << "|Количество людей в группе: " << exc.people << endl;
    return out;
}
istream& operator >> (istream &in, Excursion &exc)
{
    string nm;
    cout << "|Название: ";
    in >> exc.name;

    cout << "|Цена: ";
    in >> exc.price;

    cout << "|Длина маршрута(км): ";
    in >> exc.length_way;

    cout << "|Длительность(мин):  ";
    in >> exc.time;

    cout << "|Количество людей в группе: ";
    in >> exc.people;
    cout << "|_____________________________"<< endl;
    return in;
}
