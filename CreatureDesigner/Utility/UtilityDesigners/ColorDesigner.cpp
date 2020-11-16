#include "ColorDesigner.h"
#include "Operation/Operation.h"

ColorDesigner::ColorDesigner()
{
	AddOperation<EmotionToHsv>();
	AddOperation<HsvToRgbOperation>();
	AddOperation<ColorToFinishedDesign>();
}
