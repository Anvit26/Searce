#include<iostream>
using namespace std;

#pragma region Question_1

void q1(int* arr,int n){
    cout<<"Question 1"<<endl;
    int i=0;
    cout<<"\nArray: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    while(i<=n/2){
        int tmp = arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1] = tmp;
        i++;
    }
    cout<<"\nReverse: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return;
}
#pragma endregion

#pragma region Question_2
class node{
    public:
        int data;
        node* next;
        node(int x){
            data = x;
            next = NULL;
        }
};

void addLast(node* &head,int data){
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        return;
    }

    node* curr = head;
    node* newNode = new node(data);
    while(curr->next!=NULL){
        curr= curr->next;
    }
    curr->next = newNode;
}

void printList(node* head){
    cout<<"Print link-list"<<endl;
    node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}


void q2(){
    cout<<"\nQuestion 2"<<endl;
    node* head = NULL;
    addLast(head,5);
    addLast(head,4);
    addLast(head,3);
    addLast(head,2);
    addLast(head,1);

    printList(head);
}
#pragma endregion

int main()
{
    int s = 10;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    q1(arr,s);
    q2();
    return 0;
}