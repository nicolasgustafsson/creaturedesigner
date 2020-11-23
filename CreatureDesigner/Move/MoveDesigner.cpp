#include "MoveDesigner.h"
#include "Move/MoveOperation.h"

MoveDesigner::MoveDesigner()
{

	AddOperation<MoveAttributesToFinishedDesign>();
}
