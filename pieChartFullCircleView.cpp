#include <gui/piechartfullcircle_screen/PieChartFullCircleView.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Color.hpp>
#include <gui/Common/Utils.hpp>
//#include <touchgfx/widgets/canvas/CanvasWidgetRenderer.hpp>

pieChartFullCircleView::pieChartFullCircleView():
    pieChartClickedCallback(this, &pieChartFullCircleView::pieChartClickHandler),
    radiusOfPieChart(0),
//    centerYSemiDonut(-5),
    angleSerie1Set(0),
    angleSerie2Set(0),
    angleSerie3Set(0),
    angleSerie4Set(0),
    angleSerie5Set(0),
    angleSerie6Set(0),
    angleSplitPieChartAnimationSerie1(0),
    angleSplitPieChartAnimationSerie2(0),
    angleSplitPieChartAnimationSerie3(0),
    angleSplitPieChartAnimationSerie4(0),
    angleSplitPieChartAnimationSerie5(0),
    angleSplitPieChartAnimationSerie6(0),
    angleSerie1calculate(0),
    angleSerie2calculate(0),
    angleSerie3calculate(0),
    angleSerie4calculate(0),
    angleSerie5calculate(0),
    angleSerie6calculate(0),
    angleStart(90),
//    legendSelected(NO_LEGEND_SELECT),
    centerYPieChartContainerFullCircle(115),
    centerXPieChartContainerFullCircle(120),
//    centerYPieChartContainerDonut(166),
//    centerXPieChartContainerDonut(120),
    angleInDegreesClick(0),
//    color_black(touchgfx::Color::getColorFromRGB(00, 00, 00)),
//    color_grey(touchgfx::Color::getColorFromRGB(202, 203, 204)),
    speedPieChartAnimation(0),
    middleAnglePieChart(0)
{

}

void pieChartFullCircleView::setupScreen()
{
    pieChartFullCircleViewBase::setupScreen();
//    mcuLoad.setTextColor(Color::getColorFromRGB(0x0, 0x0, 0x0));
//    pieChartContainer.setClickAction(pieChartClickedCallback);
//    legendSerie1.startMoveAnimation(240, 47, 6, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//    legendSerie4.startMoveAnimation(360, 47, 10, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//    legendSerie2.startMoveAnimation(240, 89, 10, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//    legendSerie5.startMoveAnimation(360, 89, 14, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//    legendSerie3.startMoveAnimation(240, 131, 14, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//    legendSerie6.startMoveAnimation(360, 131, 16, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
    // Increase canvas buffer for smooth circles
//    static uint8_t canvasBuffer[7200];
//    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, 7200);
    Serie1.setRadius(0);
    Serie2.setRadius(0);
    Serie3.setRadius(0);
    Serie4.setRadius(0);
    Serie5.setRadius(0);
    Serie6.setRadius(0);
    Serie1.updateArc(0, 0);
    Serie2.updateArc(0, 0);
    Serie3.updateArc(0, 0);
    Serie4.updateArc(0, 0);
    Serie5.updateArc(0, 0);
    Serie6.updateArc(0, 0);
    resetPieChart();
    pieChartAnimation = REDRAW_PIECHART;
//    pieState = FULL_CIRCLE;
}

void pieChartFullCircleView::tearDownScreen()
{
    pieChartFullCircleViewBase::tearDownScreen();
}

void pieChartFullCircleView::handleTickEvent()
{
    //Launches the animations
    if (pieChartAnimation == NO)
    {
    }
    else if (pieChartAnimation == REDRAW_PIECHART)
    {
        drawPieChartAnimation();
        drawPieChartAnimation();
    }
//    else if (pieChartAnimation == SWITCH_TO_GRAPH)
//    {
//        switchToGraphAnimation();
//    }
    else if (pieChartAnimation == REDRAW_PIECHART2_PART1)
    {
        redrawPieChartAnimationPart1();
    }
    else if (pieChartAnimation == REDRAW_PIECHART2_PART2)
    {
        redrawPieChartAnimationPart2();
    }
//    else if (pieChartAnimation == SWITCH_TO_SEMI_DONUT)
//    {
//        putDonutAnimation();
//    }
//    else if (pieChartAnimation == SWITCH_TO_FULL_CIRCLE)
//    {
//        putFullCircleAnimation();
//    }
}

//void PieChartFullCircleView::printLegendSerie1()
//{
//    // display the legend if the legend is not already selected otherwise remove the legend
//    if (legendSelected == LEGEND_SERIE_1)
//    {
//        legendSelected = REMOVE_LEGEND;
//        displayPieChartLegend();
//    }
//    else
//    {
//        legendSelected = LEGEND_SERIE_1;
//        displayPieChartLegend();
//    }
//}

//void PieChartFullCircleView::printLegendSerie2()
//{
//    if (legendSelected == LEGEND_SERIE_2)
//    {
//        legendSelected = REMOVE_LEGEND;
//        displayPieChartLegend();
//    }
//    else
//    {
//        legendSelected = LEGEND_SERIE_2;
//        displayPieChartLegend();
//    }
//}

//void PieChartFullCircleView::printLegendSerie3()
//{
//    if (legendSelected == LEGEND_SERIE_3)
//    {
//        legendSelected = REMOVE_LEGEND;
//        displayPieChartLegend();
//    }
//    else
//    {
//        legendSelected = LEGEND_SERIE_3;
//        displayPieChartLegend();
//    }
//}

//void PieChartFullCircleView::printLegendSerie4()
//{
//    if (legendSelected == LEGEND_SERIE_4)
//    {
//        legendSelected = REMOVE_LEGEND;
//        displayPieChartLegend();
//    }
//    else
//    {
//        legendSelected = LEGEND_SERIE_4;
//        displayPieChartLegend();
//    }
//}

//void PieChartFullCircleView::printLegendSerie5()
//{
//    if (legendSelected == LEGEND_SERIE_5)
//    {
//        legendSelected = REMOVE_LEGEND;
//        displayPieChartLegend();
//    }
//    else
//    {
//        legendSelected = LEGEND_SERIE_5;
//        displayPieChartLegend();
//    }
//}

//void PieChartFullCircleView::printLegendSerie6()
//{
//    if (legendSelected == LEGEND_SERIE_6)
//    {
//        legendSelected = REMOVE_LEGEND;
//        displayPieChartLegend();
//    }
//    else
//    {
//        legendSelected = LEGEND_SERIE_6;
//        displayPieChartLegend();
//    }
//}

