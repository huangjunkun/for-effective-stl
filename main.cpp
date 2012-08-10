//---------------------------------------------------------------------------

#include "stdafx.h"
#include "main.h"
#include "../project-tool/win_sync_func.h"
#include "../project-tool/win_file.h"
//#include "
using namespace std;
using namespace junkun;
//---------------------------------------------------------------------------

int main(int argc, char* argv[])
{

//    {
//    using namespace junkun;
//    cout_trace (win_file::err_msg());
//
////    test_win32_sync_func(2); // for critical_section ...
//    for (unsigned i = 0; i < 5; ++i)
//    {
//        cout_trace(" --- test_win32_sync_func: i = " << i );
//        test_win32_sync_func(i);
//    }
////    event e;
////    cout_trace("handle:" << e.handle() << " is_valid:" << e.is_valid());
//    ///error: 'junkun::locker::locker(const junkun::locker&)' is private|
////    event e2(e);
////    cout_trace("handle2:" << e2.handle() << " is_valid:" << e2.is_valid());
//    }
/**
//---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -------------------
    {
        cout << "---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -----" << endl ;
        vector<int> iVec(10 ,999) ;
        {
            LockContainer< vector<int> > Lock(iVec) ;
            // ---   Lock Container-- iVec
        }
        typedef TTestThread< vector<int> > TTestThread2VecInt;
        vector<TTestThread2VecInt*>       threadVec ;

        //vector<TTestThread*> TestThreadVec ;
        //TTestThread< vector<int> >::c = iVec ;
        const unsigned THREAD_COUNT = 5;
        for(unsigned i=0 ; i < THREAD_COUNT ; ++i)
        {
            TTestThread2VecInt* testThread = new TTestThread2VecInt(false ,iVec ,i+1) ;
            threadVec.push_back(testThread) ;
        }
        vector<HANDLE> handleVec;
        handleVec.resize(threadVec.size());
        //HANDLE handleVec[THREAD_COUNT];
        for (unsigned i = 0; i < handleVec.size(); ++i)
            handleVec[i] = threadVec[i]->handle();

        //::WaitForMultipleObjects(THREAD_COUNT, handleVec, TRUE, INFINITE);
        ::WaitForMultipleObjects(handleVec.size(), handleVec.data(), TRUE, INFINITE);//&handleVec.front()

        for(int i=0 ; i<threadVec.size() ; ++i)
        {
            delete threadVec[i];
            threadVec[i] = NULL;
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

    cout << "\n Hello, World !" << endl;
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------


