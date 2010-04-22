
#ifndef RAII_FACTORY_IMP_H
#define RAII_FACTORY_IMP_H

/**
 * This example code is a supplement to the article 
 * 'RAII, Dynamic Objects, and Factories in C++'
 * at CodeProject: http://www.codeproject.com/
 */

#include <vector>
#include <algorithm> // find
#include <assert.h>


/**
 * RaiiFactoryImp
 * reusable implementation class template for RAII factories
 */
template <typename T>
class RaiiFactoryImp {
public:
   RaiiFactoryImp() { expand(); }
   
   /** delete created objects */
   ~RaiiFactoryImp() { 
      disposeAll();
   }
  
   /** take over object *p */
   T* keep (T* p) {
      assert (p);
      container.push_back(p); 
      expand();
      return p;
   }

   /** delete object *p; *p must have been created by the factory that uses this RaiiFactoryImp  */ 
   void dispose (const T* p) {
      assert (p);
      typedef std::vector<const void*>::reverse_iterator  reverse_iterator;
      reverse_iterator rpos = std::find (container.rbegin(), container.rend(), p);
      if (rpos != container.rend()) {
         container.erase ((++rpos).base()); // see: Scott Meyers - http://www.aristeia.com/Papers/CUJ_June_2001.pdf - Guideline 3:
         doDelete (p);
      } else { 
         assert (0 && "unknown pointer: object not created by this factory");
      }
   }

   /** current number of owned objects */
   size_t size() const { return container.size(); }
   
   T* operator[] (size_t n) { 
      assert (n < size());
      return const_cast<T*> (static_cast<const T*> (container[n])); 
   }
   
   const T* operator[] (size_t n) const { 
      assert (n < size());
      return static_cast<const T*> (container[n]); 
   }
  
private:
   void expand() {
      if (container.capacity() < container.size() + 1) {
         if (container.size() == 0) {
            container.reserve (16);   
         } else if (container.size() < 8192) {
            container.reserve (container.capacity() * 2);
         } else {
            container.reserve (container.capacity() / 2 * 3);
         }
      }
   }

   void disposeAll() {
      while (!container.empty()) {
         const void* p = container.back();
         container.pop_back();
         doDelete (p);
      }
   }

   void doDelete (const void* p) const {
      try {
         delete static_cast<const T*> (p);
      } catch (...) {
         assert (0);
      }
   }

   std::vector<const void*> container;

   // non-copyable
   RaiiFactoryImp (const RaiiFactoryImp&);
   RaiiFactoryImp& operator= (const RaiiFactoryImp&);
};
#endif // RAII_FACTORY_IMP_H
