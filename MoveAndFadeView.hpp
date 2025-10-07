#ifndef MOVEANDFADEVIEW_HPP
#define MOVEANDFADEVIEW_HPP

#include <gui_generated/moveandfade_screen/MoveAndFadeViewBase.hpp>
#include <gui/moveandfade_screen/MoveAndFadePresenter.hpp>

class MoveAndFadeView : public MoveAndFadeViewBase
{
public:
    MoveAndFadeView();
    virtual ~MoveAndFadeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void volumeControlOn();
    virtual void volumeControlOff();
    virtual void handleTickEvent();
    virtual void handleDragEvent(const touchgfx::DragEvent& evt) override;

protected:
    uint16_t counter;
};

#endif // MOVEANDFADEVIEW_HPP
