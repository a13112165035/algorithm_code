
import java.util.*;

public class las {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Random r = new Random(1);
		ArrayList<Integer> x = new ArrayList<Integer>();
		for(int i = 0; i < 100; i++) {
			x.add(r.nextInt(100));
		}
		int k = r.nextInt(100);
		System.out.println("在x中第 %d小的数字是： "+k);
		System.out.println(NKS_LV(x, k));
		
	}

	private static int NKS_LV(ArrayList<Integer> x, int k) {
		// TODO 自动生成的方法存根
		int len = x.size();
		Random r = new Random(1);
		int s = x.get(r.nextInt(len));
		ArrayList<Integer> S1 = new ArrayList<Integer>();
		ArrayList<Integer> S2 = new ArrayList<Integer>();
		ArrayList<Integer> S3 = new ArrayList<Integer>();

		for(int i = 0; i < len; i++) {
			int xx = x.get(i);
			if (xx < s) {
				S1.add(xx);
			}else if (xx == s){
				S2.add(xx);
			}else {
				S3.add(xx);
			}
		}
		if (k <= S1.size()) {
			return NKS_LV(S1,k);
		}else if ( k <= S1.size() + S2.size()) {
			return s;
		}else {
			return NKS_LV(S3, k - S1.size() - S2.size());
		}
			
	}

}