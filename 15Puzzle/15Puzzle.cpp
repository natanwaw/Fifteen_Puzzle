#include <iostream>
#include "DFS.h"
#include "BFS.h"
#include "Hamming.h"
#include "Manhatan.h"
#include <sstream>
#include <fstream>

int main(int argc, char* argv[])
{
    string order;
    string initialStateFileName;
    string solutionFileName;
    bool Dfs = false;
    bool Bfs = false;
    bool HAMMING = false;
    bool MANHATAN = false;

    stringstream ss;

    string arg;
    arg = argv[1];
    if (arg == "bfs") {
        Bfs = true;
        arg.clear();
        arg = argv[2];
        order = arg;
    }
    else if (arg == "dfs") {
        Dfs = true;
        arg.clear();
        arg = argv[2];
        order = arg;
    }
    else if (arg == "astr") {
        arg.clear();
        arg = argv[2];
        order = "LRUD";
        if (arg == "hamm") {
            HAMMING = true;
        }
        else if (arg == "manh") {
            MANHATAN = true;
        }
    }

    arg.clear();
    arg = argv[3];
    initialStateFileName = arg;

    arg.clear();
    arg = argv[4];
    solutionFileName = arg;

    ifstream initialStateFile(initialStateFileName);

    vector<short> v;
    string values;
    for (int i = 0; i < 16; i++) {
        short x;
        values.clear();
        initialStateFile >> values;
        ss.clear();
        ss << values;
        ss >> x;
        v.push_back(x);
    }

    State s(v);

    if (Bfs) {
        BFS bfs;
        bfs.solve(s, order, solutionFileName);
    }
    else if (Dfs) {
        DFS dfs;
        dfs.solve(s, order, solutionFileName);
    }
    else if (MANHATAN) {   
        Manhatan m;
        m.solve(s, order, solutionFileName);
    }
    else if (HAMMING) {
        Hamming h;
        h.solve(s, order, solutionFileName);
    }

    return 0;
}
