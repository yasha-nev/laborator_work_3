#include "excursion.h"

Node* readFile(Node *head,char * argv[]){ //чтение из файла
	Node *tmp = head;
	
	FILE *f;
	if ((f=fopen(argv[1],"rb")) == NULL){
		return tmp;
	}

	while(!feof(f)){
		tmp = push(tmp);
		fread(&tmp->name, sizeof(tmp->name), 1, f);
		fread(&tmp->price, sizeof(tmp->price), 1, f);
		fread(&tmp->length_way, sizeof(tmp->length_way), 1, f);
		fread(&tmp->time, sizeof(tmp->time), 1, f);
		fread(&tmp->people, sizeof(tmp->people), 1, f);
	}
	if (tmp!=NULL){
		tmp = del(tmp,1);
	}

	fclose(f);
	return tmp;
}

int writeFile(Node *head, char * argv[]){ // запись в файл
	FILE *f;
	if ((f=fopen(argv[1],"wb")) == NULL){
		return 0;
	}

	Node *tmp = head;
	while (tmp != NULL){
		fwrite(&tmp->name, sizeof(tmp->name), 1, f);
		fwrite(&tmp->price, sizeof(tmp->price), 1, f);
		fwrite(&tmp->length_way, sizeof(tmp->length_way), 1, f);
		fwrite(&tmp->time, sizeof(tmp->time), 1, f);
		fwrite(&tmp->people, sizeof(tmp->people), 1, f);
		tmp = tmp->next;
	}

	fclose(f);
	return 0;
}
