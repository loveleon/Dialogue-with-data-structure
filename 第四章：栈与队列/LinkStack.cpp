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
		/*将s的后继置为原栈顶*/
		s->next = top;
		/*将栈顶置为s*/
		top = s;
		count++;
		return true;
	}
	bool pop(ElemType *e) {
		StackNode *p= new StackNode();
		if (p == NULL)return false;
		*e = top->data;
		/*将p置为原栈顶*/
		p = top;
		/*栈顶下移*/
		top = top->next;
		/*释放原栈顶*/
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
	/*创建一个空栈*/
	LinkStack<int> mystack;
	cout << endl;
	/*将1-9-9插入到栈*/
	mystack.push(e);
	e = 9;
	mystack.push(e);
	mystack.push(e);
	
	e = 7;
	/*将top元素的值返回给e*/
	mystack.getTop(&e);
	cout << "e:" << e << endl << "length :" << mystack.getLength() << endl;
	cout << endl;
	
	/*弹出栈顶元素到e*/
	mystack.pop(&e);
	cout << "e:" << e << endl << "length :" << mystack.getLength() << endl;
	

	/*清空栈*/
	mystack.clear();
	cout << "length :" << mystack.getLength() << endl;
	
	
	system("pause");
	return 0;

	return 0;
}
