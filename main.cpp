//---------------------------------------------------------------------------

#include "stdafx.h"
#include "main.h"


//---------------------------------------------------------------------------

int main(int argc, char* argv[])
{
//---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -------------------
    {
     cout << "---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -----" << endl ;
    vector<int> iVec(10 ,999) ;
    {
        LockContainer< vector<int> > Lock(iVec) ;
        // ---   Lock Container-- iVec
    }
    typedef TTestThread< vector<int> > TTestThread2VecInt;
    vector<TTestThread2VecInt*>       HandleVec ;

    int     ThreadNum = 1 ;
    //vector<TTestThread*> TestThreadVec ;
    //TTestThread< vector<int> >::c = iVec ;
    for(int i=0 ;i<5 ;++i)
    {
       TTestThread2VecInt* TestThread = new TTestThread2VecInt(false ,iVec ,ThreadNum++ ) ;
       HandleVec.push_back(TestThread) ;
    }
    for(int i=0 ;i<HandleVec.size() ;++i)
    {
       WaitForSingleObject(HandleVec[i]->handle() ,INFINITE) ;  // ---- 1 .
       cout << " WaitForSingleObject(HandleVec[" << i << "] ,INFINITE) \n" ;
       //ThreadRunOver->WaitFor(5000) ; // INFINITE // ----- or 2 .
       cout << " TestThread[" << i << "] , Run Over -------\n" ;
    }

    for(int i=0 ;i<HandleVec.size() ;++i)
    {
        delete HandleVec[i];
        HandleVec[i] = NULL;
    }
    cout << " All TestThread Run Over -------\n" ;
    }

    /**
    ostream_iterator<int>   outite(cout, " " );
    time_t  t;
    srand(time(&t));
//---条款40：若一个类是函数子，则应使它可配接 ----
    cout << " ---条款40：若一个类是函数子，则应使它可配接 ----\n";
//  template <typename T>
//  class Functor1 : public unary_function<T, bool> {// ...}
//  template <typename T1, typename T2>
//  class Functor2 : public binary_function<T1, T2, bool> {// ...}

//---条款41：理解ptr_fun ，mem_fun ，和mem_fun_ref的由来 ---
    cout << " ---条款41：理解ptr_fun ，mem_fun ，和mem_fun_ref的由来 ---\n";

//---条款42：确保less<T> 与operator< 具有相同的语义 ---
    cout << " ---条款42：确保less<T> 与operator< 具有相同的语义 ---  \n";

//---条款48：总是包含（#include）正确的头文件 ----
    {
    cout << " ---条款48：总是包含（#include）正确的头文件 ----\n";
    }

//---条款49：学会分析与STL相关的编译器诊断信息 ----
    {
    cout << " ---条款49：学会分析与STL相关的编译器诊断信息 ---\n";
    }

//---条款50：熟悉与STL 相关的Web站点 ----
    {
    cout << " ---条款50：熟悉与STL 相关的Web站点 ----\n";
    }

    /**     */
//---------------------------------------------------------------------------

    cout << "\n\n\n     Hello, World !" << endl;
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------


