#include <gui/phase5_screen/Phase5View.hpp>
#include <touchgfx/Math3D.hpp>

Phase5View::Phase5View():
    pieChartClickedCallback(this, &Phase5View::pieChartClickHandler),
    serie1Selected(false),
    serie2Selected(false),
    serie3Selected(false),
    serie4Selected(false),
    serie5Selected(false),
    serie6Selected(false),
    allSlicesExpanded(false),
    serie1Value(0),
    serie2Value(0),
    serie3Value(0),
    serie4Value(0),
    serie5Value(0),
    serie6Value(0),
    originalCenterX(120),
    originalCenterY(120),
    // NEW: Initialize animation variables
    currentAnimation(NO_ANIMATION),
    radiusAnimation(0),
    angleStartAnimation(90),
    angle1Animation(0),
    angle2Animation(0),
    angle3Animation(0),
    angle4Animation(0),
    angle5Animation(0),
    angle6Animation(0),
    angle1Target(0),
    angle2Target(0),
    angle3Target(0),
    angle4Target(0),
    angle5Target(0),
    angle6Target(0)
{

}

void Phase5View::setupScreen()
{
    Phase5ViewBase::setupScreen();

    pieChartContainer.setClickAction(pieChartClickedCallback);

    serie1.setCenter(originalCenterX, originalCenterY);
    serie2.setCenter(originalCenterX, originalCenterY);
    serie3.setCenter(originalCenterX, originalCenterY);
    serie4.setCenter(originalCenterX, originalCenterY);
    serie5.setCenter(originalCenterX, originalCenterY);
    serie6.setCenter(originalCenterX, originalCenterY);

    serie1Percentage.setVisible(false);
    serie2Percentage.setVisible(false);
    serie3Percentage.setVisible(false);
    serie4Percentage.setVisible(false);
    serie5Percentage.setVisible(false);
    serie6Percentage.setVisible(false);

    // NEW: Set initial values
    serie1Value = 15;
    serie2Value = 20;
    serie3Value = 25;
    serie4Value = 10;
    serie5Value = 18;
    serie6Value = 12;

    // Calculate target angles
    angle1Target = (serie1Value * 360) / 100;
    angle2Target = (serie2Value * 360) / 100;
    angle3Target = (serie3Value * 360) / 100;
    angle4Target = (serie4Value * 360) / 100;
    angle5Target = (serie5Value * 360) / 100;
    angle6Target = (serie6Value * 360) / 100;

    // Update text buffers
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d%%", serie1Value);
    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d%%", serie2Value);
    Unicode::snprintf(serie3PercentageBuffer, SERIE3PERCENTAGE_SIZE, "%d%%", serie3Value);
    Unicode::snprintf(serie4PercentageBuffer, SERIE4PERCENTAGE_SIZE, "%d%%", serie4Value);
    Unicode::snprintf(serie5PercentageBuffer, SERIE5PERCENTAGE_SIZE, "%d%%", serie5Value);
    Unicode::snprintf(serie6PercentageBuffer, SERIE6PERCENTAGE_SIZE, "%d%%", serie6Value);

    // NEW: Start with radius 0 and trigger animation
    serie1.setRadius(0);
    serie2.setRadius(0);
    serie3.setRadius(0);
    serie4.setRadius(0);
    serie5.setRadius(0);
    serie6.setRadius(0);

    currentAnimation = DRAW_PIECHART;
}


void Phase5View::tearDownScreen()
{
    Phase5ViewBase::tearDownScreen();
}

void Phase5View::handleTickEvent()
{
    // Call this every frame to run animations
    if (currentAnimation == DRAW_PIECHART)
    {
        drawPieChartAnimation();
        drawPieChartAnimation();  // Call twice for faster animation
    }
}


void Phase5View::updateQuarterData()
{
    // Determine which radio button is selected
    if (radioButtonQ1.getSelected())
    {
        // Q1: 6 values totaling 100%
        updatePieChart(15, 20, 25, 10, 18, 12);
    }
    else if (radioButtonQ2.getSelected())
    {
        // Q2: Different distribution
        updatePieChart(18, 15, 22, 12, 20, 13);
    }
    else if (radioButtonQ3.getSelected())
    {
        // Q3: Another distribution
        updatePieChart(12, 25, 18, 15, 16, 14);
    }
    else if (radioButtonQ4.getSelected())
    {
        // Q4: Final distribution
        updatePieChart(20, 18, 15, 20, 12, 15);
    }
    //When changing quarters, show all slices expanded with percentages
    if (!allSlicesExpanded)
    {
        toggleAllSlices();  // Expand all to show new data
    }
}

