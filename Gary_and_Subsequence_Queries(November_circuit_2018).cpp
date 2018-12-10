#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isSubSequence(string str1,string str2, int m, int n) 
{ 
   int j = 0;
   std::size_t found;
   found=str2.find(str1[j]);
   while(found!=std::string::npos)
   {
       if (str1[j] == str2[found]) 
       {
            j++;
       }
       found=str2.find(str1[j],found+1);
   }
   return (j==m); 
} 
int main()
{
    int n,q;
    unsigned int x,y,i,j;
    string s[100001];
    map<pair<int,int>,int> m;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    while(q--)
    {
        cin>>x>>y;
        if(m[make_pair(x,y)]==1 or m[make_pair(x,y)]==2)
        {
            if(m[make_pair(x,y)]==1)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else if(m[make_pair(y,x)]==1 or m[make_pair(y,x)]==2)
        {
            if(m[make_pair(y,x)]==1)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
        {
            if(s[x].length()<s[y].length())
            {
                if(isSubSequence(s[x],s[y],s[x].length(),s[y].length()))
                {
                    cout<<"Yes"<<endl;
                    m[make_pair(x,y)]=1;
                    m[make_pair(y,x)]=1;
                }
                else
                {
                    cout<<"No"<<endl;
                    m[make_pair(x,y)]=2;
                    m[make_pair(y,x)]=2;
                }
            }
            else if(s[x].length()>s[y].length())
            {
                if(isSubSequence(s[y],s[x],s[y].length(),s[x].length()))
                {
                    cout<<"Yes"<<endl;
                    m[make_pair(x,y)]=1;
                    m[make_pair(y,x)]=1;
                }
                else
                {
                    cout<<"No"<<endl;
                     m[make_pair(x,y)]=2;
                    m[make_pair(y,x)]=2;
                }
            }
            else
            {
                if(s[x]==s[y])
                {
                    cout<<"Yes"<<endl;
                    m[make_pair(x,y)]=1;
                    m[make_pair(y,x)]=1;
                }
                else
                {
                    cout<<"No"<<endl;
                    m[make_pair(x,y)]=2;
                    m[make_pair(y,x)]=2;
                }
            }
        }
        
    }
}
