#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "graph.h"






pedge newEdege(int newWheight,int newEndpoint )
{
    pedge Edege=(pedge)calloc(1,sizeof(edge));
    if(!Edege)
    {
        return NULL;
    }
    Edege->weight=newWheight;
    Edege->num_endpoint=newEndpoint;
    Edege->next=NULL;
    return Edege;
}

pnode newNode (int num)
{
    pnode Node=(pnode)calloc(1,sizeof(node));
    if(!Node)
    {
        return NULL;
    }
    Node->node_num=num;
    Node->edges=NULL;
    Node->next=NULL;

    return Node;

}
void addOtherEdg(pedge head,int wt, int ep)
{
    if(!head)
    {
        return;
    }
    pedge cur=head;
    while (cur->next)
    {
        cur=cur->next;
    }
    pedge nEdege=newEdege(wt,ep);
    if(!nEdege)
    {
        return;
    }
    cur->next=nEdege;
    
    

}

void build_node(pnode node)//A
{
    int ep=0;
    int wt=0;
    if(scanf("%d",&ep)!=1)
    {
          
            return;

    }
    
   
    scanf("%d",&wt);
    pedge* head=(pedge*)calloc(1,sizeof(pedge));
    //first edge in the list
    *head=newEdege(wt,ep);
    if(!*head)
    {
        return;
    }

    node->edges=head;

    while(scanf("%d",&ep))
    {
        scanf("%d",&wt);
        addOtherEdg(*head,wt,ep);

    }
    
 
}
int containNode(pnode* start,int val)
{
    int index=0;
    pnode cur=*start;
    while(cur)
    {
        if(cur->node_num==val)
        {
            return index;

        }
        index++;
        cur=cur->next;

    }
    return -1;
}
void deleteEdege(pnode node,int val)
{
    if(!node)
    {
        return;
    }
    pedge* head=node->edges;
    if(!head || !*head)
    {
        return;
    }
    
    if((*head)->num_endpoint==val)
    {
        if(!(*head)->next)
        {
            free(*head);
            free(head);
            node->edges=NULL;
            return;
        }
        pedge new_head=((*head)->next);
        free(*head);
        *(node->edges)=new_head;
        

        return;
    }
    
    while((*head)->next)
    {
        if((*head)->next->num_endpoint==val)
        {
            pedge temp=(*head)->next;
            (*head)->next=temp->next;

            free(temp);
            return;

        }
        else
        {
            *head=(*head)->next;
        }
                    
    }
  
}

void deleteEdeges(pnode* start, int val)
{
    if(!start || !(*start))
    {
        return;
    }

    pnode cur=*start;
    while(cur)
    {
        deleteEdege(cur,val);
        cur=cur->next;
    }
    
    
}

pnode* deleteNode(pnode* start,int* size,int val)
{
    if(!start || !(*start))
    {
        return NULL;
    }
    
    if((*start)->node_num==val)
    {
        pnode temp=*start;
        start=&((*start)->next);
      if((temp->edges))
      {

      
       pedge cur_ed=*(temp->edges);
        while(cur_ed->next)
        {
        pedge temp2=cur_ed;
        cur_ed=cur_ed->next;
        free(temp2);
        }
   
        free(cur_ed);
    
    
        free((temp->edges));
    
      }
    

        free(temp);
        (*size)--;
        return start;

    }
    
    int index=containNode(start,val);
    if(index==-1)
    {
        return NULL;
    }
    (*size)--;
    
    pnode cur=*start;
    int count=0;
    while(count<index-1)
    {
        cur=cur->next;
        count++;
    }
    pnode temp= cur->next;
    cur->next=temp->next;

    if((temp->edges))
    {
    
   
    pedge cur_ed=*(temp->edges);
    while(cur_ed->next)
    {
        pedge temp2=cur_ed;
        cur_ed=cur_ed->next;
        free(temp2);
    }
   
        free(cur_ed);
   
        free(temp->edges);
    }

    free(temp);
    deleteEdeges(start,val);
    return start;
}

void deleteGraph(pnode* start,int* size)
{
    if(!start || !(*start))
    {
        return;
    }
    
    while((*size)>0)
    {
       
        int val=(*start)->node_num;
        start=deleteNode(start,size,val);
       
    }

}




