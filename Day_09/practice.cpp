#include <iostream>
using namespace std;

int arr [1001]{0};

int memoization(const int n)
{
    if (n <= 1)
        return 1;
    if (arr[n] != 0)
        return arr[n];
    else
        arr[n] = memoization(n - 1) + memoization(n - 2);
    return arr[n];
}

int bottomUp(const int n)
{
    int arr1[n+1]{0};
    arr1[0] = 1;
    arr1[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        arr1[i] = arr1[i - 1] + arr1[i - 2];
    }
    return arr1[n];
}

int fib(){
    const int n = 5;
    arr[0]=arr[1]=1;
    cout << "Fibonacci series " << n << " is " << memoization(n)<<endl;
    cout << "Fibonacci series " << n << " is " << bottomUp(n);
    return 0;
}
 
int maxSum(int arr2[], int s)
{
   int max_till = arr2[0];
   int currmax = arr2[0];
 
   for (int i = 1; i < s; i++)
   {
        currmax = max(arr2[i], currmax+arr2[i]);
        max_till = max(max_till, currmax);
   }
   return max_till;
}
 
void maxSumDriver()
{
   const int s =10; 
   int arr2[s] =  {1,-3,4,-5,3,-2,3,-1,5,2};
   int sum = maxSum(arr2, s);
   cout << "Maximum sum " << sum;
}

int main()
{
    fib();
    cout<<endl;
    maxSumDriver();
}
