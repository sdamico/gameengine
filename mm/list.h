#ifndef LIST_H
#define LIST_H

#include "../res.h"

template<typename C> class ListElement {
 public:
  C *self;
  ListElement<C> *prev;
  ListElement<C> *next;
  ListElement() {
    prev = NULL;
    next = NULL;
    self = NULL;
  }
  ~ListElement() {
    if (self)
      delete self;
  }
};

template<typename C> class List {
  ListElement<C> *first;
  ListElement<C> *last;
  ListElement<C> *current;

 public:
  List() {
    first = NULL;
    last = NULL;
    current = NULL;
    std::cout << "[List Created]" << std::endl;
  }
  ~List() {
    std::cout << "[List Terminated]" << std::endl;
    deleteAllElements();
  }
  void deleteAllElements() {
    int i = 0;
    while (first) {
      deleteElement(first);
      i++;
    }
    std::cout << "[" << i << " List Elements Deleted]" << std::endl;
  }
  C *find(std::string ID) {
    resetList();
    if (current->self->getID() == ID)
      return current->self;

    while (nextElement()) {
      if (current->self->getID() == ID)
        return current->self;
    }
    return NULL;
  }
  C *currentElement() {
    if (current != NULL)
      return current->self;
    else
      return NULL;
  }
  ListElement<C> *getCurrent() {
    return current;
  }
  void setCurrent(ListElement<C> *c) {
    current = c;
  }
  bool nextElement() {
    if (current != NULL)
      if (current->next != NULL) {
        current = current->next;
        return true;
      }
    return false;
  }

  bool prevElement() {
    if (current != NULL)
      if (current->prev != NULL) {
        current = current->prev;
        return true;
      }
    return false;
  }

  void resetList() {
    current = first;
  }

  void resetListToLast() {
    current = last;
  }

  bool deleteElement(ListElement<C> *w) {

    if (w == NULL)
      return false;
    if (w == current) {
      if (w->next != NULL)
        current = w->next;
      else if (w->prev != NULL)
        current = w->prev;
      else
        current = NULL;
    }
    if (w->prev == NULL && w->next == NULL) {
      delete w;
      first = NULL;
      last = NULL;
      return true;
    }
    if (w->prev == NULL && w->next != NULL) {
      w->next->prev = NULL;
      first = w->next;
      delete w;
      return true;
    }
    if (w->next == NULL && w->prev != NULL) {
      w->prev->next = NULL;
      last = w->prev;
      delete w;
      return true;
    }
    if (w->next != NULL && w->prev != NULL) {
      w->prev->next = w->next;
      w->next->prev = w->prev;
      delete w;
      return true;
    }
    return false;

  }
  bool deleteElement(std::string id) {
    if (find(id)) {
      //if(current->self)delete current->self;

      deleteElement(current);
      return true;
    } else {
      return false;
    }
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
