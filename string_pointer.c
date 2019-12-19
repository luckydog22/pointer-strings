#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char ch;
	int count1;
	struct node  *next;
}node_t;
int main()
{
	char a[] =" fffff";
	int i,j;
	int n=sizeof(a)/sizeof(char)-1;
	int count;
	int flag=0;
	node_t *h = (node_t *)malloc(sizeof(node_t));
	h->next = NULL;
	node_t *p = h;
	node_t *new;

	for(i=0;i<n;i++)
	{
		count=1;
		if(flag)
		{
			if(a[i]=='0')
			{
				continue;
			}
		}
		for(j=1+i;j<n;j++)
		{
			if(a[i]==a[j])
			{	
				count++;

				a[j]='0';
				
			}
		}
		new=(node_t *)malloc(sizeof(node_t));
		new->ch = a[i];
		new->count1 = count;
		new->next = p->next;

		p->next = new;

		p = new;
		flag=1;

	}
	p = h;
	p = p->next;
	char zm = p->ch ;
	int cs = p->count1;
	while(p!=NULL)
	{
		if(cs<p->count1)
		{
			zm = p->ch;
			cs = p->count1;
		}
		p=p->next;
	}
	printf("zi mu:%c\nci shu:%d\n",zm,cs);
}
