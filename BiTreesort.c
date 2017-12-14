#include<stdio.h>
#include<stdlib.h>

#define  Maxsize 50
#define  null    0


typedef int Status;

typedef struct BiTreeNode{
	int  data;
	struct BiTreeNode *lchild,*rchild;

}BiTreeNode, *BiTree;

typedef struct SqList {
	   int data[Maxsize];
	   int length;
}SqList;

int createBiTree(BiTree *T,SqList L){
    BiTree s,p;
	int i;
	i=1;
	s=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data=L.data[0];
	s->lchild=null;
	s->rchild=null;
	*T=s;
	p=*T;
	 while(i<L.length){
		 printf("ok");
		 while(p){
			 if(p&&L.data[i]>(p->data))
			 {   s=p;
				 p=p->rchild;
			 }
			  if(p&&L.data[i]<(p->data))
			 {   s=p;
				 p=p->rchild;
			 }
			  if(p&&L.data[i]==(p->data))
			 {   
				  p=*T;
				  i++;
			 }
		 }
		 printf("ok");
		 p=s;
	     s=(BiTreeNode *)malloc(sizeof(BiTreeNode));
       	 s->data=L.data[i];
	     s->lchild=null;
	     s->rchild=null;
		 if(L.data[i]>(p->data))
			 p->rchild=s;
		 if(L.data[i]<(p->data))
			 p->lchild=s;
		 p=*T;
		 i++;

	 }
printf("ok");
return 1;
}

void preOrderTraverse(BiTree T,int level)
{
    if(T)
	{
		printf("%d  %d\n ",T->data,level);
		preOrderTraverse(T->lchild,level+1);
        preOrderTraverse(T->rchild,level+1);

	}
}
int main(){
	BiTree t;
	SqList L;
	int i;
    for(i=0;i<9;i++)
	scanf("%d\n",&L.data[i]);
	L.length=i;
	createBiTree(&t,L);
	preOrderTraverse(t,0);


	return 0;
}