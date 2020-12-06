typedef struct List{
    char c;
    int data;
    struct List *next;
}List;


typedef struct Node{
    char c;
    int poids;
    struct Node* left;
    struct Node* right;
}Node;

typedef Node Tree;

typedef struct Element{  //it should be a list but I want to keep the old data structure for the moment
    Tree* Nodes;
    struct Element* next;

}Element;

typedef struct Queue{
    Element* q_values;
}Queue;
