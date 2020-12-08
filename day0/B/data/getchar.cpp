#include<cstdio>
int main()
{
    char ch;
    int cn=0;
    while(ch=getchar(),1)
    {
        if(ch>='0'&&ch<='9'||ch==' '||ch=='\n'||ch=='.'||ch=='-'||ch=='+'||ch>='A'&&ch<='z')putchar(ch);
        //printf("%d\n",(int)ch);
        if(++cn==3000000)return 0;
    }
    return 0;
}