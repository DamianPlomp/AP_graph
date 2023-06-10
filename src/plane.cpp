#include <iostream>
#include "include\plane.hpp"

// Made by ChatGPT
// The car travels 10 faster than travelling 'normally'
// This is purely random so don't take it too serious, I simply put some numbers in
Plane::Plane(Node* from, Node* to, float weight)
    : Edge(from, to, weight*10)
{
    
}