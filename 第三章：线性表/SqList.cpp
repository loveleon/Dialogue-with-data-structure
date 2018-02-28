#include <iostream>
using namespace std;
#define MAXSIZE 20

template<typename ElemType>
class SqList {
public:
	/*���캯��������һ���ձ�*/
	SqList() { length = 0; }
	~SqList() {}
	/*�������Ա���*/
	int getLength() const { return length; }
	/*�����Ա�Ϊ�շ���true�����򷵻�false*/
	bool isEmpty() const { return length == 0 ? true : false; }
	/*������Ա�*/
	void clearList() { length = 0; }
	/*���ң����ұ�����e��ͬ��Ԫ�أ��ɹ��������±꣬���򷵻�-1*/
	int locateElem(ElemType e) const {
		for (int i = 0; i != length; i++) {
			if (data[i] == e) return i;
		}
		return -1;
	}
	/*���Ԫ�أ���e���ظñ��е�i������Ԫ�ص�ֵ*/
	bool getElem(int i, ElemType *e)const {
		if (0 == length || i<1 || i>length)return false;
		*e = data[i - 1];
		return true;
	}
	/*���룺�ڱ��е�i��λ�ò���e��length+1*/
	bool listInsert(int i, ElemType e) {
		int k;
		/*˳�����Ա�����*/
		if (length == MAXSIZE) return false;
		/*��i���ڷ�Χ��ʱ*/
		if (i<1 || i>length+1)return false;
		/*����������λ�ò��ڱ�β*/
		if (i <= length) {
			/*��Ҫ����λ�ú�Ԫ������ƶ�һλ*/
			for (k = length - 1; k != i; k--) {
				data[k + 1] = data[k];
			}
		}
		data[i - 1] = e;
		length++;
		return true;	
	}
	/*ɾ����ɾ�����е�i������Ԫ�ز����ظ�e��length-1*/
	bool listDelete(int i, ElemType *e) {
		int k;
		/*���Ա�Ϊ��*/
		if (0 == length)return false;
		/*ɾ��λ�ò���ȷ*/
		if (i<1 || i>length) return false;
		/*���ɾ���Ĳ������λ��*/
		if (i < length) {
			/*��ɾ��λ�ú��Ԫ��ǰ��*/
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
	/*����һ�������Ա�*/
	SqList<int> mylist;
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
	cout << "e���ڵ�λ��λ:" << mylist.locateElem(e)+1 << endl;

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