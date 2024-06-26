#include <gui/containers/Graph.hpp>

#define GRAPH_OFFSET 5

Graph::Graph()
{
  graphHeight = dynamicGraph1.getHeight();
  graphPosY = dynamicGraph1.getY();
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
  bg_6_11.setVisible(false);
  bg_11_21.setVisible(false);
  bg_9_17.setVisible(false);
  bg_spec_1.setVisible(false);

  values_6_11.setVisible(false);
  values_11_21.setVisible(false);
  values_9_17.setVisible(false);
  values_spec_1.setVisible(false);

  dynamicGraph1.setHeight(graphHeight);
  dynamicGraph1.setY(graphPosY);

  switch (data->scaleType) {
    case MFD_GaugeScaleType_6_11: {
      bg_6_11.setVisible(true);
      values_6_11.setVisible(true);

      dynamicGraph1.setHeight(graphHeight - GRAPH_OFFSET);
      dynamicGraph1.setY(graphPosY + GRAPH_OFFSET);

      Unicode::snprintf(value_6_11_0Buffer, VALUE_6_11_0_SIZE, "%d", data->scaleValues[0]);
      Unicode::snprintf(value_6_11_1Buffer, VALUE_6_11_1_SIZE, "%d", data->scaleValues[1]);
      Unicode::snprintf(value_6_11_2Buffer, VALUE_6_11_2_SIZE, "%d", data->scaleValues[2]);
      Unicode::snprintf(value_6_11_3Buffer, VALUE_6_11_3_SIZE, "%d", data->scaleValues[3]);
      Unicode::snprintf(value_6_11_4Buffer, VALUE_6_11_4_SIZE, "%d", data->scaleValues[4]);
      Unicode::snprintf(value_6_11_5Buffer, VALUE_6_11_5_SIZE, "%d", data->scaleValues[5]);

      break;
    }
    case MFD_GaugeScaleType_11_21: {
      bg_11_21.setVisible(true);
      values_11_21.setVisible(true);

      dynamicGraph1.setHeight(graphHeight - GRAPH_OFFSET);
      dynamicGraph1.setY(graphPosY + GRAPH_OFFSET);

      Unicode::snprintf(value_11_21_0Buffer, VALUE_11_21_0_SIZE, "%d", data->scaleValues[0]);
      Unicode::snprintf(value_11_21_1Buffer, VALUE_11_21_1_SIZE, "%d", data->scaleValues[1]);
      Unicode::snprintf(value_11_21_2Buffer, VALUE_11_21_2_SIZE, "%d", data->scaleValues[2]);
      Unicode::snprintf(value_11_21_3Buffer, VALUE_11_21_3_SIZE, "%d", data->scaleValues[3]);
      Unicode::snprintf(value_11_21_4Buffer, VALUE_11_21_4_SIZE, "%d", data->scaleValues[4]);
      Unicode::snprintf(value_11_21_5Buffer, VALUE_11_21_5_SIZE, "%d", data->scaleValues[5]);
      Unicode::snprintf(value_11_21_6Buffer, VALUE_11_21_6_SIZE, "%d", data->scaleValues[6]);
      Unicode::snprintf(value_11_21_7Buffer, VALUE_11_21_7_SIZE, "%d", data->scaleValues[7]);
      Unicode::snprintf(value_11_21_8Buffer, VALUE_11_21_8_SIZE, "%d", data->scaleValues[8]);
      Unicode::snprintf(value_11_21_9Buffer, VALUE_11_21_9_SIZE, "%d", data->scaleValues[9]);
      Unicode::snprintf(value_11_21_10Buffer, VALUE_11_21_10_SIZE, "%d", data->scaleValues[10]);

      break;
    }
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
