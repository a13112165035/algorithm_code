#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int n;
int source = 0;     //��ӵ�0���ڵ㵽�����ڵ�����·��
int* dist;
int* path;
int* color;     //��ɫΪ1˵���Ѿ��ҵ����·����Ϊ-1˵��û�ҵ����·��

//���Ĭ�ϵ�ͼ������ͼ�������ġ�ʹ���ڽӾ����ʾ
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

//ʹ�õϽ�˹�����㷨��Դ���·��
void single_source_shortest_path(int** matrix,int source){

    int i,j,index,min;

    dist = (int*)malloc(sizeof(int)*n);
    color = (int*)malloc(sizeof(int)*n);
    path = (int*)malloc(sizeof(int)*n);

    //��ʼ�����·����
    //ֱ�������ĳ�ʼ��ΪȨ�أ���ֱ�������ĳ�ʼ��ΪINT_MAX
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

    //��һ����Դ�㵽�����ڵ���̵�·��
    for(j=0;j<n;j++){
        min = INT_MAX;
        index = -1;
        for(i=0;i<n;i++){
            if(!color[i] && dist[i]<min){
                index = i;
                min = dist[i];
            }
        }

        if(index==-1){  //ȫ����������ھ��붼ȷ��
            break;
        }

        color[index] = 1;   //���Ϊ�Ѿ�ȷ����̾���Ķ���

        //���������µ�ÿһ��δȷ����̾���Ķ���ľ���
        //����Դ�㵽�ոռ���Ľڵ����̾���+�ոռ���Ľڵ�ľ��뵽δȷ����̾���Ķ���ľ��� < Դ��̾��룬����� 

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

