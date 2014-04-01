/*
build finite_automata
O( m*m*m*( E+1))  where E is size of alphabet
*/
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int prefix_pattern_suffix_text(string &pattern,int k,int state,char c) {
    if(k==0) return 1;
    if(pattern[k-1] != c) return 0;
    int j=state-1;
    int i;
    for(i=k-2;i!=-1 && pattern[i] == pattern[j] ;i--) {
        j--;    
    }
    if(i==-1) return 1;
    else return 0;   
}

void build_fsa(string & pattern, vector<vector<int> > & fsa,vector<char> & alphabet ) {
    for(int i=0;i<fsa.size();i++) {
        for(int j=0;j<fsa[0].size();j++) {
           int k= min(static_cast<int>(fsa.size()), i+1); 
           cout<<k;
           for(;;k=k-1){
               if(prefix_pattern_suffix_text(pattern,k,i,alphabet[j])){
                   fsa[i][j]=k;
                   break;
               }
           }
        }
    }
}

int main(void) {
    string pattern = "ababaca";
    vector<vector<int> > fsa(pattern.size()+1,vector<int>(3,0));
    vector<char> alphabet={'a','b','c'};   
    build_fsa(pattern,fsa,alphabet);
    
    for(int i=0;i<fsa.size();i++) {
        cout<<endl;
        for(int j=0;j<fsa[0].size();j++) {
            cout<<fsa[i][j]; 
        }

   }
   string text="abbcaab";
   text.append(pattern);
   text.push_back('c');
   int state=0;
   for(int i=0; i<text.size();i++) {
       state=fsa[state][text[i] -'a'];
       if(state==7) break;
   }
   cout<<"The state is "<<state;
   

}
