#include <gui/screenlogo_screen/ScreenLogoView.hpp>
#include <touchgfx/Color.hpp>
ScreenLogoView::ScreenLogoView()
{

}

void ScreenLogoView::setupScreen()
{
    ScreenLogoViewBase::setupScreen();
    shapeB1.setPosition(490, 0, 80, 80);
    shapeB1.setOrigin(0.0f, 0.0f);
    shapeB1.setScale(1.0f, 1.0f);
    shapeB1.setAngle(0.0f);
    shapeB1Painter.setColor(touchgfx::Color::getColorFromRGB(11, 50, 222));
    shapeB1.setPainter(shapeB1Painter);
    const touchgfx::AbstractShape::ShapePoint<float> shapeB1Points[8] = { { 0.0f, 0.0f },{ 40.0f, 0.0f }, { 60.0f, 20.0f }, { 40.0f, 40.0f }, { 60.0f, 60.0f }, { 40.0f, 80.0f }, { 0.0f, 100.0f }, { 0.0f, 0.0f } };
    shapeB1.setShape(shapeB1Points);
    add(shapeB1);

    shapeB1.clearMoveAnimationEndedAction();
    shapeB1.startMoveAnimation(300, 127, 60, touchgfx::EasingEquations::cubicEaseIn, touchgfx::EasingEquations::cubicEaseIn);

}

void ScreenLogoView::tearDownScreen()
{
    ScreenLogoViewBase::tearDownScreen();
}
