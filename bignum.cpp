#include<stdio.h>
#include<string.h>
int main()
{
	/* a,b�洢������m�洢�˻� */
   int a[1000],b[1000],m[1000],la,lb,lm,i,j; 
   char na[500],nb[500];
	/*������a,b,m����*/
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   memset(m,0,sizeof(m));
	/*���ַ�������ʽ��������*/
   scanf("%s%s",na,nb);
   la=strlen(na);
   lb=strlen(nb);
   /*���ַ�������*/
   for(i=0;i<la;i++)
   		a[i]=na[la-i-1]-'0';
   for(j=0;j<lb;j++)
   		b[j]=nb[lb-j-1]-'0';
	/*ѭ������*/
   for(i=0;i<la;i++)
   		for(j=0;j<lb;j++)
      	{
    		m[i+j]=m[i+j]+a[i]*b[j];
          	m[i+j+1]+= m[i+j]/10;
          	m[i+j]%=10;
      	}
	lm=la+lb;
   while(!m[lm])lm--;	/*����˻���ʵ�ʳ���*/ 
   for(i=lm;i>=0;i--)
   		printf("%d",m[i]);
   return 0;
}
