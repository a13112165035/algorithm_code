/*
 * a[][]的下标从1 开始;0只是用来填满位置，无其他用处；-1表示两点不通
 * v 顶点		a 图用二维数组表示
 * dist 从顶点到每个点的距离用数组表示	prev 前驱结点数组
 */
package greedyAlgorithm;

import java.util.Scanner;

public class SingleSourceShortestPath {
	
	public static void main(String[] args) {

		System.out.println("请输入图顶点的个数：");
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		int n = Integer.parseInt(line);
		System.out.println("请输入图的路径长度，用二维矩阵表示节点间的距离，-1代表俩点不通：");
		float[][] a = new float[n + 1][n + 1]; // 下标从1开始，以下都是
		float[] dist = new float[n + 1];
		int[] prev = new int[n + 1];
		for (int i = 0; i < n; i++) {
			line = sc.nextLine();
			String[] ds = line.split(",");
			for (int j = 0; j < ds.length; j++) {
				a[i + 1][j + 1] = Float.parseFloat(ds[j]);
			}
		}
		int v = 1; // 顶点从1开始
		dijkstra(v, a, dist, prev);
		sc.close();

	}
	
	public static void dijkstra(int v, float[][] a, float[] dist, int[] prev) {

		int n = dist.length - 1;
		if (v < 1 || v > n)// 合法性检测
			return; 
		boolean[] s = new boolean[n + 1]; // 顶点放入或不放入的标志

		// 初始化
		for (int i = 1; i <= n; i++) {
			dist[i] = a[v][i];
			s[i] = false;
			if(dist[i]==-1)
				prev[i] = 0;
			else
				prev[i] = v;
		}
		dist[v] = 0; // 顶点放入
		s[v] = true;
		for (int i = 1; i < n; i++) { // 共扫描n-1次
			float temp = Float.MAX_VALUE;
			int u = v; // u存放下一个被放入的点
			for (int j = 1; j <= n; j++) { // 循环找到下一个距离最短的点
				if (!s[j] && dist[j] < temp && dist[j] != -1) {
					u = j;
					temp = dist[j];
				}
			}
			s[u] = true;
			for (int m = 1; m <= n; m++) { // 循环更改每个点的最短距离
				if (!s[m] && a[u][m] != -1) {
					float newdist = dist[u] + a[u][m];
					if (newdist < dist[m] || dist[m] == -1) {
						dist[m] = newdist;
						prev[m] = u;
					}
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			System.out.println(i + "节点的最短距离是：" + dist[i] + "；前驱点是：" + prev[i]);
		}
	}

}
