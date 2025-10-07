#include <gui/moveandfade_screen/MoveAndFadeView.hpp>

MoveAndFadeView::MoveAndFadeView()
:counter(0)
{

}

void MoveAndFadeView::setupScreen()
{
    MoveAndFadeViewBase::setupScreen();

}

void MoveAndFadeView::tearDownScreen()
{
    MoveAndFadeViewBase::tearDownScreen();
}

void MoveAndFadeView::volumeControlOn()
{
	circleVolume.clearMoveAnimationEndedAction();
	circleVolume.startMoveAnimation(38, 3, 6, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

	volumeOFF.setVisible(false);
	volumeOFF.invalidate();

	volumeON.setVisible(true);
	volumeON.invalidate();

}
void MoveAndFadeView::volumeControlOff()
{
	circleVolume.clearMoveAnimationEndedAction();
	circleVolume.startMoveAnimation(0, 3, 6, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

	volumeON.setVisible(false);
	volumeON.invalidate();

	volumeOFF.setVisible(true);
	volumeOFF.invalidate();
}

void MoveAndFadeView::handleTickEvent()
{
	circleScreen.invalidate();
	if(counter <120)
	{
		circleScreen.setX(counter*4);
		lineScreenBottom.setAlpha(counter);
		counter++;
	}
	else counter = 0;
	circleScreen.invalidate();// is it need here?
	lineScreenBottom.invalidate();

}

void MoveAndFadeView::handleDragEvent(const touchgfx::DragEvent& evt)
{
    // Get current position and delta
    int newX = circleLights.getX() + evt.getDeltaX();

    const int minX = 0;
    const int maxX = 38;
    newX = MAX(minX, MIN(newX, maxX));

    // Move the circle
    circleLights.moveTo(newX, circleLights.getY());
    circleLights.invalidate();

    // Map X position to alpha (0–255)
    int alpha = (newX * 255) / maxX;
    lights.setAlpha(alpha);
    lights.invalidate();
}
