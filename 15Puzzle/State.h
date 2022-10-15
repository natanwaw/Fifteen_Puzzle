#pragma once
#include <vector>
#include <string>

using namespace std;

class State
{
private:
	vector<short> values;
	int depth;
	string route;
public:
	State();
	State(vector<short>& v);
	int getDepth() const { return depth; }
	const string& getRoute() const { return route; }
	const vector<short>& getValues() const { return values; }
	const State neighbor(char c) const;
	void show() const;
	const bool isTargetState() const;
	const vector<State> neighbors(const string & order ) const;
	bool operator==(const State& s) const;
	bool operator!=(const State& s) const;
	friend ostream& operator<<(ostream& os, State s);
};

