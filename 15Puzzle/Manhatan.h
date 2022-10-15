#pragma once
#include "Solver.h"
#include <queue>

struct compareManhatan {
    bool operator () (const State& s1, const State& s2) {
        int s1Cost = 0;
        s1Cost += s1.getDepth();
        for (int i = 0; i < s1.getValues().size(); i++) {
            if (s1.getValues()[i] != 0) {
                int xPos = i % 4;
                int yPos = i / 4;
                int xCel = (s1.getValues()[i] - 1) % 4;
                int yCel = (s1.getValues()[i] - 1) / 4;
                s1Cost += abs(xPos - xCel) + abs(yPos - yCel);
            }
        }

        int s2Cost = 0;
        s2Cost += s2.getDepth();
        for (int i = 0; i < s2.getValues().size(); i++) {
            if (s2.getValues()[i] != 0) {
                int xPos = i % 4;
                int yPos = i / 4;
                int xCel = (s2.getValues()[i] - 1) % 4;
                int yCel = (s2.getValues()[i] - 1) / 4;
                s2Cost += abs(xPos - xCel) + abs(yPos - yCel);
            }
        }

        if (s1Cost > s2Cost) {
            return true;
        }
        return false;
    }
};

class Manhatan : public Solver
{
private:
    priority_queue<State, vector<State>, compareManhatan> openList;
    vector<State> closedList;
    int maxDepth;
public:
    Manhatan();
    virtual void solve(State s, string order, string solutionFile);
};

