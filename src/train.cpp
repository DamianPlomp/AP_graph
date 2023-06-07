#include <iostream>
#include "include\train.hpp"

// Made by ChatGPT
Train::Train(Node* from, Node* to, float weight)
    : Edge(from, to, weight*2.5)
{
    
}