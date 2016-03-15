#ifndef DEFAULTNODEGEOMETRYDECLARATION
#define DEFAULTNODEGEOMETRYDECLARATION
#include "NodeBaseDeclaration.h"
#include "GraphicsSeparatorDeclarations.h"
template <typename NodeBaseType,typename GraphicsType,typename NodeHelperType>
class NodeGeometry;

class NodeHelperInfo;
using DefaultNodeGeometry = NodeGeometry<DefaultNodeBase,DefaultGraphicsSeparator,NodeHelperInfo>;
#endif // DEFAULTNODEGEOMETRYDECLARATION

