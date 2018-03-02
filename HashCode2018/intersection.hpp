#pragma once

#include <utility>
#include <iostream>
#include <cstdlib>
#include <utility>

typedef std::pair<unsigned int, unsigned int> intersection;

static std::ostream& operator<<(std::ostream& os, const intersection& inter) {
	return os << "i=" << inter.first << ':' << inter.second;
}

static std::istream& operator>>(std::istream& is, intersection& inter) {
	return is >> std::ws >> inter.first >> std::ws >> inter.second;
}

static unsigned int operator-(const intersection& inter1, const intersection& inter2) {
	return abs((long)(inter1.first - inter2.first)) + abs((long)(inter1.second - inter2.second));
}

static bool operator==(const intersection& inter1, const intersection& inter2) {
	return inter1.first == inter2.first && inter1.second == inter2.second;
}