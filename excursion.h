#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 	//Структура хранящая информацию о экскурсии
	char name[128]; //Название
	int price; 	//Цена
	int length_way;	//Длина маршрута
	int time;	//Длительность
	int people;	//Количество людей в группе

	
	struct Node *next;	//указательна слудующий элемент списка
	struct Node *prev;	//указательна предыдущий элемент списка

} Node;


//excursion.c
Node* push(Node *head);
Node* del(Node * head, int index);
Node* find(Node * head, int index);
int size(Node *head);
void print(Node *head);
void freeList(Node *head);
void add_new_excursion(Node *head);


//sort.c
Node* sort_list(Node * tmp, int value, int opt);
Node* compare_name(Node * tmp, Node *tmp_next, int opt);
Node* compare_price(Node * tmp, Node *tmp_next, int opt);
Node* compare_length_way(Node *tmp, Node *tmp_next, int opt);
Node* compare_time(Node *tmp, Node *tmp_next, int opt);
Node* compare_places(Node *tmp, Node *tmp_next, int opt);
int swap(Node * tmp, Node* tmp_swap);

//serch.c
int search_list(Node * head, int value);
int search_name(Node *head, Node *tmp);
int search_price(Node *head, Node *tmp);
int search_length_way(Node *head, Node *tmp);
int search_time(Node *head, Node *tmp);
int search_people(Node *head, Node *tmp);

//workFiles.c
Node* readFile(Node *head, char * argv[]);
int writeFile(Node *head, char * argv[]);

//change.c 
int change_list(Node *head, int value);






