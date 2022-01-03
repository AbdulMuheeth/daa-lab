#include<stdio.h>
#define INF 9999

struct edge
{
    int u;
    int v;
    int weight;
};

struct graph
{
    int vertices;
    int edges;
    struct edge *edge;
};

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bellmanford(struct graph* g,int source)
{
    int i,j,d[g->vertices],p[g->vertices],u,v,w;
    int ve = g->vertices;
    int ee = g->edges;
    for(i=0;i<ve;i++)
    {
        d[i] = INF;
        p[i] = 0;
    }
    
    d[source] = 0;

    for(i=0;i<ve;i++)
    {
        for(j=0;j<ee;j++)
        {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].weight;

            if(d[u] != INF && d[v]>d[u]+w)
            {
                d[v] = d[u]+w;
                p[v] = u;
            }
        }
    }

    for(i=0;i<ee;i++)
    {
        u = g->edge[i].u;
        v = g->edge[i].v;
        w = g->edge[i].weight;

        if(d[u] != INF && d[v]>d[u]+w)
        {
            printf("Negative cycle exists");
            return;
        }
    }

    printf("distance array: ");
    display(d, ve);
    printf("predecessor array: ");
    display(p, ve);
}

int main()
{
    int v, e, i;
    struct graph *g = (struct graph*) malloc(sizeof(struct graph));
    printf("\n enter the total vertices and edges:");
    scanf("%d%d", &v, &e);
    g->vertices = v;
    g->edges = e;

    g->edge = (struct edge *)malloc(e*sizeof(struct edge));
    printf("\n enter edge u,v and weight w..:");
    for (i = 0; i < e; i++) {
        scanf("%d%d%d", &g->edge[i].u, &g->edge[i].v, &g->edge[i].weight);
    }
    bellmanford(g, 0);

    return 0;
}