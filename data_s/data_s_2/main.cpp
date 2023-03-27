#include <iostream>
//#include <stack>


/*infix postfix prefix
 
 ///---profix---///
 int evalutePostFix(char * exp){
    create stack S;
    for(i = 0; i < len(exp); i++){
        if(exp[i] == operand){
            S.push(exp[i]);
        }
        else if(exp[i] == operator){
             op1 = S.pop();
             op2 = S.pop();
             res = perform(exp[i],op1,op2);
             S.push(res);
        }
    }
    return S.top();
 }
 */

//--introduction to QUEUEs--//

    //array of int imp.
int A[10];
int front = -1;
int rear = -1;

bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if(rear == std::size(A)-1){
        return true;
    }
    return false;
}

void enQueue(int x){
    if(isFull() == 1){
        printf("the queue is full\n");
        return;
    }
    else if (isEmpty() == 1){
        rear = 0; front = 0;
    }
    else{                                   //there are some big problems in this algorhitm but fine.
        rear ++;
    }
    A[rear] = x;
}

void deQueue(){
    if(isEmpty() == 1){
        printf("the list is empty");
        return;
    }
    else if(rear == front){
        front = -1; rear = -1;
         
    }
    else{
        A[front] = 0;
        front++;
    }
}

void printQueue(){
    for (int i = 0; i < std::size(A); i++){
        std::cout<<A[i]<<" - ";
    }
}
      //end of the array queue imp.

//linked list imp. Queue
struct Node{
    int data;
    Node * next;
};

Node * Rear;
Node * Front;

void enQueue_linked(int x){
    Node * temp  = new Node();
    temp->data = x;
    if(Rear == NULL && Front == NULL){
        Front = temp;
        Rear = temp;
        return;
    }
    Rear->next = temp;
    Rear = temp;
}
void deQueue_linked(){
    if(Front == NULL){printf("the list is empty.\n"); return;}
    else if(Front == Rear){
        Front = NULL;
        Rear = NULL;
        return;
    }
    Node * temp = Front;
    Front = Front->next;
    free(temp);
}

int Queue_top(){
    return Front->data;
}

void print_Q_L(){
    Node * temp = Front;
    if(temp == NULL){printf("the list is empty :/\n"); return;}
    while (temp != NULL) {
        std::cout<<temp->data<<" - ";
        temp = temp->next;
    }
}
//end of the linked list imp. Queue


int main() {

    return 0;
}

