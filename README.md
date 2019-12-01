# algorithm_code
算法代码作业提交
#include <stdio.h>
int binary_search(int key,int a[],int n) //鑷畾涔夊嚱鏁癰inary_search()
{
int low,high,mid,count=0,count1=0;
low=0;
high=n-1;
while(low<high) //鏌绘壘鑼冨洿涓嶄负0鏃舵墽琛屽惊鐜綋璇彞
{
count++; //count璁板綍鏌绘壘娆℃暟
mid=(low+high)/2; //姹備腑闂翠綅缃?
if(key<a[mid]) //key灏忎簬涓棿鍊兼椂
high=mid-1; //纭畾宸﹀瓙琛ㄨ寖鍥?
else if(key>a[mid]) //key 澶т簬涓棿鍊兼椂
low=mid+1; //纭畾鍙冲瓙琛ㄨ寖鍥?
else if(key==a[mid]) //褰搆ey绛変簬涓棿鍊兼椂锛岃瘉鏄庢煡鎵炬垚鍔?
{
printf("鏌ユ壘鎴愬姛!\n 鏌ユ壘 %d 娆?a[%d]=%d",count,mid,key); //杈撳嚭鏌绘壘娆℃暟鍙婃墍鏌绘壘鍏冪礌鍦ㄦ暟缁勪腑鐨勪綅缃?
count1++; //count1璁板綍鏌ユ壘鎴愬姛娆℃暟
break;
}
}
if(count1==0) //鍒ゆ柇鏄惁鏌ユ壘澶辨晽
printf("鏌ユ壘澶辨晽!"); //鏌绘壘澶辨晽杈撳嚭no found
return 0;
}
int main()
{
int i,key,a[100],n;
printf("璇疯緭鍏ユ暟缁勭殑闀垮害锛歕n");
scanf("%d",&n); //杈撳叆鏁扮粍鍏冪礌涓暟
printf("璇疯緭鍏ユ暟缁勫厓绱狅細\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]); //杈撳叆鏈夊簭鏁板垪鍒版暟缁刟涓?
printf("璇疯緭鍏ヤ綘鎯虫煡鎵剧殑鍏冪礌锛歕n");
scanf("%d",&key); //杈撳叆瑕乛鎵剧殑鍏抽敭瀛?
binary_search(key,a,n); //璋冪敤鑷畾涔夊嚱鏁?
printf("\n");
return 0;
}