//void PieChartFullCircleView::pieChartClickHandler(const Container& c, const ClickEvent& evt)
//{
//    // display the Pie Chart when it is clicked
//    if (evt.getType() == ClickEvent::PRESSED)
//    {
//        if (pieState == FULL_CIRCLE)
//        {
//            angleInDegreesClick = CWRUtil::angle<int>(evt.getX() - centerXPieChartContainerFullCircle, evt.getY() - centerYPieChartContainerFullCircle);
//            if ((evt.getX() - centerXPieChartContainerFullCircle) * (evt.getX() - centerXPieChartContainerFullCircle) + (evt.getY() - centerYPieChartContainerFullCircle) * (evt.getY() - centerYPieChartContainerFullCircle) <= 25 * 25)
//            {
//                //circle of radius 25 inside the pie chart
//                if (legendSelected == ALL_SELECT)
//                {
//                    legendSelected = REMOVE_LEGEND;
//                    displayPieChartLegend();
//                }
//                else
//                {
//                    legendSelected = ALL_SELECT;
//                    displayPieChartLegend();
//                }
//            }
//            else if ((evt.getX() - centerXPieChartContainerFullCircle) * (evt.getX() - centerXPieChartContainerFullCircle) + (evt.getY() - centerYPieChartContainerFullCircle) * (evt.getY() - centerYPieChartContainerFullCircle) <= 75 * 75)
//            {
//                //donut between a radius of 25 and 70
//                if (angleInDegreesClick <= pieChartSerie1.getArcEnd() - 360)
//                {
//                    printLegendSerie1();
//                }
//                else if (angleInDegreesClick > pieChartSerie1.getArcEnd() - 360 && angleInDegreesClick <= pieChartSerie2.getArcEnd() - 360)
//                {
//                    printLegendSerie2();
//                }
//                else if (angleInDegreesClick > pieChartSerie2.getArcEnd() - 360 && angleInDegreesClick <= pieChartSerie3.getArcEnd() - 360)
//                {
//                    printLegendSerie3();
//                }
//                else if (angleInDegreesClick > pieChartSerie3.getArcEnd() - 360 && angleInDegreesClick <= pieChartSerie4.getArcEnd() - 360)
//                {
//                    printLegendSerie4();
//                }
//                else if (angleInDegreesClick > pieChartSerie4.getArcEnd() - 360 && angleInDegreesClick <= pieChartSerie5.getArcEnd() - 360)
//                {
//                    printLegendSerie5();
//                }
//                else if (angleInDegreesClick > pieChartSerie5.getArcEnd() - 360 && angleInDegreesClick <= pieChartSerie6.getArcEnd() - 360)
//                {
//                    printLegendSerie6();
//                }
//            }
//        }
//        else
//        {
//            angleInDegreesClick = CWRUtil::angle<int>(evt.getX() - centerXPieChartContainerDonut, evt.getY() - centerYPieChartContainerDonut);
//            if (angleInDegreesClick >= 0 && angleInDegreesClick <= 90)
//            {
//                angleInDegreesClick = angleInDegreesClick + 360;
//            }
//            if ((evt.getX() - centerXPieChartContainerDonut) * (evt.getX() - centerXPieChartContainerDonut) + (evt.getY() - centerYPieChartContainerDonut) * (evt.getY() - centerYPieChartContainerDonut) <= 40 * 40 && evt.getY() <= 166)
//            {
//                //half circle of radius 40 inside the pie chart
//                if (legendSelected == ALL_SELECT)
//                {
//                    legendSelected = REMOVE_LEGEND;
//                    displayPieChartLegend();
//                }
//                else
//                {
//                    legendSelected = ALL_SELECT;
//                    displayPieChartLegend();
//                }
//            }
//            else if ((evt.getX() - centerXPieChartContainerDonut) * (evt.getX() - centerXPieChartContainerDonut) + (evt.getY() - centerYPieChartContainerDonut) * (evt.getY() - centerYPieChartContainerDonut) <= 100 * 100 && evt.getY() <= 166)
//            {
//                // half donut between a radius of 40 and 90
//                if (angleInDegreesClick >= 245 && angleInDegreesClick <= pieChartSerie1.getArcEnd())
//                {
//                    printLegendSerie1();
//                }
//                else if (angleInDegreesClick > pieChartSerie1.getArcEnd() && angleInDegreesClick <= pieChartSerie2.getArcEnd())
//                {
//                    printLegendSerie2();
//                }
//                else if (angleInDegreesClick > pieChartSerie2.getArcEnd() && angleInDegreesClick <= pieChartSerie3.getArcEnd())
//                {
//                    printLegendSerie3();
//                }
//                else if (angleInDegreesClick > pieChartSerie3.getArcEnd() && angleInDegreesClick <= pieChartSerie4.getArcEnd())
//                {
//                    printLegendSerie4();
//                }
//                else if (angleInDegreesClick > pieChartSerie4.getArcEnd() && angleInDegreesClick <= pieChartSerie5.getArcEnd())
//                {
//                    printLegendSerie5();
//                }
//                else if (angleInDegreesClick > pieChartSerie5.getArcEnd() && angleInDegreesClick <= pieChartSerie6.getArcEnd())
//                {
//                    printLegendSerie6();
//                }
//            }
//        }
//    }
//}

void pieChartFullCircleView::pieChartClickHandler(const Container& c, const ClickEvent& evt)
{
    if (evt.getType() == ClickEvent::PRESSED)
    {
//        if (pieState == FULL_CIRCLE)
//        {
            angleInDegreesClick = CWRUtil::angle(evt.getX() - centerXPieChartContainerFullCircle, evt.getY() - centerYPieChartContainerFullCircle);

            // CENTER CLICK (radius < 25)
            if ((evt.getX() - centerXPieChartContainerFullCircle) * (evt.getX() - centerXPieChartContainerFullCircle) +
                (evt.getY() - centerYPieChartContainerFullCircle) * (evt.getY() - centerYPieChartContainerFullCircle) <= 25 * 25)
            {
                // Reset all to center
                Serie1.setCenter(120, 120);
                Serie2.setCenter(120, 120);
                Serie3.setCenter(120, 120);
                Serie4.setCenter(120, 120);
                Serie5.setCenter(120, 120);
                Serie6.setCenter(120, 120);
//                backgroundPieChart.invalidate();
            }
            // PIE SLICE CLICK (radius between 25 and 75)
            else if ((evt.getX() - centerXPieChartContainerFullCircle) * (evt.getX() - centerXPieChartContainerFullCircle) +
                     (evt.getY() - centerYPieChartContainerFullCircle) * (evt.getY() - centerYPieChartContainerFullCircle) <= 75 * 75)
            {
                // First reset all slices to center
                Serie1.setCenter(120, 120);
                Serie2.setCenter(120, 120);
                Serie3.setCenter(120, 120);
                Serie4.setCenter(120, 120);
                Serie5.setCenter(120, 120);
                Serie6.setCenter(120, 120);

                // Then highlight the clicked slice
                if (angleInDegreesClick <= Serie1.getArcEnd() - 360)
                {
                    displayPieChartSelect(Serie1, angleSerie1calculate);
                }
                else if (angleInDegreesClick > Serie1.getArcEnd() - 360 && angleInDegreesClick <= Serie2.getArcEnd() - 360)
                {
                    displayPieChartSelect(Serie2, angleSerie2calculate);
                }
                else if (angleInDegreesClick > Serie2.getArcEnd() - 360 && angleInDegreesClick <= Serie3.getArcEnd() - 360)
                {
                    displayPieChartSelect(Serie3, angleSerie3calculate);
                }
                else if (angleInDegreesClick > Serie3.getArcEnd() - 360 && angleInDegreesClick <= Serie4.getArcEnd() - 360)
                {
                    displayPieChartSelect(Serie4, angleSerie4calculate);
                }
                else if (angleInDegreesClick > Serie4.getArcEnd() - 360 && angleInDegreesClick <= Serie5.getArcEnd() - 360)
                {
                    displayPieChartSelect(Serie5, angleSerie5calculate);
                }
                else if (angleInDegreesClick > Serie5.getArcEnd() - 360 && angleInDegreesClick <= Serie6.getArcEnd() - 360)
                {
                    displayPieChartSelect(Serie6, angleSerie6calculate);
                }

//                backgroundPieChart.invalidate();
            }
        }
        // You can keep the SEMI_DONUT part or remove it if not needed
    }
