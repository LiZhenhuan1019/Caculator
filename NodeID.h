#ifndef NODEID_H
#define NODEID_H
#include <functional>

class NodeID
{
public:
    NodeID(int id = -1)
        :id(id)
    {
    }
    int getID()
    {
        return id;
    }

private:
    int id;
};
inline bool operator==(NodeID lhs,NodeID rhs)
{
    return lhs.getID()==rhs.getID();
}

namespace std {
template <>
class hash<NodeID> {
 public:
  size_t operator()(NodeID id) const
  {
      return hash<int>()(id.getID());
  }
};
}

#endif // NODEID_H
