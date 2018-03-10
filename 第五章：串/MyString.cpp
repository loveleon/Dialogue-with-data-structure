#include <iostream>
#include <vector>
using namespace std;
#define MAXIMUM 100
/****************
串结构
MAXIMUM为串的最大容量
*****************/
class MyString {
public :
	//创建一个空串
	explicit MyString() {
		init();
	}
	//同strAssign()生成一个等于字符串常量chars的新串
	explicit MyString(const char* chars) {
		init();
		int i = 0;
		while (*(chars+i) != 0) {
			data[i] = chars[i];
			i++;
		}
	}
	//同strCopy，由串S复制得新串
	MyString(const MyString& S) {
		init();
		for (int i = 0; i != S.length(); i++) {
			data[i] = S.getIndex(i);
		}
	}
	//获取串index处的字符
	char getIndex(int i) const{
		return data[i];
	}
	//改变串index处的字符 失败直接返回
	void setIndex(int i, char c) {
		if (i > length() || i < 0) return;
		data[i] = c;
	}
	//获取串的长度
	int length() const{
		int count = 0;
		while (data[count] != 0) count++;
		return count;
	}
	//清空串
	void clear() {
		init();
	}
	//串是否为空
	bool isEmpty() const { return length() == 0 ? true : false; }
	//若本串>S串 返回 1 相等返回0 否则返回 -1；
	int compare(const MyString& S) {
		int length1 = length();
		int length2 = S.length();
		if (length1 != length2) return length1 > length2 ? 1 : -1;
		else {
			for (int i = 0; i != length1; i++) {
				if (data[i] != S.getIndex(i)) return data[i] > S.getIndex(i) ? 1 : -1;
			}
			return 0;
		}
	}
	//重载<<
	friend std::ostream& operator<<(std::ostream& os, MyString& T) {
		int i = 0;
		while (T.getIndex(i) != 0) {
			cout << T.getIndex(i);
			i++;
		}
		return os;
	}
	//重载 + ：等于concat 返回一个由str1 , str2 拼接的串
	MyString operator+(const MyString &str2) {
		MyString resstr;
		int length1 = length();
		int length2 = str2.length();
		if (length1 + length2 >= MAXIMUM) return resstr;
		for (int i = 0; i != length1; i++) resstr.setIndex(i, data[i]);
		for (int i = 0; i != length2; i++) resstr.setIndex(length1 + i, str2.getIndex(i));
		return resstr;
	}
	//返回串中 pos -> pos + length 的字串
	MyString subString(int pos, int length1) {
		MyString resstr;
		if (pos - 1 + length1 >= length() || pos < 1 || length1 < 0) return resstr;
		for (int i = 0; i != length1; i++) resstr.setIndex(i, data[pos - 1 + i]);
		return resstr;
	}
	//查找串中是否包含串T 找到返回第一个字符下标，否则返回-1
	int index_KMP(const MyString& T, int pos) {
		int length1 = length();
		int length2 = T.length();
		if (length1 < length2) return -1;
		else if (length1 == 0) return 0;
		else {
			vector<int> next;
			_next(T,next);
			int cur1 = 0, cur2 = 0;
			while (length1 - cur1 > length2 - cur2) {
				while (data[cur1 + cur2] == T.getIndex(cur2)) {
					if (cur2 == length2 - 1) return cur1;
					cur2++;
				}
				if (cur2 == 0) cur1++;
				else {
					cur1 += cur2 - next[cur2 - 1];
					cur2 -= cur2 - next[cur2 - 1];
				}
			}
			return -1;
		}
	}
	//将串T插入在str的pos前
	void insert(int pos, const MyString& T) {
		int length1 = length();
		int length2 = T.length();
		if (pos < 1 || pos > length1) return;
		if (length1 + length2 > MAXIMUM) return;
		pos -= 1;
		for (int i = length1 - 1; i != pos - 1; i--) data[i + length2] = data[i];
		for (int i = 0; i != length2; i++) {
			data[pos + i] = T.getIndex(i);
		}
	}
	//删除串中 pos -> pos + length 字符
	void _delete(int pos, int length) {
		int length1 = this->length();
		if (pos < 1 || pos > length1) return; 
		if (length > this->length()) return;
		pos -= 1;
		for (int i = pos; i != length1 - pos; i++) {
			data[i] = data[i + length];
		}
		for (int i = length1 - length; i != length1; i++) data[i] = 0;
	}
private:
	//初始化串
	void init() {
		for (int i = 0; i != MAXIMUM; i++) {
			data[i] = 0;
		}
	}
	//K.M.P串匹配  ---  Partial_Match_Table
	void _next(const MyString& T, vector<int>& next) {
		int length = T.length();
		for (int i = 0; i != length; i++) {
			next.push_back(0);
		}
		int k = 0;
		for (int i = 1; i != length; i++) {
			if (T.getIndex(k) == T.getIndex(i)) {
				next[i] = next[i - 1] + 1;
				k++;
			}
			else k = 0;
		}

	}
private:
	char data[MAXIMUM];
};

int main(void) {
	MyString str1("bacbaabababcababaabcbab\0");
	MyString str ("abababca\0");
	MyString str2(str);

	cout << str1 << endl << str2 <<endl;
	cout << "str1 length :" << str1.length() << endl << "str2 length :" << str2.length() << endl;
	cout << "Compare(str1, str2) :" << str1.compare(str2) << endl;
	MyString str3(str1 + str2);
	cout << "str1 + str2 = " << str3 << endl;
	MyString str4(str1.subString(1, 5));
	cout << "str1 sub(pos = 1, length = 5)" << str4 << endl;
	cout << "str1 contains str2 ? index_K.M.P : " << str1.index_KMP(str2, 0) + 1 << endl;
	str1.insert(3, str2);
	cout << "insert str2 into str1 ---insert(pos = 3):" << str1 << endl;
	cout << "str1 length :" << str1.length() << endl;
	str1._delete(2, 10);
	cout << "str1_delete(pos = 2, length = 10):" << str1 << endl;
	cout << "str1 length :" << str1.length() << endl;
	system("pause");
	return 0;
}