//void Phase5View::updatePieChart(int newSerie1Value, int newSerie2Value)
//{
//    // Store new percentage values
//    serie1Value = newSerie1Value;
//    serie2Value = newSerie2Value;
//
//    // Convert percentages to degrees (360° total)
//    int serie1Angle = (serie1Value * 360) / 100;  // e.g., 30% = 108°
////    int serie2Angle = 360 - serie1Angle;          // Remaining degrees
//
//    // Update Serie1 arc (starting at 0°)
//    serie1.setArc(0, serie1Angle);
//
//    // Update Serie2 arc (starting where Serie1 ends)
//    serie2.setArc(serie1Angle, 360);
//
//    // Reset selections and move slices back to center
//    if (serie1Selected)
//    {
//        serie1Selected = false;
//        serie1Percentage.setVisible(false);
//        moveSlice(serie1, 0, serie1Angle, false);
//    }
//
//    if (serie2Selected)
//    {
//        serie2Selected = false;
//        serie2Percentage.setVisible(false);
//        moveSlice(serie2, serie1Angle, 360, false);
//    }
//
//    // Update text buffers with new values
//    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d", serie1Value);
//    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d", serie2Value);
//
//    // Redraw everything
//    pieChartContainer.invalidate();
//}
void Phase5View::updatePieChart(int s1, int s2, int s3, int s4, int s5, int s6)
{
    // Store new percentage values
    serie1Value = s1;
    serie2Value = s2;
    serie3Value = s3;
    serie4Value = s4;
    serie5Value = s5;
    serie6Value = s6;

    // Convert percentages to cumulative angles
    int angle1 = (serie1Value * 360) / 100;
    int angle2 = angle1 + (serie2Value * 360) / 100;
    int angle3 = angle2 + (serie3Value * 360) / 100;
    int angle4 = angle3 + (serie4Value * 360) / 100;
    int angle5 = angle4 + (serie5Value * 360) / 100;
    // angle6 ends at 360

    // Update all arcs
    serie1.setArc(0, angle1);
    serie2.setArc(angle1, angle2);
    serie3.setArc(angle2, angle3);
    serie4.setArc(angle3, angle4);
    serie5.setArc(angle4, angle5);
    serie6.setArc(angle5, 360);

    // Reset all selections and move slices back to center
    if (serie1Selected)
    {
        serie1Selected = false;
        serie1Percentage.setVisible(false);
        moveSlice(serie1, 0, angle1, false);
    }

    if (serie2Selected)
    {
        serie2Selected = false;
        serie2Percentage.setVisible(false);
        moveSlice(serie2, angle1, angle2, false);
    }

    if (serie3Selected)
    {
        serie3Selected = false;
        serie3Percentage.setVisible(false);
        moveSlice(serie3, angle2, angle3, false);
    }

    if (serie4Selected)
    {
        serie4Selected = false;
        serie4Percentage.setVisible(false);
        moveSlice(serie4, angle3, angle4, false);
    }

    if (serie5Selected)
    {
        serie5Selected = false;
        serie5Percentage.setVisible(false);
        moveSlice(serie5, angle4, angle5, false);
    }

    if (serie6Selected)
    {
        serie6Selected = false;
        serie6Percentage.setVisible(false);
        moveSlice(serie6, angle5, 360, false);
    }

    // Update text buffers with new values
    Unicode::snprintf(serie1PercentageBuffer, SERIE1PERCENTAGE_SIZE, "%d%%", serie1Value);
    Unicode::snprintf(serie2PercentageBuffer, SERIE2PERCENTAGE_SIZE, "%d%%", serie2Value);
    Unicode::snprintf(serie3PercentageBuffer, SERIE3PERCENTAGE_SIZE, "%d%%", serie3Value);
    Unicode::snprintf(serie4PercentageBuffer, SERIE4PERCENTAGE_SIZE, "%d%%", serie4Value);
    Unicode::snprintf(serie5PercentageBuffer, SERIE5PERCENTAGE_SIZE, "%d%%", serie5Value);
    Unicode::snprintf(serie6PercentageBuffer, SERIE6PERCENTAGE_SIZE, "%d%%", serie6Value);

    // Redraw everything
    pieChartContainer.invalidate();
}

