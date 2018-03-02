#include <iostream>
using namespace std;
#define MAXSIZE 100

template<typename ElemType>
class LinkStack {
public :
	LinkStack() { init(); }
	~LinkStack() {
		clear();
		delete top;
	}
	void init(){
		count = 0;
		top = new StackNode();
		if (top == NULL) { cout << "ERROR"; return; }
		top->next = NULL;
	}
	void clear() {
		StackNode *p;
		while (count) {
			p = top;
			top = top->next;
			delete p;
			count--;
		}
	}
	int getLength() { return count; }
	bool isEmpty() { return count == 0 ? true : false; }
	bool getTop(ElemType *e) {
		if (isEmpty()) return false;
		*e = top->data;
		return true;
	}
	bool push(ElemType e) {
		StackNode *s = new StackNode();
		if (s == NULL)return false;
		s->data = e;
		/*��s�ĺ����Ϊԭջ��*/
		s->next = top;
		/*��ջ����Ϊs*/
		top = s;
		count++;
		return true;
	}
	bool pop(ElemType *e) {
		StackNode *p= new StackNode();
		if (p == NULL)return false;
		*e = top->data;
		/*��p��Ϊԭջ��*/
		p = top;
		/*ջ������*/
		top = top->next;
		/*�ͷ�ԭջ��*/
		delete p;
		count--;
	}

private :
	int count;
	struct StackNode {
		ElemType data;
		struct StackNode *next;
	}*top;
	
	
};
int main(void) {
	int e = 1;
	/*����һ����ջ*/
	LinkStack<int> mystack;
	cout << endl;
	/*��1-9-9���뵽ջ*/
	mystack.push(e);
	e = 9;
	mystack.push(e);
	mystack.push(e);
	
	e = 7;
	/*��topԪ�ص�ֵ���ظ�e*/
	mystack.getTop(&e);
	cout << "e:" << e << endl << "length :" << mystack.getLength() << endl;
	cout << endl;
	
	/*����ջ��Ԫ�ص�e*/
	mystack.pop(&e);
	cout << "e:" << e << endl << "length :" << mystack.getLength() << endl;
	

	/*���ջ*/
	mystack.clear();
	cout << "length :" << mystack.getLength() << endl;
	
	
	system("pause");
	return 0;

	return 0;
}
