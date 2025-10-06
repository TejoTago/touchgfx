#include <gui/containers/CustomContainer2.hpp>

CustomContainer2::CustomContainer2()
{

}

void CustomContainer2::initialize()
{
    CustomContainer2Base::initialize();
}

void CustomContainer2::setIndex(int16_t value)
{
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);
    textArea1.invalidate();
}
