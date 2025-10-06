#include <gui/containers/CustomContainer1.hpp>

CustomContainer1::CustomContainer1()
{

}

void CustomContainer1::initialize()
{
    CustomContainer1Base::initialize();
}

void CustomContainer1::setIndex(int16_t value)
{
	 Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", value);
	 textArea1.invalidate();
}