//void Phase5View::pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt)
//{
//    if (evt.getType() != ClickEvent::RELEASED)
//    {
//        return;
//    }
//
//    int16_t clickX = evt.getX();
//    int16_t clickY = evt.getY();
//
//    int clickedSlice = getClickedSlice(clickX, clickY);
//
//    if (clickedSlice == 1)
//    {
//        serie1Selected = !serie1Selected;
//        serie1Percentage.setVisible(serie1Selected);
//        serie1Percentage.invalidate();
//
//        // Calculate current arc range for Serie1
//        int serie1Angle = (serie1Value * 360) / 100;
//        moveSlice(serie1, 0, serie1Angle, serie1Selected);
//    }
//    else if (clickedSlice == 2)
//    {
//        serie2Selected = !serie2Selected;
//        serie2Percentage.setVisible(serie2Selected);
//        serie2Percentage.invalidate();
//
//        // Calculate current arc range for Serie2
//        int serie1Angle = (serie1Value * 360) / 100;
//        moveSlice(serie2, serie1Angle, 360, serie2Selected);
//    }
//}
void Phase5View::pieChartClickHandler(const touchgfx::Container& src, const touchgfx::ClickEvent& evt)
{
    if (evt.getType() != ClickEvent::RELEASED)
    {
        return;
    }

    int16_t clickX = evt.getX();
    int16_t clickY = evt.getY();
    // NEW: Check if click is near the center
    const int16_t centerX = 120;
    const int16_t centerY = 120;
    const int16_t innerRadius = 25;  // 25-pixel radius for center circle

    int16_t deltaX = clickX - centerX;
    int16_t deltaY = clickY - centerY;
    int distanceSquared = (deltaX * deltaX) + (deltaY * deltaY);
    int innerRadiusSquared = innerRadius * innerRadius;

    // If clicked in center, toggle ALL slices
    if (distanceSquared <= innerRadiusSquared)
    {
        toggleAllSlices();
        return;  // Don't process individual slice selection
    }

    int clickedSlice = getClickedSlice(clickX, clickY);

    // Calculate cumulative angles for all series
    int angle1 = (serie1Value * 360) / 100;
    int angle2 = angle1 + (serie2Value * 360) / 100;
    int angle3 = angle2 + (serie3Value * 360) / 100;
    int angle4 = angle3 + (serie4Value * 360) / 100;
    int angle5 = angle4 + (serie5Value * 360) / 100;

    if (clickedSlice == 1)
    {
        serie1Selected = !serie1Selected;
        serie1Percentage.setVisible(serie1Selected);
        serie1Percentage.invalidate();
        moveSlice(serie1, 0, angle1, serie1Selected);
    }
    else if (clickedSlice == 2)
    {
        serie2Selected = !serie2Selected;
        serie2Percentage.setVisible(serie2Selected);
        serie2Percentage.invalidate();
        moveSlice(serie2, angle1, angle2, serie2Selected);
    }
    else if (clickedSlice == 3)
    {
        serie3Selected = !serie3Selected;
        serie3Percentage.setVisible(serie3Selected);
        serie3Percentage.invalidate();
        moveSlice(serie3, angle2, angle3, serie3Selected);
    }
    else if (clickedSlice == 4)
    {
        serie4Selected = !serie4Selected;
        serie4Percentage.setVisible(serie4Selected);
        serie4Percentage.invalidate();
        moveSlice(serie4, angle3, angle4, serie4Selected);
    }
    else if (clickedSlice == 5)
    {
        serie5Selected = !serie5Selected;
        serie5Percentage.setVisible(serie5Selected);
        serie5Percentage.invalidate();
        moveSlice(serie5, angle4, angle5, serie5Selected);
    }
    else if (clickedSlice == 6)
    {
        serie6Selected = !serie6Selected;
        serie6Percentage.setVisible(serie6Selected);
        serie6Percentage.invalidate();
        moveSlice(serie6, angle5, 360, serie6Selected);
    }
}

