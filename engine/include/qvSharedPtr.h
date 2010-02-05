#ifndef _SHARED_PTR_H_
#define _SHARED_PTR_H_

//! Save wrapper around the the reference counted pointers with an interface like irr::IReferenceCounted
//! NOTE: IrrPtr is made to mostly look like boost::shared_ptr. Differences are mostly because it has not the exact same job.
template <typename T>
class SharedPtr
{
public:

    //! Default constructor for empty SharedPtr
    SharedPtr()
    : mRefCounted(0)
    {
    }

    //! constructor
    /** \param ptr A reference counted pointer
        \param grab When true the reference count for the pointer is increased.
                    When false it is expected that the ptr has already an increased reference counter, for example because
                    it was returned by one of the Irrlicht create functions */
    explicit SharedPtr(T * ptr, bool grab=true)
    : mRefCounted(ptr)
    {
        if ( mRefCounted && grab )
            mRefCounted->grab();
    }

    //! copy constructor
    SharedPtr(const SharedPtr& other)
    : mRefCounted(0)
    {
        *this = other;
    }

    //! destructor
    ~SharedPtr()
    {
        if ( mRefCounted )
            mRefCounted->drop();
    }

    //! assign operator
    SharedPtr& operator=(const SharedPtr& other)
    {
        if ( this == &other )   // currently not needed due to set implementation, I just feel bad removing it.
            return *this;

        set(other.mRefCounted);

        return *this;
    }

    //! Dereference can use the managed pointer directly
    T & operator*() const
    {
        return *mRefCounted;
    }

    //! Memberaccess can use the managed pointer directly
    T * operator->() const
    {
        return mRefCounted;
    }

    //! Allows using bool operations for SharedPtr
    /** Like: SharedPtr<SomeType> instance; if ( instance ) { // do }; if ( !instance) { // do not } */
    typedef T * (SharedPtr::*unspecified_bool_type)() const;
    operator unspecified_bool_type () const
    {
        return mRefCounted ? &SharedPtr<T>::get : 0;
    }

    bool operator==(const SharedPtr<T>& other) const
    {
        return mRefCounted == other.mRefCounted;
    }

    bool operator!=(const SharedPtr<T>& other) const
    {
        return mRefCounted != other.mRefCounted;
    }

    bool operator<(const SharedPtr<T>& other) const
    {
        return mRefCounted < other.mRefCounted;
    }

    //! Access pointer directly
    T * get() const
    {
        return mRefCounted;
    }

    //! set a new pointer.
    /** The old pointer will be released unless it's identical with the new one.
        If old and new pointer are identical then nothing is done.
        \param ptr A reference counted pointer
        \param grab When true the reference count for the pointer is increased.
                    When false it is expected that the ptr has already an increased reference counter, for example because
                    it was returned by one of the Irrlicht create functions */
    void set(T * ptr, bool grab=true)
    {
        if ( mRefCounted != ptr )
        {
            if ( mRefCounted )
                mRefCounted->drop();
            mRefCounted = ptr;
            if ( mRefCounted )
                mRefCounted->grab();
        }
    }

    //! After a reset the class contains no longer a pointer.
    void reset()
    {
        if ( mRefCounted )
        {
            mRefCounted->drop();
            mRefCounted = 0;
        }
    }

    //! Swap the content with that of another SharedPtr
    void swap(SharedPtr<T> & other)
    {
        T * dummy = mRefCounted;
        mRefCounted = other.mRefCounted;
        other.mRefCounted = dummy;
    }

private:
    T * mRefCounted;
};

#endif // _SHARED_PTR_H_ 