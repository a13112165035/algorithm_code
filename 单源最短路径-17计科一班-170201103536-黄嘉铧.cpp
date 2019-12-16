#include <iostream>
using namespace std;

#define MaxInt 32767                    					//表示极大值，即∞
#define MVNum 100                       					//最大顶点数
typedef char VerTexType;              						//假设顶点的数据类型为字符型 
typedef int ArcType;                  						//假设边的权值类型为整型

int *D=new int[MVNum];	                    				//用于记录最短路的长度
bool *S=new bool[MVNum];          							//标记顶点是否进入S集合
int *Path=new int[MVNum];									//用于记录最短路顶点的前驱


typedef struct{ 
	VerTexType vexs[MVNum];            						//顶点表 
	ArcType arcs[MVNum][MVNum];      						//邻接矩阵 
	int vexnum,arcnum;                						//图的当前点数和边数 
}AMGraph;


int LocateVex(AMGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
   return -1;
}//LocateVex


void CreateUDN(AMGraph &G){ 
    //采用邻接矩阵表示法，创建有向网G   
	int i , j , k;
	cin >> G.vexnum >> G.arcnum;							//输入总顶点数，总边数
    for(i = 0; i < G.vexnum; ++i)
	{   
		cin >> G.vexs[i];                        			//依次输入点的信息 
	}
    for(i = 0; i < G.vexnum; ++i)                			//初始化邻接矩阵，边的权值均置为极大值MaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = MaxInt; 
	for(k = 0; k < G.arcnum;++k){							//构造邻接矩阵 
		VerTexType v1 , v2;
		ArcType w;
		cin >> v1 >> v2 >> w;								//输入一条边依附的顶点及权值
	i = LocateVex(G, v1);  j = LocateVex(G, v2);
		G.arcs[i][j] = w;									//边<v1, v2>的权值置为w 
	  //	G.arcs[j][i] = G.arcs[i][j]; //***若改成无向网****置<v1, v2>的对称边<v2, v1>的权值也为w 
	}//for
}//CreateUDN



void ShortestPath_DIJ(AMGraph G, int v0){ 
    //用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径 
    int v , i , w , min;
	int n = G.vexnum;                    					//n为G中顶点的个数 

	for(v = 0; v < n; ++v){             					//n个顶点依次初始化 
		S[v] = false;                  						//S初始为空集 
		D[v] = G.arcs[v0][v];           					//将v0到各个终点的最短路径长度初始化为弧上的权值 
		if(D[v] < MaxInt)  Path [v] = v0;  					//如果v0和v之间有弧，则将v的前驱置为v0 
		else Path [v] = -1;               					//如果v0和v之间无弧，则将v的前驱置为-1 
	}//for 

	S[v0]=true;                    							//将v0加入S 
	D[v0]=0;                      							//源点到源点的距离为0 

	/*―初始化结束，开始主循环，每次求得v0到某个顶点v的最短路径，将v加到S集―*/ 
	for(i = 1;i < n; ++i){									//对其余n-1个顶点，依次进行计算 
        min= MaxInt; 
        for(w = 0; w < n; ++w) 
			if(!S[w] && D[w] < min){						//选择一条当前的最短路径，终点为v 
				v = w; 
				min = D[w];
			}//if         	
		S[v]=true;                   						//将v加入S 
		for(w = 0;w < n; ++w)           					//更新从v0出发到集合V?S上所有顶点的最短路径长度 
			if(!S[w] && (D[v] + G.arcs[v][w] < D[w])){ 
				D[w] = D[v] + G.arcs[v][w];   				//更新D[w] 
				Path [w] = v;              					//更改w的前驱为v 
			}//if 
    }//for  
}

void DisplayPath(AMGraph G , int begin ,int temp ){
	//显示最短路
	if(Path[temp] != -1){
		DisplayPath(G , begin ,Path[temp]);
		cout << G.vexs[Path[temp]] << "-->";
	}
}

main()
{
	int i , j ,num_qidian , num_zhongdian;
	VerTexType qidian,zhongdian;
	AMGraph G;
	CreateUDN(G);
	cin >> qidian >> zhongdian;
	num_qidian = LocateVex(G , qidian);
	num_zhongdian = LocateVex(G , zhongdian);
	ShortestPath_DIJ(G , num_qidian);
	ShortestPath_DIJ(G,0);
	if(D[num_zhongdian]<MaxInt)  
	{		
		cout << endl <<"最短路径为：";
		DisplayPath(G , num_qidian , num_zhongdian);
		cout << G.vexs[num_zhongdian]<<endl;
		cout <<"最短路径长度为：" <<D[num_zhongdian]<<endl; 
	}
} 

