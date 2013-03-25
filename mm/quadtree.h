#ifndef QUADTREE_H
#define QUADTREE_H

#include "../res.h"

template<typename C> class QuadTreeElement {
 public:
  C *self;
  QuadTreeElement<C> *upperLeft;
  QuadTreeElement<C> *upperRight;
  QuadTreeElement<C> *lowerLeft;
  QuadTreeElement<C> *lowerRight;

  ListElement()
  {
    upperLeft=NULL;
    lowerLeft=NULL;
    lowerRight=NULL;
    upperRight=NULL;
    self=NULL;
  }
  ~ListElement() {
    if (self)
      delete self;
  }
};

template<typename C> class QuadTree {
  QuadTreeElement<C> *first;
  QuadTreeElement<C> *current;

 public:
  List()
  {
    first=NULL;
    current=NULL;
    std::cout<<"[Quadtree Created]"<<endl;
  }
  ~List() {
    std::cout << "[Quadtree Terminated]" << endl;
    deleteAllElements();
  }
  void deleteAllElements() {
    while (first) {
      deleteElement(first);
    }
  }
  C *find(string ID) {

  }
  C *currentElement() {
    if (current != NULL)
      return current->self;
    else
      return NULL;
  }
  QuadTreeElement<C> *getCurrent() {
    return current;
  }
  bool nextElement( enum {
    upperleft,
    upperright,
    lowerleft,
    lowerright
  } direction) {
    if (direction == upperleft) {
      if (current->upperLeft != NULL) {
        current = current->upperLeft;
        return true;
      } else
        return false;
    }
    if (direction == upperright) {
      if (current->upperRight != NULL) {
        current = current->upperRight;
        return true;
      } else
        return false;

    }
    if (direction == lowerleft) {
      if (current->lowerLeft != NULL) {
        current = current->lowerLeft;
        return true;
      } else
        return false;

    }
    if (direction == lowerright) {
      if (current->lowerRight != NULL) {
        current = current->lowerRight;
        return true;
      } else
        return false;

    }

    return false;
  }

  void resetList() {
    current = first;
  }

  void addElement(C *add) {
    ListElement<C> *e = new ListElement<C>;
    e->self = add;
    e->prev = NULL;
    if (last) {
      last->next = e;
      e->prev = last;
    } else {
      e->prev = NULL;
      first = e;
    }
    e->next = NULL;
    last = e;
    current = last;
  }
};

#endif
