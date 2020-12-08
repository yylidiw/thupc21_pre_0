#include<bits/stdc++.h>
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

int x[111111];
double f[2555][2555];
int g[2555][2555];
int main()
{
    int n=io::F(),m=io::F();
    double sum=0;
    assert(1<=n&&n<=2500);
    assert(1<=m&&m<=n);
    for(int i=1;i<=n;++i)x[i]=io::F(),assert(x[i]>=1&&x[i]<=50000),sum+=x[i];
    std::sort(x+1,x+n+1);
    for(int i=n;i;--i)
        for(int j=m;j;--j)
        {
            f[i][j]=dmax(f[i+1][j],(x[i]+f[i+1][j]+f[i+1][j-1])/2);
            g[i][j]=f[i+1][j]>(x[i]+f[i+1][j]+f[i+1][j-1])/2;
            assert(!(g[i][j]==0&&g[i][j+1]==1));
        }
    printf("%.10lf\n",sum-f[1][m]);
    return 0;
}