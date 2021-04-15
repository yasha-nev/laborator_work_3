#include "file.h"

File::File(){}

void File::ReadFile(char *f, List *l)
{
    fstream out(f, ios::in);
    if (!out.is_open()){
        cout << "file didnt open" << endl;
        return;
    }
    string nm;
    int pr, lw, t, pp, size;
    out >> size;
    Excursion* tmp;
    for (int i=0; i<size; i++){
        out >> nm;
        out >> pr;
        out >> lw;
        out >> t;
        out >> pp;
        l->Push();
        l->GetHead()->SetName(nm);
        l->GetHead()->SetPrice(pr);
        l->GetHead()->SetLengthWay(lw);
        l->GetHead()->SetTime(t);
        l->GetHead()->SetPeople(pp);

    }
    out.close();
}

void File::WriteFile(char *f, List *l)
{
    fstream in(f, ios::out);
    if (!in.is_open()){
            cout << "file didnt open" << endl;
            return;
    }
    string nm;
    int pr, lw, t, pp;
    Excursion *tmp = l->GetHead();

    in << l->Size() << endl;

    while(tmp != nullptr){
        nm = tmp->GetName();
        pr = tmp->GetPrice();
        lw = tmp->GetLengthWay();
        t = tmp->GetTime();
        pp = tmp->GetPeople();

        in << nm <<endl;
        in << pr << endl;
        in << lw << endl;
        in << t << endl;
        in << pp << endl;

        tmp = tmp->GetNext();
    }
    in.close();
}
