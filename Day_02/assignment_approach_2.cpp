#include<iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

#define s 1000000

class stack{
    private:
        int* arr;
        int top;
        int maxEle;
    public:
        stack(){
            arr=new int[s];
            top=0;
            maxEle=-1;
        }
        
        void push(int x){
            if(top>s-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            if(top==0){
                maxEle = x;
                arr[top]=x;
                top++;
                return;
            }
            if(x>maxEle){
                arr[top]=(2*x)-maxEle;
                maxEle=x;
            }else{
                arr[top]=x;
                top++;
            }
            return;
        }

        void pop(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            if(arr[top]>maxEle){
                maxEle = 2*maxEle - arr[top];
            }
            top--;
            return;
        }

        int peek(){
            if(top==-1){
                return -1;
            }
            return arr[top];
        }

        int getMax(){
            return maxEle;
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