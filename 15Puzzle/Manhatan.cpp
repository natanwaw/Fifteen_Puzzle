#include "Manhatan.h"
#include <fstream>
#include <iostream>

Manhatan::Manhatan()
{
	maxDepth = 0;
}

void Manhatan::solve(State s, string order, string solutionFile)
{
	ofstream solution(solutionFile);
	if (s.isTargetState()) {
		cout << "The initial state is the target state";
	}
	else {
		addToVisitedList(s);
		openList.push(s);
		while (openList.size()) {
			vector<State> tmpNeighbors = openList.top().neighbors(order);
			closedList.push_back(openList.top());
			openList.pop();
			for (auto& it : tmpNeighbors) {
				if (!isOnVisitedList(it) && it.getDepth() <= 20) {
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
