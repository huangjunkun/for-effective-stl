#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#pragma once
#include "stdafx.h"
#include "../project-tool/win_thread_class.h"
#include "../project-tool/win_sync_func.h"

using namespace std;
using namespace test_namespace;


static junkun::mutex s_mxPrintContainer;//�ٽ���
static junkun::critical_section s_csPrintContainer;//��Ҫ���� -----

//---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -------------------
#define LOCKNAME    "LockName"
template <typename Container >
class LockContainer
{
    // �쳣 ���������ֲ����󣬼�~LockContainer() ---��׳�� ---
private:
    HANDLE  hMutex;
    const Container&   c;
public:
    LockContainer(const Container& container)  : c(container)
    {
        for(;;)
        {
            hMutex = CreateMutex(NULL, true, LOCKNAME);
            if(hMutex == NULL)//    GetLastError()==ERROR_ALREADY_EXISTS
                ;//cout << " (GetLastError()==ERROR_ALREADY_EXISTS) \n";
            else //(GetLastError()==0)  //NULL
            {
                cout << " (GetLastError()!=ERROR_ALREADY_EXISTS) \n";
                break;
            }
            Sleep(100);  /**/
        }
        cout << " Create LockContainer OK  \n";
    }
    ~LockContainer()
    {
        ReleaseMutex(hMutex);
    }
};
//---------------------------------------------------------------------------
template <class T>
void    print(const T& i)
{
    cout << i << ' ';
}
//---------------------------------------------------------------------------

template <typename Container >
void    PrintContainer(const Container& c)
{
    // ---   Lock Container--
    junkun::scoped_lock lock(s_mxPrintContainer);
    cout << ::GetCurrentThreadId() << " : print  container ---------- \n";
    for_each(c.begin(), c.end(), ptr_fun(print<Container::value_type>) );
    cout << endl;
    Sleep(3000);
}

//---------------------------------------------------------------------------
template <typename Container >
void PrintContainer(const Container& c, const int& ThreadNum)
{
    // ---   Lock Container--
    junkun::scoped_lock lock(s_csPrintContainer);
    //try
    {
        cout << "Thread "<<ThreadNum << " : print  container ---------- \n";
        for_each(c.begin(), c.end(), ptr_fun(print<typename Container::value_type>) );
        cout << endl;
        Sleep(2000);
    }
    //__finally
    {
        //ThreadRunOver->SetEvent();
    }
    //// ---   UnLock Container--
}
class TThread : public thread_base
{
public:
    TThread(bool bCreateSuspended)
        : thread_base(NULL, bCreateSuspended)
    {}

protected:
    virtual unsigned thread_proc(void* args) {}
};


template <typename Container >
class TTestThread : public TThread
{
private:
    const Container&   c;
    int  ThreadNum;
protected:
    virtual unsigned thread_proc(void* args)
    {
        PrintContainer(c, ThreadNum);
    }
public:

