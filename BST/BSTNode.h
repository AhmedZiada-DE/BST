#pragma once
#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{
public:
	T value;
	BSTNode* left, * right;
	BSTNode(T value) :
		left(nullptr), value(value), right(nullptr){}

};

