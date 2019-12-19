package com.zhbit;
import java.util.PriorityQueue;
class Node implements Comparable<Node>{
	int id;
	int length;//当前情况下到达该顶点的长度
	public int compareTo(Node d){
		if(this.length < d.length)
			return -1;
		else if(this.length == d.length)
			return 0;
		return 1;
	}
}
public class Short {
	public static int INFINITE = Integer.MAX_VALUE;
	int n=5;
	int[] prev = new int[n];//用于存储节点们的前驱节点。
	int[] dist = new int[n];//用于存储源节点到节点们的最短距离。
	//对节点之间的距离信息进行初始化，全部存储在二维数组中。
	int[][] c = {{0,100,30,INFINITE,10},{INFINITE,0,INFINITE,INFINITE,INFINITE},
			{INFINITE,60,0,60,INFINITE},{INFINITE,10,INFINITE,0,INFINITE},
			{INFINITE,INFINITE,INFINITE,50,0}};
	public void shorttestPath(int t){
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		for(int i=0;i<dist.length;i++)
			dist[i] = INFINITE;
		for(int i=0;i<prev.length;i++)
			prev[i] = -1;
		//对给定的源节点进行初始化。
		Node source = new Node();
		source.id = t;
		source.length = 0;
		dist[t] = 0;
		pq.add(source);
		while(!pq.isEmpty()){
			Node fatherNode = pq.poll();
			//取出所有该节点能够到达，并且到达总长度不大于已发现的最优长度的节点
			for(int j=0;j<n;j++){
				if(c[fatherNode.id][j]<INFINITE 
						&& fatherNode.length+c[fatherNode.id][j]<dist[j]){
					//更新该孩子节点的最优长度和前驱节点。然后再将其放入优先队列中。
					dist[j] = fatherNode.length+c[fatherNode.id][j];
					prev[j] = fatherNode.id;
					Node newNode = new Node();
					newNode.id = j;
					newNode.length = dist[j];
					pq.add(newNode);
				}
			}
		}
		
		System.out.println(t+"号节点到其他节点的最短路径长度和路径分别为：");
		for(int i=0;i<n;i++){
			System.out.println("到"+i+"号节点的最短长度为:"+((dist[i]==INFINITE)?"不可达":""+dist[i]));
			if(dist[i]!=INFINITE && i!=t){
				System.out.print("其路径为:  "+i+"----");
				int temp = i;
				while(prev[temp]!=t){
					System.out.print(prev[temp]+"----");
					temp = prev[temp];
				}
				System.out.println(prev[temp]);
			}
		}
		
	}
	public static void main(String[] args){
		Short sp = new Short();
		sp.shorttestPath(4);
	}
 
}
