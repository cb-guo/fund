#include<iostream>
#include<string.h>
using namespace std;

// 自定义string
class MyString {
  public:
    MyString(char *str = nullptr);
    ~MyString();
    // 拷贝构造函数/拷贝赋值运算符
    MyString(const MyString& ms);
    MyString& operator=(const MyString& ms);
    // 移动构造函数/移动赋值运算符
    MyString(MyString&& ms);
    MyString& operator=(MyString&& ms);
    // operator+=
    MyString& operator+=(MyString& ms);
    char& operator[](int i);
    char& operator()(int i);
    void print_data() { cout << data << endl; }
  private:
    char *data;
};

MyString::~MyString() {
  delete[] data;
  cout << "xigou" << endl;
}
// 构造函数
MyString::MyString(char *str) {
  if (str == nullptr) {
    data = new char[1];
    *data = '\1';
    cout << "default gouzao" << endl;
  } else {
    int len = strlen(str);
    data = new char[len+1];
    strcpy(data, str);
    cout << "gouzao func" << endl;
  }
}
// 拷贝构造函数
MyString::MyString(const MyString& ms) {
  int len = strlen(ms.data);
  data = new char[len+1];
  strcpy(data, ms.data);
  cout << "kaobei gouzao func" << endl;
}
// 拷贝赋值运算符
MyString& MyString::operator=(const MyString& ms) {
  if (this != &ms) {
    delete[] data;
    data = nullptr;
    int len = strlen(ms.data);
    data = new char[len+1];
    strcpy(data, ms.data);
  }
  cout << "kaobei fuzhi op" << endl;
  return *this;
}
// 移动构造函数
MyString::MyString(MyString&& ms) {
  data = ms.data;
  ms.data = nullptr;
  cout << "move gouzao func" << endl;
}

// 移动赋值运算符
MyString& MyString::operator=(MyString&& ms) {
  if (this != &ms) {
    delete[] data;
    data = nullptr;
    data = ms.data;
  ms.data = nullptr;
  }
  cout << "move fuzhi op" << endl;
  return *this;
}

MyString& MyString::operator+=(MyString& ms) {
  int size1 = strlen(data);
  int size2 = strlen(ms.data);
  char *tmp = new char[size1 + size2 + 1];
  strcpy(tmp, data);
  strcat(tmp, ms.data);
  delete[] data;
  data = nullptr;
  data = tmp;
  cout << "op +=" << endl;
  return *this;
}

char& MyString::operator[](int i) {
  return data[i];
}
char& MyString::operator()(int i) {
  return data[i];
}

int main() {
  cout << "test: 默认构造函数" << endl;
  MyString ms0;

  cout << "test: 传参构造函数" << endl;
  MyString ms1("chunbo");

  cout << "test: 拷贝构造函数" << endl;
  MyString ms2(ms1);

  cout << "test: 移动构造函数" << endl;
  MyString ms3(std::move(ms1));

  cout << "test: 拷贝赋值运算符" << endl;
  MyString ms4;
  ms4 = ms0;

  cout << "test: 移动赋值运算符" << endl;
  MyString ms5;
  ms5 = std::move(ms3);
  ms5.print_data();

  cout << "test: operator+=" << endl;
  MyString ms6("lanlan");
  ms6 += ms5;
  ms6.print_data();

  ms6[1] = '9';
  ms6.print_data();
  ms6[2] = '8';
  ms6.print_data();

}




