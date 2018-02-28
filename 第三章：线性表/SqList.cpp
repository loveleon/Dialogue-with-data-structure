#include <iostream>
using namespace std;
#define MAXSIZE 20

template<typename ElemType>
class SqList {
public:
	/*构造函数，构建一个空表*/
	SqList() { length = 0; }
	~SqList() {}
	/*返回线性表长度*/
	int getLength() const { return length; }
	/*若线性表为空返回true，否则返回false*/
	bool isEmpty() const { return length == 0 ? true : false; }
	/*清空线性表*/
	void clearList() { length = 0; }
	/*查找：查找表中与e相同的元素，成功返回其下标，否则返回-1*/
	int locateElem(ElemType e) const {
		for (int i = 0; i != length; i++) {
			if (data[i] == e) return i;
		}
		return -1;
	}
	/*获得元素：用e返回该表中第i个数据元素的值*/
	bool getElem(int i, ElemType *e)const {
		if (0 == length || i<1 || i>length)return false;
		*e = data[i - 1];
		return true;
	}
	/*插入：在表中第i个位置插入e，length+1*/
	bool listInsert(int i, ElemType e) {
		int k;
		/*顺序线性表已满*/
		if (length == MAXSIZE) return false;
		/*当i不在范围内时*/
		if (i<1 || i>length+1)return false;
		/*若插入数据位置不在表尾*/
		if (i <= length) {
			/*将要插入位置后元素向后移动一位*/
			for (k = length - 1; k != i; k--) {
				data[k + 1] = data[k];
			}
		}
		data[i - 1] = e;
		length++;
		return true;	
	}
	/*删除：删除表中第i个数据元素并返回给e，length-1*/
	bool listDelete(int i, ElemType *e) {
		int k;
		/*线性表为空*/
		if (0 == length)return false;
		/*删除位置不正确*/
		if (i<1 || i>length) return false;
		/*如果删除的不是最后位置*/
		if (i < length) {
			/*将删除位置后继元素前移*/
			for (k = i; k != length; k++) {
				data[k - 1] = data[k];
			}
		}
		length--;
		return true;
	}
	void show() const{
		if (length != 0) {
			cout << data[0];
			for (int i = 1; i != length && cout << "-"; i++) {
				cout << data[i];
			}
			cout << endl;
		}
		else cout << "List is empty!" << endl;
	}
private:
	ElemType data[MAXSIZE];
	int length;
};


int main(void) {
	int e = 1;
	/*创建一个空线性表*/
	SqList<int> mylist;
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
	cout << "e所在的位置位:" << mylist.locateElem(e)+1 << endl;

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