import java.util.Scanner;

public class SSSP
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        System.out.print("请输入图的顶点和边的个数(格式：顶点个数 边个数)：");
        int n = input.nextInt(); //顶点的个数
        int m = input.nextInt(); //边的个数
        
        System.out.println();
        
        int[][] a = new int[n + 1][n + 1];
        //初始化邻接矩阵
        for(int i = 0; i < a.length; i++)
        {
            for(int j = 0; j < a.length; j++)
            {
                a[i][j] = -1; //初始化没有边
            }
        }
        
        System.out.println("请输入图的路径长度(格式：起点 终点 长度)：");
        //总共m条边
        for(int i = 0; i < m; i++)
        {
            //起点，范围1到n
            int s = input.nextInt();
            //终点，范围1到n
            int e = input.nextInt();
            //长度
            int l = input.nextInt();
            
            if(s >= 1 && s <= n && e >= 1 && e <= n)
            {
                //无向有权图
                a[s][e] = l;
                a[e][s] = l;
            }
        }
        
        System.out.println();
        
        //距离数组
        int[] dist = new int[n+1];
        //前驱节点数组
        int[] prev = new int[n+1];
        
        int v =1 ;//顶点，从1开始
        dijkstra(v, a, dist, prev);
    }
    
    //单源最短路径算法(迪杰斯特拉算法)
    public static void dijkstra(int v, int[][] a, int[] dist, int[] prev)
    {
        int n = dist.length;
        /**
         * 顶点从1开始，到n结束，一共n个结点
         */
        if(v > 0 && v <= n)
        {
            //顶点是否放入的标志
            boolean[] s = new boolean[n];
            
            //初始化
            for(int i = 1; i < n; i++)
            {
                //初始化为 v 到 i 的距离
                dist[i] = a[v][i];
                //初始化顶点未放入
                s[i] = false;
                //v到i无路，i的前驱节点置空
                if(dist[i] == -1)
                {
                    prev[i] = 0;
                }
                else
                {
                    prev[i] = v;
                }
            }
            
            //v到v的距离是0
            dist[v] = 0;
            //顶点放入
            s[v] = true;
            
            //共扫描n-2次，v到v自己不用扫
            for(int i = 1; i < n - 1; i++)
            {
                int temp = Integer.MAX_VALUE;
                //u为下一个被放入的节点
                int u = v;
                
                //这个for循环为第二步，观测域为v的观测域
                //遍历所有顶点找到下一个距离最短的点
                for(int j = 1; j < n; j++)
                {
                    //j未放入，且v到j有路，且v到当前节点路径更小
                    if(!s[j] && dist[j] != -1 && dist[j] < temp)
                    {
                        u = j;
                        //temp始终为最小的路径长度
                        temp = dist[j];
                    }
                }
                
                //将得到的下一节点放入
                s[u] = true;
                
                //这个for循环为第三步，用u更新观测域
                for(int k = 1; k < n; k++)
                {
                    if(!s[k] && a[u][k] != -1)
                    {
                        int newdist=dist[u] + a[u][k];
                        if(newdist < dist[k] || dist[k] == -1)
                        {
                            dist[k] = newdist;
                            prev[k] = u;
                        }
                    }
                }
            }
        }
        
        for(int i = 2; i < n; i++)
        {
            System.out.println(i + "节点的最短距离是："
                + dist[i] + "；前驱点是：" + prev[i]);
        }

    }
}