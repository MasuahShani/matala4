#ifndef GRAPH_
#define GRAPH_

struct GRAPH_NODE_; 
typedef struct edge_ {
    int weight;
    int num_endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge* edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

pedge newEdege(int newWheight,int newEndpoint );
pnode newNode (int num);
void addOtherEdg(pedge head,int wt, int ep);
void build_node(pnode node);
int containNode(pnode* start,int val);
void deleteEdege(pnode node,int val);
void deleteEdeges(pnode* start, int val);
pnode* deleteNode(pnode* start,int* size,int val);
void deleteGraph(pnode* start,int* size);
void build_graph(pnode* start, int size);
void startGraph(int* size, pnode* start);
pnode* insertNode(int* size,pnode* start);
float Min(float x, float y);
float shortest(pnode* start, int src, int dst,int* prev);
float T(int st, int* nodes,int k,int left, int* prevs, pnode* start, int size);
float TSP(pnode* start, int size);



#endif
