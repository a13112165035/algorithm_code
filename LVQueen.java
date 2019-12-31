import java.util.*;
public class LVQueen
{
    static Random rnd;//随机数产生器
    static int n;//皇后个数
    static int[] x;//解向量
    
    private static boolean place(int k)
    {
        for(int j = 1; j< k; j++)
        {
            if(Math.abs(k - j) == Math.abs(x[k] - x[j]) || x[j] == x[k])
                return false;
        }
        return true;
    }
    private  static boolean queensLV()
    {
        rnd = new Random();
        int k = 1;
        int count = 1;
        while((k <= n) &&(count > 0))
        {
            count  = 0;
            int j = 0;
            for(int i = 1; i <= n; i++)
            {
                x[k] = i;
                if(place(k))
                {
                    if(rnd.random(++count) == 0)
                        {
                            j = i;
                            System.out.println("j = " +j +" count = "+count );
                            //break;//有break如果第一此找到合适的列place(k)满足，那么此时random（1）==0恒成立，遇到下面的break，就把皇后放置在这个位置。如果这种放置皇后的方案不可行，下次循环还会执行同样的，故一直循环调不出来找不到方案。即剩下的所有皇后放置不了的可能性增大。
                            //没有break，会一直试探for循环结束。x[k]会在随机的选择当前可以放置的位置中for循环最后一个满足的列。那么后面如果n-1个皇后放置不了的可能性减小。
                        }
                }
            }
            if(count > 0) 
            {
                x[k++] = j;
                System.out.println("k = " + k+" x[k-1] = " + x[k-1]);
            }
        }
                    
        return  (count> 0);
    }
    
    public static  void nQueen()
    {
        x = new int[n+1];
        for(int i = 0; i <= n; i++)
        {
            x[i]= 0;
        }
        
        while(!queensLV());
        System.out.println("-----解法--------");
        for(int i = 1; i <= n; i++)
        {
            System.out.println("("+i + " , " +x[i]+")" );
        }       
    }
    
    public static void main(String[] args)
    {
        rnd = new Random();
        n = 8;
        nQueen();
    }
}

