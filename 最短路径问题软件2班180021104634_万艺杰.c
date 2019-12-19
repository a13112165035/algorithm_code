#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int n;
int source = 0;     //求从第0个节点到其它节点的最短路径
int* dist;
int* path;
int* color;     //颜色为1说明已经找到最短路径。为-1说明没找到最短路径

//获得默认的图，即上图所看到的。使用邻接矩阵表示
int** get_graph(){
    int** matrix;
    int i,j;
    int start,end,weight;

    printf("input vertex num:\n");
    scanf("%d",&n);

    matrix = (int**)malloc(sizeof(int*)*n);

    for(i=0;i<n;i++){
        matrix[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            if(i!=j)
                matrix[i][j] = INT_MAX;
            else
                matrix[i][j] = 0;
        }
    }

    printf("input start end weight, stop by -1\n");

    for(;;){
        scanf("%d",&start);  
        if(start==-1){  
            break;  
        }  
        scanf("%d %d",&end,&weight); 
        matrix[start][end] = weight;
        matrix[end][start] = weight;
    }
    return matrix;
}

//使用迪杰斯特拉算法求单源最短路径
void single_source_shortest_path(int** matrix,int source){

    int i,j,index,min;

    dist = (int*)malloc(sizeof(int)*n);
    color = (int*)malloc(sizeof(int)*n);
    path = (int*)malloc(sizeof(int)*n);

    //初始化最短路径：
    //直接相连的初始化为权重，不直接相连的初始化为INT_MAX
    for(i=0;i<n;i++){
        dist[i] = matrix[source][i];
        color[i] = 0;
        if(i!=source && dist[i]!=INT_MAX){
            path[i] = source;
        }else{
            path[i] = -1;
        }
    }

    color[source] = 1;
    path[source] = 0;

    //找一个从源点到其它节点最短的路径
    for(j=0;j<n;j++){
        min = INT_MAX;
        index = -1;
        for(i=0;i<n;i++){
            if(!color[i] && dist[i]<min){
                index = i;
                min = dist[i];
            }
        }

        if(index==-1){  //全部定点的终于距离都确定
            break;
        }

        color[index] = 1;   //标记为已经确定最短距离的定点

        //接下来更新到每一个未确定最短距离的定点的距离
        //假设源点到刚刚加入的节点的最短距离+刚刚加入的节点的距离到未确定最短距离的定点的距离 < 源最短距离，则更新 
        for(i=0;i<n;i++){
            if(!color[i] && matrix[index][i]!=INT_MAX && dist[index]+matrix[index][i]<dist[i]){
                 dist[i] = dist[index]+matrix[index][i];
                 path[i] = index;
            }
        }
    }
}


int main(){

    int** matrix = get_graph();
    int i,t;

    single_source_shortest_path(matrix,source);

    printf("\n");
    for(i=0;i<n;i++){
        printf("%d: %d,and the path is(inverse order): %d ",i,dist[i],i);
        t = path[i];
        while(1){
            printf(" %d ",t);
            if(t==0){
                break;
            }
            t = path[t];
        }
        printf("\n");
    }

    printf("\n");
    return EXIT_SUCCESS;
}
