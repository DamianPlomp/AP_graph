#include <iostream>
#include <queue>
#include "include/nodegreaterthan.hpp"
#include "include/graph.hpp"

int main()
{
    // Graphs are hardcoded here
    // With this example you can't really see that the plane and train actually go faster, but if you wish
    // to get this shown, simple implement the getWeight function somewhere.


    // Graph for car
    
    Node a = Node("a"); Node b = Node("b"); Node c = Node("c"); Node d = Node("d"); Node e = Node("e"); Node f = Node("f");

    Edge a1 = Edge(&a, &b, 4); Edge a2 = Edge(&a, &c, 3);    
    Edge b1 = Edge(&b, &a, 4); Edge b2 = Edge(&b, &c, 5); Edge b3 = Edge(&b, &d, 2);
    Edge c1 = Edge(&c, &a, 3); Edge c2 = Edge(&c, &b, 5); Edge c3 = Edge(&c, &d, 2); Edge c4 = Edge(&c, &e, 1);    
    Edge d1 = Edge(&d, &b, 2); Edge d2 = Edge(&d, &c, 2); Edge d3 = Edge(&d, &e, 1); Edge d4 = Edge(&d, &f, 1);    
    Edge e1 = Edge(&e, &c, 1); Edge e2 = Edge(&e, &d, 1); Edge e3 = Edge(&e, &f, 3);       
    Edge f1 = Edge(&f, &d, 1); Edge f2 = Edge(&f, &e, 3);

    Graph carGraph = Graph(
        {&a, &b, &c, &d, &e, &f},
        {&a1, &a2, &b1, &b2, &b3, &c1, &c2, &c3, &c4, &d1, &d2, &d3, &d4, &e1, &e2, &e3, &f1, &f2}
    );


    std::priority_queue<Node*, std::vector<Node*>, NodeGreaterThan> pq;
    pq.push(&a);
    pq.push(&b);
    pq.push(&c);
    pq.push(&d);
    pq.push(&e);
    pq.push(&f);

    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();

// ---------------------------------------------------------------------------------------------
// Graph for train

    Node g = Node("g"); Node h = Node("h"); Node i = Node("i"); Node j = Node("j"); Node k = Node("k"); Node l = Node("l");

    Edge g1 = Edge(&g, &h, 4); Edge g2 = Edge(&g, &i, 3);    
    Edge h1 = Edge(&h, &g, 4); Edge h2 = Edge(&h, &i, 5); Edge h3 = Edge(&h, &j, 2);
    Edge i1 = Edge(&i, &g, 3); Edge i2 = Edge(&i, &h, 5); Edge i3 = Edge(&i, &j, 2); Edge i4 = Edge(&i, &k, 1);    
    Edge j1 = Edge(&j, &h, 2); Edge j2 = Edge(&j, &i, 2); Edge j3 = Edge(&j, &k, 1); Edge j4 = Edge(&j, &l, 1);    
    Edge k1 = Edge(&k, &i, 1); Edge k2 = Edge(&k, &j, 1); Edge k3 = Edge(&k, &l, 3);       
    Edge l1 = Edge(&l, &j, 1); Edge l2 = Edge(&l, &k, 3);


    Graph trainGraph = Graph(
        {&g, &h, &i, &j, &k, &l},
        {&g1, &g2, &h1, &h2, &h3, &i1, &i2, &i3, &i4, &j1, &j2, &j3, &k1, &k2, &k3, &l1, &l2}
    );


    std::priority_queue<Node*, std::vector<Node*>, NodeGreaterThan> trainVec;
    trainVec.push(&g);
    trainVec.push(&h);
    trainVec.push(&i);
    trainVec.push(&j);
    trainVec.push(&k);
    trainVec.push(&l);

    trainVec.pop();
    trainVec.pop();
    trainVec.pop();
    trainVec.pop();
    trainVec.pop();

// -------------------------------------------------------
// Graph for plane

    Node m = Node("m"); Node n = Node("n"); Node o = Node("o"); Node p = Node("p"); Node q = Node("q"); Node r = Node("r");
    Node s = Node("s"); Node t = Node("t");

    Edge m1 = Edge(&m, &n, 2); Edge m2 = Edge(&m, &o, 4);
    Edge n1 = Edge(&n, &m, 2); Edge n2 = Edge(&n, &q, 3);
    Edge o1 = Edge(&o, &m, 4); Edge o2 = Edge(&o, &p, 5);
    Edge p1 = Edge(&p, &o, 5); Edge p2 = Edge(&p, &r, 8); Edge p3 = Edge(&p, &s, 5); Edge p4 = Edge(&p, &q, 3);
    Edge q1 = Edge(&q, &n, 3); Edge q2 = Edge(&q, &p, 3); Edge q3 = Edge(&q, &t, 2);
    Edge r1 = Edge(&r, &p, 8); Edge r2 = Edge(&r, &s, 4);
    Edge s1 = Edge(&s, &p, 5); Edge s2 = Edge(&s, &r, 4); Edge s3 = Edge(&s, &t, 4);
    Edge t1 = Edge(&t, &s, 4); Edge t2 = Edge(&t, &q, 2);

    Graph planeGraph = Graph(
        {&m, &n, &o, &p, &q, &r, &s, &t},
        {&m1, &m2, &n1, &n2, &o1, &o2, &p1, &p2, &p3, &p4, &q1, &q2, &q3, &r1, &r2, &s1, &s2, &s3, &t1, &t2}
    );


    std::priority_queue<Node*, std::vector<Node*>, NodeGreaterThan> planeVec;
    planeVec.push(&m);
    planeVec.push(&n);
    planeVec.push(&o);
    planeVec.push(&p);
    planeVec.push(&q);
    planeVec.push(&r);
    planeVec.push(&s);
    planeVec.push(&t);

    planeVec.pop();
    planeVec.pop();
    planeVec.pop();
    planeVec.pop();
    planeVec.pop();
    planeVec.pop();
    planeVec.pop();

    std::cout << "Welcome to the knockoff version of Google Maps" << std::endl;

    int x;

    std::cout << "Would you like to travel by car, train, or plane? Choose by typing 1, 2, or 3" << std::endl;

    std::cin >> x;
    if(x==1)
    {
        std::cout << "Please enter a starting point (a, b, c, d, e, f): " << std::endl;
        std::string startingPoint;
        std::cin >> startingPoint;
        Node first = Node(startingPoint);

        std::cout << "Please enter an ending point (a, b, c, d, e, f): " << std::endl;
        std::string endingPoint;
        std::cin >> endingPoint;
        Node second = Node(endingPoint);

        std::cout << "You chose to travel by car, the fastest route for this would be: " << std::endl;

        std::vector<std::string> fastestCarRoute = carGraph.dijkstraAlgorithm(&first, &second);

        for(std::string i : fastestCarRoute)
        {
            std::cout << i + " ";
        }
    }
    else if(x==2)
    {
        std::cout << "Please enter a starting point (g, h, i, j, k, l):" << std::endl;
        std::string startingPoint;
        std::cin >> startingPoint;
        Node first = Node(startingPoint);

        std::cout << "Please enter an ending point (g, h, i, j, k, l): " << std::endl;
        std::string endingPoint;
        std::cin >> endingPoint;
        Node second = Node(endingPoint);

        std::cout << "You chose to travel by train, the fastest route for this would be: " << std::endl;

        std::vector<std::string> fastestTrainRoute = trainGraph.dijkstraAlgorithm(&first, &second);

        for(std::string n : fastestTrainRoute)
        {
            std::cout << n + " ";
        }
    }
    else if(x==3)
    {
        std::cout << "Please enter a starting point (m, n, o, p, q, r, s, t): " << std::endl;
        std::string startingPoint;
        std::cin >> startingPoint;
        Node first = Node(startingPoint);

        std::cout << "Please enter an ending point (m, n, o, p, q, r, s, t): " << std::endl;
        std::string endingPoint;
        std::cin >> endingPoint;
        Node second = Node(endingPoint);

        std::cout << "You chose to travel by plane, the fastest route for this would be: " << std::endl;

        std::vector<std::string> fastestPlaneRoute = planeGraph.dijkstraAlgorithm(&first, &second);

        for(std::string i : fastestPlaneRoute)
        {
            std::cout << i + " ";
        }
    }
    else
    {
        std::cout << "That's a wrong input" << std::endl;
        return main();
    }


    return 0;
}
