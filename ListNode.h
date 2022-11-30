#ifndef FINALPROJECT1_LISTNODE_H
#define FINALPROJECT1_LISTNODE_H

template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode {
   friend class List<NODETYPE>;

public:
   explicit ListNode(const NODETYPE& info)
   : data(info), nextPtr{nullptr}{}

   NODETYPE getData() const {return data;}

private:
   NODETYPE data;
   ListNode<NODETYPE>* nextPtr;

};
#endif //FINALPROJECT1_LISTNODE_H