void build_graph(pnode* start, int size)
{
    int index=1;
    int numNode=0;
    char c=' ';
    

    pnode cur=*start;    
    while( index<size)
    {
        scanf("%c",&c);
        scanf("%d",&numNode);
        pnode node=newNode(numNode);
        if(!node)
        {
            return;
        }
        build_node(node);
        cur->next=node;
        cur=cur->next;
        index++;        
        

    }


}
void startGraph(int* size, pnode* start)// כתובת של הגודל וכתובת של הכתובת של המערך
{ 
    if(*start)
    {
        deleteGraph(start,size);
    }
    scanf("%d",size);
    char c=' ';
    scanf("%c",&c);
    int num=0;
    while(scanf("%d",&num)!=1)
    {
        scanf("%c",&c);
    }
    *start=newNode(num);
    if(!start ||!(*start))
    {
        return;
    }
    build_node(*start);
    build_graph(start,*size);
    

}
pnode* insertNode(int* size,pnode* start)
{
    if(!start || !(*start))
    {
        return NULL;
    }
    int val=0;
    scanf("%d",&val);
    int index=containNode(start,val);

    pnode node=newNode(val);
    
    build_node(node);

    if(index==-1)
    {
        (*size)++;
        
        pnode cur=*start;
        while(cur->next)
        {
            cur=cur->next;
        }
        cur->next=node;

    }
    else
    {
        if(index==0)
        {
            pnode temp=*start;
            node->next=(*start)->next;
            start=&node;

                if((temp->edges))
        {

        
        pedge cur_ed=*(temp->edges);
        while(cur_ed->next)
        {
            pedge temp2=cur_ed;
            cur_ed=cur_ed->next;
            free(temp2);
        }
    
            free(cur_ed);
        
        
            free(temp->edges);
        
        }

            free(temp);

        }
        int count=1;
        pnode cur=*start;
        while(count<index)
        {
            cur=cur->next;
            count++;
        }
        pnode temp=cur->next;
        cur->next=node;
        node->next=temp->next;

        if((temp->edges))
      {

      
       pedge cur_ed=*(temp->edges);
    while(cur_ed->next)
    {
        pedge temp2=cur_ed;
        cur_ed=cur_ed->next;
        free(temp2);
    }
   
        free(cur_ed);
    
    
        free(temp->edges);
    
      }


        free(temp);
    }
    return start;
}
float Min(float x, float y)
{
    if(x<y)
    {
        return x;
    }
    return y;
}

float shortest(pnode* start, int src, int dst,int* prev)
{
    if(containNode(start,src)==-1||containNode(start,dst)==-1)
    {
        return INFINITY;
    }
    if(src==dst)
    {
        return 0;
    }
    if(!(*prev))
    {
        *prev=src;
    }
    else
    {
            
    int* i=prev;
    while(*i)
    {
        if((*i)==src)
        {
            return INFINITY;
        }
        i=i+1;


    }
    *i=src;
    }    
    
    int index=containNode(start, src);
    pnode* node_src;
    
    if(index==0)
    {
        node_src= start;
    }
    else
    {
   
    pnode cur=*start;
    while(cur->next)//find the src node
    {
        if(cur->next->node_num==src)
        {
            node_src=&(cur->next);
        }
        cur=cur->next;
    }
    }
    

    if(!((*node_src)->edges))
    {
        return INFINITY;
    }
    pedge curE=*((*node_src)->edges);
    float min=INFINITY;
    while(curE)
    {
        min=Min(min,shortest(start,curE->num_endpoint,dst,prev)+(curE->weight));
        curE=curE->next;

    }
       

    return min;
}



float T(int st, int* nodes,int k,int left, int* prevs, pnode* start, int size)
{
    if(left==1)
    {
        return 0;
    }

    int* curNodes=(int*)calloc(left,sizeof(int));

    
    
    *(prevs+k-left)=st;
    left--;
    

    int* prevs_forS=(int*)calloc(size,sizeof(int));
    int j=0;
    int index=0;
  
    int visit=0;
    int i=0;
    while(i<k)
    {
        while(j<(k-left))
        {
            if(*(nodes+i)==*(prevs+j))//if we visit this node
            {
                visit=1;
            }
            j++;
        }
        if(visit==0)
        {
            *(curNodes+index)=*(nodes+i);
            index++;
        }
        visit=0;
        j=0;
       
        i++;
        
    }

    i=0;
    float min=INFINITY;
    while (i<left)
    {
        
        min=Min(min,shortest(start,st,*(curNodes+i),prevs_forS)+T(*(curNodes+i),nodes,k,left,prevs,start,size));
        i++;
    }
    
    free(curNodes);
    free(prevs_forS);
    return min;


}

float TSP(pnode* start, int size)
{
    if(!start ||!(*start))
    {
        return -1;
    }
    int k=0;
    scanf("%d",&k);
    int* nodes=(int*)calloc(k,sizeof(int));
    if(!nodes)
    {
        return -1;
    }
    int* prevNodes=(int*)calloc(k,sizeof(int));
    if(!prevNodes)
    {
        return -1;
    }
    int i=0;
    float min=INFINITY;
    while(i<k)
    {
        int num=0;
        scanf("%d",&num);
        *(nodes+i)=num;
        i++;
        
    }
    i=0;
    while(i<k)
    {
        min=Min(min,T(*(nodes +i),nodes,k,k,prevNodes,start,size));
        memset(prevNodes,0,k);
        i++;
    }
    

    
    free(nodes);
    free(prevNodes);
    if(min==INFINITY)
    {
        return -1;
    }
    return min;
}







