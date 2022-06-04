#include "debug_data.h"

#define DBGD_OS_DELAY_NORMAL 50
#define DBGD_OS_DELAY_RANDOM 500

extern RNG_HandleTypeDef hrng;
extern MFD_DataSourceTypeDef MFD_DataSourcesAll[];

uint32_t tickCounter = 0;
bool useRandom = false;
bool enabled = true;

void DBGD_init(void) {
}

void DBGD_toggleRandom(void) {
  useRandom = !useRandom;
}

void DBGD_toggleEnable(void) {
  enabled = !enabled;
}

void DBGD_resetPeak(void) {
  for (uint8_t i = 0; i < MFD_DATASOURCES_SIZE; i++) {
    MFD_DataSourcesAll[i].peakValue = MFD_DataSourcesAll[i].value;
  }
}

static void DBGD_stubIncDecEntry(MFD_DataSourceTypeDef *entry, bool inc) {
  if (entry->DEBUG_modifier == 0) entry->DEBUG_modifier = 1;
  entry->value = inc ? entry->value + entry->DEBUG_modifier : entry->value - entry->DEBUG_modifier;
  if (entry->value >= entry->max) entry->value = entry->min;
  if (entry->value <= entry->min) entry->value = entry->max;
  if (entry->value > entry->peakValue) entry->peakValue = entry->value;
}

void DBGD_stubIncDecAll(bool inc) {
  for (uint8_t i = 0; i < MFD_DATASOURCES_SIZE; i++) {
    DBGD_stubIncDecEntry(&MFD_DataSourcesAll[i], inc);
  }
}

static void DBGD_stubEntry(MFD_DataSourceTypeDef *entry) {
  if (entry->DEBUG_modifier == 0) entry->DEBUG_modifier = 1;

  if (useRandom) {
    entry->value = HAL_RNG_GetRandomNumber(&hrng) % entry->max;
  } else {
    entry->value += entry->DEBUG_modifier;

    if (entry->value <= entry->min) {
      entry->value = entry->min;
      entry->DEBUG_modifier *= -1;
    }
    if (entry->value >= entry->max) {
      entry->value = entry->max;
      entry->DEBUG_modifier *= -1;
    }
  }
  if (entry->value > entry->peakValue) entry->peakValue = entry->value;
}

void DBGD_tick(void) {
  tickCounter++;

  if (enabled) {
    for (uint8_t i = 0; i < MFD_DATASOURCES_SIZE; i++) {
      DBGD_stubEntry(&MFD_DataSourcesAll[i]);
    }
  }

  osDelay(useRandom ? DBGD_OS_DELAY_RANDOM : DBGD_OS_DELAY_NORMAL);
}
