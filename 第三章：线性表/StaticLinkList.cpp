#include <iostream>
using namespace std;
#define MAXSIZE 100

template<typename ElemType>
class StaticLinkList {
public :
	StaticLinkList() { initList(); }
	~StaticLinkList(){}
	void initList() {
		for (int i = 0; i != MAXSIZE - 1; i++) sllist[i].cur = i + 1;
		sllist[MAXSIZE - 1].cur = 0;
		sllist[0].data = 0;
	}
	int mallocFromList() {
		/*��ǰ�����һ��Ԫ��cur��ֵ����Ҫ���صĵ�һ�����ÿռ���±�*/
		int i = sllist[0].cur;
		/*����������һ���±���ʹ��,�����Ҫ���һ���µı����±�*/
		if (sllist[0].cur != 0) sllist[0].cur = sllist[i].cur;
		return i;
	}
	/*�ڵ�i��Ԫ��ǰ����e*/
	bool listInsert(int i, ElemType e) {
		int k = MAXSIZE - 1;
		if (i<1 || i>sllist[0].data+1) return false;
		/*����һ������λ��*/
		int j = mallocFromList();
		if (j!=0) {
			/*�������ݸ��Ƹ��˷�����data*/
			sllist[j].data = e;
			/*�ҵ���i��Ԫ�ص�ǰһ��λ��*/
			for (int l = 1; l != i; l++) k = sllist[k].cur;
			/*����Ԫ�ص�cur��Ϊ��i��Ԫ��*/
			sllist[j].cur = sllist[k].cur;
			/*�ѵ�k��Ԫ�ص�cur��Ϊj*/
			sllist[k].cur = j;
			sllist[0].data++;
			return true;
		}
		return false;
	}
	bool listDelete(int i) {
		if (i<1 || i>sllist[0].data) return false;
		int k = MAXSIZE - 1;
		for (int j = 1; j != i; j++) k = sllist[k].cur;
		int j = sllist[k].cur;
		sllist[k].cur = sllist[j].cur;
		free(j);
		sllist[0].data--;
		return true;
	}
	/*���±�Ϊk�Ŀ��нڵ���ձ���*/
	void free(int k) {
		sllist[k].cur = sllist[0].cur;
		sllist[0].cur = k;
	}
	/*�������Ա���*/
	int getLength() const { return sllist[0].data; }
	/*�����Ա�Ϊ�շ���true�����򷵻�false*/
	bool isEmpty() const { return sllist[0].data == 0 ? true : false; }
		/*������Ա�*/
	void clearList() { 
		initList();
	}
	/*���ң����ұ�����e��ͬ��Ԫ�أ��ɹ��������±꣬���򷵻�-1*/
	int locateElem(ElemType e) const {
		if (isEmpty()) return -1;
		int k = MAXSIZE - 1;
		for (int i = 0; i != sllist[0].data; i++) {
			if (sllist[k].data == e)return k;
			k = sllist[k].cur;
		}
		return -1;
	}
	/*���Ԫ�أ���e���ظñ��е�i������Ԫ�ص�ֵ*/
	bool getElem(int i, ElemType *e) const {
		if (i<1 || i>sllist[0].data) return false;
		int k = MAXSIZE - 1;
		for (int j = 0; j != i; j++) {
			k = sllist[k].cur;
		}

		*e = sllist[k].data;
		return true;
	}
	/*��ӡ�����е�Ԫ��*/
	void show() const {
		if(!isEmpty()){
			int k = MAXSIZE-1;
			k = sllist[k].cur;
			cout << sllist[k].data;
			k = sllist[k].cur;
			while (k != 0 && cout << "->") {
				cout << sllist[k].data;
				k = sllist[k].cur;
			}
			cout << endl;
		}
		else cout << "List is empty!" << endl;
	}
private:
	struct Component {
		ElemType data;
		/*�α�(cursor),Ϊ0ʱ��ʾ��ָ��*/
		int cur;
	}sllist[MAXSIZE];
};
int main(void) {
	int e = 1;
	/*����һ�������Ա�*/
	StaticLinkList<int> mylist;
	mylist.show();
	cout << endl;
	/*��1-9-9���뵽���Ա�*/
	mylist.listInsert(1, e);
	e = 9;
	mylist.listInsert(2, e);
	mylist.listInsert(3, e);
	
	mylist.show();
	cout << "length :" << mylist.getLength() << endl;
	cout << endl;
	
	/*����һ��Ԫ�ص�ֵ���ظ�e*/
	mylist.getElem(1, &e);
	cout << "e��ֵΪ:" << e << endl;
	/*cout << "e���ڵ�λ��λ:" << mylist.locateElem(e)+1 << endl;*/
	
	/*ɾ�����Ա��еڶ���Ԫ��*/
	mylist.listDelete(2);
	mylist.show();
	cout << "length :" << mylist.getLength() << endl;
	
	
	/*������Ա�*/
	mylist.clearList();
	mylist.show();
	
	
	system("pause");
	return 0;

	return 0;
}