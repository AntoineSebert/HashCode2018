#pragma once

#include <utility>
#include <iostream>
#include <cstdlib>

typedef std::pair<unsigned int, unsigned int> intersection;

extern std::ostream& operator<<(std::ostream& os, const intersection& inter) {
	return os << inter.first << ':' << inter.second;
}

extern intersection operator-(const intersection &inter1, const intersection &inter2) {
	return intersection(abs((long)(inter1.first - inter2.first)), abs((long)(inter1.second - inter2.second)));
}