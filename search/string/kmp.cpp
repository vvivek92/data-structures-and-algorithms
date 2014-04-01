#include<iostream>
#include<vector>
#include<string>
using namespace std;


void construct_lps(string & pattern, vector<int> & lps) {
    lps[0]=0;
    for(int i=1;i<lps.size();i++) {
        int k=lps[i-1];
        while(pattern[i] != pattern[k] && k>0)
            k=lps[k-1];
        if(pattern[i]==pattern[k])
            k++;
        lps[i]=k;
    }
}

int find(string & pattern, string & text, vector<int> & lps) {
    int state=0;
    for(int i=0;i<text.size();i++) {
        if(state==4) {
            cout<<"found";
            state=lps[3];
        }
        else if(text[i]==pattern[state])
            state++;
        else
             if(state!=0)state=lps[state-1];
    }
}

int main(void) {
    string pattern="abab";
    string text="qwerababdf";
    vector<int> lps(pattern.size());
    construct_lps(pattern,lps);
    for(int i=0;i<4;i++)
        cout<<" "<<lps[i];
    find(pattern,text,lps);
    
}
