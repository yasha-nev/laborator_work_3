#include "list.h"
List::List()
{
   head = nullptr;
   size = 0;

}

List::~List()
{
    Excursion *tmp = head;
    while(tmp != nullptr){
        Excursion *p = tmp;
        tmp = tmp->GetNext();
        delete p;
    }
}

Excursion* List::GetHead()
{
    return head;
}

void List::SetHead(Excursion *h)
{
    head = h;
}

void List::Print()
{
    Excursion *tmp = head;
    for (int i = 0; i<size; i++){
        cout << " __________________________" << endl;
        cout << "|Экскурсия " << i+1  << endl;
        cout << *tmp << endl;
        tmp = tmp->GetNext();
    }
}

void List::Push()
{
    Excursion *tmp = new Excursion();
    tmp->SetNext(head);
    tmp->SetPrev(nullptr);
    if (head != nullptr){
        head->SetPrev(tmp);
    }
    head = tmp;
    size++;

    return;
}

Excursion* List::Find(int index){
    Excursion * finded = nullptr, * tmp = head;
    int i = 0;
    while(tmp != nullptr) {
        if(i == index) {
            finded = tmp;
            break;
        }
        i++;
        tmp = tmp->GetNext();
    }
    return finded;
}

void List::Del(int index)
{
    Excursion * finded = List::Find(index-1);

    if(finded == nullptr){
        return;
    }

    if(finded->GetPrev()) {
        finded->GetPrev()->SetNext(finded->GetNext()); //finded->prev->next = finded->next;
    }

    if(finded->GetNext()) {
        finded->GetNext()->SetPrev(finded->GetPrev()); //finded->next->prev = finded->prev;
     }

     if (index == 1){	// Если удаляем первый элемент нужно изменить указатель на первый элемент
        head = finded->GetNext();
        delete(finded);
        size--;
     }

     else{
        size--;
        delete(finded);
     }
}

int List::Size()
{
    return size;
}

void List::AddNew()
{
    List::Push();
    cin >> *head;
}

void List::Swap(Excursion *left, Excursion *rigth)
{
    Excursion * t_next = left->GetNext();
    Excursion * t_prev = left->GetPrev();


    Excursion * ti_next = rigth->GetNext();
    Excursion * ti_prev = rigth->GetPrev();

    if ((left->GetNext() != rigth) && (left->GetPrev() != rigth)){//Если элементы не соседи
        rigth->SetNext(t_next);
        rigth->SetPrev(t_prev);


        if (t_next){
            t_next->SetPrev(rigth);
        }

        if (t_prev){
            t_prev->SetNext(rigth);
        }


        left->SetNext(ti_next);
        left->SetPrev(ti_prev);

        if (ti_next){
            ti_next->SetPrev(left);
        }
        if (ti_prev){
            ti_prev->SetPrev(left);
        }
    }
    else{ //если элементы соседи
        left->SetNext(ti_next);
        left->SetPrev(rigth);

        if (ti_next){
            ti_next->SetPrev(left);
        }

        rigth->SetNext(left);
        rigth->SetPrev(t_prev);


        if (t_prev){
            t_prev->SetNext(rigth);
        }
    }
}
