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

  dynamicGraph1.setGraphRange(dynamicGraph1.getGraphRangeXMin(), dynamicGraph1.getGraphRangeXMax(), data->min, data->max);

  Unicode::strncpy(units_labelBuffer, data->unitsLabel, UNITS_LABEL_SIZE);
  units_label.invalidate();

  dynamicGraph1.clear();
  dynamicGraph1.invalidate();
}
