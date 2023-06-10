#pragma once
#include <map>
#include "node.hpp"
#include "edge.hpp"

class Graph
{
    private:
        // The nodes
        std::vector<Node*> nodes;
        // The edges
        std::vector<Edge*> edges;

    public:
        // The constructor for the graph
        Graph(std::vector<Node*> nodes, std::vector<Edge*> edges);
        // Add a node to the graph
        void addNode(Node* node);
        // Add an edge to the graph
        void addEdge(Edge* edge);
        // Get an edge from the graph
        Edge* getEdge(Node* from, Node* to);
        // The shortest path algorithm to go through a graph
        std::vector<std::string> dijkstraAlgorithm(Node* start, Node* end);
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);
};