#include <gui/shapeheightclick_screen/ShapeHeightClickView.hpp>

ShapeHeightClickView::ShapeHeightClickView()
{

}


void ShapeHeightClickView::setupScreen()
{
	ShapeHeightClickViewBase::setupScreen();

    // Define shape points
    shapePoints[0] = { 0.0f, 100.0f };
    shapePoints[1] = { 80.0f, 100.0f };
    shapePoints[2] = { 80.0f, 135.0f };
    shapePoints[3] = { 0.0f, 135.0f };

    // Apply shape to shape1
    shape1.setShape(shapePoints);

    shape2Points[0] = { 0.0f, 100.0f };
    shape2Points[1] = { 80.0f, 100.0f };
    shape2Points[2] = { 80.0f, 135.0f };
    shape2Points[3] = { 0.0f, 135.0f };

    shape2.setShape(shape2Points);


}

void ShapeHeightClickView::tearDownScreen()
{
	ShapeHeightClickViewBase::tearDownScreen();
}

void ShapeHeightClickView::handleDragEvent(const DragEvent& evt) {
//    if (!shapeTouched) return;
	if (!shapeTouched && !shape2Touched) return;
	 if (shapeTouched) {

//    int deltaY = initialTouchY - evt.getNewY();
    int deltaY = initialTouchY - (evt.getNewY() - waterPressure.getY());

    float newHeight = currentHeight + deltaY;

    if (newHeight < 10.0f) newHeight = 10.0f;
    if (newHeight > 200.0f) newHeight = 200.0f;

    shapePoints[0].y = shapePoints[3].y - newHeight;
    shapePoints[1].y = shapePoints[3].y - newHeight;
    shape1.setShape(shapePoints);
    shape1.invalidate();
	 }
    if (shape2Touched) {
        int deltaY2 = initialTouchY2 - (evt.getNewY() - temperature.getY());
        float newHeight2 = currentHeight2 + deltaY2;

        if (newHeight2 < 10.0f) newHeight2 = 10.0f;
        if (newHeight2 > 200.0f) newHeight2 = 200.0f;

        shape2Points[0].y = shape2Points[3].y - newHeight2;
        shape2Points[1].y = shape2Points[2].y - newHeight2;
        shape2.setShape(shape2Points);
        shape2.invalidate();
    }

}
void ShapeHeightClickView::handleClickEvent(const ClickEvent& evt) {
//    int touchX = evt.getX();
//    int touchY = evt.getY();
	int touchX = evt.getX() - waterPressure.getX();
	int touchY = evt.getY() - waterPressure.getY();

    // Check if touch is inside shape1's area
    if (touchX >= shape1.getX() && touchX <= shape1.getX() + shape1.getWidth() &&
        touchY >= shape1.getY() && touchY <= shape1.getY() + shape1.getHeight()) {

        initialTouchY = touchY;
        shapeTouched = true; // Allow drag to affect this shape
        shape2Touched = false;
    } else {
        shapeTouched = false;
    }

    // Optionally update currentHeight on release
    if (evt.getType() == ClickEvent::RELEASED && shapeTouched) {
        currentHeight = shapePoints[3].y - shapePoints[0].y;
    }
    int touchX2 = evt.getX() - temperature.getX();
    int touchY2 = evt.getY() - temperature.getY();

    if (touchX2 >= shape2.getX() && touchX2 <= shape2.getX() + shape2.getWidth() &&
        touchY2 >= shape2.getY() && touchY2 <= shape2.getY() + shape2.getHeight()) {

        initialTouchY2 = touchY2;
        shape2Touched = true;
        shapeTouched = false;
    } else {
        shape2Touched = false;
    }

    if (evt.getType() == ClickEvent::RELEASED && shape2Touched) {
        currentHeight2 = shape2Points[3].y - shape2Points[0].y;
    }

}


