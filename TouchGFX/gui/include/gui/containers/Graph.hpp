#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <gui_generated/containers/GraphBase.hpp>

#include <data.h>

class Graph : public GraphBase
{
public:
    Graph();
    virtual ~Graph() {}

    virtual void initialize();

    void addPoint(int);

    void setConfig(MFD_GaugeDataTypeDef *config);
protected:
    MFD_GaugeDataTypeDef *data;
};

#endif // GRAPH_HPP
