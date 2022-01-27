#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int avgEffecientTime(vector<pair<int,int>>at,int n){
    sort(at.begin(), at.end());
    int sum = 0;

    set<pair<int,int>> pq;
    int t = at[0].first;
    int j = 0;
    while (j < n || pq.size()) {
        while (j < n && at[j].first <= t) {
            pq.insert(pair<int,int>(at[j].second, j));
            ++j;
        }
        if (pq.empty()) {
            t = at[j].first;
        } else {
            int i = pq.begin()->second;
            pq.erase(pq.begin());
            t += at[i].second;
            sum += t-at[i].first;
        }
    }
    return sum/n;
}

int main() {
    cout<<"Enter No. of customer : ";
    int n;
    cin >> n;
    vector<pair<int,int>> at(n);

    int i = 0;
    while(i<n){
        cout<<endl<<"Enter Arival Time: ";
        cin>>at[i].first;
        cout<<endl<<"Enter Waiting Time: ";
        cin>>at[i].second;
        i++;
    }

    cout<<"Minimum average waiting time: "<<avgEffecientTime(at,n)<<endl;

    return 0;
}