#include "ColorDesigner.h"
#include "Operation/Operation.h"

ColorDesigner::ColorDesigner()
{
	AddOperation<HsvToRgbOperation>();
}
