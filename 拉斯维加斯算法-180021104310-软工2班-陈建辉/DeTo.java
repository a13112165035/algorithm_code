import java.util.*;
public class DeTo {

	// 问题规模
    static int SIZE =10;
    // 随机数发生器
    static Random rnd = new Random(SIZE);
    // 解向量
    static int[] queen = new int[SIZE];

    private static boolean check(int row) {
        for (int i = 0; i < queen.length && i != row; i++) {
            if (queen[i] == queen[row] || i - queen[i] == row - queen[row] || i + queen[i] == row + queen[row]) {
                return false;
            }
        }
        return true;
    }

    private static boolean queensLV() {
        int row = 0;
        int count = 1;
        while ((row < SIZE) && (count > 0)) {
            count = 0;
            int j = 0;
            for (int column = 0; column < SIZE; column++) {
                queen[row] = column;
                if (check(row)) {
                    if (rnd.nextInt(++count) == 0) {
                          j = column;
                        // break;//有break如果第一此找到合适的列place(k)满足，那么此时random（1）==0恒成立，遇到下面的break，就把皇后放置在这个位置。如果这种放置皇后的方案不可行，下次循环还会执行同样的，故一直循环调不出来找不到方案。即剩下的所有皇后放置不了的可能性增大。
                        // 没有break，会一直试探for循环结束。x[k]会在随机的选择当前可以放置的位置中for循环最后一个满足的列。那么后面如果n-1个皇后放置不了的可能性减小。
                    }
                }
            }
            if (count > 0) {
                queen[row++] = j;
            }
        }
        return (count > 0);
    }

    public static void nQueen() {
        while (!queensLV());
        System.out.println("-------------解法---------------");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j <10; j++) {
                if (queen[i] == j) {
                    System.out.print(" Q ");
                } else {
                    System.out.print(" . ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        nQueen();
    }
}