//int Phase5View::getClickedSlice(int16_t clickX, int16_t clickY)
//{
//    const int16_t centerX = 120;
//    const int16_t centerY = 120;
//    const int16_t radius = 60;
//
//    int16_t deltaX = clickX - centerX;
//    int16_t deltaY = clickY - centerY;
//    int distanceSquared = (deltaX * deltaX) + (deltaY * deltaY);
//    int radiusSquared = radius * radius;
//
//    if (distanceSquared > radiusSquared)
//    {
//        return 0;
//    }
//
//    int angleInDegrees = CWRUtil::angle(deltaX, deltaY);
//
//    // Dynamically calculate the boundary based on current values
//    int serie1Angle = (serie1Value * 360) / 100;
//
//    if (angleInDegrees >= 0 && angleInDegrees <= serie1Angle)
//    {
//        return 1;  // Serie1 was clicked
//    }
//    else if (angleInDegrees > serie1Angle && angleInDegrees <= 360)
//    {
//        return 2;  // Serie2 was clicked
//    }
//
//    return 0;
//}
int Phase5View::getClickedSlice(int16_t clickX, int16_t clickY)
{
    const int16_t centerX = 120;
    const int16_t centerY = 120;
    const int16_t radius = 60;

    int16_t deltaX = clickX - centerX;
    int16_t deltaY = clickY - centerY;
    int distanceSquared = (deltaX * deltaX) + (deltaY * deltaY);
    int radiusSquared = radius * radius;

    if (distanceSquared > radiusSquared)
    {
        return 0;
    }

    int angleInDegrees = CWRUtil::angle(deltaX, deltaY);

    // Calculate cumulative angle boundaries
    int angle1 = (serie1Value * 360) / 100;
    int angle2 = angle1 + (serie2Value * 360) / 100;
    int angle3 = angle2 + (serie3Value * 360) / 100;
    int angle4 = angle3 + (serie4Value * 360) / 100;
    int angle5 = angle4 + (serie5Value * 360) / 100;

    // Determine which slice was clicked
    if (angleInDegrees >= 0 && angleInDegrees <= angle1)
    {
        return 1;
    }
    else if (angleInDegrees > angle1 && angleInDegrees <= angle2)
    {
        return 2;
    }
    else if (angleInDegrees > angle2 && angleInDegrees <= angle3)
    {
        return 3;
    }
    else if (angleInDegrees > angle3 && angleInDegrees <= angle4)
    {
        return 4;
    }
    else if (angleInDegrees > angle4 && angleInDegrees <= angle5)
    {
        return 5;
    }
    else if (angleInDegrees > angle5 && angleInDegrees <= 360)
    {
        return 6;
    }

    return 0;
}

void Phase5View::moveSlice(touchgfx::Circle& slice, int arcStart, int arcEnd, bool moveOut)
{
    if (moveOut)
    {
        int arcAngle = arcEnd - arcStart;
        int middleAngle = arcStart + (arcAngle / 2);

        int offsetX = (CWRUtil::toQ5(15) * CWRUtil::sine(middleAngle)).to<int>();
        int offsetY = -(CWRUtil::toQ5(15) * CWRUtil::cosine(middleAngle)).to<int>();

        slice.setCenter(originalCenterX + offsetX, originalCenterY + offsetY);
    }
    else
    {
        slice.setCenter(originalCenterX, originalCenterY);
    }

    pieChartContainer.invalidate();
}

void Phase5View::toggleAllSlices()
{
    // Calculate all angles
    int angle1 = (serie1Value * 360) / 100;
    int angle2 = angle1 + (serie2Value * 360) / 100;
    int angle3 = angle2 + (serie3Value * 360) / 100;
    int angle4 = angle3 + (serie4Value * 360) / 100;
    int angle5 = angle4 + (serie5Value * 360) / 100;

    // Toggle the state
    allSlicesExpanded = !allSlicesExpanded;

    // Apply to all slices
    serie1Selected = allSlicesExpanded;
    serie2Selected = allSlicesExpanded;
    serie3Selected = allSlicesExpanded;
    serie4Selected = allSlicesExpanded;
    serie5Selected = allSlicesExpanded;
    serie6Selected = allSlicesExpanded;

    // Show/hide all percentages
    serie1Percentage.setVisible(allSlicesExpanded);
    serie2Percentage.setVisible(allSlicesExpanded);
    serie3Percentage.setVisible(allSlicesExpanded);
    serie4Percentage.setVisible(allSlicesExpanded);
    serie5Percentage.setVisible(allSlicesExpanded);
    serie6Percentage.setVisible(allSlicesExpanded);

    // Move all slices
    moveSlice(serie1, 0, angle1, allSlicesExpanded);
    moveSlice(serie2, angle1, angle2, allSlicesExpanded);
    moveSlice(serie3, angle2, angle3, allSlicesExpanded);
    moveSlice(serie4, angle3, angle4, allSlicesExpanded);
    moveSlice(serie5, angle4, angle5, allSlicesExpanded);
    moveSlice(serie6, angle5, 360, allSlicesExpanded);

    // Invalidate text areas
    serie1Percentage.invalidate();
    serie2Percentage.invalidate();
    serie3Percentage.invalidate();
    serie4Percentage.invalidate();
    serie5Percentage.invalidate();
    serie6Percentage.invalidate();
}

