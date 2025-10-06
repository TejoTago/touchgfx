#ifndef SCROLLWHEELVIEW_HPP
#define SCROLLWHEELVIEW_HPP

#include <gui_generated/scrollwheel_screen/ScrollWheelViewBase.hpp>
#include <gui/scrollwheel_screen/ScrollWheelPresenter.hpp>

class  ScrollWheelView : public  ScrollWheelViewBase
{
public:
    ScrollWheelView();
    virtual ~ ScrollWheelView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void scrollWheel1UpdateItem(CustomContainer1& item, int16_t itemIndex);
    virtual void scrollWheel1UpdateCenterItem(CustomContainer2& item, int16_t itemIndex);
    virtual void scrollWheel2UpdateItem(CustomContainer1& item, int16_t itemIndex);
    virtual void scrollWheel2UpdateCenterItem(CustomContainer2& item, int16_t itemIndex);
    virtual void scrollWheel3UpdateItem(CustomContainer1& item, int16_t itemIndex);
    virtual void scrollWheel3UpdateCenterItem(CustomContainer2& item, int16_t itemIndex);

protected:
    void evaluateLockState();
    int selectedIndex1;
    int selectedIndex2;
	int selectedIndex3;
};

#endif // SCROLLWHEELVIEW_HPP
