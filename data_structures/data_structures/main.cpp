#include <iostream>

//singly linked lists---///
struct Node{
    int data;
    Node * next;
};

//1
/*Node * insert(int x, Node * head){
    Node * temp = (Node*)malloc(sizeof(Node)); //creating a new node.
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}
void print(Node * head){

    std::cout<<"list is: "<<std::endl;;
    while(head != NULL){
        std::cout<<head->data<<std::endl;
        head = head->next;
    }
}*/


void print(Node * head){
    Node * temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" - ";
        temp = temp->next;
    }
}

Node * insert(Node * head,int data, int index){
    Node * temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(index == 1){
        temp1->next = head;
        head = temp1;
        return head;
    }
    Node * temp2 = head;
    for(int i = 0; i < index-2 ; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return NULL;
}

Node * deleteElement(Node* head ,int index){
    Node * temp = head;
    if(index == 1){
        head = temp->next;
        free(temp);
        return head;
    }
    for(int i = 0; i < index -2; i++){
        temp = temp->next; //going one behind step the delete object.
    }
    Node * del = temp->next; //the node which we want to delete.
    temp->next = del->next;
    free(del);
    return NULL;
}

void recursion_print(Node * p){
    if(p == NULL){
        return; // exit from function;
    }
    std::cout<<p->data<<" - ";
    recursion_print(p->next);
}

void recursion_reverse_print(Node * temp){
    if(temp == NULL)return;
    recursion_reverse_print(temp->next);
    std::cout<<temp->data<<" - ";
    
}

//reversing the link list
Node * reverseList(Node * head){
    Node * prev,* current,* next;
    current = head;
    prev = NULL;;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/*Node * reverse_list_recursion(Node * temp){
    Node * head = NULL;
    if(temp->next == NULL){
        head = temp;
        return head;
    }
    reverse_list_recursion(temp->next);
    Node * q = temp->next;
    q->next = temp;
    temp->next = NULL;
    if(temp->next != NULL){
        return NULL;
    }
    return head;
}*/
//end of the singly linked list ---///

//doubly linked lists---///
struct NODE{
    int data;
    NODE * next;
    NODE * prev;//store the previos node, so we can easily reverse the list whenever we want.
};

struct NODE * Head;

NODE * getNewNode(int i){
    NODE * newNode = new NODE();
    newNode->data = i;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int i){
    NODE * temp = getNewNode(i);
    if(Head == NULL){
        Head = temp;
        return;
    }
    Head->prev = temp;
    temp->next = Head;
    Head = temp;
}
void insertLast(NODE * node){
    NODE * temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    node->next = NULL;
}

void insertAtTail(int i){
    NODE * newNode = getNewNode(i);
    insertLast(newNode);
}

void print_d(){
    NODE * temp = Head;
    while(temp != NULL){
        std::cout<<(*temp).data<<" - ";
        temp = temp->next;
    }
}
void reverse_print_d(){
    NODE * temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        std::cout<<temp->data<<" - ";
        temp = temp->prev;
    }
}

int main(){
    insertAtHead(3);
    insertAtTail(4);
    insertAtTail(10);
    insertAtTail(31);
    insertAtHead(1);
    insertAtHead(311);
    
    print_d();
    printf("\n");
    reverse_print_d(); 
    /*printf("\n");
    reverse_print_d();
    return 0;*/
}
