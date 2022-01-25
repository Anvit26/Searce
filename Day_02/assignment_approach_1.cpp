#include<iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

#define s 1000000

class stack{
    private:
        int* stc;
        int top;
        int* st2;
        int tp;
    public:
        stack(){
            stc=new int[s];
            top=0;
            st2 = new int[s];
            tp = 0;
            st2[tp] = -1;
        }
        
        void push(int x){
            if(top==s-1){
                cout<<"stack overflow"<<endl;
                return;
            }
            stc[top++]=x;
            if(tp==0){
                st2[tp++] = x;
                return;
            }
            if(x >= st2[tp-1]){
                st2[tp++] = x;
            }
            return;
        }

        void pop(){
            if(top<0){
                cout<<"stack underflow"<<endl;
                return;
            }
            if(st2[tp-1]==stc[top-1]){
                tp--;
                top--;
                return;
            }
            top--;
            return;
        }

        int peek(){
            if(top==-1){
                return -1;
            }
            return stc[top];
        }

        int getMax(){
            if(tp==-1){
                return -1;
            }
                return st2[tp-1];
        }
        void printStacks(){
            cout<<"MAIN:";
            for(int i=0;i<5;i++){
                cout<<stc[i]<<" ";
            }
            cout<<endl;
            cout<<"MAX:";
            for(int i=0;i<5;i++){
                cout<<st2[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    
    stack st;
    int n = 10,i=0;
    vector<string> v =  {"1 90", "2", "1 20","2","1 26","1 20","2","3","1 91","3" };
    while(i<n){
        for(int j=0;j<v[i].size();j++){
            if(v[i][0]=='1'){
                string str =  v[i].substr(1, v[i].length());
                st.push(stoi(str));
            }
            if(v[i][0]=='2'){
                st.pop();
            }
            if(v[i][0]=='3'){
                cout<<st.getMax()<<endl;
            }
        }
        i++;
    }
    return 0;
}