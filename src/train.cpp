#include <iostream>
#include "include\train.hpp"

// Made by ChatGPT
// The car travels 2.5 faster than travelling 'normally'
// This is purely random so don't take it too serious, I simply put some numbers in
Train::Train(Node* from, Node* to, float weight)
    : Edge(from, to, weight*2.5)
{
    
}