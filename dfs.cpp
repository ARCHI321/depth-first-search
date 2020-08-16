#include<stdio.h>
#include<stdlib.h>

int n,s,**a,i,j,*nodes,*visited,*st,*dfs,top=-1,dfs_pos=0;

void push(int ele)
{	
	st[++top] = ele;
}

int pop()
{
	return(st[top--]);
}

int peek()
{
	return(st[top]);
}

void unvisited(int c)
{
	int pos;
	for(int i=0;i<n;i++)
	{
		if(nodes[i] == c)
		{
			pos = i;
			break;
			
		}
	}
    visited[pos] = 1;
}
	
int returnpos(int c)
{
	int pos;
	for(int i=0;i<n;i++)
	{
		if(nodes[i] == c)
		{
			pos = i;
			break;
			
		}
	}
	
	return (pos);
}


void fillstack(int pos)
{	
int flag = 0;
	for(int i=0;i<n;i++)
	{

		if(a[pos][i] == 1 && visited[i] == 0)
		{	

			dfs[dfs_pos++] = nodes[i];
			push(nodes[i]);
			unvisited(nodes[i]);
			a[pos][i] =2;
			a[i][pos] =2;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		pop();
	}
}
	




int main()
{
	int pos=0,ele,c=0;
	scanf("%d",&n);
	scanf("%d",&s);
	a= (int**)malloc(n*sizeof(int*));	
	for(i=0;i<n;i++)
	{
		a[i] = (int*)malloc(n*sizeof(int));
	}
	nodes= (int*)malloc(n*sizeof(int));
	visited= (int*)malloc(n*sizeof(int));
	st = (int*)malloc(n*sizeof(int));
	dfs= (int*)malloc(n*sizeof(int));
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		
	for(i=0;i<n;i++)
	{
		nodes[i] = i+1;
	}
    for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		st[i] = 0;
	}
	dfs[dfs_pos++] = s;
	unvisited(s);
	push(s);
	pos = returnpos(dfs[0]);
	
	while(dfs_pos<n)
	{
		fillstack(pos);
		ele = peek();
		pos = returnpos(ele);
		c++;
	}
	
	printf("DFS= " );
	for(i=0;i<n;i++)
	{
		printf("%d ",dfs[i]);
	}
		
}

