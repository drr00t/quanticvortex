
#ifndef G_FACTORY_H
#define G_FACTORY_H

/*
 * This class template is a supplement to the article
 * 'RAII, Dynamic Objects, and Factories in C++'
 * at CodeProject: http://www.codeproject.com/
 */

#include "qvRAIIFactoryImp.h"

/**
 * Generic RAII-Factory for 0 to 8 arguments;
 * 9 - 16 arguments are supported if all arguments are const
 *
 * GFactory<T> creates and and owns objects of a user specified type
 *
 * <code>
 *
 * Example:
 *    GFactory<MyClass> myClassFactory;
 *    MyClass* m = myClassFactory.create (123);
 *
 * </code>
 */
template <typename T>
class GFactory {
public:
T* create() { return imp.keep (new T); }


// ---- begin generated code ----------------------------------------

template <typename A1>
T* create (A1& a1) { return imp.keep (new T (a1)); }

template <typename A1>
T* create (const A1& a1) { return imp.keep (new T (a1)); }

/*
//template <typename A1, typename A2>
//T* create (A1& a1, A2& a2) { return imp.keep (new T (a1, a2)); }
//
//template <typename A1, typename A2>
//T* create (const A1& a1, A2& a2) { return imp.keep (new T (a1, a2)); }
//
//template <typename A1, typename A2>
//T* create (A1& a1, const A2& a2) { return imp.keep (new T (a1, a2)); }
//
//template <typename A1, typename A2>
//T* create (const A1& a1, const A2& a2) { return imp.keep (new T (a1, a2)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (A1& a1, A2& a2, A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (const A1& a1, A2& a2, A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (A1& a1, const A2& a2, A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (const A1& a1, const A2& a2, A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (A1& a1, A2& a2, const A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (const A1& a1, A2& a2, const A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (A1& a1, const A2& a2, const A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3>
//T* create (const A1& a1, const A2& a2, const A3& a3) { return imp.keep (new T (a1, a2, a3)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4) { return imp.keep (new T (a1, a2, a3, a4)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5) { return imp.keep (new T (a1, a2, a3, a4, a5)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6) { return imp.keep (new T (a1, a2, a3, a4, a5, a6)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8)); }
//
//// ---- end generated code ------------------------------------------
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10, typename A11>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10, const A11& a11 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10, typename A11, typename A12>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10, const A11& a11, const A12& a12 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10, typename A11, typename A12, typename A13>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)); }
//
//template <typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8,
//          typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16>
//T* create (const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8,
//           const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15, const A16& a16 )
//           { return imp.keep (new T (a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16)); }
*/

private:
   RaiiFactoryImp<T> imp;
};

#endif // G_FACTORY_H
