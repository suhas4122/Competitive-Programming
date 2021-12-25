#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n, bool f = 1)
{
    if(f) n++; 
    string s = to_string(n);
    ll ns = s.length(); 
    for(int i =0; i< ns-1; i++)
    {
        if(s[i]==s[i+1])
        {
            if(s[i]=='9')
            {
                if(i==0)
                {
                    string ans = "1";
                    for(int i =0; i< s.length(); i++)
                    {
                        if(i%2) ans+='1';
                        else ans+='0'; 
                    }
                    return solve(stoll(ans), 0); 
                }
                else
                {
                    s[i-1]++; 
                    for(int j=i; j< ns; j++)
                    {
                        if ((j - i) % 2)
                            s[j] = '1';
                        else
                            s[j] = '0';
                    }
                    return solve(stoll(s), 0);
                }
            }
            else
            {
                s[i+1]++; 
                for(int j=i+2; j< ns; j++)
                {
                    if((j-i-2)%2) s[j]='1';
                    else s[j]='0'; 
                }
                return solve(stoll(s), 0); 
            }
            
        }
    }
    return n; 
}

int main(){
    ll n;
    cin >> n;
    cout << solve(n) << "\n";
}