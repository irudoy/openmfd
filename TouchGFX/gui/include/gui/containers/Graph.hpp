#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <gui_generated/containers/GraphBase.hpp>

class Graph : public GraphBase
{
public:
    Graph();
    virtual ~Graph() {}

    virtual void initialize();

    void addPoint(int);
protected:
};

#endif // GRAPH_HPP
