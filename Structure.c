//create a queue
Queue* create_queue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->q_values = NULL;
    return q;
}
//create a new element
Element* create_element_N(Tree* node){
    Element* new_el = (Element*)malloc(sizeof(Element));
    new_el->Nodes = node;
    new_el->next = NULL;
    return new_el;
}

//add element to the queue
void enqueue(Queue* q,Node* node){
    Element *new_el = create_element_N(node);
    if(q->q_values != NULL){
        Element *old = q->q_values;
        while(old->next != NULL){
            old = old->next;
        }
        old ->next = new_el;
    }
    else{
        q->q_values = new_el;
    }
}
//check if an element is in the queue
int is_queue_empty(Queue* q){
    if(q != NULL){
        if(q->q_values == NULL){
            return 1; //empty
        }
        else{
            return 0; //not empty
        }
    }
    else{
        return -1; //the queue is NULL;
    }
}
//remove element from the queue
Node* dequeue(Queue* q){
    Node* remove_node = NULL;
    if(is_queue_empty(q) == 0){
        Element *temp = q->q_values;
        q->q_values = q->q_values->next;
        remove_node = temp ->Nodes;
        free(temp);
    }
    return remove_node;
}
