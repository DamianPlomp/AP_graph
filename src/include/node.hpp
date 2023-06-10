#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "edge.hpp"

class Node
{
    private:
        // Edges that are connected to this node
        std::vector<Edge*> edges;
        // Name of a node (in this program it's letters of the alphabet)
        std::string name;

    public:
        // constructor for the Node
        Node(std::string name);
        // Get the name of the node
        std::string getName() const;
        // Add an edge to the node
        void addEdge(Edge* edge);
        // Get all edges connected to the node
        std::vector<Edge*> getEdges() const;
        
        friend bool operator<(const Node& lhs, const Node& rhs);
        friend bool operator>(const Node& lhs, const Node& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Node& n);
};