//}

void pieChartFullCircleView::displayPieChartSelect(touchgfx::Circle&  Serie, int angleSeriecalculate)
{
//    if (pieState == FULL_CIRCLE)
//    {
        Serie.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(Serie.getArcStart() + (angleSeriecalculate) / 2)).to<int>(),
                                120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(Serie.getArcStart() + (angleSeriecalculate) / 2)).to<int>());
//    }
//    else
//    {
//        Serie.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie.getArcStart() + anglePieChartSeriecalculate / 4)).to<int>(),
//                                120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie.getArcStart() + anglePieChartSeriecalculate / 4)).to<int>());
//    }
}


//void PieChartFullCircleView::displayPieChartLegend()
//{
//    textLegendSerie1.setVisible(false);
//    textLegendSerie2.setVisible(false);
//    textLegendSerie3.setVisible(false);
//    textLegendSerie4.setVisible(false);
//    textLegendSerie5.setVisible(false);
//    textLegendSerie6.setVisible(false);
//    textAreaSerie1.setColor(color_grey);
//    textAreaSerie2.setColor(color_grey);
//    textAreaSerie3.setColor(color_grey);
//    textAreaSerie4.setColor(color_grey);
//    textAreaSerie5.setColor(color_grey);
//    textAreaSerie6.setColor(color_grey);
//    legendSerieImage1.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_BLUE_ID));
//    legendSerieImage2.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_GREEN_ID));
//    legendSerieImage3.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_ORANGE_ID));
//    legendSerieImage4.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_RED_ID));
//    legendSerieImage5.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_YELLOW_ID));
//    legendSerieImage6.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_PURPLE_ID));
//    pieChartSerie1.setCenter(120, 120);
//    pieChartSerie2.setCenter(120, 120);
//    pieChartSerie3.setCenter(120, 120);
//    pieChartSerie4.setCenter(120, 120);
//    pieChartSerie5.setCenter(120, 120);
//    pieChartSerie6.setCenter(120, 120);
//
//    if (legendSelected == LEGEND_SERIE_1)
//    {
//        textLegendSerie1.setVisible(true);
//        textAreaSerie1.setColor(color_black);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie1), anglePieChartSerie1calculate);
//        legendSerieImage1.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_BLUE_ACTIVE_ID));
//    }
//    else if (legendSelected == LEGEND_SERIE_2)
//    {
//        textLegendSerie2.setVisible(true);
//        textAreaSerie2.setColor(color_black);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie2), anglePieChartSerie2calculate);
//        legendSerieImage2.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_GREEN_ACTIVE_ID));
//    }
//    else if (legendSelected == LEGEND_SERIE_3)
//    {
//        textLegendSerie3.setVisible(true);
//        textAreaSerie3.setColor(color_black);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie3), anglePieChartSerie3calculate);
//        legendSerieImage3.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_ORANGE_ACTIVE_ID));
//    }
//    else if (legendSelected == LEGEND_SERIE_4)
//    {
//        textLegendSerie4.setVisible(true);
//        textAreaSerie4.setColor(color_black);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie4), anglePieChartSerie4calculate);
//        legendSerieImage4.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_RED_ACTIVE_ID));
//    }
//    else if (legendSelected == LEGEND_SERIE_5)
//    {
//        textLegendSerie5.setVisible(true);
//        textAreaSerie5.setColor(color_black);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie5), anglePieChartSerie5calculate);
//        legendSerieImage5.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_YELLOW_ACTIVE_ID));
//    }
//    else if (legendSelected == LEGEND_SERIE_6)
//    {
//        textLegendSerie6.setVisible(true);
//        textAreaSerie6.setColor(color_black);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie6), anglePieChartSerie6calculate);
//        legendSerieImage6.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_PURPLE_ACTIVE_ID));
//    }
//    else if (legendSelected == REMOVE_LEGEND)
//    {
//        legendSelected = NO_LEGEND_SELECT;
//    }
//    else if (legendSelected == ALL_SELECT)
//    {
//        textLegendSerie1.setVisible(true);
//        textLegendSerie2.setVisible(true);
//        textLegendSerie3.setVisible(true);
//        textLegendSerie4.setVisible(true);
//        textLegendSerie5.setVisible(true);
//        textLegendSerie6.setVisible(true);
//        textAreaSerie1.setColor(color_black);
//        textAreaSerie2.setColor(color_black);
//        textAreaSerie3.setColor(color_black);
//        textAreaSerie4.setColor(color_black);
//        textAreaSerie5.setColor(color_black);
//        textAreaSerie6.setColor(color_black);
//        legendSerieImage1.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_BLUE_ACTIVE_ID));
//        legendSerieImage2.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_GREEN_ACTIVE_ID));
//        legendSerieImage3.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_ORANGE_ACTIVE_ID));
//        legendSerieImage4.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_RED_ACTIVE_ID));
//        legendSerieImage5.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_YELLOW_ACTIVE_ID));
//        legendSerieImage6.setBitmap(touchgfx::Bitmap(BITMAP_PIE_CHART_LEGEND_PURPLE_ACTIVE_ID));
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie1), anglePieChartSerie1calculate);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie2), anglePieChartSerie2calculate);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie3), anglePieChartSerie3calculate);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie4), anglePieChartSerie4calculate);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie5), anglePieChartSerie5calculate);
//        displayPieChartSelect(const_cast <touchgfx::Circle&>(pieChartSerie6), anglePieChartSerie6calculate);
//    }
//    backgroundPieChart.invalidate();
//}

void pieChartFullCircleView::resetPieChart()
{
    int shares[NUMBER_OF_PIE_CHART_SECTIONS];

    int remaining = 100;
    int sum = 0;

    for (int i = 0; i < NUMBER_OF_PIE_CHART_SECTIONS; i++)
    {
        shares[i] = Utils::randomNumberBetween(20, 110);
        sum += shares[i];
    }
    for (int i = 0; i < NUMBER_OF_PIE_CHART_SECTIONS - 1; i++)
    {
        shares[i] = (shares[i] * 100) / sum;
        remaining -= shares[i];
    }
    shares[NUMBER_OF_PIE_CHART_SECTIONS - 1] = remaining;

//    Unicode::snprintf(textLegendSerie1Buffer, TEXTLEGENDSERIE1_SIZE, "%d", shares[0]);
//    Unicode::snprintf(textLegendSerie2Buffer, TEXTLEGENDSERIE2_SIZE, "%d", shares[1]);
//    Unicode::snprintf(textLegendSerie3Buffer, TEXTLEGENDSERIE3_SIZE, "%d", shares[2]);
//    Unicode::snprintf(textLegendSerie4Buffer, TEXTLEGENDSERIE4_SIZE, "%d", shares[3]);
//    Unicode::snprintf(textLegendSerie5Buffer, TEXTLEGENDSERIE5_SIZE, "%d", shares[4]);
//    Unicode::snprintf(textLegendSerie6Buffer, TEXTLEGENDSERIE6_SIZE, "%d", shares[5]);

    angleSerie1calculate = (shares[0] * 360) / 100;
    angleSerie2calculate = (shares[1] * 360) / 100;
    angleSerie3calculate = (shares[2] * 360) / 100;
    angleSerie4calculate = (shares[3] * 360) / 100;
    angleSerie5calculate = (shares[4] * 360) / 100;
    angleSerie6calculate = (shares[5] * 360) / 100;
}

