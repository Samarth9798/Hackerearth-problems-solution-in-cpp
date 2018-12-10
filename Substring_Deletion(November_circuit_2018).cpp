#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    while(cin>>s)
    {
        ll i,j,k;
        char prev='\0';
        map<char,int> m;
        string sss="";
        string ss="";
        for(i=0;i<s.length();i++)
        {
            if(m[s[i]]==0)
            {
                sss=sss+s[i];
                m[s[i]]=1;
            }
            if(s[i]!=prev)
            {
                ss=ss + s[i];
            }
            prev=s[i];
        }
        int arr[ss.length()];
        int count;
        m.clear();
        count=0;
        int temp;
        int dp[30];
        for(i=ss.length() - 1;i>=0;i--)
        {
            if(m[ss[i]]==0)
            {
                count++;
                m[ss[i]]=1;
            }
            arr[i]=count; 
            dp[ss[i] - 97]=i; 
        }
        int l=sss.length();
        sort(sss.begin(),sss.end());
        string ans="";
        ll index;
        int flag;
        char c;
        std::string::size_type found;
        for(i=0;i<l;i++)
        {
            temp=0;
            for(j=0;j<sss.length();j++)
            {
                temp=0;
                flag=0;
                index=dp[sss[j] - 97];
                temp=arr[index];
                if(temp==sss.length())
                {
                    flag=1;
                    c=sss[j];
                    break;
                }
            }
            if(flag==1)
            {
                ans+=c;
                sss.erase(sss.begin()+j);
                found=ss.find_last_of(c);
                for(j=ss.length()-1;j>=index;j--)
                {
                    if(j<=found)
                    arr[j]-=1;
                    dp[ss[j]- 97]=j;
                }
            }
        }
        
        m.clear();
        cout<<ans<<endl;
    }
}