    __fastcall TTestThread(bool CreateSuspended, const Container& container, int Num)
        : TThread(CreateSuspended), c(container), ThreadNum(Num)    //
    {
        //this->FreeOnTerminate = true; //�߳̽���ʱ�Զ�ɾ��
    }
    //template< typename Container>
    //friend void PrintContainer(const Container& c);
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---����7���������������ͨ��new ��������ָ�룬�м���������������ǰ��ָ��delete�� -----

typedef struct DeletePtr
{
    template <typename T>
    T*& operator () ( T*& ptr) const
    {
        delete ptr;
        ptr = NULL;
        return  ptr;
    }
} DeletePtr;
//---����8�����𴴽�����auto_ptr���������� --------------
//template <typename T >
bool PtrToRefComp(const auto_ptr<int>& lhs, const auto_ptr<int>& rhs)
{
    return  *lhs < *rhs;
}

template <class T>
struct APtrToRefPtint //typedef
{
    // template <typename T >  // No  ----
    void operator () (const auto_ptr<T>& ptr) const
    {
        cout << *ptr << ' ';
    }
};   // PtrToRefPtint

//---------------------------------------------------------------------------
//---����10���˽������(allocator)��Լ�������� --------- 1 ~~~ 5 tips
template <typename T>  // --- 1
class SpecialAllocator
{
public:  // --- 2
    typedef T*  pointer_type;
    typedef T&  reference_type;
    typedef unsigned int    size_t;

private:
    pointer_type    pointee_;
public:  // --- 3
    pointer_type allocate(size_t numObjects)
    {
        //try
        {
            pointee_ =  new T[numObjects];
        }
        //__finally
        {
            // --- 4
            return pointee_;
        }
    }
    void deallocate(pointer_type p)
    {
        delete[] p;
    }
    // --- 5
    template <typename U>
    struct rebind
    {
        typedef SpecialAllocator<U> other;
    };
};
//---����11������Զ�������ӵĺ����÷� ----------------
void*   mallocShared(size_t byteNeeded);
void*   freeShared(void*ptr);

template <typename T>
class ShareMemoryAlloc
{
public:  // --- 2
    typedef T*  pointer_type;
    typedef T&  reference_type;
    typedef unsigned int    size_t;

public:
// ...
    pointer_type allocate(size_t numOblects, const void *localityHint = 0)
    {
        return static_cast<pointer_type>(mallocShared(numOblects*sizeof(T)));
    }
    void deallocate(pointer_type  ptrToMemory, size_t numObjects)
    {
        freeShared(ptrToMemory);
    }
};
//---------------------------------------------------------------------------
//---����9������ѡ��ɾ��Ԫ�صķ��� -----------------------
template <int I>
struct badValue : public unary_function<bool, int>
{
    bool operator () (int value)
    {
        if(value<I)
            return true;
        else
            return  false;
        // Or return    value<2000
    }
};

//---------------------------------------------------------------------------

class   C
{
public:
    C():_data(3) { }
    // there is not trivial operator
    /*       ostream&    operator << (ostream& os )   // friend
           {
                os << _data;
                return  os;
           }     */
    friend ostream&    operator << (ostream& os, const C& c );
private:
    int _data;
};
//---------------------------------------------------------------------------

ostream&    operator << (ostream& os, const C& c )   //
{
    os << c._data;
    return  os;
}
template <class T>
struct display
{
    void operator()(const T& x)
    {
        cout << x << ' ';
    }
}; /*
template <class T>
void    Display(const T& x)  //   const ostream& os,
{ //[C++ Error] UnitMain.cpp(32): E2094 'operator<<' not implemented in type 'ostream' for arguments of type 'T'
    std::cout << x << ' ';
}
void    Display(const string& x)
{
    cout << x << ' ';
}   */
//---------------------------------------------------------------------------
namespace   MySpace
{
class Shape
{
public:
    virtual void display() = 0;
};
class Rect : public Shape
{
public:
    virtual void display()
    {
        cout << " Rect ----" << endl;
    }
};
class Circle : public Shape
{
public:
    virtual void display()
    {
        cout << " Circle ----" << endl;
    }
};
class Square : public Shape
{
public:
    virtual void display()
    {
        cout << " Square ----" << endl;
    }
};

}
//---------------------------------------------------------------------------
class   Int
{
public:
    explicit    Int(int i)  : m_i(i) {}
    void    Print() const
    {
        cout << '[' << m_i <<']';
    }
    void    PrintArg(const int& i) const
    {
        cout << '[' << m_i+1 <<']';
    }
private:
    int m_i;
};
//---------------------------------------------------------------------------
int MyRand(int  r)
{
    time_t  t;
    srand(time(&t));
    return rand() % r;

}
//---------------------------------------------------------------------------
//-----Test hash_set ---
struct  eqstr
{
    bool operator () (const char*s1, const char* s2) const
    {
        return  strcmp(s1, s2)==0;
    }
};
using namespace __gnu_cxx;
typedef const char* c_char_ptr;
typedef hash_set<c_char_ptr, hash<c_char_ptr>, eqstr> str_hash_t;

str_hash_t::const_iterator
lookup(const str_hash_t& Set,
       const char* word)
{
    str_hash_t::const_iterator it = Set.find(word);
    cout << " " << word << " : "
         << (it!=Set.end() ? "" : "not ") << "present\n";
    return it;
}

//---------------------------------------------------------------------------
class   Widget
{
public:
    bool    isCertified() const
    {
        return  Certified;
    }
    Widget()
    {
        Certified = rand()%2;
    }
private:
    bool    Certified;
};
void DelAndNULLifyUncertified(Widget*& pWidget)
{
    if(!pWidget->isCertified())
    {
        delete pWidget;
        pWidget = 0;
    }
}
//---------------------------------------------------------------------------
//---����20��Ϊ����ָ��Ĺ���������������������ָ���Ƚ����� ��-----
typedef struct  DereferenceLess
{
    template<typename PtrType>
    bool operator () (PtrType pT1, PtrType pT2) const
    {
        return  *pT1 < *pT2;
    }
} DereferenceLess;
//---����22��ֱ�������޸�set���� multiset �еļ�ֵ -----
class Employee
{
public:
    const string& getname() const
    {
        return _name;
    }
    void setname(const string& name )
    {
        _name = name;
    }
    const string& gettitle() const
    {
        return _title;
    }
    void settitle(const string& title )
    {
        _title = title;
    }
    int getID() const
    {
        return _ID;
    }
    void setID(const int& ID)
    {
        _ID = ID;
    }
    Employee(const string& name, const string& title, const int& ID )
    {
        _name = name;
        _title = title;
        _ID = ID;
    }
    Employee&   operator = (const Employee& e)
    {
        _name = e.getname();
        _title = e.gettitle();
        _ID = e.getID();
        return  *this;
    }
private:
    string  _name;
    string  _title;
    int     _ID;
};
typedef struct IDLess :
    public binary_function<Employee, Employee, bool>
{
    bool operator () (const Employee& lhs, const Employee& rhs) const
    {
        return lhs.getID() < rhs.getID();
    }
} ID;
typedef set<Employee, IDLess>   EmpIDSet;
//---����24����Ч��������Ҫʱ������map::operator[] �� map::insert ֮���������ѡ��-------
template<typename MapType, typename KeyArgType,
typename ValueArgType >
typename MapType::iterator
EfficientAddOrUpdate(MapType& m, const KeyArgType& k,
                     const ValueArgType );
template<typename MapType, typename KeyArgType,
typename ValueArgType >
typename MapType::iterator
EfficientAddOrUpdate(MapType& m, const KeyArgType& k,
                     const ValueArgType v)
{
    typename MapType::iterator  lb = m.lower_bound(k);
    if(lb!=m.end() &&
            !(m.key_comp()(k, lb->first)))
    {
        lb->second = v;
        return  lb;
    }
    else
    {
        typedef typename MapType::value_type    MVT;
        return  m.insert(lb, MVT(k, v));
    }
}

//---------------------------------------------------------------------------

//---����30��ȷ��Ŀ�������㹻�� ----------------------
int transmogrify(const int& x)
{
    return  x+1;
}
//---����31���˽�����������йص�ѡ�� ----------------
//class  -> [C++ Error] _algo.c(606): E2247 'PredIntTo50<int>::operator ()(const int &)' is not accessible
template <typename T>
struct PredIntTo50 : public unary_function<T, bool>
{
    bool operator () (const T& x) const
    {
        return x > T(50);
    }

};
//---����37��ʹ��accumulate ���� for_each ��������ͳ�� ---
string::size_type
stringLengthSum(string::size_type sumSoFar, const string& s)
{
    return sumSoFar+s.size();
}
struct dPoint
{
    dPoint(double x, double y) : x(x), y(y)
    {
    }
    double x, y;
    friend ostream& operator << (ostream& os, const dPoint& P);
};
// ------ accumulate(...) --------
class PointAverage : public binary_function<dPoint, dPoint, dPoint>
{
private:
    size_t  numPoints;
    double  xSum, ySum;
public:
    PointAverage(): xSum(0), ySum(0), numPoints(0) {}
    const dPoint operator () (const dPoint& avgSoFar, const dPoint& P)
    {
        ++numPoints;
        xSum += P.x;
        ySum += P.y;
        return   dPoint(xSum/numPoints, ySum/numPoints);
    }
};
// ------ for_each(...) --------
class PointAverage_ : public unary_function<dPoint, void>
{
private:
    size_t  numPoints;
    double  xSum, ySum;
public:
    PointAverage_(): xSum(0), ySum(0), numPoints(0) {}
    void  operator () (const dPoint& P)
    {
        ++numPoints;
        xSum += P.x;
        ySum += P.y;
    }
    dPoint result() const
    {
        return   dPoint(xSum/numPoints, ySum/numPoints);
    }
};

ostream& operator << (ostream& os, const dPoint& P)
{
    os << "(" << P.x << ", " << P.y << ") ";
    return  os;
}
//---����35��ͨ�� mismatch �� lexicographical_compare ʵ�ּ򵥵ĺ��Դ�Сд
// --- call mismatch ---- return -1 or 0 or 1 ---------------
int ciCharCopare(char c1, char c2)
{
    int lc1 = tolower(c1); //toupper(c1)
    int lc2 = tolower(c2); //toupper(c2)
    if(lc1 < lc2 )  return -1;
    if(lc1 > lc2 )  return 1;
    return 0;// lc1 == lc2
}
int ciStringCompareImpl(const string& s1, const string& s2);
int ciStringCompare(const string& s1, const string& s2)
{
    // --- ��֤�Ϸ�����STL�㷨�� mismatch��...�� -----
    if(s1.size()<=s2.size())
        return  ciStringCompareImpl(s1, s2);
    else
        return  -ciStringCompareImpl(s2, s1);
}
int ciStringCompareImpl(const string& s1, const string& s2)
{
    typedef pair<string::const_iterator, string::const_iterator> PSCIT;
    PSCIT p = mismatch(s1.begin(), s1.end(), s2.begin(), not2(ptr_fun(ciCharCopare)) );
    // not2(ptr_fun(ciCharCopare)),  == return true, != return false -------
    if(p.first==s1.end())
    {
        if(p.second==s2.end())
            return 0;
        else
            return -1;
    }
    return  ciCharCopare(*p.first, *p.second);
}
// --- call lexicographical_compare ---- return true or false ---------------
bool ciCharLess(char c1, char c2)
{
    return tolower(static_cast<unsigned char>(c1)) <
           tolower(static_cast<unsigned char>(c2));
}
bool ciStringCompare_(const string& s1, const string& s2)
{
    return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                   ciCharLess );
}

