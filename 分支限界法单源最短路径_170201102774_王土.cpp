#include<iostream>

using namespace std;
#define defaultSize 10000
#define MAXINT 10000

//================================================MinHeap.h=================================================

template<class T>
class MinHeap {
public:
	MinHeap(int sz);         //最小堆的默认构造函数
	MinHeap(T arr[], int sz);             //通过一个数组创建构造函数
	~MinHeap();                            //析构函数
	bool insert(const T& x);              //将x插入到最小堆中
	bool removeMin(T& x);                //删除最小堆中最小的元素，保存至x中
private:
	T* _heap;                              //存放堆中元素的数组
	int _currentSize;                       //最小堆中当前元素的个数
	int _maxHeapSize;                       //最小堆中最多允许的个数
	void shifDown(int start, int end);      //从start 到end下滑调整为最小堆
	void shifUp(int start);                //从start 到0上滑调整为最小堆
};
//最小堆的默认构造函数
template<class T>
MinHeap<T>::MinHeap(int sz /*= defaultSize*/) {
	_maxHeapSize = (sz > defaultSize) ? sz : defaultSize;          //_maxHeapSize为参数sz与defaultSize中的较大者
	_heap = new T[_maxHeapSize];                                   //为存放堆元素的数组分配内存
	if (_heap == nullptr) {                                        //内存分配失败
		cerr << "内存分配错误！" << endl;
		exit(-1);
	}
	_currentSize = 0;                                             //当前堆元素数量为0
}
//通过一个数组创建构造函数
template<class T>
MinHeap<T>::MinHeap(T arr[], int sz) {
	_maxHeapSize = (sz > defaultSize) ? sz : defaultSize;          //_maxHeapSize为参数sz与defaultSize中的较大者
	_heap = new T[_maxHeapSize];                                   //为存放堆元素的数组分配内存
	if (_heap == nullptr) {                                        //内存分配失败
		cerr << "内存分配错误！" << endl;
		exit(-1);
	}

	for (int i = 0; i < sz; i++)                                     //将参数数组中的元素一一赋值给堆元素
		_heap[i] = arr[i];
	_currentSize = sz;                                             //为堆元素数量赋值，和参数数组大小相同

	int currentPos = (_currentSize - 2) / 2;                       //临时变量，指向最后一个有叶节点的堆
	while (currentPos >= 0) {
		shifDown(currentPos, _currentSize - 1);                    //自底向上(对于整个堆而言)-自上而下(对于局部堆而言)调整为堆
		currentPos--;
	}
}
//从start 到end下滑调整为最小堆
template<class T>
void MinHeap<T>::shifDown(int start, int end) {
	//私有函数：从结点start开始，到end为止，自上向下比较，如果
	//子女的值小于父节点的值，则关键码小的值上浮，继续向下层比较
	//这样将一个集合局部调整为最小堆
	int i = start;
	int j = 2 * i + 1;                             //指向i的左结点
	T tempValue = _heap[i];                        //临时保存下标为start结点的值
	while (j <= end) {                             //未达到end结束结点，一直循环
		if (j < end && _heap[j] > _heap[j + 1])    //如果有右结点，并且右结点小于左结点
			j++;                                    //j就指向右结点
		if (tempValue <= _heap[j])                 //如果父节点小于等于左右结点，就直接进行下一层循环
			break;
		else {
			_heap[i] = _heap[j];                     //否则将子结点的值赋值给父节点
			i = j;                                   //使i指向子节点
			j = 2 * i + 1;                           //j指向i的子结点
		}
	}
	_heap[i] = tempValue;                            //回返
}
//从start 到end上滑调整为最小堆
template<class T>
void MinHeap<T>::shifUp(int start) {
	//私有函数，从结点start开始到结点0为止，自下向上比较
	//如果子女的值小于父节点的值，则相互交换
	//这样将集合重新调整为最小堆
	int j = start;
	int i = (j - 2) / 2;                          //将i指向j的父节点
	T tempValue = _heap[j];                       //tempValue暂存_heap[j]的值
	while (j > 0) {                               //在未达到父节点之前，一直循环
		if (tempValue >= _heap[i])                //如果子结点大于等于父节点就直接进行下一层循环
			break;
		else {
			_heap[i] = _heap[j];
			j = i;                                //j指向当前的父节点
			i = (j - 2) / 2;                      //i指向j的父节点
		}
	}
	_heap[j] = tempValue;                         //回返
}
//析构函数
template<class T>
MinHeap<T>::~MinHeap() {
	if (_heap != nullptr)
		delete _heap;
}
//公共函数将x插入到最小堆中
template<class T>
bool MinHeap<T>::insert(const T& x) {
	if (isFull())                                           //如果已满，就不能进行插入
		return false;
	_heap[_currentSize] = x;                               //将参数赋值给新的堆元素
	shifUp(_currentSize);                                  //调用shifUp函数进行最小堆调整
	_currentSize++;                                        //参数个数自增加一
	return true;
}
//删除最小堆中最小的元素，保存至x中
template<class T>
bool MinHeap<T>::removeMin(T& x) {
	if (isEmpty())                                         //如果已空,就不能进行删除
		return false;
	x = _heap[0];                                         //堆顶元素赋值给返回参数x
	_heap[0] = _heap[_currentSize - 1];                   //将最后一个元素赋值给堆顶元素
	_currentSize--;                                     //参数个数自减减一
	shifDown(0, _currentSize - 1);                        //调用shifDown函数进行最小堆调整  
	return true;
}


