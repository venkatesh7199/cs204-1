#include<iostream>
#define ll long long

ll string_size(char *s)
{
	ll t=0;
	while((*(s++))!='\0')
	{
		t++;
	}
	return t;
}

void string_reverse(char *a)
{
	ll n=string_size(a);
	char c;
	for(int i=0;i<n/2;i++)
	{
		c=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=c;
	}
}

void string_adder(char *a,char *b,int f,char *ans,int *flag)
{
	ll na=string_size(a);
	string_reverse(a);
	ll nb=string_size(b);
	string_reverse(b);
	ll mxx;
	if(na>nb) mxx=na;
	else mxx=nb;
	ll carry=f;
	int i;
	for(i=0;i<mxx;i++)
	{
		ll t=carry;
		if(i<na) t+=(a[i]-'0');
		if(i<nb&&f==0) t+=(b[i]-'0');
		else if(i<nb&&f==1) t+=(9-(b[i]-'0'));
		else if(f==1) t+=9;
		ans[i]=(t%10+'0');
		carry=t/10;
	}
	if(carry==0&&f==1)
	{
		*flag=1;
	}
	ans[i]='\0';
	string_reverse(ans);
	return ;
}

int main(void)
{
	static char a[1000000],b[1000000],ans[2000005];
    scanf("%s",a);
    scanf("%s",b);
    int flag=0;
    string_adder(a,b,0,ans,&flag);
    printf("%s",ans);

	return 0;
}