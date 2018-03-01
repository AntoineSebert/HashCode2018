#pragma once

#include <vector>
#include <utility>
#include <iostream>

typedef std::pair<unsigned int, unsigned int> intersection;

std::ostream& operator<<(std::ostream& os, const intersection& inter) {
	os << inter.first << ':' << inter.second;
}