#include <gui/scrollwheel_screen/ScrollWheelView.hpp>

ScrollWheelView::ScrollWheelView()
: selectedIndex1(0), selectedIndex2(0), selectedIndex3(0)
{

}

void ScrollWheelView::setupScreen()
{
    ScrollWheelViewBase::setupScreen();
}

void ScrollWheelView::tearDownScreen()
{
    ScrollWheelViewBase::tearDownScreen();
}

void ScrollWheelView::scrollWheel1UpdateItem(CustomContainer1& item, int16_t itemIndex)
{
    item.setIndex(itemIndex);
}

void ScrollWheelView::scrollWheel2UpdateItem(CustomContainer1& item, int16_t itemIndex)
{
    item.setIndex(itemIndex);
}
void ScrollWheelView::scrollWheel3UpdateItem(CustomContainer1& item, int16_t itemIndex)
{
    item.setIndex(itemIndex);
}

void ScrollWheelView::scrollWheel1UpdateCenterItem(CustomContainer2& item, int16_t itemIndex)
{
    item.setIndex(itemIndex);
    selectedIndex1 = itemIndex;
    evaluateLockState();
}

void ScrollWheelView::scrollWheel2UpdateCenterItem(CustomContainer2& item, int16_t itemIndex)
{
    item.setIndex(itemIndex);
    selectedIndex2 = itemIndex;
    evaluateLockState();
}

void ScrollWheelView::scrollWheel3UpdateCenterItem(CustomContainer2& item, int16_t itemIndex)
{
    item.setIndex(itemIndex);
    selectedIndex3 = itemIndex;
    evaluateLockState();
}

void ScrollWheelView::evaluateLockState()
{
    if (selectedIndex1 == 1 && selectedIndex2 == 1 && selectedIndex3 == 8)
    {
        lock.setVisible(false);
        unlock.setVisible(true);
    }
    else
    {
        lock.setVisible(true);
        unlock.setVisible(false);
    }

    lock.invalidate();
    unlock.invalidate();
}
