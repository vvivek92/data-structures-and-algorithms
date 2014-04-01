//finding window in S in which all characters from T reoccur
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

string find_win(string &s, string &t) {
    unordered_map<char,int> hash_t;
    unordered_map<char,int> hash_s;
    string p="LOL";
    int count=0;
    for(int i=0;t[i]!='\0';i++) {
        if(hash_t.find(t[i])==hash_t.end()) {
            hash_t[t[i]]=1;
            hash_s[t[i]]=0;
        }
        else
            hash_t[t[i]]++;
    
        count++;
    }
    int temp_cnt=0;
    int start=0,end=0;
    int i;
    for( i=0;s[i]!='\0' && temp_cnt<count;i++) {
        if(hash_t.find(s[i]) != hash_t.end()) {
           hash_s[s[i]]++;
           end=i;
           if(hash_s[s[i]]<= hash_t[s[i]])
               temp_cnt++;
        }
    }
    if(temp_cnt<count) return p;
    
    for(;s[i]!='\0';i++) {
        if(hash_t.find(s[i]) != hash_t.end()) {
            end=i;
            hash_s[s[i]]++;
            
            for(;start <=i ;start++) {
                if(hash_t.find(s[start])==hash_t.end())
                    ;
                else if(hash_s[s[start]] > hash_t[s[start]])
                   { hash_s[s[start]]--;cout<<start<<endl;}
                else
                    break;
                  
            }
        }
    }
    p = s.substr(start,end-start+1);
    return p;

}
    


int main(void) {
    string s="this is a test string";
    string t = "tist";
    cout<< endl<<find_win(s,t);


}

