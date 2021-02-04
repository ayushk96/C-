#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    char a[6]={'(','+','-','*','/','^'};
    int i;
    int ans=0;
    for(i=0;i<6;i++)
    {
        if(c == a[i])
            break;
    }
    if(i%2==1)
        i++;
    return i;
}
int main()
{
    int tt,i,n;
    string str,ans;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        cin>>str;
        stack <char> s;
        ans="";
        for(i=0;i<n;i++)
        {
            int temp=(int)str[i];
            //cout<<temp<<endl;
            if(str[i] == '(')
                s.push('(');
            else if(str[i] == ')' )
            {
                while(!s.empty() && s.top() != '(')
                {
                    ans=ans+s.top();
                    s.pop();
                }
                s.pop();
            }
            else if(temp>=65 && temp <=90)
            {
                ans+=str[i];
            }
            else
            {
                if(s.empty() || s.top() == '(' || ( prec(str[i])>prec(s.top()) ) )
                {
                    //cout<<"yes";
                    s.push(str[i]);
                }
                else
                {
                    while(!s.empty() && s.top() != '(' && (prec(str[i])<=prec(s.top())) )
                    {
                        ans=ans+s.top();
                        s.pop();
                    }
                    s.push(str[i]);
                }
            }
        }
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        cout<<ans<<endl;
    }
}