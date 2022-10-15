#include "DFS.h"
#include <iostream>
#include <fstream>

using namespace std;

DFS::DFS()
{
	maxDepth = 0;
}

void DFS::solve(State s, string order, string solutionFile)
{
	ofstream solution(solutionFile);
	if (s.isTargetState()) {
		cout << "The initial state is the target state";
	}
	else {
		addToVisitedList(s);
		openList.push_back(s);
		while (openList.size()) {
			vector<State> tmpNeighbors = openList.back().neighbors(order);
			closedList.push_back(openList.back());
			openList.pop_back();
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
					addToVisitedList(it);
				}
			}
			for (vector<State>::reverse_iterator i = tmpNeighbors.rbegin(); i != tmpNeighbors.rend(); ++i) {
				if (!isOnVisitedList(*i) && (*i).getDepth() <= 10) {
					openList.push_back(*i);
				}
				
			}
		}
		solution << "-1";
	}
}
