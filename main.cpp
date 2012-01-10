//---------------------------------------------------------------------------

#include "stdafx.h"
#include "main.h"
#include "../project-tool/win_sync_func.h"
//#include "
using namespace std;

//---------------------------------------------------------------------------

int main(int argc, char* argv[])
{
//    {
//    using namespace junkun;
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
///**
//---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -------------------
    {
        cout << "---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -----" << endl ;
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
    //---����40����һ�����Ǻ����ӣ���Ӧʹ������� ----
    cout << " ---����40����һ�����Ǻ����ӣ���Ӧʹ������� ----\n";
    //  template <typename T>
    //  class Functor1 : public unary_function<T, bool> {// ...}
    //  template <typename T1, typename T2>
    //  class Functor2 : public binary_function<T1, T2, bool> {// ...}

    //---����41�����ptr_fun ��mem_fun ����mem_fun_ref������ ---
    cout << " ---����41�����ptr_fun ��mem_fun ����mem_fun_ref������ ---\n";

    //---����42��ȷ��less<T> ��operator< ������ͬ������ ---
    cout << " ---����42��ȷ��less<T> ��operator< ������ͬ������ ---  \n";

    //---����48�����ǰ�����#include����ȷ��ͷ�ļ� ----
    {
    cout << " ---����48�����ǰ�����#include����ȷ��ͷ�ļ� ----\n";
    }

    //---����49��ѧ�������STL��صı����������Ϣ ----
    {
    cout << " ---����49��ѧ�������STL��صı����������Ϣ ---\n";
    }

    //---����50����Ϥ��STL ��ص�Webվ�� ----
    {
    cout << " ---����50����Ϥ��STL ��ص�Webվ�� ----\n";
    }

    /**     */
//---------------------------------------------------------------------------

    cout << "\n Hello, World !" << endl;
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------


