#include <iostream>
#include "include\car.hpp"

// Made by ChatGPT
// The car travels 1.5 faster than travelling 'normally'
// This is purely random so don't take it too serious, I simply put some numbers in
Car::Car(Node* from, Node* to, float weight)
    : Edge(from, to, weight*1.5)
{
    
}
