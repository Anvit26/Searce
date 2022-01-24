#include<iostream>
using namespace std;

#define s 100

// Stack
class stack{
    private:
        int* arr;
        int tp;
    public: 
        stack(){
            arr = new int[s];
            tp = -1;
        }

        void push(int n){
            if(tp==n-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arr[++tp]=n;
        }
        void pop(){
            if(tp==-1){
                cout<<"No element found"<<endl;
                return;
            }
            tp--;
            return;
        }
        int top(){
            if(tp==-1){
                cout<<"No element found"<<endl;
                return -1;
            }
            return arr[tp];
        }

        bool isEmpty(){
            return tp>-1?1:0;
        }

        bool isFull(){
            return tp==s?1:0;
        }
};

// Queue using stack
class queue{
    private:
        int* q;
        int front;
        int back;
    
    public:
    queue(){
        q = new int[s];
        front = back = -1;
    }

    void push(int n){
        if(back==s-1){
             cout<<"Queue Full"<<endl;
        }
        back++;
        q[back]=n;
        if(front ==-1){
            front++;
        }
    }

    void pop(){
        if(front>back||front==-1){
            cout<<"Empty queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front>back||front==-1){
            cout<<"Empty queue"<<endl;
            return -1;
        }
        return q[front];
    }

    bool isEmpty(){
        if(front>back||front==-1){
            return 1;
        }
        return 0;
    }

};

// Linked list
class node{
    public:
        int data;
        node* next;
    node(int n){
        data = n;
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

void addFirst(node* &head,int data){
    node* newNode = new node(data);
    if(head==NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void printList(node* head){
    cout<<"Print link-list"<<endl;
    node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}

// Queue using linked list 
class lqueue{
    private:
        node* front;
        node* back;
    public:
        lqueue(){
            front=NULL;
            back=NULL;
        }
        
        void push(int x){
            node* newNode = new node(x);

            if(front == NULL){
                front=newNode;
                back=newNode;
                return;
            }
            back->next= newNode;
            back = newNode; 
        }

        void pop(){
            if(front==NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
            node* prev = front;
            front=front->next;
            delete prev;
        }

        int peek(){
            if(front==NULL){
                cout<<"Queue is empty"<<endl;
                return -1;
            } 
            return front->data;
        }
        
        bool isEmpty(){
            if(front==NULL){
                return 1;
            }
            return 0;
        }
};



int main()
{
    // Stack
    #pragma region stack
    cout<<"\tStack"<<endl;
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.top()<<endl;

    //Reverse array element using stack
    cout<<"\tReverse Array using stack"<<endl;
    stack rev;
    int arr[5]{0};
    int i=0;
    cout<<"Array :";
    while(i<5){
        arr[i]=(i+1)*10;
        cout<<" "<<arr[i];    
        rev.push(arr[i]);
        i++;
    }
    i=0;
    while(i<5){
        arr[i]=rev.top();
        rev.pop();
        i++;
    }
    cout<<"\nReversed Array :";
    i=0;
    while(i<5){
        cout<<" "<<arr[i++];    
    }
    #pragma endregion

    // Queue
    #pragma region queue
    cout<<"\n\tQueue"<<endl;
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<"Is Empty:"<<q.isEmpty()<<endl;

    cout<<"\n\tQueue Using Linked List"<<endl;
    lqueue lq;

    lq.push(1);
    lq.push(2);
    lq.push(3);
    lq.push(4);
    lq.push(5);
    cout<<lq.peek()<<endl;
    lq.pop();
    cout<<lq.peek()<<endl;
    lq.pop();
    cout<<lq.peek()<<endl;
    lq.pop();
    cout<<lq.peek()<<endl;
    lq.pop();
    cout<<lq.peek()<<endl;
    cout<<"Is Empty:"<<lq.isEmpty()<<endl;
    lq.pop();
    cout<<"Is Empty:"<<lq.isEmpty()<<endl;

    #pragma endregion

    //Linked-list
    #pragma region linked-list
    cout<<"\tLink-list"<<endl;
    node* head = NULL;
    addLast(head,5);
    addLast(head,4);
    addLast(head,3);
    addLast(head,2);
    addLast(head,1);
    addFirst(head,1);
    printList(head);
    #pragma endregion 
    return 0;
}
