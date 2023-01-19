#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "graph.h"
int main()
{
    int size=0;
    pnode start=NULL;
    pnode* add_start=&start;
    char let=' ';
    //printf("enter letter\n");
   while (scanf("%c",&let))
   {
        
        if(let=='A')
        {
            startGraph(&size,add_start);
        }
        
        if(let=='B')
        {
           add_start=insertNode(&size, add_start);
           start=*add_start;
        }
        
        if(let=='D')
        {
            int val=0;
            scanf("%d",&val);
            add_start=deleteNode(add_start,&size,val);
            start=*add_start;
        }
        
        if(let=='S')
        {
            int src=-1,dst=-1;
            scanf("%d",&src);
            scanf("%d",&dst);
            int* prev=(int*)calloc(size,sizeof(int));
            float ans=shortest(add_start,src,dst,prev);
            if(ans==INFINITY)
            {
                ans=-1;
            }
            
            printf("Dijsktra shortest path: %d\n",(int)ans);
            free(prev);
        }
        
        if(let=='T')
        {
            printf("TCP shortest path: %d\n",(int)TSP(add_start,size));
        }
        
       
   }
    return 0;
}
