#include "appfunction.h"

AppFunction::AppFunction(){}

void AppFunction::Change(List *l, int index)
{
    Excursion * finded = l->Find(index);
    if (finded==nullptr){
        return;
    }
    int opt;
    cin >> opt;
    switch(opt){
        case(1):
            {
                cout << "Введите новое название: ";
                string nm;
                cin >> nm;
                finded->SetName(nm);
            }
            break;

        case(2):
            {
                cout << "Введите новую цену: ";
                int pr;
                cin >> pr;
                finded->SetPrice(pr);
            }
            break;

        case(3):
            {
                cout << "Введите новую длину маршрута: ";
                int lw;
                cin >> lw;
                finded->SetLengthWay(lw);
            }
            break;

        case(4):
            {
                cout << "Введите новую длительность: ";
                int t;
                cin >> t;
                finded->SetTime(t);
            }
            break;

        case(5):
            {
                cout << "Введите новое количество людей в группе: ";
                int pp;
                cin >> pp;
                finded->SetPeople(pp);
            }
            break;
    }
    return;

}
void AppFunction::Search(List *l, int value)
{
    string nm;
    int pr, lw, t, pp;

    if (value == 1){
        cout <<"Искомое название: " <<endl;
        cin >> nm;
    }
    else if(value == 2){
        cout << "Искомая цена: ";
        cin >> pr;
    }
    else if(value == 3){
        cout << "Искомая длина маршрута: ";
        cin >> lw;
    }
    else if(value == 4){
        cout << "Искомое количество времени: ";
        cin >> t;
    }
    else if(value == 5){
        cout << "Искомое количество людей: ";
        cin >> pp;
    }
    Excursion *tmp = l->GetHead();
    int size = l->Size();

    for (int i = 0; i< size; i++){
        if (value == 1){
            if (tmp->GetName() == nm){
                cout << " __________________________" << endl;
                cout << "|Экскурсия " << i  << endl;
                cout << *tmp << endl;

            }
        }
        else if(value == 2){
            if (tmp->GetPrice() == pr){
                cout << " __________________________" << endl;
                cout << "|Экскурсия " << i  << endl;
                cout << *tmp << endl;

            }
        }
        else if(value == 3){
            if (tmp->GetLengthWay() == lw){
                cout << " __________________________" << endl;
                cout << "|Экскурсия " << i  << endl;
                cout << *tmp << endl;
            }
        }
        else if(value == 4){
            if (tmp->GetTime() == t){
                cout << " __________________________" << endl;
                cout << "|Экскурсия " << i  << endl;
                cout << *tmp << endl;

            }
        }
        else if(value == 5){
            if (tmp->GetPeople() == pp){
                cout << " __________________________" << endl;
                cout << "|Экскурсия " << i  << endl;
                cout << *tmp << endl;

            }
        }
        tmp = tmp->GetNext();
    }
}
void AppFunction::DrawHeart()
{
    cout << " _____________________________  "<< endl;
    cout << "/           __    __          \\ " << endl;
    cout << "|          /  \\  /  \\         |" << endl;
    cout << "|          |   \\/   |         |" << endl;
    cout << "|           \\      /          |" << endl;
    cout << "|            \\    /           |" << endl;
    cout << "|             \\  /            |" << endl;
    cout << "|              \\/             |" << endl;
    cout << "\\_____________________________/" << endl;
    cout << "Спасибо, что использовали наш продукт" << endl;
    cout << "Вы думайте об отдыхе," << endl;
    cout << "А мы позаботимся обо всем остальном." << endl;
    cout << endl;
}
void AppFunction::DrawMenu()
{
    cout << "\n" << endl;
    cout << " ____Городские Экскурсии_______" << endl;
    cout << "|1) Добавить экскурсию         |" << endl;
    cout << "|2) Вывести список экскурсий   |" << endl;
    cout << "|3) Колличество экскурсий      |" << endl;
    cout << "|4) Удалить экскурсию          |" << endl;
    cout << "|5) Сортировать по возростанию |" << endl;
    cout << "|6) Сортировать по убыванию    |" << endl;
    cout << "|7) Поиск                      |" << endl;
    cout << "|8) Изменить                   |" << endl;
    cout << "|0) выйти                      |" << endl;
    cout << "|______________________________|" << endl;
    cout << endl;
    cout << " ______________________________" << endl;
    cout << "|Введите число от 0 до 8 " << endl;
}
