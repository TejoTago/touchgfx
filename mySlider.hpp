#ifndef MYSLIDER_HPP
#define MYSLIDER_HPP

#include <gui_generated/containers/mySliderBase.hpp>

class mySlider : public mySliderBase
{
public:
    mySlider();
    virtual ~mySlider() {}

    virtual void initialize();

    virtual void handleClickEvent(const ClickEvent& evt);
    virtual void handleDragEvent(const DragEvent& evt);

    void initiateConfirmation();
    int getState();

protected:
    int clickedState;
    int state;
};

#endif // MYSLIDER_HPP
