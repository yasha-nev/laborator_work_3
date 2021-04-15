#include <iostream>
#include "list.h"
#include "appfunction.h"

using namespace std;
int main(int argc, char * argv[]){
    if (argc < 2){
        cout << "Error" << endl;
        return 0;

    }
    List list;
    AppFunction fl;
    fl.ReadFile(argv[1], &list);
    int flag = 1;

    while (flag!=0){
        fl.DrawMenu();
        cin >> flag;

        if (flag==1){ // Дабавление
            list.AddNew();
        }

        else if (flag==2){ //Вывод всех элементов
            list.Print();
        }

        else if (flag==3){ //количество экскурсий
            cout << "|количество экскурсий: " << list.Size() << endl;
        }

        else if (flag==4){ //Удаление элемента
            int del_index;
            cout << "|Экскурсия №: ";
            cin >> del_index;
            cout << endl;
            list.Del(del_index);
        }

        else if (flag==5){ // Сортировка по возростанию
            int value;
            cout << "|1) сортировать по названию" << endl;
            cout << "|2) сортировать по цене" << endl;
            cout << "|3) сортировать по длине маршрута" << endl;
            cout << "|4) сортировать по длительности" << endl;
            cout << "|5) сортировать по количеству людей в группе" << endl;
            cin >> value;
            fl.SortList(&list, value, 1);
        }

        else if (flag==6){ // Сортировка по убыванию
            int value;
            cout << "|1) сортировать по названию" << endl;
            cout << "|2) сортировать по цене" << endl;
            cout << "|3) сортировать по длине маршрута" << endl;
            cout << "|4) сортировать по длительности" << endl;
            cout << "|5) сортировать по количеству людей в группе" << endl;
            cin >> value;
            fl.SortList(&list, value, 0);
        }

        else if (flag==7){ // поиск
            int value;
            cout << "|1) Поиск по названию " << endl;
            cout << "|2) Поиск по цене " << endl;
            cout << "|3) Поиск по длине маршрута" << endl;
            cout << "|4) Поиск по длительности" << endl;
            cout << "|5) Поиск по количеству людей в группе" << endl;
            cin >> value;
            fl.Search(&list, value);
        }

        else if (flag==8){ //Изменение
            int value;
            cout << "|Номер экскурсии: ";
            cin >> value;
            cout << "|" << endl;
            cout << "|1) Изменить название" << endl;
            cout << "|2) Изменить цену" << endl;
            cout << "|3) Изменить длину маршрута" << endl;
            cout << "|4) Изменить длительность" << endl;
            cout << "|5) Изменить количество людей в группе" << endl;
            cout << "|Введите число от 1 до 6: " << endl;
            fl.Change(&list, value - 1);
        }


        else if (flag==0){ //выход
            fl.DrawHeart();
            fl.WriteFile(argv[1], &list);
            return 0;
        }
    }

    return 0;
}
