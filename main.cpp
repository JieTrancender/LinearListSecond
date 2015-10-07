// ChainList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "chainlist.hpp"
#include "test.hpp"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LinearList<std::string> *_test = (LinearList<std::string> *) new ChainList<string> ;
	ChainList<string> _test_2;
	ChainList<string> *_test_3 = new ChainList<string>(12);

	_test->insert(0, "张三");
	_test->insert(1, "李四");
	_test->insert(2, "王五");
	cout << _test->size() << endl;

	_test_2.insert(0, "张三");
	_test_2.insert(1, "李四");
	_test_2.insert(2, "王五");
	cout << _test_2.size() << endl;
	cout << _test_2 << endl;

	_test_3->insert(0, "张三");
	_test_3->insert(1, "李四");
	_test_3->insert(2, "王五");
	cout << _test_3->size() << " " << endl;
	_test_3->output(cout);
	cout << endl;

	LinearList<PC> *test = (LinearList<PC> *) new ChainList<PC>;
	ChainList<PC> test_2;
	ChainList<PC> *test_3 = new ChainList<PC>(12);

	PC admin{ "MJ", "1467159125" };
	PC user_1{ "YQR", "1467159126" };
	PC user_2{ "LL", "1467159127" };

	test->insert(0, admin);
	test->insert(1, user_1);
	test->insert(2, user_2);

	std::cout << "The linear list size = " << test->size() << std::endl;
	test->output(cout);
	cout << endl;

	test_2.insert(0, admin);
	test_2.insert(1, user_1);
	test_2.insert(2, user_2);
	std::cout << "The linear list size = " << test_2.size() << std::endl;
	cout << test_2 << endl;
	return 0;
}

