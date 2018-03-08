#include <iostream>
using namespace std;
#define MAXIMUM  50


/************
队列的顺序储存--循环队列
front指向队列的前端
rear指向队列尾端元素的下一个位置
front==rear时队列为空
(rear + 1) % MAXIMUM == front 时队列满
*************/
template<typename ElemType>
class SqQueue {
public :
	explicit SqQueue() {
		init();
	}
	~SqQueue() {}
	//初始化队列
	void init() {
		front = 0;
		rear = 0;
	}
	//获取队列的长度
	int getLength() const {
		return (rear - front + MAXIMUM) % MAXIMUM;
	}
	void clear() {
		init();
	}
	bool isEmpty() const{
		return front == rear ? true : false;
	}
	//获取队头元素，不弹出
	bool getHead(ElemType *e) {
		if (isEmpty())return false;
		else *e = data[front];
		return true;
	}
	//将元素e插入队尾
	bool enter_back(const ElemType e) {
		if ((rear + 1) % MAXIMUM == front) return false;
		else {
			data[rear++] = e;
			rear %= MAXIMUM;
			return true;
		}
	}
	//弹出队头元素到e
	bool delete_front(ElemType *e) {
		if (isEmpty()) return false;
		else {
			*e = data[front++];
			front %= MAXIMUM;
			return true;
		}
	}
private:
	ElemType data[MAXIMUM];
	int front;
	int rear;
};

int main(void) {
	SqQueue<int> myqueue;
	int anum=5;
	cout << "queue's length :" << myqueue.getLength() << endl;
	
	myqueue.enter_back(anum);
	anum = 6;
	myqueue.enter_back(anum);
	cout << "queue's length :" << myqueue.getLength() << endl;
	myqueue.getHead(&anum);
	cout << "a :" << anum << endl;
	cout << "queue's length :" << myqueue.getLength() << endl;

	myqueue.delete_front(&anum);
	cout << "a :" << anum << endl;
	cout << "queue's length :" << myqueue.getLength() << endl;

	myqueue.clear();
	cout << "queue's length :" << myqueue.getLength() << endl;

	system("pause");
	return 0;
}