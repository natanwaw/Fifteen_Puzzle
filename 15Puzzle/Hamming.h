#pragma once
#include "Solver.h"
#include <queue>

struct compareHamming {
    bool operator () (const State& s1, const State& s2) {
        int s1Cost = 0;
        s1Cost += s1.getDepth();
        for (int i = 0; i < s1.getValues().size(); i++) {
            if (s1.getValues()[i] != i + 1 && s1.getValues()[i] != 0) {
                s1Cost++;
            }
        }

        int s2Cost = 0;
        s2Cost += s2.getDepth();
        for (int i = 0; i < s2.getValues().size(); i++) {
            if (s2.getValues()[i] != i + 1 && s2.getValues()[i] != 0) {
                s2Cost++;
            }
        }

        if (s1Cost > s2Cost) {
            return true;
        }
        return false;
    }
};

class Hamming : public Solver
{
private:
    priority_queue<State, vector<State>, compareHamming> openList;
    vector<State> closedList;
    int maxDepth;
public:
    Hamming();
    virtual void solve(State s, string order, string solutionFile);
};

