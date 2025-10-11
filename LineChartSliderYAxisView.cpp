#include <gui/linechartslideryaxis_screen/LineChartSliderYAxisView.hpp>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

LineChartSliderYAxisView::LineChartSliderYAxisView()
    : tickCounter(0), lastValue(80)
{
//	srand(tickCounter);
//	srand(static_cast<unsigned int>(HAL_GetTick()));
	srand(static_cast<unsigned int>(time(NULL)));
}

void LineChartSliderYAxisView::setupScreen()
{
    LineChartSliderYAxisViewBase::setupScreen();
//    updateLineChart();
}

void LineChartSliderYAxisView::tearDownScreen()
{
    LineChartSliderYAxisViewBase::tearDownScreen();
}

void LineChartSliderYAxisView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 6 == 0)
    {
        // Generate the new value
        int16_t newValue = generateDeltaValue(lastValue, 15, 150, 5);

        // Add it to the chart
        lineChart.addDataPoint(newValue);
        lineChart.invalidate();

        // Update the text area to show the current value
        Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", newValue);
        textArea1.invalidate();

    }
}

int16_t LineChartSliderYAxisView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
{
    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
    int16_t newValue = lastValue + delta;

    // Clamp to min/max
    if (newValue < min) newValue = min;
    if (newValue > max) newValue = max;

    lastValue = newValue;
    return newValue;
}

void LineChartSliderYAxisView::setYAxisRange(int value)
{
    // Update the Y-axis range
    lineChart.setGraphRangeY(0, value);

    // Update the Y-axis grid interval to match the new range
    // For example, divide range by 10 for consistent gridlines
    int gridInterval = value / 10;
    if (gridInterval < 1) gridInterval = 1;
    lineChartMajorYAxisGrid.setInterval(gridInterval);

    // Update the Y-axis label interval to match
    // Typically 2x the grid interval for cleaner display
    int labelInterval = gridInterval * 2;
    if (labelInterval < 1) labelInterval = 1;
    lineChartMajorYAxisLabel.setInterval(labelInterval);
    // Invalidate the chart to redraw
    lineChart.invalidate();
}



