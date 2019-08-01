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
	if(f==0)
	{
		while(carry>0)
		{
			ans[i]=carry%10+'0';
			carry/=10;
			i++;
		}
	}
	ans[i]='\0';
	string_reverse(ans);
	string_reverse(a);
	string_reverse(b);
	return ;
}

void string_dividor(char *a,char*b,ll na,ll nb,char *ans1,char *ans2)
{
	char f[10][nb+5];
	char t[1000005];
	f[0][0]='\0';
	ll fn[10];
	fn[0]=0;
	int flag=0;
	for(ll i=1;i<10;i++)
	{
		string_adder(b,f[i-1],0,f[i],&flag);
		fn[i]=string_size(f[i]);
	}
	ans2[0]='\0';
	char temp[1000005];
	temp[0]='\0';
	for(ll i=0;i<na;i++)
	{
		ll ntt=string_size(temp);
		temp[ntt]=a[i];
		temp[ntt+1]='\0';
		for(ll j=9;j>=0;j--)
		{
			flag=0;
			string_adder(temp,f[j],1,ans2,&flag);
			if(flag==0)
			{
				ll nt=string_size(ans2);
				for(ll j=0;j<nt;j++)
				{
					temp[j]=ans2[j];
				}
				temp[nt]='\0';
				ans1[i]=j+'0';
				break;
			}
		}
	}
	ans1[na]='\0';
	return;
}

int main(void)
{
	static char a[1000005],b[1000005],ans1[1000005],ans2[1000005];
    scanf("%s",a);
    scanf("%s",b);
	ll na=string_size(a);
	ll nb=string_size(b);
    string_dividor(a,b,na,nb,ans1,ans2);
	char *t=ans1;
	while(*t=='0') t++;
	if(*t=='\0') printf("0\n");
    else printf("%s\n",t);
	t=ans2;
	while(*t=='0') t++;
	if(*t=='\0') printf("0\n");
    else printf("%s\n",t);

	return 0;
}