void pieChartFullCircleView::drawPieChartAnimation()
{
    if (radiusOfPieChart <= 58) // grow up the circle
    {
        Serie1.setRadius(radiusOfPieChart);
        Serie2.setRadius(radiusOfPieChart);
        Serie3.setRadius(radiusOfPieChart);
        Serie4.setRadius(radiusOfPieChart);
        Serie5.setRadius(radiusOfPieChart);
        Serie6.setRadius(radiusOfPieChart);
        radiusOfPieChart += 2;
    }
    if (angleStart < 360) // turn the circle on itself
    {
        angleStart += 10;
    }
    for (int i = 0; i < 4; i++) // made the pie chart progress
    {
        if (angleSerie1Set < angleSerie1calculate)
        {
            angleSerie1Set++;
        }
        if (angleSerie2Set < angleSerie2calculate)
        {
            angleSerie2Set++;
        }
        if (angleSerie3Set < angleSerie3calculate)
        {
            angleSerie3Set++;
        }
        if (angleSerie4Set < angleSerie4calculate)
        {
            angleSerie4Set++;
        }
        if (angleSerie5Set < angleSerie5calculate)
        {
            angleSerie5Set++;
        }
        if (angleSerie6Set < angleSerie6calculate)
        {
            angleSerie6Set++;
        }
        Serie1.setArc(angleStart, angleSerie1Set + angleStart);
        Serie2.updateArc(angleSerie1Set + angleStart, angleSerie1Set + angleSerie2Set + angleStart);
        Serie3.updateArc(angleSerie1Set + angleSerie2Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleStart);
        Serie4.updateArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleStart);
        Serie5.updateArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleStart);
        Serie6.updateArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleSerie6Set + angleStart);
        if (angleSerie1Set == angleSerie1calculate && angleSerie2Set == angleSerie2calculate && angleSerie3Set == angleSerie3calculate && angleSerie4Set == angleSerie4calculate && angleSerie5Set == angleSerie5calculate && angleSerie6Set == angleSerie6calculate && radiusOfPieChart == 60 && angleStart == 360)
        {
            Serie6.setArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleStart, 720);
            pieChartAnimation = NO;
//            pieState = FULL_CIRCLE;
        }
//        backgroundPieChart.invalidate();
    }
}

//void pieChartFullCircleView::switchToGraph()
//{
//    if (pieChartAnimation == NO)
//    {
//        pieChartAnimation = SWITCH_TO_GRAPH;
//        legendSerie1.startMoveAnimation(480, 47, 16, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//        legendSerie4.startMoveAnimation(600, 47, 14, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//        legendSerie2.startMoveAnimation(480, 92, 14, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//        legendSerie5.startMoveAnimation(600, 92, 10, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//        legendSerie3.startMoveAnimation(480, 135, 10, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//        legendSerie6.startMoveAnimation(600, 135, 6, EasingEquations::linearEaseNone, EasingEquations::linearEaseNone);
//    }
//}

//void pieChartFullCircleView::switchToGraphAnimation()
//{
////    if (pieState == FULL_CIRCLE)
////    {
//        if (radiusOfPieChart <= 60 && radiusOfPieChart >= 2)
//        {
//            Serie1.setRadius(radiusOfPieChart);
//            Serie2.setRadius(radiusOfPieChart);
//            Serie3.setRadius(radiusOfPieChart);
//            Serie4.setRadius(radiusOfPieChart);
//            Serie5.setRadius(radiusOfPieChart);
//            Serie6.setRadius(radiusOfPieChart);
//            radiusOfPieChart -= 3;
//        }
//        backgroundPieChart.invalidate();
//        if (radiusOfPieChart == 0)
//        {
//            gotoGraphScreen();
//        }
//    }
//    else
//    {
//        if (radiusOfPieChart <= 60 && radiusOfPieChart >= 2)
//        {
//            Serie1.setRadius(radiusOfPieChart);
//            pieChartSerie2.setRadius(radiusOfPieChart);
//            pieChartSerie3.setRadius(radiusOfPieChart);
//            pieChartSerie4.setRadius(radiusOfPieChart);
//            pieChartSerie5.setRadius(radiusOfPieChart);
//            pieChartSerie6.setRadius(radiusOfPieChart);
//            pieChartSerie1.setLineWidth(radiusOfPieChart);
//            pieChartSerie2.setLineWidth(radiusOfPieChart);
//            pieChartSerie3.setLineWidth(radiusOfPieChart);
//            pieChartSerie4.setLineWidth(radiusOfPieChart);
//            pieChartSerie5.setLineWidth(radiusOfPieChart);
//            pieChartSerie6.setLineWidth(radiusOfPieChart);
//            radiusOfPieChart -= 3;
//        }
//        if (centerYSemiDonut > -15)
//        {
//            pieChartSerie1.setXY(0, centerYSemiDonut);
//            pieChartSerie2.setXY(0, centerYSemiDonut);
//            pieChartSerie3.setXY(0, centerYSemiDonut);
//            pieChartSerie4.setXY(0, centerYSemiDonut);
//            pieChartSerie5.setXY(0, centerYSemiDonut);
//            pieChartSerie6.setXY(0, centerYSemiDonut);
//            centerYSemiDonut -= 5;
//        }
//        backgroundPieChart.invalidate();
//        if (radiusOfPieChart == 0 && centerYSemiDonut >= -16)
//        {
//            gotoGraphScreen();
//        }
//    }
//}

//void pieChartFullCircleView::putDonutOrPie()
//{
//    if (pieChartAnimation == NO)
//    {
//        if (pieState == FULL_CIRCLE)
//        {
//            pieChartAnimation = SWITCH_TO_SEMI_DONUT;
//            angleStart = 360;
//            radiusOfPieChart = 30;
//
//        }
//        else
//        {
//            pieChartAnimation = SWITCH_TO_FULL_CIRCLE;
//            angleStart = 270;
//            radiusOfPieChart = 60;
//        }
//    }
//}

