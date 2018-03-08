#include <iostream>
using namespace std;
#define MAXIMUM  50

template<typename ElemType>
class SqQueue {
public :
	explicit SqQueue() {
		init();
	}
	~SqQueue() {}
	void init() {
		front = 0;
		rear = 0;
	}
	int getLength() const {
		return (rear - front + MAXIMUM) % MAXIMUM;
	}
	void clear() {
		init();
	}
	bool isEmpty() const{
		return front == rear ? true : false;
	}
	bool getHead(ElemType *e) {
		if (isEmpty())return false;
		else *e = data[front];
		return true;
	}
	bool enter_back(const ElemType e) {
		if ((rear + 1) % MAXIMUM == front) return false;
		else {
			data[rear++] = e;
			rear %= MAXIMUM;
			return true;
		}
	}
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