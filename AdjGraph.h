#include <stdio.h>
#include <stdlib.h>
#define MAXVertexNum 100

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode
{
	int data;
	ArcNode *next;
}VNode, AdjList[MAXVertexNum];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

void InitGraph(ALGraph *G)
{
	int n, m;
	ArcNode *s;
	for (int i=0; i<MAXVertexNum; i++) {
		G->vertices[i].data = 0;
		G->vertices[i].next = NULL;
	}
	G->vexnum = 0; G->arcnum = 0;
	printf("第一行输入弧尾节点, 第二行输入弧头节点, -1结束\n");
	scanf("%d", &n);
	while (n != -1){
		scanf("%d", &m);
		while (m != -1){
			s = (ArcNode*)malloc(sizeof(ArcNode));
			s->adjvex = m;
			s->next = G->vertices[n].next;
			G->vertices[n].next = s;
			G->arcnum++;
			G->vertices[m].data = 1;
			scanf("%d", &m);
		}
		G->vexnum++;
		G->vertices[n].data = 1;
		scanf("%d", &n);
	}
}

void TopologicalSort(ALGraph G)
{
	// 栈的作用在于避免递归, TopoList用于记录拓扑序列
	int *S = (int*)malloc(sizeof(int)*MAXVertexNum);
	int *TopoList = (int*)malloc(sizeof(int)*G.vexnum);
	int *indegree = (int*)malloc(sizeof(int)*MAXVertexNum);
	int S_top=0;// 栈S的栈顶指针
	int index = 0; //index用于指名拓扑序列的下标
	int topvalue, Gvalue;// topvalue专指栈中的栈顶元素, Gvalue用于表示遍历过程中的元素
	ArcNode *p;
	// 计算每个节点的入度
	for (int i=0; i<MAXVertexNum; i++) indegree[i] = 0;
	for (int i=0; i<MAXVertexNum; i++){
		if (! G.vertices[i].data) continue;
		p = G.vertices[i].next;
		while (p != NULL){
			indegree[p->adjvex]++;
			p = p->next;
		}
	}
	for (int i=1; i<G.vexnum+1; i++) {
		if (indegree[i] == 0) {
			S[S_top++] = i;
		}
	}
	// 接下来的操作会将入度为0的点继续放入topo序列中, 及算及放
	//因为不是遍历indegree列表, 所以图中如果没有环路的话, 算法是不会把已经在栈里的点重新放进去的
	while(S_top != 0){
		topvalue = S[--S_top];
		TopoList[index++] = topvalue;
		for (p=G.vertices[topvalue].next; p != NULL; p = p->next){
			Gvalue = p->adjvex;
			if (!(--indegree[Gvalue])){
				S[S_top++] = Gvalue;// Gvalue入栈
			}
		}
	}
	if (index == G.vexnum){
		for (int i=0; i<index-1; i++) printf("%d ", TopoList[i]);
		printf("%d\n", TopoList[index-1]);
	} else {
		printf("图中存在环路\n");
	}
}