//void pieChartFullCircleView::putDonutAnimation()
//{
//    pieState = SEMI_DONUT;
//    displayPieChartLegend();
//    for (int i = 0; i < 3; i++)
//    {
//        if (angleStart > 270)
//        {
//            angleStart -= 5;
//        }
//        if (anglePieChartSerie1Set > anglePieChartSerie1calculate / 2)
//        {
//            anglePieChartSerie1Set--;
//        }
//        if (anglePieChartSerie2Set > anglePieChartSerie2calculate / 2)
//        {
//            anglePieChartSerie2Set--;
//        }
//        if (anglePieChartSerie3Set > anglePieChartSerie3calculate / 2)
//        {
//            anglePieChartSerie3Set--;
//        }
//        if (anglePieChartSerie4Set > anglePieChartSerie4calculate / 2)
//        {
//            anglePieChartSerie4Set--;
//        }
//        if (anglePieChartSerie5Set > anglePieChartSerie5calculate / 2)
//        {
//            anglePieChartSerie5Set--;
//        }
//        if (anglePieChartSerie6Set > anglePieChartSerie6calculate / 2)
//        {
//            anglePieChartSerie6Set--;
//        }
//        pieChartSerie1.setArc(angleStart, anglePieChartSerie1Set + angleStart);
//        pieChartSerie2.updateArc(anglePieChartSerie1Set + angleStart, anglePieChartSerie1Set + anglePieChartSerie2Set + angleStart);
//        pieChartSerie3.updateArc(anglePieChartSerie1Set + anglePieChartSerie2Set + angleStart, anglePieChartSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + angleStart);
//        pieChartSerie4.updateArc(anglePieChartSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + angleStart, anglePieChartSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + anglePieChartSerie4Set + angleStart);
//        pieChartSerie5.updateArc(anglePieChartSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + anglePieChartSerie4Set + angleStart, angleSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + anglePieChartSerie4Set + anglePieChartSerie5Set + angleStart);
//        pieChartSerie6.updateArc(anglePieChartSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + anglePieChartSerie4Set + anglePieChartSerie5Set + angleStart, anglePieChartSerie1Set + anglePieChartSerie2Set + anglePieChartSerie3Set + anglePieChartSerie4Set + anglePieChartSerie5Set + anglePieChartSerie6Set + angleStart);
//
//        if (anglePieChartSerie1Set == anglePieChartSerie1calculate / 2 && anglePieChartSerie2Set == anglePieChartSerie2calculate / 2  && anglePieChartSerie3Set == anglePieChartSerie3calculate / 2  && anglePieChartSerie4Set == anglePieChartSerie4calculate / 2  && anglePieChartSerie5Set == anglePieChartSerie5calculate / 2  && anglePieChartSerie6Set == anglePieChartSerie6calculate / 2)
//        {
//            if (radiusOfPieChart <= 59)
//            {
//                pieChartSerie1.setLineWidth(60);
//                pieChartSerie2.setLineWidth(60);
//                pieChartSerie3.setLineWidth(60);
//                pieChartSerie4.setLineWidth(60);
//                pieChartSerie5.setLineWidth(60);
//                pieChartSerie6.setLineWidth(60);
//                pieChartSerie1.setRadius(radiusOfPieChart);
//                pieChartSerie2.setRadius(radiusOfPieChart);
//                pieChartSerie3.setRadius(radiusOfPieChart);
//                pieChartSerie4.setRadius(radiusOfPieChart);
//                pieChartSerie5.setRadius(radiusOfPieChart);
//                pieChartSerie6.setRadius(radiusOfPieChart);
//                radiusOfPieChart += 1;
//            }
//            if (centerYSemiDonut <= 49)
//            {
//                pieChartSerie1.setXY(0, centerYSemiDonut);
//                pieChartSerie2.setXY(0, centerYSemiDonut);
//                pieChartSerie3.setXY(0, centerYSemiDonut);
//                pieChartSerie4.setXY(0, centerYSemiDonut);
//                pieChartSerie5.setXY(0, centerYSemiDonut);
//                pieChartSerie6.setXY(0, centerYSemiDonut);
//                centerYSemiDonut += 1;
//            }
//            if (radiusOfPieChart == 60 && centerYSemiDonut == 50)
//            {
//                pieChartSerie6.setArc(pieChartSerie6.getArcStart(), 450);
//                pieChartAnimation = NO;
//                donutOrPieButton.setBitmaps(touchgfx::Bitmap(BITMAP_PIE_TOGGLE_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_PIE_TOGGLE_BUTTON_INACTIVE_ID));
//                donutOrPieButton.invalidate();
//            }
//        }
//        backgroundPieChart.invalidate();
//    }
//}

//void pieChartFullCircleView::putFullCircleAnimation()
//{
//    for (int i = 0; i < 3; i++)
//    {
//        if (angleSerie1Set == angleSerie1calculate / 2 && angleSerie2Set == angleSerie2calculate / 2  && angleSerie3Set == angleSerie3calculate / 2  && angleSerie4Set == angleSerie4calculate / 2  && angleSerie5Set == angleSerie5calculate / 2  && angleSerie6Set == angleSerie6calculate / 2)
//        {
//            if (radiusOfPieChart > 30)
//            {
//                Serie1.setRadius(radiusOfPieChart);
//                Serie2.setRadius(radiusOfPieChart);
//                Serie3.setRadius(radiusOfPieChart);
//                Serie4.setRadius(radiusOfPieChart);
//                Serie5.setRadius(radiusOfPieChart);
//                Serie6.setRadius(radiusOfPieChart);
//                radiusOfPieChart--;
//            }
//            if (centerYSemiDonut > -5)
//            {
//                Serie1.setXY(0, centerYSemiDonut);
//                Serie2.setXY(0, centerYSemiDonut);
//                Serie3.setXY(0, centerYSemiDonut);
//                Serie4.setXY(0, centerYSemiDonut);
//                Serie5.setXY(0, centerYSemiDonut);
//                Serie6.setXY(0, centerYSemiDonut);
//                centerYSemiDonut--;
//            }
//            if (radiusOfPieChart == 30 && centerYSemiDonut == -5)
//            {
//                Serie1.setLineWidth(0);
//                Serie2.setLineWidth(0);
//                Serie3.setLineWidth(0);
//                Serie4.setLineWidth(0);
//                Serie5.setLineWidth(0);
//                Serie6.setLineWidth(0);
//                Serie1.setRadius(60);
//                Serie2.setRadius(60);
//                Serie3.setRadius(60);
//                Serie4.setRadius(60);
//                Serie5.setRadius(60);
//                Serie6.setRadius(60);
//            }
//        }
//        if (radiusOfPieChart == 30 && centerYSemiDonut == -5)
//        {
//            pieState = FULL_CIRCLE;
//            displayPieChartLegend();
//            if (angleStart < 360) // turn the circle on itself
//            {
//                angleStart += 5;
//            }
//            if (angleSerie1Set < angleSerie1calculate)
//            {
//                angleSerie1Set++;
//            }
//            if (angleSerie2Set < angleSerie2calculate)
//            {
//                angleSerie2Set++;
//            }
//            if (angleSerie3Set < angleSerie3calculate)
//            {
//                angleSerie3Set++;
//            }
//            if (angleSerie4Set < angleSerie4calculate)
//            {
//                angleSerie4Set++;
//            }
//            if (angleSerie5Set < angleSerie5calculate)
//            {
//                angleSerie5Set++;
//            }
//            if (angleSerie6Set < angleSerie6calculate)
//            {
//                angleSerie6Set++;
//            }
//            Serie1.setArc(angleStart, angleSerie1Set + angleStart);
//            Serie2.updateArc(angleSerie1Set + angleStart, angleSerie1Set + angleSerie2Set + angleStart);
//            Serie3.updateArc(angleSerie1Set + angleSerie2Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleStart);
//            Serie4.updateArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleStart);
//            Serie5.updateArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleStart);
//            Serie6.updateArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleStart, angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleSerie6Set + angleStart);
//            if (angleSerie1Set == angleSerie1calculate && angleSerie2Set == angleSerie2calculate && angleSerie3Set == angleSerie3calculate && angleSerie4Set == angleSerie4calculate && angleSerie5Set == angleSerie5calculate && angleSerie6Set == angleSerie6calculate)
//            {
//                Serie6.setArc(angleSerie1Set + angleSerie2Set + angleSerie3Set + angleSerie4Set + angleSerie5Set + angleStart, 720);
//                pieChartAnimation = NO;
//                donutOrPieButton.setBitmaps(touchgfx::Bitmap(BITMAP_HALF_CIRCLE_TOGGLE_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_HALF_CIRCLE_TOGGLE_BUTTON_INACTIVE_ID));
//                donutOrPieButton.invalidate();
//            }
//        }
//    }
////    backgroundPieChart.invalidate();
//}

