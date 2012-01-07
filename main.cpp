//---------------------------------------------------------------------------

#include "stdafx.h"
#include "main.h"


//---------------------------------------------------------------------------

int main(int argc, char* argv[])
{
//---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -------------------
    {
     cout << "---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -----" << endl ;
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

    cout << "\n\n\n     Hello, World !" << endl;
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------


