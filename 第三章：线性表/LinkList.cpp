#include <iostream>
using namespace std;

/*����ͷ��������ͷdata�������������ݵĸ���*/
template<typename ElemType>
class LinkList {

public:
	/*���캯��������һ���ձ�*/
	LinkList() {
		list = new Node();
		list->data = 0;
		list->next = NULL;
	}
	~LinkList() {}
	/*�������Ա���*/
	int getLength() const { return list->data; }
	/*�����Ա�Ϊ�շ���true�����򷵻�false*/
	bool isEmpty() const { return list->data == 0 ? true : false; }
	/*������Ա�*/
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
	/*���ң����ұ�����e��ͬ��Ԫ�أ��ɹ��������±꣬���򷵻�-1*/
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
	/*���Ԫ�أ���e���ظñ��е�i������Ԫ�ص�ֵ*/
	bool getElem(int i, ElemType *e) const{
		/*����һָ��p*/
		Node *p;
		/*��pָ������ĵ�һ���ڵ�*/
		p = list->next;
		/*jΪ������*/
		int j = 1;
		/*p��Ϊ���Ҽ�����j������iʱѭ������*/
		while (p &&j != i)
		{
			p = p->next;
			++j;
		}
		if (!p || j > i)return false;
		*e = p->data;
		return true;
	}
	/*���룺�ڱ��е�i��λ�ò���e��length+1*/
	bool listInsert(int i, ElemType e) {	
		int j = 1;
		Node *p, *s;
		p = list;
		while (p&&j!=i)
		{
			p = p->next;
			++j;
		}
		/*��i���ڵ㲻����*/
		if (!p || j > i)return false;
		/*�����½ڵ�*/
		s = new Node();
		s->data = e;
		/*��p�ĺ�̸��Ƹ�s�ĺ��*/
		s->next = p->next;
		/*��p�ĺ����Ϊs*/
		p->next = s;
		list->data++;
		return true;
	}
	/*ɾ����ɾ�����е�i������Ԫ�ز����ظ�e��length-1*/
	bool listDelete(int i, ElemType *e) {
		int j = 1;
		Node *p, *q;
		p = list;
		/*����Ѱ�ҵ�i-1���ڵ�*/
		while (p->next&&j != i) {
			p = p->next;
			++j;
		}
		/*��i���ڵ㲻����*/
		if (!(p->next) || j > i)return false;
		q = p->next;
		/*��p�ĺ����Ϊq�ĺ��*/
		p->next = q->next;
		*e = q->data;
		/*���սڵ�q*/
		delete q;
		list->data--;
		return true;
	}
	/*��ӡ�����е�Ԫ��*/
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
	/*����һ�������Ա�*/
	LinkList<int> mylist;
	mylist.show();
	cout << endl;
	/*��1-9-9���뵽���Ա�*/
	mylist.ListInsert(1, e);
	e = 9;
	mylist.ListInsert(2, e);
	mylist.ListInsert(3, e);

	mylist.show();
	cout << "length :" << mylist.getLength() << endl;
	cout << endl;

	/*����һ��Ԫ�ص�ֵ���ظ�e*/
	mylist.GetElem(1, &e);
	cout << "e��ֵΪ:" << e << endl;
	/*cout << "e���ڵ�λ��λ:" << mylist.locateElem(e)+1 << endl;*/

	/*ɾ�����Ա��еڶ���Ԫ��*/
	mylist.ListDelete(2, &e);
	mylist.show();
	cout << "length :" << mylist.getLength() << endl;


	/*������Ա�*/
	mylist.clearList();
	mylist.show();


	system("pause");
	return 0;
}