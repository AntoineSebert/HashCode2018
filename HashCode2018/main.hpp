#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <cstdlib>

typedef std::pair<unsigned int, unsigned int> intersection;

std::ostream& operator<<(std::ostream& os, const intersection& inter) {
	os << inter.first << ':' << inter.second;
}

intersection operator-(const intersection &inter1, const intersection &inter2) {
	return intersection(abs((long)(inter1.first - inter2.first)), abs((long)(inter1.second - inter2.second)));
}