#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include "Vector.h"
#include "Pair.h"

class Graph {
    unsigned nodes; // number of nodes
    unsigned edges; //number of edges;
    Vector<Vector<int> > adj; // adj list;
public:
    Graph();
    Graph(unsigned);
    Graph(unsigned, unsigned);
    Graph(unsigned, Vector<Pair>);
    Graph(const Graph&);
	Graph& operator=(const Graph& o);
	bool operator>(const Graph&) const;
    bool operator<(const Graph&) const;
    Vector<int> operator[](const int) const;

    ~Graph();

    void addNode();
    void addEdge(Pair);

    Vector<Pair> bfs(int) const; // return pairs of (node, distance from start)
    Vector<int> dfs(int) const; // return Vector of visited nodes

    unsigned distance(int, int) const; // return distance
    unsigned countConex() const;

    unsigned getNodes() const;
    unsigned getEdges() const;
    bool isTree() const;

    friend std::istream& operator>>(std::istream&, Graph&);
	friend std::ostream& operator<<(std::ostream&, const Graph&);
private:
    void dfsUtil(int, bool*, Vector<int>&) const;
};

std::istream& operator>>(std::istream& is, Graph& g);
std::ostream& operator<<(std::ostream& os, const Graph& g);

#endif // _GRAPH_H