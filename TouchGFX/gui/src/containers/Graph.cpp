#include <gui/containers/Graph.hpp>

Graph::Graph()
{

}

void Graph::initialize()
{
  GraphBase::initialize();
}

void Graph::addPoint(int point) {
  dynamicGraph1.addDataPoint(point);
}
