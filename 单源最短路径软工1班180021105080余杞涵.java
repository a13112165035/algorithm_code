import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
/** 单源最短路径问题 */
public class MinimumPath {
/** 节点个数 */
private int mapSize = 5;
private int totalNum = 0;
/** 组织节点间关系的二维数组 */
private int[][] map = null;
/** 红点集合，记录已经被走过的顶点 */
private List<Integer> redPoint = new ArrayList<Integer>();
/** 蓝点集合，记录未走过的定点 */
private List<Integer> bluePoint = new LinkedList<Integer>();
public MinimumPath() {
// 初始化由树转化成的二维数组
initiMap();
setMap();

// 初始化未走过的节点
for (int i = 0; i < mapSize; ++i) {
bluePoint.add(i);
}

// 打印将数转换成的二维数组，按这个数组寻找最短路径
printMap();
}
/**
* 贪心算法递归求解最短路径
* @param startPoint：开始查找节点，下标从零开始
*/
public void minStep(int startPoint) {
// 如果输入不合法，则会退出
if (startPoint >= mapSize || startPoint < 0) {
totalNum = Integer.MAX_VALUE;
return;
}
// 将startPoint从为走过的节点去除，加入到走过的节点
redPoint.add(new Integer(startPoint));
bluePoint.remove(new Integer(startPoint));
// 如果完成则退出
if (startPoint == mapSize - 1) {
return;
}
// 在未走过的节点中选择最短的路径
int temp = Integer.MAX_VALUE;
int step = 0;
Iterator<Integer> iter = bluePoint.iterator();
for (int i = 0; i < bluePoint.size() && iter.hasNext(); ++i) {
int j = iter.next();
if (temp > map[startPoint][j]) {
temp = map[startPoint][j];
step = j;
}
}
// 将最短路径加起来，并进入递归求解
totalNum += temp;
minStep(step);
}
/**
* 打印map
*/
private void printMap() {
System.out.println("本程序以书上的节点为例， $代表无穷远");
for (int j = 0; j < mapSize; ++j) {
for (int i = 0; i < mapSize; ++i) {
if (map[j][i] == Integer.MAX_VALUE) {
// $表示不能到达
System.out.print("$\t");
} else {
System.out.print(map[j][i] + "\t");
}
}
System.out.println();
}
}
/**
* 为map赋初值
*/
private void setMap() {
// 第零个节点和其他节点的距离，未赋值代表无穷远
map[0][0] = 0;
map[0][1] = 10;
map[0][3] = 30;
map[0][4] = 100;
// 第一个节点到其他节点的距离，未负值代表无穷远
map[1][1] = 0;
map[1][2] = 50;
// 第二个节点到其他节点的距离，未负值代表无穷远
map[2][2] = 0;
map[2][4] = 10;
// 第三个节点到其他节点的距离，未赋值代表无穷远
map[3][2] = 20;
map[3][3] = 0;
map[3][4] = 60;
// 第四个节点到其他节点的距离，未赋值代表无穷远
map[4][4] = 0;
}
/**
* 初始化map
*/
private void initiMap() {
// 实例化并初始化map, Integer.MAX_VALUE表示不能到达
map = new int[mapSize][mapSize];
for (int j = 0; j < mapSize; ++j) {
for (int i = 0; i < mapSize; ++i) {
map[j][i] = Integer.MAX_VALUE;
}
}
}
public List<Integer> getRedPoint() {
return redPoint;
}
public int getTotalNum() {
return totalNum;
}
public static void main(String[] args) {
MinimumPath path = new MinimumPath();
System.out.println("请输入开始的节点（下表从零开始）：");

// 获取输入节点， 比计算到达末节点的单源最短路径
Scanner sc = new Scanner(System.in);
int v = sc.nextInt();
path.minStep(v);

// 遍历路径
List<Integer> red = path.getRedPoint();
for (Integer i : red) {
System.out.print(i + " -> " + "\t");
}

// 输出最短距离
int total = path.getTotalNum();
if(total != Integer.MAX_VALUE){
System.out.println("最短路径：" + total);
} else {
System.out.println("对不起，不能到达！");
}
}
}