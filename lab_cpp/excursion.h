#ifndef EXCURSION_H
#define EXCURSION_H
#include <iostream>
#include <string>

using namespace std;

class Excursion{
private:
    string name; //Название
    int price; 	//Цена
    int length_way;	//Длина маршрута
    int time;	//Длительность
    int people;

    Excursion *next;
    Excursion *prev;

public:
    Excursion();
    Excursion(string nm, int pr, int lw, int t, int pp);

    ~Excursion();

    //getters
    string GetName();
    int GetPrice();
    int GetLengthWay();
    int GetTime();
    int GetPeople();

    Excursion *GetNext();
    Excursion *GetPrev();

    //setters
    void SetName(string nm);
    void SetPrice(int p);
    void SetLengthWay(int lw);
    void SetTime(int t);
    void SetPeople(int p);

    void SetNext(Excursion *n);
    void SetPrev(Excursion *p);
    friend ostream& operator << (ostream &out, const Excursion &exc);
    friend istream& operator >> (istream &in, Excursion &exc);

};

#endif // EXCURSION_H
