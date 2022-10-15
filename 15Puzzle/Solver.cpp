#include "Solver.h"

void Solver::addToVisitedList(State s)
{
	visitedList.insert(s);
}

bool Solver::isOnVisitedList(State s) const
{
	if (visitedList.count(s)) {
		return true;
	}
	return false;
}

int Solver::sizeOfVisitedList() const
{
	return visitedList.size();
}
