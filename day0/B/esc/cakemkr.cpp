#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
    int F()
    {
        int n=0,F=0;
        char ch;
        while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
        ch=='-'?F=1:n=ch-'0';
        while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
        return F?-n:n;
    }
}
int R(int l,int r)
{
    return rand()%(r-l+1)+l;
}
int main()
{
    srand((unsigned long long)(new char));
    int n=R(2,10),m=R(1,n-1);
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;++i)
        printf("%d ",R(1,100));
    return 0;
}