#include<iostream>
using namespace std;
 
/*定义输出一维数组的函数*/
void print(int array[], int n)
{
     for (int i = 0; i < n; i++)
     {
         cout << array[i] << " ";
     }
     cout << endl;
 }
 
/*定义二分搜索的函数:array,有序序列；n，序列长度；x，要查找的数*/
int binarySearch(int array[], int n, int x)
{
     //初始化左右边界
     int left = 0, right = n - 1;
     //当左右边界不重合时
     while (left <= right)
     {
         //初始化边界的中点
         int middle = (left + right) / 2;
         //判断所查找元素和当前中点元素是否相等，如果相等则返回中点元素所在的位置
         if (x == array[middle])
         {
             return middle;
         }
         else if (x > array[middle])
         {
             //如果所查找元素大于中点元素，则所查找元素在右部分，则将左边界向右移
             left = middle + 1;
         }
         else{
             //说明所查找元素小于中点元素，则所查找元素在做部分，则将右边界向左移
             right = middle - 1;
         }
     }
     //如果找不到，则返回-1
     return -1;
 }

int main()
{
     //定义待排序的一维数组
     int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
     //输出原始数组
     cout << "原始数组是：" << endl;
     print(array, 10);
     //定义要查找的数
     int number;
     //输入要查找的数
     cout << "请输入要查找的数：";
     cin >> number;
     //调用二分搜索的函数进行查找
     int location = binarySearch(array, 10, number);
     if (location > 0)
     {
         //说明找到了
         cout << number << "在该序列中，是第" << (location + 1) << "个数" << endl;
     }
     else
     {
         //说明没找到
         cout << number << "不在该序列中..." << endl;
 
     }
     return 0;
}
