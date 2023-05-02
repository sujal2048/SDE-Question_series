#include<bits/stdc++.h>           //https://www.youtube.com/watch?v=4JstGzs6Q9I&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=84
using namespace std;
int main(){                             //time=nlogn
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a){              //for input & is used
        cin>>i;
    }
    multiset<int,greater<int>> s;
    vector <int> ans;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());      //multiset give's iterator at that element
    for(int i=k;i<n;i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
/*
int main(){                          //time=o(n);
     int n,k;cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a){              //for input & is used
        cin>>i;
    }
    deque<int> q;
    vector<int>  ans;
    for(int i=0;i<k;i++){                   //q me index of max
        while(!q.empty() and a[q.back()]<a[i]){           //max wala always front pe rahega deque ke
            q.pop_back();                    //accordingly observe that baad me ane wala max hi hum store kar
        }                                    // rahe kyuki further window me sirf uske select hone  ke chances hai
        q.push_back(i);                      //5 4 6 1 3
    }                                        //5...   5 4.....   6.....
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++){
        if(q.front()==i-k){                checking the index of max element if it id not element which is to be removed from deque
            q.pop_front();
        }
        while(!q.empty() and a[q.back()]< a[i]){
             q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);

    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}*/