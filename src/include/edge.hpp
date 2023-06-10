#pragma once
#include <vector>
#include <iostream>
//#include "node.hpp" Dit zou verkeerd gaan, want Node.hpp heeft edge.hpp nodig...

class Node; //...dit (a.k.a. Forward declaration) werkt ook, maar alleen als ik pointers van Nodes gebruik

class Edge
{
    protected:
        // Starting point
        Node* from;
        // Ending point
        Node* to;
        // Weight of the edge (km for example)
        float weight;

    public:
        // Constructor for the Edge
        Edge(Node* from, Node* to, float weight);
        // Get the starting point
        Node* getFrom() const;
        // Get the ending point
        Node* getTo() const;
        // Virtual function to get the weight of the edge
        virtual float getWeight() const;
};