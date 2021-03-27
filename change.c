#include "excursion.h"

int change_list(Node *head, int value){ //Изменение информации структуры
	Node *tmp = head;	
	Node * finded = find(tmp, value-1);
	if (finded==NULL){
		return 0;
	}
	int opt;
	printf("|1) Изменить название\n");
	printf("|2) Изменить цену\n");
	printf("|3) Изменить длину маршрута\n");
	printf("|4) Изменить длительность\n");
	printf("|5) Изменить количество людей в группе\n");
	printf("|Введите число от 1 до 6: ");
	scanf("%d",&opt);	
	switch(opt){
		case(1):
			printf("Введите новое название: ");	
			scanf("%s", finded->name);	
			break;
			
		case(2):
			printf("Введите новую цену: ");	
			scanf("%d", &finded->price);		
			break;
		
		case(3):
			printf("Введите новую длину маршрута: ");
			scanf("%d", &finded->length_way);
			break;

		case(4):
			printf("Введите новую длительность: ");	
			scanf("%d", &finded->time);	
			break;

		case(5):		
			printf("Введите новое количество людей в группе: ");
			scanf("%d", &finded->people);
			break;
	}
	return 0;

}