void Phase5View::drawPieChartAnimation()
{
    bool animationComplete = true;

    // Phase 1: Grow radius from 0 to 60
    if (radiusAnimation < 60)
    {
        radiusAnimation += 2;  // Grow by 2 pixels per frame

        serie1.setRadius(radiusAnimation);
        serie2.setRadius(radiusAnimation);
        serie3.setRadius(radiusAnimation);
        serie4.setRadius(radiusAnimation);
        serie5.setRadius(radiusAnimation);
        serie6.setRadius(radiusAnimation);

        animationComplete = false;
    }

    // Phase 2: Rotate starting angle from 90° to 360°
    if (radiusAnimation >= 60 && angleStartAnimation < 360)
    {
        angleStartAnimation += 10;  // Rotate by 10° per frame
        animationComplete = false;
    }

    // Phase 3: Draw each slice progressively
    if (angleStartAnimation >= 360)
    {
        // Increment each angle toward its target (in steps of 4)
        for (int i = 0; i < 4; i++)
        {
            if (angle1Animation < angle1Target)
            {
                angle1Animation++;
                animationComplete = false;
            }
            if (angle2Animation < angle2Target)
            {
                angle2Animation++;
                animationComplete = false;
            }
            if (angle3Animation < angle3Target)
            {
                angle3Animation++;
                animationComplete = false;
            }
            if (angle4Animation < angle4Target)
            {
                angle4Animation++;
                animationComplete = false;
            }
            if (angle5Animation < angle5Target)
            {
                angle5Animation++;
                animationComplete = false;
            }
            if (angle6Animation < angle6Target)
            {
                angle6Animation++;
                animationComplete = false;
            }
        }

        // Calculate cumulative angles
        int cumulativeAngle1 = angle1Animation;
        int cumulativeAngle2 = cumulativeAngle1 + angle2Animation;
        int cumulativeAngle3 = cumulativeAngle2 + angle3Animation;
        int cumulativeAngle4 = cumulativeAngle3 + angle4Animation;
        int cumulativeAngle5 = cumulativeAngle4 + angle5Animation;
        int cumulativeAngle6 = cumulativeAngle5 + angle6Animation;

        // Update arcs with animated angles
        serie1.setArc(angleStartAnimation, angleStartAnimation + cumulativeAngle1);
        serie2.setArc(angleStartAnimation, angleStartAnimation + cumulativeAngle2);
        serie3.setArc(angleStartAnimation, angleStartAnimation + cumulativeAngle3);
        serie4.setArc(angleStartAnimation, angleStartAnimation + cumulativeAngle4);
        serie5.setArc(angleStartAnimation, angleStartAnimation + cumulativeAngle5);
        serie6.setArc(angleStartAnimation, angleStartAnimation + cumulativeAngle6);
    }

    // When animation is complete
    if (animationComplete)
    {
        // Set final arcs at standard 0-360 range
        int angle1 = (serie1Value * 360) / 100;
        int angle2 = angle1 + (serie2Value * 360) / 100;
        int angle3 = angle2 + (serie3Value * 360) / 100;
        int angle4 = angle3 + (serie4Value * 360) / 100;
        int angle5 = angle4 + (serie5Value * 360) / 100;

        serie1.setArc(0, angle1);
        serie2.setArc(angle1, angle2);
        serie3.setArc(angle2, angle3);
        serie4.setArc(angle3, angle4);
        serie5.setArc(angle4, angle5);
        serie6.setArc(angle5, 360);

        // Stop animation
        currentAnimation = NO_ANIMATION;
    }

    // Redraw
    pieChartContainer.invalidate();
}

