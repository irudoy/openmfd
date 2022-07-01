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

  // reset all
  bg_9_17.setVisible(false);
  bg_spec_1.setVisible(false);

  values_9_17.setVisible(false);
  values_spec_1.setVisible(false);

  switch (data->scaleType) {
    case MFD_GaugeScaleType_6_11:
    case MFD_GaugeScaleType_11_21:
    case MFD_GaugeScaleType_9_17: {
      bg_9_17.setVisible(true);
      values_9_17.setVisible(true);

      Unicode::snprintf(value_9_17_0Buffer, VALUE_9_17_0_SIZE, "%d", data->scaleValues[0]);
      Unicode::snprintf(value_9_17_1Buffer, VALUE_9_17_1_SIZE, "%d", data->scaleValues[1]);
      Unicode::snprintf(value_9_17_2Buffer, VALUE_9_17_2_SIZE, "%d", data->scaleValues[2]);
      Unicode::snprintf(value_9_17_3Buffer, VALUE_9_17_3_SIZE, "%d", data->scaleValues[3]);
      Unicode::snprintf(value_9_17_4Buffer, VALUE_9_17_4_SIZE, "%d", data->scaleValues[4]);
      Unicode::snprintf(value_9_17_5Buffer, VALUE_9_17_5_SIZE, "%d", data->scaleValues[5]);
      Unicode::snprintf(value_9_17_6Buffer, VALUE_9_17_6_SIZE, "%d", data->scaleValues[6]);
      Unicode::snprintf(value_9_17_7Buffer, VALUE_9_17_7_SIZE, "%d", data->scaleValues[7]);
      Unicode::snprintf(value_9_17_8Buffer, VALUE_9_17_8_SIZE, "%d", data->scaleValues[8]);

      break;
    }
    case MFD_GaugeScaleType_SPEC_1: {
      bg_spec_1.setVisible(true);
      values_spec_1.setVisible(true);

      Unicode::snprintfFloat(value_spec_1_0Buffer, VALUE_SPEC_1_0_SIZE, "%2.1f", data->scaleValues[0] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_1Buffer, VALUE_SPEC_1_1_SIZE, "%2.1f", data->scaleValues[1] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_2Buffer, VALUE_SPEC_1_2_SIZE, "%2.1f", data->scaleValues[2] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_3Buffer, VALUE_SPEC_1_3_SIZE, "%2.1f", data->scaleValues[3] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_4Buffer, VALUE_SPEC_1_4_SIZE, "%2.1f", data->scaleValues[4] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_5Buffer, VALUE_SPEC_1_5_SIZE, "%2.1f", data->scaleValues[5] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_6Buffer, VALUE_SPEC_1_6_SIZE, "%2.1f", data->scaleValues[6] / data->scaler);
      Unicode::snprintfFloat(value_spec_1_7Buffer, VALUE_SPEC_1_7_SIZE, "%2.1f", data->scaleValues[7] / data->scaler);

      break;
    }
    default:
      break;
  }

  dynamicGraph1.setGraphRange(dynamicGraph1.getGraphRangeXMin(), dynamicGraph1.getGraphRangeXMax(), data->min, data->max);

  Unicode::strncpy(units_labelBuffer, data->unitsLabel, UNITS_LABEL_SIZE);

  dynamicGraph1.clear();

  invalidate();
}
