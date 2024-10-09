#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+9;
int hp[N];
vector<int>hashed(N,0);
int canRemove[N];
const int mod = 1e9+7;

vector<int> getDistinctPF(int num){
    vector<int> ans;
    while(num>1){
        int highestPrime  = hp[num]; // it can be done by lowest prime also
        while(num%highestPrime == 0){
            num = num/highestPrime;
        }
        ans.push_back(highestPrime);

    }
    return ans;
}

int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   
    for(int i=2;i<N;i++){
         if (hp[i] == 0) {
            for (int j = i; j < N; j += i) {
                
                    hp[j] = i;
                
            }
        }
    }
    int n , q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        hashed[x]++;
    }
    for(int i=2;i<N;i++){
        if(hashed[i]>0){ // element is present in array
           for(ll j=i;j<N;j=j*i){
            canRemove[j]=1;
          
           }
        }
    }
    while(q--){
       int num;
       cin>>num;
       vector<int>pf = getDistinctPF(num);
       bool isPossible = false;
       for(int i=0;i<pf.size();i++){
        for(int j=i;j<pf.size();j++){ // iterate to every pair of distinct prime and find weather 
        // Q can be reduce to this two pair , morever loop will run atmost 100 times since in max prime a number can have till 1e5 is 10
            ll product = pf[i]*pf[j];
            if(i==j && num%product !=0  ) // since prime should be unique ans division should give integer
              continue;

            int toremove = num/product;  
            if(canRemove[toremove]==1 || toremove==1){ // || toremove==1 for case when num is made of only 2 prime factor
                isPossible = true;
                break;
            }
          
        }
          if(isPossible){ // since if possible then break from for loop also 
                break; 
            }
       }
       if(isPossible==true){
         cout<<"YES\n";
       }
       else{
        cout<<"NO\n";
       }
    }
  

 return 0;
}