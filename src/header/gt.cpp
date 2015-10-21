#include "gt.hpp"

#include <iostream>

gt::config::config()
{
	std::cout << "class created\n";
}

void gt::config::readconfig()
{
}

int gt::config::getresx()
{
	return resx;
}

int gt::config::getresy()
{
	return resy;
}

long int gt::config::getseed()
{
	return seed;
}
