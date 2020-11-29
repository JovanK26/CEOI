#include <bits/stdc++.h>

using namespace std;
int n;
int ind[151];
int color[151];
int query(int m,int x)
{
    cout << m+1 <<' ';
    for(int i=0;i<m;i++)
    {
        cout << ind[i]+1 <<' ';
    }
    cout << x+1 << endl;
    int rez;
    cin >> rez;
    return rez;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int colors=1;
    for(int i=1;i<n;i++)
    {
        if(query(colors,i)==colors+1)
        {
            ind[colors]=i;
            color[i]=colors;
            colors++;
        }
        else
        {
            int l=0;
            int r=colors-1;
            int m;
            while(l<r)
            {
                m=(l+r)/2;
                if(query(m+1,i)==m+2)
                {
                    l=m+1;
                }
                else
                {
                    r=m;
                }
            }
            color[i]=l;
        }
    }
    cout << 0;
    for(int i=0;i<n;i++)
    {
        cout << ' ' << color[i]+1;
    }
    cout << endl;
    return 0;
}
