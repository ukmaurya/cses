#include<bits/stdc++.h>
using namespace std;
vector<int> calLPS(string &pat){
        int n = pat.size();
        vector<int> lps(n,0);
        int prefix = 0;
        int suffix = 1;
        while(suffix<n){
            if(pat[prefix]==pat[suffix]){
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            }
            else{
                if(prefix==0){
                    lps[suffix]=0;
                    suffix++;
                }
                else{
                    prefix = lps[prefix-1];
                }
            }
        }
        return lps;
    }
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str ;
    cin>>str;
     vector<int> lps = calLPS(str);
     vector<int>ans;
     int n = str.size();
    int index = n-1;
    while(lps[index]>0){
     
        ans.push_back(lps[index]);
        index = lps[index]-1;
    }
     sort(ans.begin() , ans.end());
     for(int i=0;i<ans.size();i++){
             cout<<ans[i]<<" ";
     }
    return 0;
}