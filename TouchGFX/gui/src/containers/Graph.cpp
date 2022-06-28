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

void Graph::setConfig(MFD_GaugeDataTypeDef *conf)
{
  data = conf;

  dynamicGraph1MajorYAxisLabel.setInterval((data->max - data->min) / 5);
  dynamicGraph1MajorYAxisGrid.setInterval((data->max - data->min) / 5);
  dynamicGraph1MinorYAxisGrid.setInterval((data->max - data->min) / 25);

  dynamicGraph1.setGraphRange(dynamicGraph1.getGraphRangeXMin(), dynamicGraph1.getGraphRangeXMax(), data->min, data->max);

  dynamicGraph1.clear();

  dynamicGraph1.invalidate();
}
