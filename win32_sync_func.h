#ifndef WIN32_SYNC_FUNC_H_INCLUDED
#define WIN32_SYNC_FUNC_H_INCLUDED

#include <iostream>
#include "../learn-cplusplus/c_single_file.h"
#include <windows.h>

//#include <stl/_alloc.h>


namespace junkun
{
using namespace std;
using namespace junkun;

class mutex
{
public:
    mutex()
    : _handle(::CreateMutex(NULL, TRUE, NULL)), _wait_time(INFINITE)
    {}

    mutex(const string_t& name)
    : _handle(::CreateMutex(NULL, TRUE, name.c_str())), _name(name), _wait_time(INFINITE)
    {}

    ~mutex() { SAFE_CLOSE_HANDLE(_handle); }
    bool lock()
    {
        if (_handle)
        {
            _wait_ret = ::WaitForSingleObject(
                               _handle,    // handle to mutex
                               _wait_time);  // no time-out interval

            if (WAIT_OBJECT_0 == _wait_ret)
                return true;
        }
        return false;
    }
    bool unlock()
    {
        return ::ReleaseMutex(_handle);
    }
    HANDLE handle() { return _handle; }
    string_t name() const { return _name; }
    int get_wait_ret() const { return _wait_ret; }
    unsigned get_wait_time() const { return _wait_time; }
    void set_wait_time(unsigned wait_time) { _wait_time = wait_time; }
    int error() const { return ::GetLastError(); }

private:
    HANDLE      _handle;
    string_t    _name;
    unsigned    _wait_time;
    int         _wait_ret;
};

class event
{
public:

private:

};
class critical_section
{
public:

private:

};

class semaphore
{
public:

private:

};


class wrap_critical_section
{
	public:
		wrap_critical_section()
		{
			::InitializeCriticalSection(&_critical_section);
		}
		virtual ~wrap_critical_section()
		{
			::DeleteCriticalSection(&_critical_section);
		}
		void lock()
		{
			::EnterCriticalSection( &_critical_section);
		}
		void unlock()
		{
			::LeaveCriticalSection(&_critical_section);
		}
	private:
		CRITICAL_SECTION _critical_section;
};

template <class _Locker>
class scoped_lock_t
{
	public:
		scoped_lock_t( _Locker& mutex_obj )
		: _locker(mutex_obj)
		{
			_locker.lock();
		}
		~scoped_lock_t()
		{
			_locker.unlock();
		}
	private:
		_Locker& _locker;
};


}/// namespace junkun

#endif // WIN32_SYNC_FUNC_H_INCLUDED
