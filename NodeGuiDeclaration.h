#ifndef DEFAULTNODEGEOMETRYDECLARATION
#define DEFAULTNODEGEOMETRYDECLARATION
#include "NodeBaseDeclaration.h"
#include "GraphicsSeparatorDeclarations.h"
template <typename NodeBaseType,typename GraphicsType,typename NodeHelperType>
class NodeGuiItem;

class NodeHelperInfo;
using DefaultNodeGeometry = NodeGuiItem<DefaultNodeBase,GraphicsSeparatorT,NodeHelperInfo>;
#endif // DEFAULTNODEGEOMETRYDECLARATION

