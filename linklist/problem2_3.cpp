#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* deleteNthFromEnd(Node* head,int n){
    Node* first = head;
    Node* second = head;
    for(int i = 0;i < n;i++)
        first = first->next;
    if(first == NULL){
        Node* temp = head;
        head = head ->next;
        delete temp;
        return head;
    }
    while(first->next != NULL){
        first = first->next;
        second = second->next;
    }
    Node* temp = second->next;
    second->next = second->next->next;
    delate temp;
    return head;
}
void traverse(Node* head){
    while(head != NULL){
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
} 
int main(){
    Node* first = new Node{1,NULL};
    Node* second = new Node{2,NULL};
    Node* third = new Node{3,NULL};
    Node* fourth = new Node{4,NULL};
    Node* fifth = new Node{5,NULL};

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    first = deleteNthFromEnd(first,2);
    traverse(first);
    return 0;
}