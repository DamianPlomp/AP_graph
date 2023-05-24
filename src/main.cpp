#include <iostream>
#include "include/graph.hpp"

int main()
{
    Node a = Node("a"); Node b = Node("b"); Node c = Node("c"); Node d = Node("d"); Node e = Node("e"); Node f = Node("f");

    Edge a1 = Edge(&a, &b, 4); Edge a2 = Edge(&a, &c, 3);    
    Edge b1 = Edge(&b, &a, 4); Edge b2 = Edge(&b, &c, 5); Edge b3 = Edge(&b, &d, 2);
    Edge c1 = Edge(&c, &a, 3); Edge c2 = Edge(&c, &b, 5); Edge c3 = Edge(&c, &d, 2); Edge c4 = Edge(&c, &e, 1);    
    Edge d1 = Edge(&d, &b, 2); Edge d2 = Edge(&d, &c, 2); Edge d3 = Edge(&d, &e, 1); Edge d4 = Edge(&d, &f, 1);    
    Edge e1 = Edge(&e, &c, 1); Edge e2 = Edge(&e, &d, 1); Edge e3 = Edge(&e, &f, 3);       
    Edge f1 = Edge(&f, &d, 1); Edge f2 = Edge(&f, &e, 3);

    Graph g = Graph(
        {&a, &b, &c, &d, &e, &f},
        {&a1, &a2, &b1, &b2, &b3, &c1, &c2, &c3, &c4, &d1, &d2, &d3, &d4, &e1, &e2, &e3, &f1, &f2}
    );

    std::cout << g << std::endl;
    
    return 0;
}
