#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"
#include <string.h>
#include <time.h>


void output(char*file){

    int b,a,c;
    FILE *f,*t;
    f = fopen(file,"r+");
    t = fopen("Output.txt","w");
    while((c = fgetc(f)) != EOF ){
        if(c != 10){
            for(int i = 7; i>= 0;i--){
                a = c >> i;             //convert decimal into binary using bitwise operators
                if(a & 1){
                    b = 1;
                }
                else{
                    b = 0;
                }
                fprintf(t,"%d",b);
            }
        }
    }
    fclose(f);
    fclose(t);
}
int countchar(char*file){
    int cpt= 0,c;
    FILE *f = NULL;
    f = fopen(file,"r");
    while((c = fgetc(f)) != EOF ){
        if(c != 10){
            cpt++;
        }
    }
    fclose(f);
    return cpt;
}

List* create_element(char c){
    List* new;
    new=(List*)malloc(sizeof(List));
    new->data = 1;
    new->c = c;
    new->next = NULL;
    return new;
}

List* list_carac(char* file){
    char c;
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
            else if(temp->next==NULL){
                temp->next = create_element(c);
            }
        }
    }
    fclose(f);
    return list_car;
}


void print_list(List* l){
    if(l != NULL){
        printf("%d->", l->data);
        printf("%c\n",l->c);
        print_list(l->next);
    }
    else{
        printf("X\n");
    }   
}

void list_remove(List** l, int n){
    if(l == 0 || (*l) == 0){return;}

    List* buffer = *l, * temp = 0;
    int count = 0;

    while(buffer->next != 0 && count==0)
    {
        if (buffer->data == n){
            temp = buffer;
            *l = (*l)->next;
            free(temp);
            count+=1;
        }
        else if(buffer->next->data == n && count == 0)
        {
            temp = buffer->next->next;
            free(buffer->next);
            buffer->next = temp;
            count+=1;
        }else{
            buffer = buffer->next;
        }
        
    }

    if ((*l)->data == n && count==0)
    {
        buffer = *l;
        *l = (*l)->next;
        free(buffer);
    }
}
    
List* smallest(List *l){
    List* temp, *tem;
    int min=10000000, pos=0, count=0;
    temp = l;
    while(temp!=NULL){
        if (min>temp->data){
            min = temp->data;
            pos = count;
        }
        count+=1;
        temp=temp->next;
    }
    temp = l;
    for (int i=0; i<pos; i++)
        temp = temp->next;
    tem=create_element(temp->c);
    tem->data = temp->data;
    return tem;
}

Tree* create_element_T(){
    Tree* new;
    new = (Tree*)malloc(sizeof(Tree));
    new->poids = 0;
    new->left = NULL;
    new->right = NULL;
    new->c = '0';
    return new;
}

Tree* create_huffman(List* element){
    Tree* root, *root2;
    List* temp;
    temp = element;
    root = create_element_T();

    root->right = create_element_T();
    root->right->poids = temp->data;
    root->right->c = temp->c;
    temp=temp->next;

    root->left = create_element_T();
    root->left->poids = temp->data;
    root->left->c = temp->c;
    root->poids = root->left->poids + root->right->poids;
    temp=temp->next;

    while (temp != NULL){
        root2 = create_element_T();
        root2->right = root;

        root2->left = create_element_T();
        root2->left->poids = temp->data;
        root2->left->c = temp->c;
        temp = temp->next;
        root2->poids = root2->left->poids + root2->right->poids;
        root = root2;
        balance(&root);
    }
    return root;
}

void Dico(Tree* root, char* s, FILE* dico){
    if (root!=NULL){
        concatenate(s,'0');
        Dico(root->left, s, dico);
        decon(s);
        concatenate(s,'1');
        Dico(root->right,s,dico);
        decon(s);
        if (root->left == NULL && root->right == NULL){
            fprintf(dico, "%c%s\n",root->c, s);
        }
    }
    
}

int tree_depth(Tree* tree){
    if (tree == NULL){
        return 0;
    }
    else{
        int dl = tree_depth(tree->left);
        int dr = tree_depth(tree->right);

        if (dl > dr){
            return dl + 1;
        }
        else{
            return dr + 1;
        }
    }
}

int bf(Tree* tree){
    if(tree == NULL){
        return 0;
    }
    else{
        return tree_depth(tree->right) - tree_depth(tree->left);
    }
}

void right_rotation(Tree** tree){
    if(*tree != NULL){
        Tree* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void left_rotation(Tree** tree){
    if(*tree != NULL){
        Tree* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}

void balance(Tree** tree){
    if (*tree != NULL){
        balance(&((*tree)->left));
        balance(&((*tree)->right));

        int balance_factor = bf(*tree);
        if(balance_factor <= -2){//Left - ????
            if(bf((*tree)->left) > 0){// Left - Right
                left_rotation(&((*tree)->left));
            }
            right_rotation(tree);// Left-Left
        }
        else if(balance_factor >= 2){//Right - ????
            if(bf((*tree)->right) < 0){// Right - Left
                right_rotation(&((*tree)->right));
            }
            left_rotation(tree);// Right-Right
        }
    }
}

void print_tree(Tree* tree){
    if (tree != NULL){
        if (tree->c != '0')
            if (tree->right == NULL && tree->left == NULL)
        print_tree(tree->left);
        print_tree(tree->right);
        
    }
}

void concatenate(char* s, char bit){
    int i=0;
    while (s[i] != '\0')
        i+=1;
    s[i]=bit;
    s[i+1]='\0';
}

void decon(char* s){
    int len=strlen(s);
    s[len-1] = '\0';
}

void translate(FILE* dico, char* s){
    rewind(dico);
    char c;
    char bit[1000];
    FILE* texte = NULL;
    FILE* output = NULL;
    texte = fopen(s, "r");
    output = fopen("OutputHuffman.txt", "w+");
    while ((c=fgetc(texte))!=EOF){
        while (c!=fgetc(dico)){}
        fscanf(dico, "%s", bit);
        //printf("%c %s\n",c, bit);
        fprintf(output, "%s", bit);
        rewind(dico);
    }
    fclose(texte);
    fclose(output);
}

void compress_file(char* name){
    FILE* dico = NULL;
    dico = fopen("dico.txt", "w+");
    int test, test2;
    output(name);
    test = countchar("Output.txt");
    printf("%d\n",test);

    List* list_car;
    list_car = list_carac(name);

    List* sorted_list, *temp;
    sorted_list = smallest(list_car);
    list_remove((&list_car), sorted_list->data);
    temp = sorted_list;
    while (list_car->next != NULL){
        temp->next = smallest(list_car);
        list_remove((&list_car), temp->next->data);
        temp = temp->next;
    }
    temp->next = list_car; 
    list_remove((&list_car), temp->data);

    Tree* root;
    char* s = malloc(sizeof(*s)*16);
    s[0]='\0'; 
    root = create_huffman(sorted_list);

    //balance(&root);
    Dico(root,s,dico);
    print_tree(root);
    printf("poids : %d\n", root->poids);

    translate(dico, name);
    test2=countchar("OutputHuffman.txt");
    printf("%d",test2);

    int coef = 100 - (test2*100)/test;
    printf("\ncoef of reduction : %d percent", coef);


    free(s);
    fclose(dico);
}