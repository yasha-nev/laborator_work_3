#include "excursion.h"
#include <string.h>

Node* sort_list(Node * head, int value, int opt){ //функция сортировки, opt - по возрастанию/убыванию
	if (value > 5){
		printf("error");
		return head;
	}
	

	Node* (*compares[5])(Node*, Node*, int)={compare_name, compare_price, compare_length_way, compare_time, compare_places};
	//массив указателей на функции сравнения
	Node *tmp = head;
	Node *header = head;
	int n = size(head);
	
	for (int i=0;i<n-1;i++){
		Node *max = tmp;
		Node *first_tmp = tmp;
	
		for (int j=i+1;j<n;j++){
			max = compares[value-1](max, tmp, opt);
			tmp = tmp->next;
		}
		max = compares[value-1](max, tmp, opt);
		swap(first_tmp, max);		
		tmp = max->next;
		if (i==0){
			header = max;
		}
	}
	
	return header;

}

int swap(Node * tmp, Node* tmp_swap){ // поменять местами элементы списка
	
	Node * t_next = tmp->next;
	Node * t_prev = tmp->prev;
	

	Node * ti_next = tmp_swap->next;
	Node * ti_prev = tmp_swap->prev;
	
	if ((tmp->next != tmp_swap) && (tmp->prev != tmp_swap)){ //если элементы не соседи
		tmp_swap->next = t_next;
	 	tmp_swap->prev = t_prev;

		
		if (t_next){
			t_next->prev = tmp_swap;
		}
		
		if (t_prev){
			t_prev->next = tmp_swap;
		}
		
		
		tmp->next = ti_next;
		tmp->prev = ti_prev;
		
		if (ti_next){
			ti_next->prev = tmp;
		}
		if (ti_prev){
			ti_prev->next = tmp;
		}    	
	}
	else{ //если элементы соседи
		tmp->next = ti_next;
		tmp->prev = tmp_swap;
		
		if (ti_next){
			ti_next->prev = tmp;
		}
		
		tmp_swap->next = tmp;
	 	tmp_swap->prev = t_prev;

		
		if (t_prev){
			t_prev->next = tmp_swap;
		}
		
		
	}
}
//Функции сравнения названия,цены, длины, времени, кол. людей
Node* compare_name(Node * tmp, Node *tmp_next, int opt){
	if (((strcmp(tmp->name, tmp_next->name)>=0) && (opt==1)) || ((strcmp(tmp->name, tmp_next->name)<0) && (opt==0))){
		return tmp;
	}
	else{
		return tmp_next;
	}
}

Node* compare_price(Node * tmp, Node *tmp_next, int opt){
	if (((tmp->price >= tmp_next->price) && (opt==1)) || ((tmp->price < tmp_next->price) && (opt==0))){
		return tmp;
	}
	else{
		return tmp_next;
	} 
}

Node* compare_length_way(Node * tmp, Node *tmp_next, int opt){
	if (((tmp->length_way >= tmp_next->length_way) && (opt==1)) || ((tmp->length_way < tmp_next->length_way) && (opt==0))){
		return tmp;
	}
	else{
		return tmp_next;
	} 
	
}
Node* compare_time(Node * tmp, Node *tmp_next, int opt){ 
	if (((tmp->time >= tmp_next->time) && (opt==1)) || ((tmp->time < tmp_next->time) && (opt==0))){
		return tmp;
	}
	else{
		return tmp_next;
	} 
}
Node* compare_places(Node * tmp, Node *tmp_next, int opt){//number_place_visited
	if (((tmp->people >= tmp_next->people) && (opt==1)) || ((tmp->people < tmp_next->people) && (opt==0))){
		return tmp;
	}
	else{
		return tmp_next;
	} 
	
}