//===================================BranchBoundShortPath.h=================================================

class BranchBoundShortPath{
	friend void findBranchShortPathAnswer();
public:
	void findShortPath();
	BranchBoundShortPath();
	BranchBoundShortPath(int n, int v, int* dist, int* prev, int** c);

private:
	int n;	//顶点个数
	int* prev;	//前驱结点
	int** c;	//图邻接矩阵
	int* dist;	//最短距离
	int v;	//开始点
};

class MinHeapNode{
	friend BranchBoundShortPath;
public:
	operator int () const { return length; }
	MinHeapNode(int i=0, int length=0);

private:
	int i;	//顶点编号
	int length;	//当前路长
};

//==================================BranchBoundShortPath.cpp============================================

#define MAXINT 1000

using namespace std;

BranchBoundShortPath::BranchBoundShortPath() {
	int** ppc = new int* [5];
	ppc[0] = new int[5]{ 0, 10, MAXINT, 30, 100 };
	ppc[1] = new int[5]{ MAXINT, 0, 50, MAXINT, MAXINT };
	ppc[2] = new int[5]{ MAXINT, MAXINT, 0, MAXINT, 10 };
	ppc[3] = new int[5]{ MAXINT, MAXINT, 20, 0, 60 };
	ppc[4] = new int[5]{ MAXINT, MAXINT, MAXINT, MAXINT, 0 };
	this->c = ppc;
	this->dist = new int[5];
	this->n = 5;
	this->prev = new int[5];
	this->v = 0;
}

BranchBoundShortPath::BranchBoundShortPath(int n, int v, int* dist, int* prev, int** c)
{
	this->c = c;
	this->dist = dist;
	this->n = n;
	this->prev = prev;
	this->v = v;
}

MinHeapNode::MinHeapNode(int i, int length) {
	this->i = i;
	this->length = length;
}

void BranchBoundShortPath::findShortPath() {
	for (int i = 0; i < n; i++) {
		dist[i] = MAXINT;
	}
	MinHeap<MinHeapNode> h(1000);
	MinHeapNode e(v, 0);
	dist[e.i] = 0;
	while (true){
		for (int j = 1; j <= n; j++) {
			if (c[e.i][j] < MAXINT && (e.length + c[e.i][j] < dist[j])) {
				dist[j] = e.length + c[e.i][j];
				prev[j] = e.i;
				MinHeapNode node;
				node.i = j;
				node.length = dist[j];
				h.insert(node);
			}
		}
		if (!h.removeMin(e)) break;
	}
}

void findBranchShortPathAnswer() {
	cout << "算法5：(BranchBoundShortPath)分支限界法单源最短路径:" << endl;
	BranchBoundShortPath* b = new BranchBoundShortPath();
	b->findShortPath();
	cout << "到点5" << "的最短长度为：" << b->dist[4] << endl;
}

//=========================================main.cpp=====================================

int main(){
	//算法5：(BranchBoundShortPath)分支限界法单源最短路径
	findBranchShortPathAnswer();
	cout << endl;
	return 0;
}