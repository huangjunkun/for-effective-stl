#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#pragma once
#include "stdafx.h"
#include "../project-tool/win_thread_class.h"
#include "../project-tool/win_sync_func.h"

using namespace std;
using namespace test_namespace;


static junkun::mutex s_mxPrintContainer;//临界区
static junkun::critical_section s_csPrintContainer;//重要区段 -----

//---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -------------------
#define LOCKNAME    "LockName"
template <typename Container >
class LockContainer
{
    // 异常 ，亦析构局部对象，即~LockContainer() ---健壮性 ---
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
        //this->FreeOnTerminate = true; //线程结束时自动删除
    }
    //template< typename Container>
    //friend void PrintContainer(const Container& c);
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---条款7：如果容器包含了通过new 操作创建指针，切记在容器对象析构前将指针delete掉 -----

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
//---条款8：切勿创建包含auto_ptr的容器对象 --------------
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
//---条款10：了解分配子(allocator)的约定和限制 --------- 1 ~~~ 5 tips
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
//---条款11：理解自定义分配子的合理用法 ----------------
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
//---条款9：慎重选择删除元素的方法 -----------------------
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
//---条款20：为包含指针的关联容器（亦其他容器）指定比较类型 ！-----
typedef struct  DereferenceLess
{
    template<typename PtrType>
    bool operator () (PtrType pT1, PtrType pT2) const
    {
        return  *pT1 < *pT2;
    }
} DereferenceLess;
//---条款22：直接切勿修改set或是 multiset 中的键值 -----
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
//---条款24：当效率至关重要时，请在map::operator[] 和 map::insert 之间谨慎做出选择-------
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

//---条款30：确保目标区间足够大 ----------------------
int transmogrify(const int& x)
{
    return  x+1;
}
//---条款31：了解各种与排序有关的选择 ----------------
//class  -> [C++ Error] _algo.c(606): E2247 'PredIntTo50<int>::operator ()(const int &)' is not accessible
template <typename T>
struct PredIntTo50 : public unary_function<T, bool>
{
    bool operator () (const T& x) const
    {
        return x > T(50);
    }

};
//---条款37：使用accumulate 或是 for_each 进行区间统计 ---
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
//---条款35：通过 mismatch 或 lexicographical_compare 实现简单的忽略大小写
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
    // --- 保证合法调用STL算法： mismatch（...） -----
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

//---条款36：理解copy_if 算法的正确实现 ，STL没有包含copy_if的实现--------------
template <typename InputIterator,
typename OutputIterator,
typename Predicate >
// ------ OK call STL 算法remove_copy_if(...)----------
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

//---条款38：遵循按值传递的原则设计函数子类 ----
// --- 以下方法：既允许函数对象可以很大并且/或者保留多态性，
// ---- 有可以与STL 所采用的传值传递函数子的习惯保持一致
// ---- “鱼与熊掌兼得” ---谨慎处理BPFC的拷贝构造函数 ----
class Widget2
{
    // ----  具体内容略 --------
};
/*  */
template <typename T>
class GoodFunctor; // 模板类 BPFC 声明 ---
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
//---条款39：确保判别式是“纯函数” ---
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
//---条款43：算法调用优先于手写算法  ---
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
//---条款46：考虑实验函数对象而不是函数作为 STL算法的参数 ----
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
