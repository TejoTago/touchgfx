#ifndef MOVEWIDGETWITHMIXINVIEW_HPP
#define MOVEWIDGETWITHMIXINVIEW_HPP

#include <gui_generated/movewidgetwithmixin_screen/MoveWidgetWithMixinViewBase.hpp>
#include <gui/movewidgetwithmixin_screen/MoveWidgetWithMixinPresenter.hpp>

class MoveWidgetWithMixinView : public MoveWidgetWithMixinViewBase
{
public:
    MoveWidgetWithMixinView();
    virtual ~MoveWidgetWithMixinView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    //void onWhiteBallAnimationEnded(const touchgfx::Drawable& d);
    void onWhiteBallAnimationEnded(const touchgfx::MoveAnimator<touchgfx::Circle>& animator);
    void onMagentaBallAnimationEnded(const touchgfx::MoveAnimator<touchgfx::Circle>& animator);

protected:
    virtual void MoveBalls();
    //touchgfx::Callback<MoveWidgetWithMixinView, const touchgfx::Drawable&> whiteBallCallback;
    touchgfx::Callback<MoveWidgetWithMixinView, const touchgfx::MoveAnimator<touchgfx::Circle>&> whiteBallCallback;
    touchgfx::Callback<MoveWidgetWithMixinView, const touchgfx::MoveAnimator<touchgfx::Circle>&> magentaBallCallback;
};

#endif // MOVEWIDGETWITHMIXINVIEW_HPP
