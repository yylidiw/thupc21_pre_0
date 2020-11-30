#include<bits/stdc++.h>
#define MAXN 2500
using namespace std;
int N,M,A[MAXN+5],S[MAXN+5];
double C[MAXN+5][MAXN+5];
bool vis[MAXN+5][MAXN+5];
double calc(int i,int j)
{
	if ((j==0)||(i>N))return 0.0;
	if (i+j-1==N)return double(S[i])/2.0;
	if (vis[i][j])return C[i][j];
	C[i][j]=max((A[i]+calc(i+1,j)+calc(i+1,j-1))/2.0,calc(i+1,j));
	vis[i][j]=1;
	return C[i][j];
}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	for (int i=N;i>=1;i--)
		S[i]=S[i+1]+A[i];
	printf("%.6lf\n",S[1]-calc(1,M));
	return 0;
}
