#include <iostream>
using namespace std;

/*带表头的链表，表头data储存链表中数据的个数*/
template<typename ElemType>
class LinkList {

public:
	/*构造函数，构建一个空表*/
	LinkList() {
		list = new Node();
		list->data = 0;
		list->next = NULL;
	}
	~LinkList() {}
	/*返回线性表长度*/
	int getLength() const { return list->data; }
	/*若线性表为空返回true，否则返回false*/
	bool isEmpty() const { return list->data == 0 ? true : false; }
	/*清空线性表*/
	void clearList() { 
		if (isEmpty()) return;	
		else {
			Node *p, *q;
			p = q = list->next;
			while (p->next) {
				q = p->next;
				delete p;
				p = q;
			}
			delete p;

			list->data = 0;
		}
	}
	/*查找：查找表中与e相同的元素，成功返回其下标，否则返回-1*/
	int locateElem(ElemType e) const{
		if (isEmpty()) return -1;
		Node *p = list->next;
		int k = 1;
		while (p)
		{
			if (p->data == e)return k;
			p = p->next;
			k++;
		}
		return -1;
	}
	/*获得元素：用e返回该表中第i个数据元素的值*/
	bool getElem(int i, ElemType *e) const{
		/*声明一指针p*/
		Node *p;
		/*让p指向链表的第一个节点*/
		p = list->next;
		/*j为计数器*/
		int j = 1;
		/*p不为空且计数器j不等于i时循环继续*/
		while (p &&j != i)
		{
			p = p->next;
			++j;
		}
		if (!p || j > i)return false;
		*e = p->data;
		return true;
	}
	/*插入：在表中第i个位置插入e，length+1*/
	bool listInsert(int i, ElemType e) {	
		int j = 1;
		Node *p, *s;
		p = list;
		while (p&&j!=i)
		{
			p = p->next;
			++j;
		}
		/*第i个节点不存在*/
		if (!p || j > i)return false;
		/*生成新节点*/
		s = new Node();
		s->data = e;
		/*将p的后继复制给s的后继*/
		s->next = p->next;
		/*将p的后继置为s*/
		p->next = s;
		list->data++;
		return true;
	}
	/*删除：删除表中第i个数据元素并返回给e，length-1*/
	bool listDelete(int i, ElemType *e) {
		int j = 1;
		Node *p, *q;
		p = list;
		/*遍历寻找第i-1个节点*/
		while (p->next&&j != i) {
			p = p->next;
			++j;
		}
		/*第i个节点不存在*/
		if (!(p->next) || j > i)return false;
		q = p->next;
		/*将p的后继置为q的后继*/
		p->next = q->next;
		*e = q->data;
		/*回收节点q*/
		delete q;
		list->data--;
		return true;
	}
	/*打印链表中的元素*/
	void show() const{
		if(0!=list->data){
			Node *p = list->next;
			cout << p->data;
			p = p->next;
			while (p&&cout<<"->") {
				cout << p->data;
				p = p->next;
			}
			cout << endl;
		}
		else cout << "List is empty!" << endl;
	}
private:
	class Node
	{
	public :
		ElemType data;
		Node *next; 
	}*list;
};


int main(void) {
	int e = 1;
	/*创建一个空线性表*/
	LinkList<int> mylist;
	mylist.show();
	cout << endl;
	/*将1-9-9插入到线性表*/
	mylist.ListInsert(1, e);
	e = 9;
	mylist.ListInsert(2, e);
	mylist.ListInsert(3, e);

	mylist.show();
	cout << "length :" << mylist.getLength() << endl;
	cout << endl;

	/*将第一个元素的值返回给e*/
	mylist.GetElem(1, &e);
	cout << "e的值为:" << e << endl;
	/*cout << "e所在的位置位:" << mylist.locateElem(e)+1 << endl;*/

	/*删除线性表中第二个元素*/
	mylist.ListDelete(2, &e);
	mylist.show();
	cout << "length :" << mylist.getLength() << endl;


	/*清空线性表*/
	mylist.clearList();
	mylist.show();


	system("pause");
	return 0;
}