#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node * links[26];
    bool flag =false;
    bool containsKey(char ch){
        return links[ch-'a']!= NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch ,Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }


};
class Trie{
     public: 
     Node *root;
    
     Trie(){
        root = new Node();

     }
     void insert(string word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                 node->put(word[i], new Node());
            }
            node= node->get(word[i]);
        }
        node->setEnd();  
     }
     
};
int main(){
     string str ;
     cin>>str;
     int n = str.size();
     int k ;
     cin>>k;
     Trie trie;
     int mod = 1e9+7;
     while(k--){
        string s;
        cin>>s;
        trie.insert(s);
      }
        vector<int> dp(n+1,0);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            Node *node = trie.root;
            for(int j=i;j<n;j++){
                  if(!node->containsKey(str[j])){
                    break;
                  }
                  node = node->get(str[j]);
                  if(node->isEnd()){
                    dp[i] = (dp[i]%mod+dp[j+1]%mod)%mod;
                  }
            }
        }
        cout<<dp[0]<<endl;
  return 0;
}