#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007ll
#define MP make_pair
#define X first
#define Y second
#define N 1000050
typedef long long LL;

struct Rec
{
	LL fx,tx,fy,ty;
}	r[N];

LL Pow(LL x,LL y)
{
	if (y==0) return 1;
	LL t=Pow(x,y/2);
	if (y&1) return t*t%mod*x%mod;
	return t*t%mod;
}

const LL div2=Pow(2,mod-2);
const LL div6=Pow(6,mod-2);

LL All(LL n,LL m)
{
	return (m*m%mod*(n-1)%mod*n%mod*(n+1)%mod+n*n%mod*(m-1)%mod*m%mod*(m+1)%mod)*div6%mod;
}

LL Sum1(LL x)
{
	return (x+1)*x%mod*div2%mod;
}

LL Sum2(LL x)
{
	return x*(x+1)%mod*(2*x+1)%mod*div6%mod;
}

LL Inout(LL fx,LL tx,LL fy,LL ty,LL n,LL m)
{
	LL mulx=(ty-fy+1)*m%mod*div2%mod;
	LL x2=2*(Sum2(tx)-Sum2(fx-1))%mod;
	LL x1=(-2*n-2)*(Sum1(tx)-Sum1(fx-1))%mod;
	LL x0=(n*n%mod+n)*(tx-fx+1)%mod;
	
	LL muly=(tx-fx+1)*n%mod*div2%mod;
	LL y2=2*(Sum2(ty)-Sum2(fy-1))%mod;
	LL y1=(-2*m-2)*(Sum1(ty)-Sum1(fy-1))%mod;
	LL y0=(m*m%mod+m)*(ty-fy+1)%mod;
	
	return (mulx*(x2+x1+x0)%mod+muly*(y2+y1+y0)%mod)%mod;
}

LL F(LL L,LL R,LL w)
{
	LL add=w%2==1?(w+1)*(w+1)%mod*div2%mod*L%mod*R%mod:0;
	LL t=w/2;
	LL xx=2*L%mod*R%mod*(w+1)%mod*t%mod*(t+1)%mod;
	LL yy=4*L%mod*R%mod*t%mod*(t+1)%mod*(t*2+1)%mod*div6%mod;
	return ((xx-yy+mod)%mod+add)%mod;
}

bool cmp1(Rec a,Rec b)
{
	return a.fx<b.fx;
}

bool cmp2(Rec a,Rec b)
{
	return a.fy<b.fy;
}

int main()
{
	LL n,m,p,i,sumx,cntx,sumy,cnty,sx,cx,sy,cy,ans,ans1,ans2,ans3,ans4,ans5;
    
    //freopen("grid.in", "r", stdin);
    //freopen("grid.out", "w", stdout);
    
	scanf("%lld%lld%lld",&n,&m,&p);
	ans1=All(n,m);
	ans2=ans3=ans4=ans5=0;
	for (i=1;i<=p;i++)
	{
		scanf("%lld%lld%lld%lld",&r[i].fx,&r[i].tx,&r[i].fy,&r[i].ty);
		(ans2+=Inout(r[i].fx,r[i].tx,r[i].fy,r[i].ty,n,m))%=mod;
		(ans3+=All(r[i].tx-r[i].fx+1,r[i].ty-r[i].fy+1))%=mod;
		(ans4+=F(r[i].fx-1,n-r[i].tx,r[i].ty-r[i].fy+1))%=mod;
		(ans4+=F(r[i].fy-1,m-r[i].ty,r[i].tx-r[i].fx+1))%=mod;
	}
	sort(r+1,r+p+1,cmp1);
	sumx=cntx=0;
	for (i=1;i<=p;i++)
	{
		cx=(r[i].tx-r[i].fx+1)*(r[i].ty-r[i].fy+1)%mod;
		sx=(r[i].fx+r[i].tx)*(r[i].tx-r[i].fx+1)%mod*div2%mod*(r[i].ty-r[i].fy+1)%mod;
		(ans5+=(sx*cntx%mod-sumx*cx%mod))%=mod;
		sumx+=sx;
		cntx+=cx;
	}
	
	sort(r+1,r+p+1,cmp2);
	sumy=cnty=0;
	for (i=1;i<=p;i++)
	{
		cy=(r[i].tx-r[i].fx+1)*(r[i].ty-r[i].fy+1)%mod;
		sy=(r[i].fy+r[i].ty)*(r[i].ty-r[i].fy+1)%mod*div2%mod*(r[i].tx-r[i].fx+1)%mod;
		(ans5+=(sy*cnty%mod-sumy*cy%mod))%=mod;
		sumy+=sy;
		cnty+=cy;
	}
	ans=((ans1-ans2+ans3+ans4+ans5)%mod+mod)%mod;
	printf("%lld\n",ans);
    
    return 0;
}
