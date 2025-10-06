#include <gui/movewidgetwithmixin_screen/MoveWidgetWithMixinView.hpp>

MoveWidgetWithMixinView::MoveWidgetWithMixinView()
//: whiteBallCallback(this, &MoveWidgetWithMixinView::onWhiteBallAnimationEnded)
: whiteBallCallback(this, &MoveWidgetWithMixinView::onWhiteBallAnimationEnded),
 magentaBallCallback(this, &MoveWidgetWithMixinView::onMagentaBallAnimationEnded)
{

}

void MoveWidgetWithMixinView::setupScreen()
{
    MoveWidgetWithMixinViewBase::setupScreen();
}

void MoveWidgetWithMixinView::tearDownScreen()
{
    MoveWidgetWithMixinViewBase::tearDownScreen();
}

void MoveWidgetWithMixinView::MoveBalls()
{
    whiteBall.clearMoveAnimationEndedAction();
    whiteBall.setMoveAnimationEndedAction(whiteBallCallback);
    whiteBall.startMoveAnimation(237, 96, 12, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

}

//void MoveWidgetWithMixinView::onWhiteBallAnimationEnded(const touchgfx::Drawable& d)
void MoveWidgetWithMixinView::onWhiteBallAnimationEnded(const touchgfx::MoveAnimator<touchgfx::Circle>& animator)

{
    purpleBall.clearMoveAnimationEndedAction();
    purpleBall.startMoveAnimation(406, -13, 12, touchgfx::EasingEquations::bounceEaseOut, touchgfx::EasingEquations::bounceEaseOut);

    orangeBall.clearMoveAnimationEndedAction();
    orangeBall.startMoveAnimation(417, 136, 12, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

    greenBall.clearMoveAnimationEndedAction();
    greenBall.startMoveAnimation(337, 206, 12, touchgfx::EasingEquations::bounceEaseIn, touchgfx::EasingEquations::bounceEaseIn);

    yellowBall.clearMoveAnimationEndedAction();
    yellowBall.startMoveAnimation(259, -13, 18, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

    lightBlueBall.clearMoveAnimationEndedAction();
    lightBlueBall.startMoveAnimation(0, 0, 18, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

    magentaBall.clearMoveAnimationEndedAction();
    magentaBall.setMoveAnimationEndedAction(magentaBallCallback);
    magentaBall.startMoveAnimation(417, 96, 12, touchgfx::EasingEquations::bounceEaseOut, touchgfx::EasingEquations::bounceEaseOut);

}
void MoveWidgetWithMixinView::onMagentaBallAnimationEnded(const touchgfx::MoveAnimator<touchgfx::Circle>& animator)

{
	magentaBall.clearMoveAnimationEndedAction();
	magentaBall.startMoveAnimation(277, 96, 18, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);
}

