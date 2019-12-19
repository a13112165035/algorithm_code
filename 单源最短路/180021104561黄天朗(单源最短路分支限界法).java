//单源最短路分支限界法

import java.util.*;


public class Main {
    // 创建一个节点类
    public static class Heapnode implements Comparable {
        int id; // 顶点编号
        float length; // 当前路长
        public Heapnode(int ii, float ll) {
            id = ii;
            length = ll;
        }

        @Override
        // 按从小到大进行排序
        public int compareTo(Object o) {
            float xl = ((Heapnode) o).length;
            if (length < xl) return -1;
            if (length == xl) return 0;
            return 1;
        }
    }

    public static void shortest(float[][] a,int v,float[] dist,int[] p){
        // a[][]为邻接矩阵
        // dist[j]保存从源到顶点j的距离
        // p[j]记录从源到顶点j的路径上的前驱顶点
        int n=p.length-1;
        LinkedList<Heapnode> nodes=new LinkedList<Heapnode>();//用LinkedList存储最小堆
        Heapnode enode=new Heapnode(v,0);
        for(int j=1;j<=n;j++){
            dist[j]=Float.MAX_VALUE;
        }
        while(true){//搜索问题解空间
            for(int j=1;j<=n;j++){
                if(a[enode.id][j]!=-1&&enode.length+a[enode.id][j]<dist[j]){
                    //顶点i到j可达，同时长度小于dist[j]
                    dist[j]=enode.length+a[enode.id][j];
                    p[j]=enode.id;
                    Heapnode e=new Heapnode(j,dist[j]);
                    nodes.add(e);
                    Collections.sort(nodes);
                }
            }
            //取下一个扩展结点
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
        float[][] a = new float[n+1][n+1];//下标从1开始，以下都是
        float[] dist = new float[n+1];
        int[] prev = new int[n+1];
        for(int i=0;i<n;i++){
            line =  sc.nextLine();
            String[] ds = line.split(",");//去逗号
            for(int j = 0;j<ds.length;j++){
                a[i+1][j+1]=Float.parseFloat(ds[j]);
            }
        }
        int v =1;//顶点从1开始
        shortest(a,v,dist,prev);
    }
}
/**
 请输入图顶点的个数：
 5
 请输入图的路径长度：
 -1,10,-1,30,100
 -1,-1,50,-1,-1
 -1,-1,-1,-1,10
 -1,-1,20,-1,60
 -1,-1,-1,-1,-1
 2节点的最短距离是：10.0；前驱点是：1
 3节点的最短距离是：50.0；前驱点是：4
 4节点的最短距离是：30.0；前驱点是：1
 5节点的最短距离是：60.0；前驱点是：3
 */


