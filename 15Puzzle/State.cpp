#include "State.h"
#include <iostream>

State::State()
{
    depth = 0;
}

State::State(vector<short>& v)
{
    values = v;
    depth = 0;
}

const State State::neighbor(char c) const
{
	State s(*this);
	short zero;
	for (int i = 0; i < s.values.size(); i++) {
		if (s.values[i] == 0) {
			zero = i;
			break;
		}
	}

    if (c == 'L') {
        if (zero % 4 == 0) {
            return s;
        }
        swap(s.values[zero], s.values[zero - 1]);
    }
    else if (c == 'R') {
        if (zero % 4 == 3) {
            return s;
        }
        swap(s.values[zero], s.values[zero + 1]);
    }
    else if (c == 'U') {
        if (zero < 4) {
            return s;
        }
        swap(s.values[zero], s.values[zero - 4]);
    }
    else if (c == 'D') {
        if (zero > 11 ) {
            return s;
        }
        swap(s.values[zero], s.values[zero + 4]);
    }
	return s;
}

void State::show() const
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << values[i * 4 + j] << " ";
        }
        cout << endl;
    }
}

const bool State::isTargetState() const
{
    for (int i = 0; i < values.size()-1; i++) {
        if (values[i] != i + 1) {
            return false;
        }
    }
    return true;
}

const vector<State> State::neighbors(const string& order) const
{
    vector<State> neighbors;
    State tmp;

    if ( *this != neighbor((char)order[0])) {
        tmp = neighbor((char)order[0]);
        tmp.depth++;
        tmp.route += (char)order[0];
        neighbors.push_back(tmp);
    }
    if (*this != neighbor((char)order[1])) {
        tmp = neighbor((char)order[1]);
        tmp.depth++;
        tmp.route += (char)order[1];
        neighbors.push_back(tmp);
    }
    if (*this != neighbor((char)order[2])) {
        tmp = neighbor((char)order[2]);
        tmp.depth++;
        tmp.route += (char)order[2];
        neighbors.push_back(tmp);
    }
    if (*this != neighbor((char)order[3])) {
        tmp = neighbor((char)order[3]);
        tmp.depth++;
        tmp.route += (char)order[3];
        neighbors.push_back(tmp);
    }

    return neighbors;
}

bool State::operator==(const State& s) const
{
    if (values == s.values) {
        return true;
    }
    return false;
}

bool State::operator!=(const State& s) const
{
    return !(*this == s);
}

ostream& operator<<(ostream& os, State s)
{
    os << s.depth << endl << s.route << endl;
    return os;
}
