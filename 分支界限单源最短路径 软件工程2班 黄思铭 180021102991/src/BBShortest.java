import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class BBShortest {
	public static class Heapnode implements Comparable{
		int id;
		float length;
		public Heapnode(int ii,float ll){
			id=ii;
			length=ll;
		}
		public int compareTo(Object x) {
			float xl=((Heapnode)x).length;
			if(length<xl) return -1;
			if(length==xl) return 0;
			return 1;
		}
 
		
	}
	public static void shortest(float[][] a,int v,float[] dist,int[] p){
		int n=p.length-1;
		LinkedList<Heapnode> nodes=new LinkedList<Heapnode>();//用LinkedList存储最小堆
		Heapnode enode=new Heapnode(v,0);
		for(int j=1;j<=n;j++){
			dist[j]=Float.MAX_VALUE;
		}
		while(true){		
			for(int j=1;j<=n;j++){
				if(a[enode.id][j]!=-1&&enode.length+a[enode.id][j]<dist[j]){
					dist[j]=enode.length+a[enode.id][j];
					p[j]=enode.id;
					Heapnode e=new Heapnode(j,dist[j]);
					nodes.add(e);
					Collections.sort(nodes);
				}
			}
			if(nodes.isEmpty())
				break;
			else{				
				enode=(Heapnode) nodes.poll();
			}
		}
		for(int i=2;i<=n;i++){
			System.out.println(i+"节点的最短距离是："+dist[i]+"；前驱点是："+p[i]);
		}
	}
	public static void main(String[] args) {
		System.out.println("请输入图顶点的个数：");
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		int n = Integer.parseInt(line);
		System.out.println("请输入图的路径长度：");
		float[][] a = new float[n+1][n+1];
		float[] dist = new float[n+1]; 
		int[] prev = new int[n+1];
		for(int i=0;i<n;i++){
			line =  sc.nextLine();			
			String[] ds = line.split(",");
			for(int j = 0;j<ds.length;j++){
				a[i+1][j+1]=Float.parseFloat(ds[j]);
			}
		}				
		int v =1;
		shortest(a,v,dist,prev);
	}
}