//---����36�����copy_if �㷨����ȷʵ�� ��STLû�а���copy_if��ʵ��--------------
template <typename InputIterator,
typename OutputIterator,
typename Predicate >
// ------ OK call STL �㷨remove_copy_if(...)----------
OutputIterator copy_if_(InputIterator first, InputIterator last,
                        OutputIterator destFirst, Predicate Pre)
{
    return  remove_copy_if(first, last, destFirst, not1(Pre) );
}
template <typename InputIterator,
typename OutputIterator,
typename Predicate >
OutputIterator copy_if(InputIterator first, InputIterator last,
                       OutputIterator destFirst, Predicate Pre)
{
    while(first!=last)
    {
        if(Pre(*first))
            *destFirst++ = *first;
        ++first;
    }
    return  destFirst;
}
//---------------------------------------------------------------------------

//---����38����ѭ��ֵ���ݵ�ԭ����ƺ������� ----
// --- ���·�������������������Ժܴ���/���߱�����̬�ԣ�
// ---- �п�����STL �����õĴ�ֵ���ݺ����ӵ�ϰ�߱���һ��
// ---- ���������Ƽ�á� ---��������BPFC�Ŀ������캯�� ----
class Widget2
{
    // ----  ���������� --------
};
/*  */
template <typename T>
class GoodFunctor; // ģ���� BPFC ���� ---
// BPFC = "Big Polymorphic Functor Class "

