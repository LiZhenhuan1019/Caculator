#ifndef GRAPHICSELEMENTS
#define GRAPHICSELEMENTS
#include "point2d.h"
#include "size2d.h"
#include "rect2d.h"

namespace GraphicsElementsSpace
{
    using type = double;
}

using Point = Point2D<GraphicsElementsSpace::type>;
using Size = Size2D<GraphicsElementsSpace::type>;
using Rect = Rect2D<GraphicsElementsSpace::type>;
using SizeFactor = int;
using DepthNum = int;


#endif // GRAPHICSELEMENTS

