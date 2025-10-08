#include <gui/containers/mySlider.hpp>

#define MIN_X 25
#define MAX_X 127
#define Y_POS 20

mySlider::mySlider()
:clickedState(0),state(0)

{

}

void mySlider::initialize()
{
    mySliderBase::initialize();
    setTouchable(true);
}

void mySlider::handleClickEvent(const ClickEvent& evt)
{
  if(evt.getType() == ClickEvent::PRESSED)
  {
	  if (evt.getX()>=container1.getX() &&
		  evt.getX()<=container1.getX() + container1.getWidth()&&
		  evt.getY()>=container1.getY() &&
		  evt.getY()<=container1.getX() + container1.getHeight())
		  {
		  clickedState = 1;
		  }
  }
  if(evt.getType() == ClickEvent::RELEASED)
	  {
	  clickedState = 0;
	  if (evt.getX() - container1.getWidth()/2>= MAX_X) initiateConfirmation();
	  else actionFailed();
	  }

}

void mySlider::handleDragEvent(const DragEvent& evt)
{
	if (clickedState)
	{
		int xVal = evt.getNewX() - container1.getWidth()/2;
		xVal = xVal< MIN_X ? MIN_X :xVal>MAX_X?MAX_X:xVal;
		container1.invalidate();
		container1.setXY(xVal, Y_POS);
		container1.invalidate();

		textSlidehere.setAlpha(255-(xVal-MIN_X)*2<0 ? 0: 255-(xVal-MIN_X)*2);
		textSlidehere.invalidate();
		textConfirmed.setAlpha((xVal-MAX_X)*2 +255<0 ? 0: (xVal-MAX_X)*2 +255);
		textConfirmed.invalidate();
	}
}

void mySlider::initiateConfirmation()
{
	actionValidated();
	setTouchable(false);
	state = 1;
}

int mySlider::getState()
{

	return state;
}
