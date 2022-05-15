#include <vector>
class Solution {
public:
    void solve(int level, string s, int n, string seq, set<string> &ans, int count, int &max)
    {
        if(count<0)
            return;
        if(level==n)
        {
            if(count==0)
            {
                ans.insert(seq);
                if(seq.size()>max)
                    max=seq.size();
            }
            return;
        }
        if(s[level]=='(')
        {
            seq.push_back(s[level]);
            solve(level+1,s,n,seq,ans,count+1,max); 
            seq.pop_back();
            
            solve(level+1,s,n,seq,ans,count,max);
        }
        else if(s[level]==')')
        {
            if(count>0)
            {
                seq.push_back(s[level]);
                solve(level+1,s,n,seq,ans,count-1,max);
                seq.pop_back();
            }
            
            solve(level+1,s,n,seq,ans,count,max);
        }
        else
        {
            seq.push_back(s[level]);
            solve(level+1,s,n,seq,ans,count,max);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        set<string> ans;
        string seq;
        int max=0;
        solve(0,s,n,seq,ans,0,max);
        
        set<string>::iterator itr;
        vector<string> fin;
        for(itr = ans.begin(); itr != ans.end(); itr++)
        {
            string temp=*itr;
            if(temp.size()==max)
                fin.push_back(temp);
        }
        return fin;
    }
};