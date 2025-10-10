#ifndef PIECHARTFULLCIRCLEVIEW_HPP
#define PIECHARTFULLCIRCLEVIEW_HPP

#include <gui_generated/piechartfullcircle_screen/PieChartFullCircleViewBase.hpp>
#include <gui/piechartfullcircle_screen/PieChartFullCirclePresenter.hpp>

class pieChartFullCircleView : public pieChartFullCircleViewBase
{
public:
    pieChartFullCircleView();
    virtual ~pieChartFullCircleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
//    void updateProcessorLoad(uint8_t mcuLoadValue);
    virtual void resetPieChart();
//    virtual void switchToGraph();
    virtual void displayPieChartSelect(touchgfx::Circle&  Serie, int angleSeriecalculate);
//    virtual void displayPieChartLegend();
//    virtual void printLegendSerie1();
//    virtual void printLegendSerie2();
//    virtual void printLegendSerie3();
//    virtual void printLegendSerie4();
//    virtual void printLegendSerie5();
//    virtual void printLegendSerie6();
    virtual void generateNewPieChart();
//    virtual void putDonutOrPie();
    virtual void drawPieChartAnimation();
//    virtual void switchToGraphAnimation();
//    virtual void putDonutAnimation();
//    virtual void putFullCircleAnimation();
    virtual void redrawPieChartAnimationPart1();
    virtual void redrawPieChartAnimationPart2();
    void pieChartClickHandler(const Container& c, const ClickEvent& e);
protected:
    Callback<pieChartFullCircleView, const Container&, const ClickEvent&> pieChartClickedCallback;
    int radiusOfPieChart;
//    int centerYSemiDonut;
    int angleSerie1Set;
    int angleSerie2Set;
    int angleSerie3Set;
    int angleSerie4Set;
    int angleSerie5Set;
    int angleSerie6Set;
    int angleSplitPieChartAnimationSerie1;
    int angleSplitPieChartAnimationSerie2;
    int angleSplitPieChartAnimationSerie3;
    int angleSplitPieChartAnimationSerie4;
    int angleSplitPieChartAnimationSerie5;
    int angleSplitPieChartAnimationSerie6;
    static const int NUMBER_OF_PIE_CHART_SECTIONS = 6;
    int angleSerie1calculate;
    int angleSerie2calculate;
    int angleSerie3calculate;
    int angleSerie4calculate;
    int angleSerie5calculate;
    int angleSerie6calculate;
    int angleStart;

    enum PieChartAnimationType
    {
        NO,
        REDRAW_PIECHART, // Fold+new slices
        REDRAW_PIECHART2_PART1, // Unfold
        REDRAW_PIECHART2_PART2,// Unfold
//        SWITCH_TO_PIECHART,
//        SWITCH_TO_GRAPH,
//        SWITCH_TO_FULL_CIRCLE,
//        SWITCH_TO_SEMI_DONUT
    } pieChartAnimation;

//    enum legendSelectedType
//    {
//        NO_LEGEND_SELECT,
//        REMOVE_LEGEND,
//        LEGEND_SERIE_1,
//        LEGEND_SERIE_2,
//        LEGEND_SERIE_3,
//        LEGEND_SERIE_4,
//        LEGEND_SERIE_5,
//        LEGEND_SERIE_6,
//        ALL_SELECT,
//    } legendSelected;

//    enum State
//    {
//        SEMI_DONUT,
//        FULL_CIRCLE
//    } pieState;

    int centerYPieChartContainerFullCircle;
    int centerXPieChartContainerFullCircle;
//    int centerYPieChartContainerDonut;
//    int centerXPieChartContainerDonut;
    int angleInDegreesClick;
//    touchgfx::colortype color_black;
//    touchgfx::colortype color_grey;
    int speedPieChartAnimation;
    int middleAnglePieChart;
};

#endif // PIECHARTVIEW_HPP
