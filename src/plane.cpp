#include <iostream>
#include "include\plane.hpp"

// Made by ChatGPT
Plane::Plane(Node* from, Node* to, float weight)
    : Edge(from, to, weight*10)
{
    
}