// Copyright (c) 2013 Eric Robert.
// All rights reserved.

#ifndef STACK__INCLUDED
#define STACK__INCLUDED

#include <algorithm>

template<typename T>
  struct StackBase
  {
    StackBase(int n = 0) :
      items(n ? static_cast<T *>(operator new(n * sizeof(T))) : 0),
      count(0),
      total(n) {
    }

    ~StackBase() {
      for(T * i = items, * end = i + count; i != end; ++i) {
        i->~T();
      }

      operator delete(items);
    }

    T * items;
    unsigned count;
    unsigned total;
  };

template<typename T>
  struct Stack : private StackBase<T>
  {
    Stack() {
    }

    Stack(Stack const & other) : StackBase(other.count) {
      while(count < other.count) {
        new(items + count) T(other.items[count]);
        ++count;
      }
    }

    Stack & operator=(Stack const & other) {
      if(this != &other) {
        StackBase copy(other);
        swap(copy);
      }
      return *this;
    }

    unsigned size() const {
      return count;
    }

    void push(T const & item) {
      if(count == total) {
        StackBase copy(total == 0 ? 2 : total * 2);
        for(unsigned i = 0; i != count; ++i) {
          new(copy.items + i) T(items[i]);
          ++copy.count;
        }

        swap(copy);
      }

      new(items + count) T(item);
      ++count;
    }

    void pop() {
      if(!count) {
        throw std::exception("stack is empty");
      }

      --count;
      items[count].~T();
    }

    T const & top() const {
      if(!count) {
        throw std::exception("stack is empty");
      }

      return items[count];
    }

    T & top() {
      if(!count) {
        throw std::exception("stack is empty");
      }

      return items[count];
    }

    void swap(StackBase & other) {
      std::swap(items, other.items);
      std::swap(count, other.count);
      std::swap(total, other.total);
    }
  };

#endif
