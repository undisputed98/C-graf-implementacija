#include <iostream>
#include <cassert>
#include "src/Stack.h"
#include "src/Queue.h"
#include "src/Vector.h"
#include "src/Graph.h"

using namespace std;

void stackTests() {
	Stack s;
	s.push(3);
	assert(s.empty() == false);
	assert(s.capacity() == 5);
	assert(s.length() == 1);
	assert(s.peek() == 3);
	s.push(4), s.push(5), s.push(6), s.push(7);
	assert(s.full() == true);
	s.push(8), s.push(9);
	assert(s.capacity() == 10);
	assert(s.length() == 7);
	assert(s.peek() == 9);
	s.pop();
	assert(s.peek() == 8);
	assert(s.length() == 6);
	Stack copy(s);
	assert(copy.length() == 6);
	assert(copy.capacity() == 10);
	assert(copy.peek() == s.peek());
}

void queueTests() {
	Queue q;
	assert(q.empty());
	q.push(1), q.push(2), q.push(3); // should resize store
	assert(q.peek() == 1);
	assert(q.length() == 3);
	assert(q.capacity() == 5);
	q.push(4), q.push(22);
	q.pop();
	assert(q.peek() == 2);
	assert(q.length() == 4);
	assert(q.capacity() == 5);
	q.push(100); // should resize store
	assert(q.capacity() == 10);
	q.push(122), q.push(123);
	while (q.length() > 2) {
		q.pop();
	}
	q.push(143), q.push(144);
	q.pop();
	q.push(150); // should shift values
	assert(q.capacity() == 10);
	assert(q.length() == 4);
	while (q.length() > 0) {
		q.pop();
	}
	assert(q.length() == 0);
	assert(q.empty());
}

void vectorTests() {
	Vector<int> v, v2;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	// Copy constructor tests
	v2 = v;
	assert(v2[0] == 1);
	assert(v2[1] == 2);
	assert(v2[2] == 3);

}

void graphTests() {
	Vector<Pair> edges;
	Vector<Pair> treeedges;
	edges.push_back(Pair(0, 1));
	edges.push_back(Pair(0, 2));
	edges.push_back(Pair(0, 3));
	edges.push_back(Pair(2, 3));
	edges.push_back(Pair(2, 4));
	edges.push_back(Pair(1, 4));

	
	treeedges.push_back(Pair(0, 1));
	treeedges.push_back(Pair(1, 2));
	treeedges.push_back(Pair(2, 3));
	treeedges.push_back(Pair(2, 4));

	Graph g(5, edges);
	Graph tree(5, treeedges);

	// BFS Test
	Vector<Pair> sol = g.bfs(0);
	assert(sol.length() == 5);
	assert(sol[0].first() == 0);
	assert(sol[0].second() == 0);
	assert(sol[1].first() == 1);
	assert(sol[1].second() == 1);
	assert(sol[2].first() == 2);
	assert(sol[2].second() == 1);
	assert(sol[3].first() == 3);
	assert(sol[3].second() == 1);
	assert(sol[4].first() == 4);
	assert(sol[4].second() == 2);

	//DFS test
	Vector<int> dfssol = g.dfs(0);
	assert(dfssol.length() == 5);
	for (int i = 0; i < 5; i++) {
		cout << dfssol[i] << " ";
	}
	assert(dfssol[0] == 0);
	assert(dfssol[1] == 1);
	assert(dfssol[2] == 4);
	assert(dfssol[3] == 2);
	assert(dfssol[4] == 3);

	// distance test

	assert(g.distance(0 , 4) == 2);
	assert(g.distance(1, 3) == 2);
	assert(tree.distance(0, 4) == 3);

	// Get edges test
	assert(g.getEdges() == 6);

	// Get nodes test
	cout << g.getNodes();
	assert(g.getNodes() == 5);

	// isTree test
	assert(g.isTree() == false);
	assert(tree.isTree() == true);

	// [] operator tests
	assert(g[0][0] == 1);
	assert(g[0][1] == 2);
	assert(g[1][0] == 0);

	// = operator tests
	Graph g2;
	g2 = g;

	assert(g2.getNodes() == g.getNodes());
	assert(g2.getEdges() == g.getEdges());
	assert(g[0][0] == g2[0][0]);
	assert(g[0][1] == g2[0][1]);
	assert(g[1][0] == g2[1][0]);

	// > and < operators tests

	assert(g > g2 == false);
	assert(g < g2 == false);
	assert(g > tree == true);
	assert(g < tree == false);

	assert(g.countConex() == 1);
	assert(tree.countConex() == 1);

	cout << g;
	g.addNode();
	g.addNode();
	assert(g.countConex() == 3);
	cout << g;

	Graph k;
	cin >> k;
	cout << k;
}

int main() {
	vectorTests();
	graphTests();
	stackTests();
	queueTests();
	return 0;
}