//void PieChartFullCircleView::setNewPieChart()
void pieChartFullCircleView::generateNewPieChart()
{
    if (pieChartAnimation == NO)
    {
        resetPieChart();
        pieChartAnimation = REDRAW_PIECHART2_PART1;
        redrawPieChartAnimationPart1();//added
    }
}

void pieChartFullCircleView::redrawPieChartAnimationPart1()
{
    // close the circle
//    if (pieState == FULL_CIRCLE)
//    {
        speedPieChartAnimation = 6;
        middleAnglePieChart = 540;
//    }
//    else
//    {
//        speedPieChartAnimation = 3;
//        middleAnglePieChart = 360;
//    }

    for (int i = 0; i < speedPieChartAnimation; i++)
    {
        if (angleSerie1Set > 0 && Serie1.getArcStart() <= middleAnglePieChart)
        {
            angleSerie1Set--;
            Serie1.setArc(Serie1.getArcStart() + 1, Serie1.getArcEnd());
        }
        if (angleSerie2Set > 0 && Serie2.getArcStart() <= middleAnglePieChart)
        {
            angleSerie2Set--;
            Serie2.setArc(Serie2.getArcStart() + 1, Serie2.getArcEnd());
            Serie1.setArc(Serie1.getArcStart() + 1, Serie2.getArcStart() + 1);
        }
        if (angleSerie3Set > 0 && Serie3.getArcStart() <= middleAnglePieChart)
        {
            angleSerie3Set--;
            Serie3.setArc(Serie3.getArcStart() + 1, Serie3.getArcEnd());
            Serie2.setArc(Serie2.getArcStart() + 1, Serie3.getArcStart() + 1);
            Serie1.setArc(Serie1.getArcStart() + 1, Serie2.getArcStart() + 1);
        }
        if (angleSerie4Set > 0 && Serie4.getArcStart() <= middleAnglePieChart)
        {
            angleSerie4Set--;
            Serie4.setArc(Serie4.getArcStart() + 1, Serie4.getArcEnd());
            Serie3.setArc(Serie3.getArcStart() + 1, Serie4.getArcStart() + 1);
            Serie2.setArc(Serie2.getArcStart() + 1, Serie3.getArcStart() + 1);
            Serie1.setArc(Serie1.getArcStart() + 1, Serie2.getArcStart() + 1);
        }
        if (angleSerie5Set > 0 && Serie5.getArcStart() <= middleAnglePieChart)
        {
            angleSerie5Set--;
            Serie5.setArc(Serie5.getArcStart() + 1, Serie5.getArcEnd());
            Serie4.setArc(Serie4.getArcStart() + 1, Serie5.getArcStart() + 1);
            Serie3.setArc(Serie3.getArcStart() + 1, Serie4.getArcStart() + 1);
            Serie2.setArc(Serie2.getArcStart() + 1, Serie3.getArcStart() + 1);
            Serie1.setArc(Serie1.getArcStart() + 1, Serie2.getArcStart() + 1);
        }
        if (angleSerie6Set > 0 && Serie6.getArcStart() <= middleAnglePieChart)
        {
            angleSerie6Set--;
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd());
            Serie5.setArc(Serie5.getArcStart() + 1, Serie6.getArcStart() + 1);
            Serie4.setArc(Serie4.getArcStart() + 1, Serie5.getArcStart() + 1);
            Serie3.setArc(Serie3.getArcStart() + 1, Serie4.getArcStart() + 1);
            Serie2.setArc(Serie2.getArcStart() + 1, Serie3.getArcStart() + 1);
            Serie1.setArc(Serie1.getArcStart() + 1, Serie2.getArcStart() + 1);
        }
        if (angleSerie6Set > 0 && Serie6.getArcEnd() >= middleAnglePieChart)
        {
            angleSerie6Set--;
            Serie6.setArc(Serie6.getArcStart(), Serie6.getArcEnd() - 1);
        }
        if (angleSerie5Set > 0 && Serie5.getArcEnd() >= middleAnglePieChart)
        {
            angleSerie5Set--;
            Serie5.setArc(Serie5.getArcStart(), Serie5.getArcEnd() - 1);
            Serie6.setArc(Serie5.getArcEnd() - 1, Serie6.getArcEnd() - 1);
        }
        if (angleSerie4Set > 0 && Serie4.getArcEnd() >= middleAnglePieChart)
        {
            angleSerie4Set--;
            Serie4.setArc(Serie4.getArcStart(), Serie4.getArcEnd() - 1);
            Serie5.setArc(Serie4.getArcEnd() - 1, Serie5.getArcEnd() - 1);
            Serie6.setArc(Serie5.getArcEnd() - 1, Serie6.getArcEnd() - 1);
        }
        if (angleSerie3Set > 0 && Serie3.getArcEnd() >= middleAnglePieChart)
        {
            angleSerie3Set--;
            Serie3.setArc(Serie3.getArcStart(), Serie3.getArcEnd() - 1);
            Serie4.setArc(Serie3.getArcEnd() - 1, Serie4.getArcEnd() - 1);
            Serie5.setArc(Serie4.getArcEnd() - 1, Serie5.getArcEnd() - 1);
            Serie6.setArc(Serie5.getArcEnd() - 1, Serie6.getArcEnd() - 1);
        }
        if (angleSerie2Set > 0 && Serie2.getArcEnd() >= middleAnglePieChart)
        {
            angleSerie2Set--;
            Serie2.setArc(Serie2.getArcStart(), Serie2.getArcEnd() - 1);
            Serie3.setArc(Serie2.getArcEnd() - 1, Serie3.getArcEnd() - 1);
            Serie4.setArc(Serie3.getArcEnd() - 1, Serie4.getArcEnd() - 1);
            Serie5.setArc(Serie4.getArcEnd() - 1, Serie5.getArcEnd() - 1);
            Serie6.setArc(Serie5.getArcEnd() - 1, Serie6.getArcEnd() - 1);
        }
        if (angleSerie1Set > 0 && Serie1.getArcEnd() >= middleAnglePieChart)
        {
            angleSerie1Set--;
            Serie1.setArc(Serie1.getArcStart(), Serie1.getArcEnd() - 1);
            Serie2.setArc(Serie1.getArcEnd() - 1, Serie2.getArcEnd() - 1);
            Serie3.setArc(Serie2.getArcEnd() - 1, Serie3.getArcEnd() - 1);
            Serie4.setArc(Serie3.getArcEnd() - 1, Serie4.getArcEnd() - 1);
            Serie5.setArc(Serie4.getArcEnd() - 1, Serie5.getArcEnd() - 1);
            Serie6.setArc(Serie5.getArcEnd() - 1, Serie6.getArcEnd() - 1);
        }
        if (angleSerie1Set == 0 && angleSerie2Set == 0 && angleSerie3Set == 0 && angleSerie4Set == 0 && angleSerie5Set == 0 && angleSerie6Set == 0)
        {
            pieChartAnimation = REDRAW_PIECHART2_PART2;
//        	redrawPieChartAnimationPart2();
            Serie1.setArc(middleAnglePieChart, middleAnglePieChart);
            Serie2.setArc(middleAnglePieChart, middleAnglePieChart);
            Serie3.setArc(middleAnglePieChart, middleAnglePieChart);
            Serie4.setArc(middleAnglePieChart, middleAnglePieChart);
            Serie5.setArc(middleAnglePieChart, middleAnglePieChart);
            Serie6.setArc(middleAnglePieChart, middleAnglePieChart);
        }
    }
