#pragma once
#include "Solver.h"

class DFS : public Solver
{
private:
	vector<State> openList;
	vector<State> closedList;
	int maxDepth;
public:
	DFS();
	virtual void solve(State s, string order, string solutionFile);
};

