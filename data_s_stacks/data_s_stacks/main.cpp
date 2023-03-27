#include <iostream>
#include <stack>
using namespace std;
//array implementation of stacks///---
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;
void push(int i){
    if(top == MAX_SIZE-1){//checking stack overflow
        printf("ERROR: stack overflow\n");
        return;
    }
    top++;
    A[top] = i;
}
void pop(){
    if(top == -1){//checking the array is empty or not.
        printf("ERROR: the array is empty. so you cannot pop any thing");
        return;
    }
    top--;
}
int Top(){//return the top of the array.
    if(top == -1){return 0;}
    return A[top];
}
void print(){
    for (int i = 0; i < top + 1; i++) {
        std::cout<<A[i]<<std::endl;
    }
}
//end of the array implementation---///

//linked list implementation of stacks///---
struct Node{
    int data;
    Node * link;
};
struct Node * ust = NULL;

void linked_push(int x){
    Node * temp = (Node*)(malloc(sizeof(Node)));
    temp->data = x;
    temp->link = ust;
    ust = temp;
}
void linked_pop(){
    if(ust == NULL){
        printf("list is allready empty / linked_pop \n");
        return;
    }
    Node * temp = ust;
    ust = temp->link;
    free(temp);
}
void linked_print(){
    if(ust == NULL){printf("list is empty/ linked_print\n"); return;}
    Node * temp = ust;
    while (temp != NULL) {
        std::cout<<temp->data<<" - ";
        temp = temp->link;
    }
}

void reverse_linked(){
    Node * temp = ust;
    Node * nexTemp = NULL;
    while(temp != NULL){
        nexTemp = temp->link;
        if(temp == ust){
            temp->link = NULL;
            temp = nexTemp;
            continue;
        }
        temp->link = ust;
        ust = temp;
        temp = nexTemp;
    }
}
void reverse_string(char * str,int n){
    stack<char> S;
    for(int i = 0; i < n; i++){
        S.push(str[i]);
    }
    
    for(int i = 0; i < n ; i++){
        str[i] = S.top();
        S.pop();
    }
}
void mySol(char * C, int n){
    stack<char> stack;
    int i = 0;
    int j = -1;
    for (int i = 0; i < n; i++) {
        stack.push(C[i]);
        j++;
    }
    while(i < j){
        char I = C[i];
        C[i] = C[j];
        C[j] = I;
        i++;
        j--;
    }
}

struct Node * head;
struct Node * last;

void insert(int n){
    Node * temp = new Node();
    temp->data = n;
    if(head == NULL){
        head = temp;
        last = temp;
        return;
    }
    last->link = temp;
    last = temp;
}
void print_linked_list(){
    Node * temp = head;
    while (temp != NULL) {
        cout<<temp->data<<" - ";
        temp = temp->link;
    }
}

void reverse_linked_list(){
    stack<Node *> S;
    Node * temp = head;
    while (temp != NULL) {
        S.push(temp);
        temp = temp->link;
    }
    Node * temp2 = S.top();
    head = temp2;
    S.pop();
    while (!S.empty()) {
        temp2->link = S.top();
        S.pop();
        temp2 = temp2->link;
    }
    temp2->link = NULL;
}

//end of the linked list implementation of stacks---///

//check for balanced paranthese using stack///---
/*solution:
 => scan from left to right.
 => if opening symbol add it to a list.
 => if closing symbol remove it from list.
 => finally it should be return ampty list.*/
bool check_paranthese(char * C,int n){
    stack<char> S;
    for(int i = 0; i < n ; i ++){
        if(C[i] == '[' || C[i] == '{' || C[i] == '('){
            S.push(C[i]);
            }
        else if ((C[i] == ']' || C[i] == '}' || C[i] == ')') && i != 0){
            S.pop();
        }
        cout<<C[i]<<endl;
    }
    return S.empty();
}

//end of the check for balanced paranthese using stack---///
int main() {
    //char C[51];
    //printf("enter a string: ");
    //cin>>C;
    //reverse_string(C,strlen(C));
    //mySol(C, strlen(C));
    //cout<<C<<endl;
    char S[6] = {'(','(','(',')',')',')'};//this is not right.
    
    cout<<strlen(S)<<endl;//strlen function does not return right value;
    return 0;
}
