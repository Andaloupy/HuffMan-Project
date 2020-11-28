#include "dictionary.h"
/*
Element* create_Element(int data, char let){
    Element* temp = (Element*)malloc(sizeof(Element));
    temp->data->character = let;
    temp->data->occurences = data;
    temp->next = NULL;

    return temp;
}

Element* create_Element2(char let){
    Element2* temp = (Element2*)malloc(sizeof(Element2));
    temp->data = let;
    temp->next = NULL;
    return temp;
}*/

/*
Element* occurences(char*file){
    int cpt = countchar(file),c,count,check;
    char ch,ui;
    FILE *f;
    f = fopen(file,"r+");
    Element* l = (Element*)malloc(sizeof(Element)),*new_el;

    while(cpt){
        count = 0;
        check = 0;

        while((c = fgetc(f)) != EOF ){
            if(check == 0){
                ch = (char)c;
                check = 1;
                myel = create_Element2(ch);
                myel->next =
            }
            if(c != 10 ){

                count++;

                new_el = create_Element(count,ch);
                cpt--;

            }


    }
    return l ;
}*/

/*
List* create_element(char c){
    List* ne;
    ne=(List*)malloc(sizeof(List));
    ne->data->occ = 1;
    ne->data->c = c;
    ne->next = NULL;
    return ne;
}

void print_list(List* l){
    if(l != NULL){
        printf("%d->", l->data->occ);
        printf("%c\n",l->data->c);
        print_list(l->next);
    }
    else{
        printf("X\n");
    }
}*/

void print_list(List* l){
    if(l != NULL){
        printf("%d->%c\n", l->data,l->c);
        //printf("%c\n",l->c);
        print_list(l->next);
    }
    else{
        printf("X\n");
    }
}

List* create_element(char c){
    List* ne;
    ne=(List*)malloc(sizeof(List));
    ne->data = 1;
    ne->c = c;
    ne->next = NULL;
    return ne;
}

List* list_carac(char* file){
    int c;
    List* list_car;
    FILE *f = NULL;
    f = fopen(file,"r");
    c = fgetc(f);
    list_car=create_element(c);
    while((c = fgetc(f)) != EOF ){
        if (list_car!=NULL){
            List *temp = list_car;
            while(temp->c != c && temp->next != NULL){
                temp=temp->next;
            }
            if (temp->c == c){
                temp->data+=1;
            }
            else if(temp->next==NULL && c !=10){
                temp->next = create_element(c);
            }
        }
    }
    fclose(f);
    return list_car;
}

Node* create_node(int val,char ch ){
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->occurence = val;
    tree->ch = ch;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

int minimum(List*l){
    int  min = l->data;
    while(l != NULL){
        if(min > l->data){
            min = l->data;

        }
        l = l->next;

    }
    return min;
}

int small(List*l,int diff){
    List* temp = l;
    int small = 0,index = 0,min = l->data;
    while(l != NULL){
        if(min > temp->data && diff != index){
            min = temp->data;
            small = index;
        }
        index++;
        temp = temp->next;
    }

    return small;
}

Node* create_huffman_tree(List* l){

    int min1,min2;

    return tree;

}


List* delete_element(List*l,int n){
    if(l == NULL){
        return NULL;
    }

    if(l->data == n){
        List *temp;
        temp = l->next;
        free(l);
        return temp;
    }
     l->next = delete_element(l->next,n);
    return l;
}

