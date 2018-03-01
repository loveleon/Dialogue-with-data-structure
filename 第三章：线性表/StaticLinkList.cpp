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
		/*当前数组第一个元素cur的值，即要返回的第一个备用空间的下标*/
		int i = sllist[0].cur;
		/*由于申请了一个下标来使用,因此需要获得一个新的备用下标*/
		if (sllist[0].cur != 0) sllist[0].cur = sllist[i].cur;
		return i;
	}
	/*在第i个元素前插入e*/
	bool listInsert(int i, ElemType e) {
		int k = MAXSIZE - 1;
		if (i<1 || i>sllist[0].data+1) return false;
		/*申请一个空闲位置*/
		int j = mallocFromList();
		if (j!=0) {
			/*将此数据复制给此分量的data*/
			sllist[j].data = e;
			/*找到第i个元素的前一个位置*/
			for (int l = 1; l != i; l++) k = sllist[k].cur;
			/*把新元素的cur置为第i个元素*/
			sllist[j].cur = sllist[k].cur;
			/*把第k个元素的cur置为j*/
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
	/*将下标为k的空闲节点回收备用*/
	void free(int k) {
		sllist[k].cur = sllist[0].cur;
		sllist[0].cur = k;
	}
	/*返回线性表长度*/
	int getLength() const { return sllist[0].data; }
	/*若线性表为空返回true，否则返回false*/
	bool isEmpty() const { return sllist[0].data == 0 ? true : false; }
		/*清空线性表*/
	void clearList() { 
		initList();
	}
	/*查找：查找表中与e相同的元素，成功返回其下标，否则返回-1*/
	int locateElem(ElemType e) const {
		if (isEmpty()) return -1;
		int k = MAXSIZE - 1;
		for (int i = 0; i != sllist[0].data; i++) {
			if (sllist[k].data == e)return k;
			k = sllist[k].cur;
		}
		return -1;
	}
	/*获得元素：用e返回该表中第i个数据元素的值*/
	bool getElem(int i, ElemType *e) const {
		if (i<1 || i>sllist[0].data) return false;
		int k = MAXSIZE - 1;
		for (int j = 0; j != i; j++) {
			k = sllist[k].cur;
		}

		*e = sllist[k].data;
		return true;
	}
	/*打印链表中的元素*/
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
		/*游标(cursor),为0时表示无指向*/
		int cur;
	}sllist[MAXSIZE];
};
int main(void) {
	int e = 1;
	/*创建一个空线性表*/
	StaticLinkList<int> mylist;
	mylist.show();
	cout << endl;
	/*将1-9-9插入到线性表*/
	mylist.listInsert(1, e);
	e = 9;
	mylist.listInsert(2, e);
	mylist.listInsert(3, e);
	
	mylist.show();
	cout << "length :" << mylist.getLength() << endl;
	cout << endl;
	
	/*将第一个元素的值返回给e*/
	mylist.getElem(1, &e);
	cout << "e的值为:" << e << endl;
	/*cout << "e所在的位置位:" << mylist.locateElem(e)+1 << endl;*/
	
	/*删除线性表中第二个元素*/
	mylist.listDelete(2);
	mylist.show();
	cout << "length :" << mylist.getLength() << endl;
	
	
	/*清空线性表*/
	mylist.clearList();
	mylist.show();
	
	
	system("pause");
	return 0;

	return 0;
}