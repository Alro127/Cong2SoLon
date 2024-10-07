#include <iostream>
#include <string.h>
using namespace std;
void Insert(char s[], int n);
void Standard(char s1[], char s2[]);
void Compare(char s1[], char s2[]);
void Sum(char s1[], char s2[], char s3[]);
void Minus(char s1[], char s2[], char s3[]);
int main()
{
	char s1[100],s2[100],s3[100],s4[100];
	gets(s1);
	gets(s2);
	Standard(s1,s2);
	Compare(s1,s2);
	Sum(s1,s2,s3);
	puts(s3);
	Minus(s1,s2,s4);
	puts(s4);
	return 0;
}
void Insert(char s[], int n)
{
	int l=strlen(s);
	for (int i=0; i<n; i++)
		s[l+i]='0';
	s[l+n]='\0';
}
void Standard(char s1[], char s2[])
{
	strrev(s1);
	strrev(s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	if (l1>l2) Insert(s2,l1-l2); else 
	if (l2>l1) Insert(s1,l2-l1);
}
void Compare(char s1[], char s2[])
{
	int l=strlen(s1)-1; 
	while (l>=0 && s1[l]==s2[l]) l--;
	if (l>=0 && s1[l]<s2[l]) 
	{
		char s[100];
		strcpy(s,s1);
		strcpy(s1,s2);
		strcpy(s2,s);
	}
	return;
}
void Sum(char s1[], char s2[], char s3[])
{
	int l=strlen(s1);
	int tempt=0;
	for (int i=0; i<l; i++)
	{
		int x=(s1[i]-'0')+(s2[i]-'0')+tempt;
		s3[i]=x%10+'0';
		tempt=x/10;
	}
	if (tempt>0) 
	{
		s3[l]=tempt+'0';
		l++;
	}
	s3[l]='\0';
	strrev(s3);
}
void Minus(char s1[], char s2[], char s3[])
{
	int l=strlen(s1);
	int tempt=0;
	for (int i=0; i<l; i++)
	{
		int x=(s1[i]-'0')-(s2[i]-'0')-tempt;
		if (x<0) 
		{
			x=x+10;
			tempt=1;
		} else tempt=0;
		s3[i]=x%10+'0';
	}
	if (tempt>0) 
	{
		s3[l]=tempt+'0';
		l++;
	}
	s3[l]='\0';
	strrev(s3);
	while (s3[0]=='0' && strlen(s3)>1) 
		 for (int j=0; j<strlen(s3); j++) s3[j]=s3[j+1];
}
