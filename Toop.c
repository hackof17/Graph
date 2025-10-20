#include "AdjGraph.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    ALGraph G;
    InitGraph(&G);
    TopologicalSort(G);
    return 0;
}