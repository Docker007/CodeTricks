// equal.cpp : �������̨Ӧ�ó������ڵ㡣
//
// so many algorithms in the std, so why not use it, no need to rewrite again.
// �����ж�
#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>


bool is_palindrome(const std::string& str)
{
	return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

void test(const std::string str)
{
	std::cout << "\"" << str << "\"" << (is_palindrome(str) ? "is" : "is not") << " palindrome" << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	test("fxp");
	test("fxf");
	return 0;
}

