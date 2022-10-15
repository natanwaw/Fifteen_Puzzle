#pragma once
#include <unordered_set>
#include "State.h"
#include <boost/functional/hash.hpp>

using namespace std;

struct State_hash {
	size_t operator()(const State& s) const {
		size_t result = 0;
		for (auto& i : s.getValues()) {
			boost::hash_combine(result, i);
		}
		return result;
	}
};

class Solver
{
private:
	unordered_set<State, State_hash> visitedList;
public:
	void addToVisitedList(State s);
	bool isOnVisitedList(State s) const;
	int sizeOfVisitedList() const;
	virtual void solve(State s, string order, string solutionFile) = 0;
};

