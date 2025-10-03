#include <gui/starflexbuttonicon_screen/StarFlexButtonIconView.hpp>
#include <touchgfx/Callback.hpp>

StarFlexButtonIconView::StarFlexButtonIconView()
:lastClickedStar(0)
{

}

void StarFlexButtonIconView::setupScreen()
{
    StarFlexButtonIconViewBase::setupScreen();
}

void StarFlexButtonIconView::tearDownScreen()
{
    StarFlexButtonIconViewBase::tearDownScreen();
}


void StarFlexButtonIconView::updateRating()
{
    int selectedStars = 0;
    if (star5.getPressed()) selectedStars = 5;
    else if (star4.getPressed()) selectedStars = 4;
    else if (star3.getPressed()) selectedStars = 3;
    else if (star2.getPressed()) selectedStars = 2;
    else if (star1.getPressed()) selectedStars = 1;

    // Only reset to zero IF:
    // - User clicks the star that is already the ONLY one set (lastClickedStar = selectedStars)
    // - And ALL the stars beyond that are OFF
    // We'll check if all other stars are off
    bool isExclusivelySet = false;
    if (selectedStars == lastClickedStar && selectedStars != 0) {
        // Check: are only the first N stars set and all others off?
        isExclusivelySet = true;
        if (star1.getPressed() != (selectedStars >= 1)) isExclusivelySet = false;
        if (star2.getPressed() != (selectedStars >= 2)) isExclusivelySet = false;
        if (star3.getPressed() != (selectedStars >= 3)) isExclusivelySet = false;
        if (star4.getPressed() != (selectedStars >= 4)) isExclusivelySet = false;
        if (star5.getPressed() != (selectedStars >= 5)) isExclusivelySet = false;
    }

    if (isExclusivelySet) {
        selectedStars = 0;
    }

    lastClickedStar = selectedStars;

    star1.setPressed(selectedStars >= 1);
    star2.setPressed(selectedStars >= 2);
    star3.setPressed(selectedStars >= 3);
    star4.setPressed(selectedStars >= 4);
    star5.setPressed(selectedStars >= 5);

    star1.invalidate();
    star2.invalidate();
    star3.invalidate();
    star4.invalidate();
    star5.invalidate();

    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", selectedStars);
    textArea1.invalidate();
}

