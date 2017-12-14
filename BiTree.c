#include<stdio.h>
#include<malloc.h>

#define  null 0
#define  error 0
#define   ok   1


typedef int  Status; 
typedef char ElemType;

typedef struct  BiTNode
{
	ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


CreatBiTree(BiTree *T){
	char c;
	
	scanf("%c",&c);
	if('#'==c)
		*T=null;
	else
	{
     *T=(BiTNode *)malloc(sizeof(BiTNode));
	 (*T)->data=c;
    CreatBiTree(&(*T)->lchild);
	CreatBiTree(&(*T)->rchild);
	}
}
void preOrderTraverse(BiTree T,int level)
{
    if(T)
	{
		printf("%c  %d\n ",T->data,level);
		preOrderTraverse(T->lchild,level+1);
        preOrderTraverse(T->rchild,level+1);

	}
}

int main(){
	int level=1;
     BiTree T=null;
	 printf("请输入节点内数据内容（字符型）：\n");
     CreatBiTree(&T);
     printf("遍历结果为：\n");
     preOrderTraverse(T,level);
	 printf("\n");
	return 0;
}