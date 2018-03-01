#pragma once

#include <vector>
#include <utility>
#include <iostream>

typedef std::pair<unsigned int, unsigned int> intersection;
typedef std::vector<intersection> city;

std::ostream& operator<<(std::ostream& os, const intersection& inter) {
	os << inter.first << ':' << inter.second;
}