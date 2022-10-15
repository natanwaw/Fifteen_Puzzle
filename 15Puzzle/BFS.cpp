#include "BFS.h"
#include <fstream>
#include <iostream>

BFS::BFS()
{
	maxDepth = 0;
}

void BFS::solve(State s, string order, string solutionFile)
{
	ofstream solution(solutionFile);
	if (s.isTargetState()) {
		cout << "The initial state is the target state";
	}
	else {
		addToVisitedList(s);
		openList.push(s);
		while (openList.size()) {
			vector<State> tmpNeighbors = openList.front().neighbors(order);
			closedList.push_back(openList.front());
			openList.pop();
			for (auto& it : tmpNeighbors) {
				if (!isOnVisitedList(it)) {
					if (it.getDepth() > maxDepth) {
						maxDepth = it.getDepth();
					}
					if (it.isTargetState()) {
						addToVisitedList(it);
						solution << it;
						return;
					}
					openList.push(it);
					addToVisitedList(it);
				}
			}
		}
		solution << "-1";
	}
}
