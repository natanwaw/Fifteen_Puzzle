#pragma once
#include "Solver.h"
#include <queue>
class BFS : public Solver
{
private:
	queue<State> openList;
	vector<State> closedList;
	int maxDepth;
public:
	BFS();
	virtual void solve(State s, string order, string solutionFiler);
};