//    backgroundPieChart.invalidate();
}


void pieChartFullCircleView::redrawPieChartAnimationPart2()
{
    int halfCircleDegrees = 0;
    int minArc = 0;
    int maxArc = 0;
//    if (pieState == FULL_CIRCLE)
//    {
        speedPieChartAnimation = 4;
        halfCircleDegrees = 180;
        minArc = 360;
        maxArc = 720;
        angleSplitPieChartAnimationSerie1 = angleSerie1calculate;
        angleSplitPieChartAnimationSerie2 = angleSerie2calculate;
        angleSplitPieChartAnimationSerie3 = angleSerie3calculate;
        angleSplitPieChartAnimationSerie4 = angleSerie4calculate;
        angleSplitPieChartAnimationSerie5 = angleSerie5calculate;
        angleSplitPieChartAnimationSerie6 = angleSerie6calculate;
//    }
//    else
//    {
//        speedPieChartAnimation = 2;
//        halfCircleDegrees = 90;
//        minArc = 270;
//        maxArc = 450;
//        angleSplitPieChartAnimationSerie1 = angleSerie1calculate / 2;
//        angleSplitPieChartAnimationSerie2 = angleSerie2calculate / 2;
//        angleSplitPieChartAnimationSerie3 = anglePieChartSerie3calculate / 2;
//        angleSplitPieChartAnimationSerie4 = anglePieChartSerie4calculate / 2;
//        angleSplitPieChartAnimationSerie5 = anglePieChartSerie5calculate / 2;
//        angleSplitPieChartAnimationSerie6 = anglePieChartSerie6calculate / 2;
//    }
    for (int i = 0; i < speedPieChartAnimation; i++)
    {
        if (angleSerie1Set < halfCircleDegrees && angleSerie1Set < angleSplitPieChartAnimationSerie1)
        {
            angleSerie1Set++;
            Serie1.setArc(Serie1.getArcStart(), Serie1.getArcEnd() - 1);
        }
        else if (angleSerie1Set >= halfCircleDegrees && angleSerie1Set < angleSplitPieChartAnimationSerie1)
        {

            angleSerie1Set++;
            Serie1.setArc(Serie1.getArcStart() + 1, Serie1.getArcEnd());
            Serie2.setArc(Serie2.getArcStart() + 1, Serie2.getArcEnd() + 1);
            Serie3.setArc(Serie3.getArcStart() + 1, Serie3.getArcEnd() + 1);
            Serie4.setArc(Serie4.getArcStart() + 1, Serie4.getArcEnd() + 1);
            Serie5.setArc(Serie5.getArcStart() + 1, Serie5.getArcEnd() + 1);
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd() + 1);

        }
        if (angleSplitPieChartAnimationSerie1 + angleSerie2Set < halfCircleDegrees && angleSerie2Set < angleSplitPieChartAnimationSerie2)
        {
            angleSerie2Set++;
            Serie2.setArc(Serie2.getArcStart(), Serie2.getArcEnd() - 1);
            Serie1.setArc(Serie1.getArcStart() - 1, Serie1.getArcEnd() - 1);
        }
        else if (angleSplitPieChartAnimationSerie1 + angleSerie2Set >= halfCircleDegrees && angleSerie2Set < angleSplitPieChartAnimationSerie2)
        {
            angleSerie2Set++;
            Serie2.setArc(Serie2.getArcStart() + 1, Serie2.getArcEnd());
            Serie3.setArc(Serie3.getArcStart() + 1, Serie3.getArcEnd() + 1);
            Serie4.setArc(Serie4.getArcStart() + 1, Serie4.getArcEnd() + 1);
            Serie5.setArc(Serie5.getArcStart() + 1, Serie5.getArcEnd() + 1);
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd() + 1);
        }
        if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSerie3Set < halfCircleDegrees && angleSerie3Set < angleSplitPieChartAnimationSerie3)
        {
            angleSerie3Set++;
            Serie3.setArc(Serie3.getArcStart(), Serie3.getArcEnd() - 1);
            Serie2.setArc(Serie2.getArcStart() - 1, Serie2.getArcEnd() - 1);
            Serie1.setArc(Serie1.getArcStart() - 1, Serie1.getArcEnd() - 1);
        }
        else if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSerie3Set >= halfCircleDegrees && angleSerie3Set < angleSplitPieChartAnimationSerie3)
        {
            angleSerie3Set++;
            Serie3.setArc(Serie3.getArcStart() + 1, Serie3.getArcEnd());
            Serie4.setArc(Serie4.getArcStart() + 1, Serie4.getArcEnd() + 1);
            Serie5.setArc(Serie5.getArcStart() + 1, Serie5.getArcEnd() + 1);
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd() + 1);
        }
        if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSerie4Set < halfCircleDegrees && angleSerie4Set < angleSplitPieChartAnimationSerie4)
        {
            angleSerie4Set++;
            Serie4.setArc(Serie4.getArcStart(), Serie4.getArcEnd() - 1);
            Serie3.setArc(Serie3.getArcStart() - 1, Serie3.getArcEnd() - 1);
            Serie2.setArc(Serie2.getArcStart() - 1, Serie2.getArcEnd() - 1);
            Serie1.setArc(Serie1.getArcStart() - 1, Serie1.getArcEnd() - 1);
        }
        else if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSerie4Set >= halfCircleDegrees && angleSerie4Set < angleSplitPieChartAnimationSerie4)
        {
            angleSerie4Set++;
            Serie4.setArc(Serie4.getArcStart() + 1, Serie4.getArcEnd());
            Serie5.setArc(Serie5.getArcStart() + 1, Serie5.getArcEnd() + 1);
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd() + 1);
        }
        if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4 + angleSerie5Set < halfCircleDegrees && angleSerie5Set < angleSplitPieChartAnimationSerie5)
        {
            angleSerie5Set++;
            Serie5.setArc(Serie5.getArcStart(), Serie5.getArcEnd() - 1);
            Serie4.setArc(Serie4.getArcStart() - 1, Serie4.getArcEnd() - 1);
            Serie3.setArc(Serie3.getArcStart() - 1, Serie3.getArcEnd() - 1);
            Serie2.setArc(Serie2.getArcStart() - 1, Serie2.getArcEnd() - 1);
            Serie1.setArc(Serie1.getArcStart() - 1, Serie1.getArcEnd() - 1);
        }
        else if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4 + angleSerie5Set >= halfCircleDegrees && angleSerie5Set < angleSplitPieChartAnimationSerie5)
        {
            angleSerie5Set++;
            Serie5.setArc(Serie5.getArcStart() + 1, Serie5.getArcEnd());
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd() + 1);
        }
        if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4 + angleSplitPieChartAnimationSerie5 + angleSerie6Set < halfCircleDegrees && angleSerie6Set < angleSplitPieChartAnimationSerie6)
        {
            angleSerie6Set++;
            Serie6.setArc(Serie6.getArcStart(), Serie6.getArcEnd() - 1);
            Serie5.setArc(Serie5.getArcStart() - 1, Serie5.getArcEnd() - 1);
            Serie4.setArc(Serie4.getArcStart() - 1, Serie4.getArcEnd() - 1);
            Serie3.setArc(Serie3.getArcStart() - 1, Serie3.getArcEnd() - 1);
            Serie2.setArc(Serie2.getArcStart() - 1, Serie2.getArcEnd() - 1);
            Serie1.setArc(Serie1.getArcStart() - 1, Serie1.getArcEnd() - 1);
        }
        else if (angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4 + angleSplitPieChartAnimationSerie5 + angleSerie6Set >= halfCircleDegrees && angleSerie6Set < angleSplitPieChartAnimationSerie6)
        {
            angleSerie6Set++;
            Serie6.setArc(Serie6.getArcStart() + 1, Serie6.getArcEnd());
        }