template <typename T>
class BPFCImpl : public unary_function<T, void>
{
private:
    Widget2 w;
    int    x;
    // ....
    //virtual ~BPFCImpl() = 0;
    //virtual void operator() (const T& val) const = 0;
public:
    virtual void operator() (const T& val) const = 0;
    /*
    {
        cout << "BPFCImpl ---- void operator() (const T& val) \n";
        cout << " ------ " << val << "------- \n";
    }  */
    virtual ~BPFCImpl() {};
    friend class GoodFunctor<T>;
};
template <typename T>
class BPFC1 : public BPFCImpl<T>
{
public:
    // ....
    ~BPFC1()
    {
        // ....
    }
    void operator() (const T& val) const
    {
        // ....
        cout << "BPFC1 ---- void operator() (const T& val) \n";
        cout << " ------ " << val << "------- \n";
    }
};
template <typename T>
class BPFC2 : public BPFCImpl<T>
{
public:
    // ....
    ~BPFC2()
    {
        // ....
    }
    void operator() (const T& val) const
    {
        // ....
        cout << "BPFC2 ---- void operator() (const T& val) \n";
        cout << " ------ " << val << "------- \n";
    }
};
template <typename T>
class GoodFunctor : public unary_function<T, void>
{
private:
    BPFCImpl<T>*    pImpl;
public:
    GoodFunctor(BPFCImpl<T>* p) : pImpl(p) {}  //

