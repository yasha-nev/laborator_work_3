#include <stdio.h>
#include "excursion.h"

int main(int argc, char * argv[]){
	if (argc<2){
		printf("Error\n");
		return 0;

	}
	Node *head = NULL;
	head = readFile(head, argv);
	int flag = 1;
	
	while (flag!=0){

		printf("\n");
		printf(" ____Городские Экскурсии_______\n");
		printf("|1) Добавить экскурсию         |\n");
		printf("|2) Вывести список экскурсий   |\n");
		printf("|3) Колличество экскурсий      |\n");
		printf("|4) Удалить экскурсию          |\n");
		printf("|5) Сортировать по возростанию |\n");
		printf("|6) Сортировать по убыванию    |\n");
		printf("|7) Поиск                      |\n");
		printf("|8) Изменить                   |\n");
		printf("|0) выйти                      |\n");
		printf("|______________________________|\n");
		printf("\n");
		printf(" ______________________________\n");
		printf("|Введите число от 0 до 8 ");
		scanf("%d",&flag);

		if (flag==1){ // Дабавление
			head=push(head);
			add_new_excursion(head);
		}

		else if (flag==2){ //Вывод всех элементов
			print(head);
		}

		else if (flag==3){ //количество экскурсий
			printf("|количество экскурсий: %d\n",size(head));
			printf("|____________________________|\n");
		}
		else if (flag==4){ //Удаление элемента
			int del_index;
			printf("|Экскурсия №: ");
			scanf("%d",&del_index);
			head = del(head, del_index);
		}
		else if (flag==5){ // Сортировка по возростанию
			int value;
			printf("|1) сортировать по названию\n");
			printf("|2) сортировать по цене\n");
			printf("|3) сортировать по длине маршрута\n");
			printf("|4) сортировать по длительности\n");
			printf("|5) сортировать по количеству людей в группе\n");
			printf("|");
			scanf("%d",&value);
			printf("|____________________________\n");
			head = sort_list(head, value, 1);
		}
		else if (flag==6){ // Сортировка по убыванию
			int value;
			printf("|1) сортировать по названию\n");
			printf("|2) сортировать по цене\n");
			printf("|3) сортировать по длине маршрута\n");
			printf("|4) сортировать по длительности\n");
			printf("|5) сортировать по количеству людей в группе\n");
			printf("|");
			scanf("%d",&value);
			printf("|____________________________\n");
			head = sort_list(head, value, 0);
		}
	
		else if (flag==7){ // поиск
			int value;
			printf("|1) Поиск по названию\n");
			printf("|2) Поиск по цене\n");
			printf("|3) Поиск по длине маршрута\n");
			printf("|4) Поиск по длительности\n");
			printf("|5) Поиск по количеству людей в группе\n");
			printf("|");
			scanf("%d",&value);
			printf("|____________________________\n");
			search_list(head, value);
		}
		else if (flag==8){ //Изменение 
			int value;
			printf("|Номер экскурсии: ");
			scanf("%d",&value);
			printf("|\n");
			change_list(head,value);
		}					
				

		else if (flag==0){ //выход
			printf(" _____________________________ \n");
			printf("/           __    __          \\ \n");
			printf("|          /  \\  /  \\         |\n");
			printf("|          |   \\/   |         |\n");
			printf("|           \\      /          |\n");
			printf("|            \\    /           |\n");
			printf("|             \\  /            |\n");
			printf("|              \\/             |\n");
			printf("\\_____________________________/\n");
			printf("Спасибо, что использовали наш продукт\n");
			printf("Вы думайте об отдыхе,\n");
			printf("А мы позаботимся обо всем остальном.\n");
			printf("\n");
			writeFile(head, argv);
			freeList(head);
			return 0;
		}
	}
		
}




