#include "include/graph.hpp"
#include "include/nodegreaterthan.hpp"

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>


Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) :
    nodes(nodes),
    edges(edges)
{
    for(Edge* edge : edges)
    {
        edge->getFrom()->addEdge(edge);
    }
}

void Graph::addNode(Node* node)
{
    nodes.push_back(node);
}
void Graph::addEdge(Edge* edge)
{
    edge->getFrom()->addEdge(edge);
} 

Edge* Graph::getEdge(Node* from, Node* to)
{
    
    std::cout << std::endl;
    std::cout << nodes.size() << std::endl;
    std::cout << edges.size() << std::endl;

    std::cout << from->getName() << std::endl;
    std::cout << from->getEdges().size() << std::endl;
    for(Edge* edge : from->getEdges())
    {
        if(edge->getTo()->getName() == to->getName())
        {
            return edge;
        }
    }

    return nullptr;
} 

std::vector<std::string> Graph::dijkstraAlgorithm(Node* start, Node* end)
{
    std::priority_queue<Node*, std::vector<Node*>, NodeGreaterThan> eval;
    std::map<Node*, unsigned int> dist;
    std::map<Node*, Node*> prev;

    // Code by Joris
    Node* startNode = nullptr;
    Node* endNode = nullptr;
    for(Node* node : this->nodes){
        if(start->getName() == node->getName()){
        startNode = node;
        } else if(end->getName() == node->getName()){
        endNode = node;
        }
    }
    // If one of them is still a nullptr:
    if(!startNode || !endNode){
        std::cout << "You gave a starting or endpoint that does not exist." << std::endl;
        exit(1); // Exit program with code 1
    }
    start = startNode;
    end = endNode;

    for(auto& node : nodes)
    {
        dist[node] = INT_MAX;
        prev[node] = nullptr;
    }

    dist[start] = 0;
    eval.emplace(start);

    while (!eval.empty())
    {
        std::vector<Edge*> edges = eval.top()->getEdges();
        eval.pop();

        for(Edge* edge : edges)
        {
            if(dist[edge->getFrom()] + edge->getWeight() < dist[edge->getTo()])
            {
                dist[edge->getTo()] = dist[edge->getFrom()] + edge->getWeight();
                prev[edge->getTo()] = edge->getFrom();
                eval.emplace(edge->getTo()); 
            }
        }
    }
    
    // TO DO, CHANGE
    std::vector<std::string> res;
    res.push_back((end->getName()));
    while(prev[end] != nullptr)
    {
        res.push_back(prev[end]->getName());
        end = prev[end];
    }
    std::reverse(res.begin(), res.end());

    return res;
}

std::ostream& operator<<(std::ostream& os, const Graph& g)
{
    for(Node* node : g.nodes)
    {
        os << (*node) << std::endl;
    }

    return os;
}

