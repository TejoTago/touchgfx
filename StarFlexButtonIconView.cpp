#include <gui/starflexbuttonicon_screen/StarFlexButtonIconView.hpp>

StarFlexButtonIconView::StarFlexButtonIconView()
{

}

void StarFlexButtonIconView::setupScreen()
{
    StarFlexButtonIconViewBase::setupScreen();
    star1.setAction(touchgfx::Callback<StarFlexButtonIconView, const touchgfx::AbstractButtonContainer&>(this, &StarFlexButtonIconView::onStar1Clicked));
        star2.setAction(touchgfx::Callback<StarFlexButtonIconView, const touchgfx::AbstractButtonContainer&>(this, &StarFlexButtonIconView::onStar2Clicked));
        star3.setAction(touchgfx::Callback<StarFlexButtonIconView, const touchgfx::AbstractButtonContainer&>(this, &StarFlexButtonIconView::onStar3Clicked));
        star4.setAction(touchgfx::Callback<StarFlexButtonIconView, const touchgfx::AbstractButtonContainer&>(this, &StarFlexButtonIconView::onStar4Clicked));
        star5.setAction(touchgfx::Callback<StarFlexButtonIconView, const touchgfx::AbstractButtonContainer&>(this, &StarFlexButtonIconView::onStar5Clicked));

}

void StarFlexButtonIconView::tearDownScreen()
{
    StarFlexButtonIconViewBase::tearDownScreen();
}

void StarFlexButtonIconView::onStar1Clicked(const touchgfx::AbstractButtonContainer&) { updateRating(1); }
void StarFlexButtonIconView::onStar2Clicked(const touchgfx::AbstractButtonContainer&) { updateRating(2); }
void StarFlexButtonIconView::onStar3Clicked(const touchgfx::AbstractButtonContainer&) { updateRating(3); }
void StarFlexButtonIconView::onStar4Clicked(const touchgfx::AbstractButtonContainer&) { updateRating(4); }
void StarFlexButtonIconView::onStar5Clicked(const touchgfx::AbstractButtonContainer&) { updateRating(5); }

void StarFlexButtonIconView::updateRating(int clickedIndex)
{
    lastClickedStar = clickedIndex;

    star1.setPressed(clickedIndex >= 1);
    star2.setPressed(clickedIndex >= 2);
    star3.setPressed(clickedIndex >= 3);
    star4.setPressed(clickedIndex >= 4);
    star5.setPressed(clickedIndex >= 5);

    star1.invalidate();
    star2.invalidate();
    star3.invalidate();
    star4.invalidate();
    star5.invalidate();

    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", clickedIndex);
    textArea1.invalidate();
}

//void StarFlexButtonIconView::updateRating()
//{
//    // Detect which star was clicked by checking which one just toggled ON
//    if (star1.getPressed() && lastClickedStar != 1) {
//        lastClickedStar = 1;
//    } else if (star2.getPressed() && lastClickedStar != 2) {
//        lastClickedStar = 2;
//    } else if (star3.getPressed() && lastClickedStar != 3) {
//        lastClickedStar = 3;
//    } else if (star4.getPressed() && lastClickedStar != 4) {
//        lastClickedStar = 4;
//    } else if (star5.getPressed() && lastClickedStar != 5) {
//        lastClickedStar = 5;
//    }
//
//    // Apply pressed state to all stars up to lastClickedStar
//    star1.setPressed(lastClickedStar >= 1);
//    star2.setPressed(lastClickedStar >= 2);
//    star3.setPressed(lastClickedStar >= 3);
//    star4.setPressed(lastClickedStar >= 4);
//    star5.setPressed(lastClickedStar >= 5);
//
//    // Refresh visuals
//    star1.invalidate();
//    star2.invalidate();
//    star3.invalidate();
//    star4.invalidate();
//    star5.invalidate();
//
//    // Update text
//    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", lastClickedStar);
//    textArea1.invalidate();
//}
//void StarFlexButtonIconView::updateRating()
//{
//    int selectedStars = 1; // default to star1
//
//    // Determine which star was pressed
//    if (star1.getPressed()) selectedStars = 1;
//    else if (star2.getPressed()) selectedStars = 2;
//    else if (star3.getPressed()) selectedStars = 3;
//    else if (star4.getPressed()) selectedStars = 4;
//    else if (star5.getPressed()) selectedStars = 5;
//
//    // Update toggle state for each star
//    star1.setPressed(selectedStars >= 1);
//    star2.setPressed(selectedStars >= 2);
//    star3.setPressed(selectedStars >= 3);
//    star4.setPressed(selectedStars >= 4);
//    star5.setPressed(selectedStars >= 5);
//
//    // Refresh visuals
//    star1.invalidate();
//    star2.invalidate();
//    star3.invalidate();
//    star4.invalidate();
//    star5.invalidate();
//
//    // Update text area
//    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", selectedStars);
//    textArea1.invalidate();
//}
