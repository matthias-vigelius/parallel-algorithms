#include <vector>

/*
 * Implements a linked list as an array.
 */
template<class T>
LinkedList {
public:

private:
  std::vector<T> mItems; /// contains all items
  std::vector<size_t> mPredecessor; /// gives the index of a predecessor to an item. if outside range, it means that this is the head. 
  std::vector<size_t> mSuccessor; /// gives the index of the succor of an item. If outside range, it means that this is the tail.
};
