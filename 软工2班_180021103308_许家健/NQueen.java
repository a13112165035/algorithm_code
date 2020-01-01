/*
 * 拉斯维加斯算法 皇后问题
 */

package lasVegasAlgorithm;

import java.util.Random;

public class NQueen {
	static int SIZE = 8;// 问题规模
	static Random rnd = new Random(SIZE);// 随机数发生器
	static int[] queen = new int[SIZE];// 解向量

	public static void main(String[] args) {
		nQueen();
	}
	
	public static void nQueen() {
		while (!queensLV())
			;
		System.out.println("----------------------");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (queen[i] == j) {
					System.out.print(" Q ");
				} else {
					System.out.print(" . ");
				}
			}
			System.out.println();
		}
	}

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
						// break;
					}
				}
			}
			if (count > 0) {
				queen[row++] = j;
			}
		}
		return (count > 0);
	}

	

}