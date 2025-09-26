#include <gui/dynamicgraphmenu_screen/DynamicGraphMenuView.hpp>
#include <cstdlib>  // rand(), srand()
//#include <ctime>    // time()


DynamicGraphMenuView::DynamicGraphMenuView()
    : tickCounter(0), lastBlueValue(0), lastGreenValue(0)
{
	srand(tickCounter);
}

void DynamicGraphMenuView::setupScreen()
{
    DynamicGraphMenuViewBase::setupScreen();
    toggleBlueLine.forceState(true);
    toggleBlueDots.forceState(true);
    toggleGreenLine.forceState(true);
    toggleGreenDots.forceState(true);
    updateBlueGraph();
    updateGreenGraph();
}

void DynamicGraphMenuView::tearDownScreen()
{
    DynamicGraphMenuViewBase::tearDownScreen();
}

void DynamicGraphMenuView::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 10 == 0)
    {
        dynamicGraphBlue.addDataPoint(generateDeltaValue(lastBlueValue, -20, 100, 5));
        dynamicGraphGreen.addDataPoint(generateDeltaValue(lastGreenValue, -20, 100, 5));
    }
}

int16_t DynamicGraphMenuView::generateDeltaValue(int16_t& lastValue, int16_t min, int16_t max, int16_t maxDelta)
{
    int16_t delta = (rand() % (2 * maxDelta + 1)) - maxDelta; // Range: [-maxDelta, +maxDelta]
    int16_t newValue = lastValue + delta;

    // Clamp to min/max
    if (newValue < min) newValue = min;
    if (newValue > max) newValue = max;

    lastValue = newValue;
    return newValue;
}

void DynamicGraphMenuView::updateLineVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementLine& line)
{
    line.setAlpha(toggle.getState() ? 255 : 0);
    line.invalidate();
}

void DynamicGraphMenuView::updateDotsVisibility(touchgfx::ToggleButton& toggle, touchgfx::GraphElementDots& dots)
{
    dots.setAlpha(toggle.getState() ? 255 : 0);
    dots.invalidate();
}

void DynamicGraphMenuView::updateGraphElements(touchgfx::ToggleButton& lineToggle,
                                               touchgfx::GraphElementLine& line,
                                               touchgfx::ToggleButton& dotsToggle,
                                               touchgfx::GraphElementDots& dots,
                                               touchgfx::GraphScroll<31>& graph)
{
	updateLineVisibility(lineToggle, line);
    updateDotsVisibility(dotsToggle, dots);
    graph.invalidate();
}

void DynamicGraphMenuView::updateBlueGraph()
{
	updateGraphElements(toggleBlueLine, dynamicGraphBlueLine1,
	                    toggleBlueDots, dynamicGraphBlueDots1,
	                    dynamicGraphBlue);

    dynamicGraphBlue.invalidate();
}

void DynamicGraphMenuView::updateGreenGraph()
{
	updateGraphElements(toggleGreenLine, dynamicGraphGreenLine1,
	                    toggleGreenDots, dynamicGraphGreenDots1,
	                    dynamicGraphGreen);
    dynamicGraphGreen.invalidate();
}

//void DynamicGraphMenuView::updateBlueGraph()
//{
//    if (toggleBlueLine.getState() == false)
//    {
//        dynamicGraphBlueLine1.setAlpha(0);
//    }
//    else
//    {
//        dynamicGraphBlueLine1.setAlpha(255);
//    }
//
//    if (toggleBlueDots.getState() == false)
//    {
//    	dynamicGraphBlueDots1.setAlpha(0);
//    }
//    else
//    {
//    	dynamicGraphBlueDots1.setAlpha(255);
//    }
//    dynamicGraphBlue.invalidate();
//}



