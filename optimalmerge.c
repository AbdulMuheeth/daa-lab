#include<stdio.h>
#include<stdlib.h>


struct heapn
{
    int capacity;
    int size;
    struct node **array;
};

struct node
{
    int weight;
    struct node * left,* right;
};

struct node* newNode(int wt)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->weight = wt;
    newnode->left = newnode->right = 0;

    return newnode;
}

struct heapn* createminheap(int capacity)
{
    struct heapn* minheap = (struct heapn*) malloc(sizeof(struct heapn));
    minheap->size = 0;
    minheap->capacity = capacity;
    minheap->array = (struct node**) malloc(minheap->capacity * sizeof(struct node*));

    return minheap;
};

void swapnode(struct node** n1, struct node** n2) {
    struct node* t = *n1;
    *n1 = *n2;
    *n2 = t;
}

void heapify(struct heapn* minheap,int pos)
{
    int min = pos;
    int left = 2*pos+1;
    int right = 2*pos+2;
    if(left < minheap->size && minheap->array[left]->weight < minheap->array[min]->weight)
        min = left;
    if(right < minheap->size && minheap->array[right]->weight < minheap->array[min]->weight)
        min = right;
    if(min != pos)
    {
        swapnode(&minheap->array[min],&minheap->array[pos]);
        heapify(minheap,min);
    }
}

struct node* extractmin (struct heapn* minheap)
{
    struct node* temp = minheap->array[0];
    minheap->array[0] = minheap->array[minheap->size-1];
    --minheap->size;
    heapify(minheap,0);
    return temp;
}

void insert(struct heapn* minheap,struct node* minh)
{
    ++minheap->size;
    int i = minheap->size-1; 
    while(i && minh->weight < minheap->array[(i-1)/2]->weight)
    {
        minheap->array[i] = minheap->array[(i-1)/2];
        i = (i-1)/2;
    }
    minheap->array[i] = minh;
}

void buildheap(struct  heapn* minheap)
{
    int i,n = minheap->size-1;
    for(i=(n-1)/2;i>=0;i--)
        heapify(minheap,i);
}


struct heapn* create(int d[],int capacity)
{
    struct heapn* minheap = createminheap(capacity);
    for(int i=0;i<capacity;i++) minheap->array[i]= newNode(d[i]);

    minheap -> size = capacity;
    buildheap(minheap);
    return minheap;
}

struct node* optt(int d[],int size)
{
    struct node *left,*right,*top;
    struct heapn *minheap = create(d,size);
    int i=0,t,tot=0;

    while(!(minheap->size == 1))
    {
        left = extractmin(minheap);
        right = extractmin(minheap);
        t = left->weight + right->weight;
        tot = tot+t;
        printf("\n merge %d and %d cost is =%d", left->weight, right->weight,t);
        top = newNode(left->weight + right->weight);
        top->left = left;
        top->right = right;
        insert(minheap,top);
    }
    printf("\n total merge cost is...:%d", tot);
    return extractmin(minheap);
}

int main()
{
    int fr[10], n, i;
    printf("\n Enter the no of files:");
    scanf("%d", &n);
    printf("enter the records of %d file", n);
    for (i = 0; i < n; i++) scanf("\n %d", &fr[i]);
    struct node* root = optt(fr, n);
}
