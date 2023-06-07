#pragma once
#include <vector>
#include <iostream>
#include "edge.hpp"

//#include "node.hpp" Dit zou verkeerd gaan, want Node.hpp heeft edge.hpp nodig...

class Node; //...dit (a.k.a. Forward declaration) werkt ook, maar alleen als ik pointers van Nodes gebruik

class Train : public Edge
{
    public:
        Train(Node* from, Node* to, float weight);

};