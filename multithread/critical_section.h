#include <windows.h>

/** 
 * 临界区 CriticalSection
 * 
 */

class MyCriticalSection
{
public:
    MyCriticalSection()
    {
        InitializeCriticalSection(&cs_);
    }

    void lock()
    {
        EnterCriticalSection(&cs_);
    }

    void unlock()
    {
        LeaveCriticalSection(&cs_);
    }

    virtual ~MyCriticalSection()
    {
        DeleteCriticalSection(&cs_);
    }

private:
    CRITICAL_SECTION cs_;
};

class MyCriticalSectionAutoLock
{
public:
    MyCriticalSectionAutoLock(MyCriticalSection *my_section) : p_my_section_(my_section)
    {
        p_my_section_->lock();
    }

    virtual ~MyCriticalSectionAutoLock()
    {
        p_my_section_->unlock();
    }
private:
    MyCriticalSection * p_my_section_;
};