    void operator() (const T& val) const
    {
        pImpl->operator()(val);
    }
};
//---����39��ȷ���б�ʽ�ǡ��������� ---
// ---  BadPredicate
template <typename T>
class BadPredicate : public unary_function<T, bool>
{
public:
    BadPredicate():timesCalled(0) {}
    bool operator()(const T& )
    {
        return  ++timesCalled==3;
    }

private:
    size_t timesCalled;  // int  timesCalled;
};
//---------------------------------------------------------------------------
//---����43���㷨������������д�㷨  ---
class Widget3
{
public:
    // ...
    Widget3():str_("Widget::str_") {}
    void reDraw() const;
    //...
private:
    string  str_;
};

void Widget3::reDraw() const
{
    cout << " str_: " << str_ << " ---Widget::reDraw() \n";
}

template <typename T>
class betweenValues : public unary_function<T, bool>
{
private:
    T   lowVal, highVal;
public:
    betweenValues(const T& l, const T& h)
        : lowVal(l), highVal(h) { }
    bool    operator () (const T& val) const
    {
        return val>lowVal && val<highVal;
    }
};

//---------------------------------------------------------------------------
//---����46������ʵ�麯����������Ǻ�����Ϊ STL�㷨�Ĳ��� ----
inline bool doubleGreater(double d1, double d2)
{
    return  d1 > d2;
}
struct  stringSize : public unary_function<string, string::size_type>
{
    string::size_type operator () (const string& str)  const
    {
        return  str.size();
    }

};

template <typename FPType>
FPType  average(const FPType& val1, const FPType& val2)
{
    return  (val1+val2)/2;
}

template <typename FPType>
struct Average : public binary_function<FPType, FPType, FPType>
{
    FPType operator () (const FPType& val1, const FPType& val2) const
    {
        return  average(val1, val2);
    }
};
template <typename InputIter1,
typename InputIter2 >
void    writeAverages(InputIter1 begin1, InputIter1 end1,
                      InputIter1 begin2, ostream& os)
{
    transform(begin1, end1, begin2,
              ostream_iterator<typename iterator_traits<InputIter1>::value_type>(os, " "),
              average<typename iterator_traits<InputIter1>::value_type> );
    /*or:
        transform(begin1, end1, begin2,
                  ostream_iterator<typename iterator_traits<InputIter1>::value_type>(os, " "),
                  Average<typename iterator_traits<InputIter1>::value_type>() );
    */
}
//---------------------------------------------------------------------------

#endif
