#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph;

void InitMG(MGraph *M)
{
    M->vexnum = 0; M->arcnum = 0;
    // 输入格式
    //第一行输入所有的定点(vexnum)值, $结束
    //接下来vexnum行, 输入所有边权值, -1表示不可达
    char c;
    scanf("%c", &c);
    while (c != '$'){
        M->vex[M->vexnum++] = c;
        scanf("%c", &c);
    }
    for (int i=0; i<M->vexnum; i++){
        for (int j=0; j<M->vexnum; j++) scanf("%d", &M->edge[i][j]);
    }
}