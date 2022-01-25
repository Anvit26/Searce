#include<iostream>
#include<stdio.h>
using namespace std;

#pragma region link-list
class node{
    public:
        int data;
        node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};

void addLast(node* &head,int x){
    node* newNode = new node(x);
    node* curr = head;
    if(head == NULL){
        head=newNode;
        return;
    }
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=newNode;
}

void addFirst(node* &head,int x){
    node* newNode = new node(x);
    newNode->next = head;
    head=newNode;
}

void addAfterElement(node* &head,int ele,int postEle){
    node* newNode = new node(ele);
    node* curr = head;
    if(head == NULL){
        cout<<"No element found "<<postEle<<endl;
        return;
    }
    while(curr->next!=NULL&&curr->data!=postEle){
        curr=curr->next;
    }
    if(curr->data!=postEle){
        cout<<"No element found "<<postEle<<endl;
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return;
}

void addBeforeElement(node* &head,int ele,int preEle){
    node* newNode = new node(ele);
    node* curr = head;
    
    if(curr == NULL){
        cout<<"No element found "<<preEle<<endl;
        return;
    }
    
    if(curr->data == preEle){
        newNode->next = head;
        head = newNode;
        return;
    }

    while(curr->next->next!=NULL&&curr->next->data!=preEle){
        curr=curr->next;
    }

    if(curr->next->data!=preEle){
        cout<<"No element found "<<preEle<<endl;
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return;
}

void deleteFirst(node* &head){
    if(head==NULL){
        return;
    }
    node* tmp = head;
    head=head->next;
    delete tmp;
}

void deleteLast(node* &head){
    if(head==NULL){
        return;
    }
    node* curr = head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    curr->next = NULL;
}

void deleteElement(node* &head, int ele){
    if(head==NULL){
        return;
    }
    node* curr = head;
    if(curr->data == ele){
        head = curr->next;
        return;
    }
    while(curr->next->next!=NULL&&curr->next->data!=ele){
        curr=curr->next;
    }
    curr->next = curr->next->next;
}

//Util Functions 
int countElement(node* head){
    int n = 0;
    while(head){
        n++;
        head=head->next;
    }
    return n;
}

int getMiddle(node* head){
    node* fast = head;
    node* slow = head;
    while(fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

void printLL(node* head){
    node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    return;
}

// Runner Function
void linkListRunner(){
    cout<<"\tRunning Link-list Functions"<<endl;
    node* head = NULL;
    addLast(head,5);
    addLast(head,6);
    addFirst(head,3);
    addAfterElement(head,4,6);
    addBeforeElement(head,3,4);
    deleteFirst(head);
    addFirst(head,1);
    deleteLast(head);
    addFirst(head,11);
    addFirst(head,12);
    addFirst(head,13);
    deleteElement(head,12);
    printLL(head);
    cout<<"\nNo. of elements: "<<countElement(head)<<endl;
    cout<<"Middle of Link-list: "<<getMiddle(head)<<endl;
    return;
}
#pragma endregion

#pragma region Stack
class stack{

};

void stackRunner(){

}
#pragma endregion

int main()
{
    linkListRunner();
    stackRunner();
    return 0;
}