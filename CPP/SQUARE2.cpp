#include <iostream>

using namespace std;

bool THFirst(pair<int,int> T1, pair<int,int> T2, pair<int,int> K){
    if (K.first == T1.first){
        if (T1.second + T2.second + K.second == T1.first)
            return true;
        return false;
    }
    else if (K.second == T1.first){
        if (T1.second + T2.second + K.first == T1.first)
            return true;        
        return false;
    }
    else if (T1.second + T2.second == max(K.first,K.second) && min(K.first,K.second) == 2)
        return true;
    return false;
}

bool THSecond(pair<int,int> T1, pair<int,int> T2, pair<int,int> K){
    if (K.first == T1.second){
        if (T1.first + T2.first + K.second == T1.second)
            return true;
        return false;
    }
    else if (K.second == T1.second){
        if (T1.first + T2.first + K.first == T1.second)
            return true;        
        return false;
    }
    else if (T1.first + T2.first == max(K.first,K.second) && min(K.first,K.second) == 2)
        return true;
    return false;
}

bool THLast(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    if (b.first + c.first == a.first && b.second + c.second == a.second)
        return true;
    if (b.first + c.second == a.first && b.second + c.first == a.second)
        return true;
    if (b.first + c.second == a.second && b.second + c.first == a.first)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    pair<int,int> a, b, c;
    cin>>a.first>>a.second; 
    cin>>b.first>>b.second; 
    cin>>c.first>>c.second;
    if (a.first == b.first){
        if (THFirst(a,b,c)){
            cout<<"YES";
            return 0;
        }
    }
    else if (a.first == c.first){
        if (THFirst(a,c,b)){
            cout<<"YES";
            return 0;
        }
    }
    else if (b.first == c.first){
        if (THFirst(b,c,a)){
            cout<<"YES";
            return 0;
        }
    }
    else if (a.second == b.second){
        if (THSecond(a,b,c)){
            cout<<"YES";
            return 0;
        }
    }
    else if (a.second == c.second){
        if (THFirst(a,c,b)){
            cout<<"YES";
            return 0;
        }
    }
    else if (b.second == c.second){
        if (THFirst(b,c,a)){
            cout<<"YES";
            return 0;
        }
    }
    else if (THLast(a,b,c))
        cout<<"YES";
    cout<<"NO";
}