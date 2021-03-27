#include "excursion.h"
#include <string.h>

int search_list(Node * head, int value){ //Поиск по заданному значанию 
	head = push(head); 
	Node *tmp = head->next;
	if (value==1){
		printf("Название: ");
		scanf("%s", head->name);
	}	
	else if (value==2){
		printf("Цена: ");
		scanf("%d", &head->price);
	}

	else if (value==3){
		printf("Длина Маршрута(км): ");
		scanf("%d", &head->length_way);
	}
	else if (value==4){
		printf("Длительность(Минуты): ");
		scanf("%d", &head->time);
	}
	else if (value==5){
		printf("Количество людей в группе: ");
		scanf("%d", &head->people);
	}
	else{
		return 0;
	}

	int count=0;
	int (*likeness[5])(Node*, Node*)={search_name, search_price, search_length_way, search_time, search_people};
	//массив указателей на функции сравнения
	while (tmp!=NULL){
		count++;
		if (likeness[value-1](head, tmp)==0){
			printf(" __________________________\n");
			printf("|Экскурсия №%d\n",count);
			printf("|Название: %s\n",tmp->name);
			printf("|Цена: %d рублей\n",tmp->price);
			printf("|Длина Маршрута: %d км\n",tmp->length_way);
			printf("|Длительность: %d минут\n",tmp->time);
			printf("|Количество людей в группе: %d\n",tmp->people);
			printf("|__________________________\n");
		}
		tmp = tmp->next;		
	}
	del(head,1);


}
int search_name(Node *head, Node *tmp){ //функция сравнения названий
	return strcmp(head->name, tmp->name); 
}

int search_price(Node *head, Node *tmp){ //функция сравнения цен
	if (head->price==tmp->price){
		return 0;
	}
	else{
		return 1;
	}
}

int search_length_way(Node *head, Node *tmp){ //функция сравнения длины маршрута
	if (head->length_way==tmp->length_way){
		return 0;
	}
	else{
		return 1;
	}
}

int search_time(Node *head, Node *tmp){ //функция сравнения длительности
	if (head->time==tmp->time){
		return 0;
	}
	else{
		return 1;
	}
}

int search_people(Node *head, Node *tmp){ //функция сравнения количества людей
	if (head->people==tmp->people){
		return 0;
	}
	else{
		return 1;
	}
}
