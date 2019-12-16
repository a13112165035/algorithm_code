// dijkstra算法实现的单源最短路径问题
//16计算机科学与技术4班 许航 160201102983
//2019.12.16
//运行时请将文件名改为 “ShortestPath.java”

import java.util.*; 
import java.lang.*; 
import java.io.*; 

class ShortestPath { 
	// 寻找不在S集合中的最短路径
	static final int V = 9; 
	int minDistance(int dist[], Boolean sptSet[]) 
	{ 
		// 初始化最小值
		int min = Integer.MAX_VALUE, min_index = -1; 

		for (int v = 0; v < V; v++) 
			if (sptSet[v] == false && dist[v] <= min) { 
				min = dist[v]; 
				min_index = v; 
			} 

		return min_index; 
	} 

	// 打印结果方法
	void printSolution(int dist[]) 
	{ 
		System.out.println("Vertex \t\t Distance from Source"); 
		for (int i = 0; i < V; i++) 
			System.out.println(i + " \t\t " + dist[i]); 
	} 

	// Dijkstra算法实现
	void dijkstra(int graph[][], int src) 
	{ 
		int dist[] = new int[V]; //储存i到源的最短路径

		// 储存查找结果
		Boolean sptSet[] = new Boolean[V]; 

		// 初始化
		for (int i = 0; i < V; i++) { 
			dist[i] = Integer.MAX_VALUE; 
			sptSet[i] = false; 
		} 

		// 源到自身的距离为零
		dist[src] = 0; 

		
		for (int count = 0; count < V - 1; count++) { 
			
			int u = minDistance(dist, sptSet); 

			sptSet[u] = true; 

			for (int v = 0; v < V; v++) 

				
				if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) 
					dist[v] = dist[u] + graph[u][v]; 
		} 

		// 打印结果
		printSolution(dist); 
	} 

	// 测试程序 
	public static void main(String[] args) 
	{ 
		/* 创建邻接矩阵 */
		int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
									{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
									{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
									{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
									{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
									{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
									{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
									{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
									{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
		ShortestPath t = new ShortestPath(); 
		t.dijkstra(graph, 0); 
	} 
} 