//        if (legendSelected == LEGEND_SERIE_1)
//        {
//            pieChartSerie1.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie1.getArcEnd() + (angleSplitPieChartAnimationSerie1) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie1.getArcEnd() + (angleSplitPieChartAnimationSerie1) / 2)).to<int>());
//        }
//        else if (legendSelected == LEGEND_SERIE_2)
//        {
//            pieChartSerie2.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie2.getArcEnd() + (angleSplitPieChartAnimationSerie2) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie2.getArcEnd() + (angleSplitPieChartAnimationSerie2) / 2)).to<int>());
//        }
//        else if (legendSelected == LEGEND_SERIE_3)
//        {
//            pieChartSerie3.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie3.getArcEnd() + (angleSplitPieChartAnimationSerie3) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie3.getArcEnd() + (angleSplitPieChartAnimationSerie3) / 2)).to<int>());
//        }
//        else if (legendSelected == LEGEND_SERIE_4)
//        {
//            pieChartSerie4.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie4.getArcEnd() + (angleSplitPieChartAnimationSerie4) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie4.getArcEnd() + (angleSplitPieChartAnimationSerie4) / 2)).to<int>());
//        }
//        else if (legendSelected == LEGEND_SERIE_5)
//        {
//            pieChartSerie5.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie5.getArcEnd() + (angleSplitPieChartAnimationSerie5) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie5.getArcEnd() + (angleSplitPieChartAnimationSerie5) / 2)).to<int>());
//        }
//        else if (legendSelected == LEGEND_SERIE_6)
//        {
//            pieChartSerie6.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie6.getArcEnd() + (angleSplitPieChartAnimationSerie6) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie6.getArcEnd() + (angleSplitPieChartAnimationSerie6) / 2)).to<int>());
//        }
//        else if (legendSelected == ALL_SELECT)
//        {
//            pieChartSerie1.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie1.getArcEnd() + (angleSplitPieChartAnimationSerie1) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie1.getArcEnd() + (angleSplitPieChartAnimationSerie1) / 2)).to<int>());
//            pieChartSerie2.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie2.getArcEnd() + (angleSplitPieChartAnimationSerie2) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie2.getArcEnd() + (angleSplitPieChartAnimationSerie2) / 2)).to<int>());
//            pieChartSerie3.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie3.getArcEnd() + (angleSplitPieChartAnimationSerie3) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie3.getArcEnd() + (angleSplitPieChartAnimationSerie3) / 2)).to<int>());
//            pieChartSerie4.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie4.getArcEnd() + (angleSplitPieChartAnimationSerie4) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie4.getArcEnd() + (angleSplitPieChartAnimationSerie4) / 2)).to<int>());
//            pieChartSerie5.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie5.getArcEnd() + (angleSplitPieChartAnimationSerie5) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie5.getArcEnd() + (angleSplitPieChartAnimationSerie5) / 2)).to<int>());
//            pieChartSerie6.setCenter(120 + (CWRUtil::toQ5(15) * CWRUtil::sine(pieChartSerie6.getArcEnd() + (angleSplitPieChartAnimationSerie6) / 2)).to<int>(),
//                                     120 - (CWRUtil::toQ5(15) * CWRUtil::cosine(pieChartSerie6.getArcEnd() + (angleSplitPieChartAnimationSerie6) / 2)).to<int>());
//        }
        if (angleSerie1Set == angleSplitPieChartAnimationSerie1 && angleSerie2Set == angleSplitPieChartAnimationSerie2 && angleSerie3Set == angleSplitPieChartAnimationSerie3 && angleSerie4Set == angleSplitPieChartAnimationSerie4 && angleSerie5Set == angleSplitPieChartAnimationSerie5 && angleSerie6Set == angleSplitPieChartAnimationSerie6)
        {
            Serie1.updateArc(minArc, minArc + angleSplitPieChartAnimationSerie1);
            Serie2.updateArc(minArc + angleSplitPieChartAnimationSerie1, minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2);
            Serie3.updateArc(minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2, minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3);
            Serie4.updateArc(minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3, minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4);
            Serie5.updateArc(minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4, minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4 + angleSplitPieChartAnimationSerie5);
            Serie6.updateArc(minArc + angleSplitPieChartAnimationSerie1 + angleSplitPieChartAnimationSerie2 + angleSplitPieChartAnimationSerie3 + angleSplitPieChartAnimationSerie4 + angleSplitPieChartAnimationSerie5, maxArc);
            pieChartAnimation = NO;
//            displayPieChartLegend();
        }
//        backgroundPieChart.invalidate();
    }
}

//void PieChartFullCircleView::updateProcessorLoad(uint8_t mcuLoadValue)
//{
//    mcuLoad.updateProcessorLoad(mcuLoadValue);
//}
