#include "excursion.h"

void print(Node *head){ //Вывод всего списка 
	Node *tmp = head;
	int count=0;

	while (tmp != NULL){
		count++;
		printf(" __________________________\n");
		printf("|Экскурсия №%d\n",count);
		printf("|Название: %s\n",tmp->name);
		printf("|Цена: %d рублей\n",tmp->price);
		printf("|Длина Маршрута: %d км\n",tmp->length_way);
		printf("|Длительность: %d минут\n",tmp->time);
		printf("|Количество людей в группе: %d\n",tmp->people);
		printf("|__________________________\n");

		tmp = tmp->next;
	}
	if (count == 0){
		printf("|Экскурсий нет\n");
	}
}

void add_new_excursion(Node *head){ //добавление информации о новой структуре
	printf("|Новая экскурсия\n");
	printf("|Название: ");
	scanf("%s",head->name);
				
	printf("|Цена:");
	scanf("%d", &head->price);

	printf("|Длина маршрута(км): ");
	scanf("%d",  &head->length_way);

	printf("|Длительность(мин):  ");
	scanf("%d", &head->time);

	printf("|Количество людей в группе: ");
	scanf("%d", &head->people);
	printf("|_____________________________\n");
}

Node* push(Node *head){	//Добавление нового элемента списка
	Node *tmp = (Node*) malloc(sizeof(Node));
	tmp->next = head;
	tmp->prev = NULL;

	if(head){
		head->prev = tmp;
	}	
	return tmp;
} 

int size(Node *head){ //Размер списка
	Node *tmp = head;
	int size = 0;
	while (tmp !=NULL){
		size++;
		tmp = tmp->next;
	}
	return size;
}

Node* find(Node * head, int index) { //Поиск по индексу
	Node * finded = NULL, * tmp = head;
	int i = 0;
	while(tmp != NULL) {
		if(i == index) {
			finded = tmp;
			break;
		}
                i++;
                tmp = tmp->next;
        }
	return finded;
}

Node* del(Node * head, int index) { //Удаление
	Node *tmp = head;
	Node * finded = find(tmp, index-1);

	if(finded==NULL){
		return tmp;
	}

	if(finded->prev) {
		finded->prev->next = finded->next;
	}

	if(finded->next) {
		finded->next->prev = finded->prev;
	}

	
	if (index == 1){	// Если удаляем первый элемент нужно изменить указатель на первый элемент
		Node* tmp_next = tmp->next;
		free(finded);
		return tmp_next;
	}
	else{
		free(finded);
		return tmp;
	} 
}

void freeList(Node *head){ //отчистка списка
	Node *tmp = head;
	while(tmp != NULL){
		Node * p = tmp;
		tmp = tmp->next;
		free(p);		
	}
}

