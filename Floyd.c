#include <stdio.h>
#include <stdlib.h>
#include "MGraph.h"

int min(int x, int y) { return x<y ? x : y;}

void Floyd(MGraph *M)
{
    int n = M->vexnum, temp=0;// 无向图中定点个数
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                if (M->edge[j][i] == -1 || M->edge[i][k] == -1) continue;
                temp = M->edge[j][i] + M->edge[i][k];
                if (temp < M->edge[j][k] || M->edge[j][k] == -1) M->edge[j][k] = temp;
            }
        }
    }
}

int main()
{
    MGraph M;
    InitMG(&M);
    Floyd(&M);
    printf("%d\n", M.edge[1][0]);
    return 0;
}