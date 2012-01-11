
/* {
    int     i = 111 ,j = 222 ,k = 333;
    i = j = k;
    cout << i << " ," << j << " ," << k << endl;
    i = 111 ,j = 222 ,k = 333;  
    (i = j )= k;
    cout << i << " ," << j << " ," << k << endl;
    }  */

    ostream_iterator<int>   outite(cout ," " );
    time_t  t;
    srand(time(&t));
/*
//---条款1：慎重选择容器类型 ----------------

//---条款2：不要试图编写独立于容器类型的代码 --------------

//---条款3：确保容器中的对象拷贝正确而高效 ------------

//---条款4：调用empty() 而不是检查size()是否为 0 --------

//---条款5：区间成员函数优先于与之对于的单元素成员函数 ----
    {
    // 1.   区间创建 -- container::container(InputIterator begin ,InputIterator end);
    // 2.   区间插入 -- container::inserst(iterator position ,InputIterator begin ,InputIterator end);
    // 3.   区间删除 -- iterator/void container::erase(iterator begin ,Iiterator end);
    // 4.   区间赋值 -- void container::assign(InputIterator begin ,InputIterator end);
    #define NUM 100
    long    timeCount;
    int*    iData = new int[NUM];
    //memset(iData ,0 ,NUM);  // --- error ---
    //uninitialized_fill_n(iData ,NUM ,999); //--- OK ---
    for(int i=0;i<NUM;++i)
        iData[i] = i;
    vector<int> iVec;
    cout << " ---------1 . perfect ----- \n";
    timeCount =  GetTickCount(); //
    iVec.insert(iVec.begin() ,iData ,iData+NUM);// --perfect ---
    cout << " timeCount = " << GetTickCount()-timeCount << "\n"; //
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    cout << " ---------2 . not perfect ----- \n";
    iVec.clear(); 
    timeCount =  GetTickCount();//
    vector<int>::iterator   it = iVec.begin();
    for(int i=0;i<NUM;i++)
    {
        it = iVec.insert(it ,iData[i]);
        it++;
    }      
    cout << " timeCount = " << GetTickCount()-timeCount << "\n";//
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n"; 
    cout << " ---------3 . not perfect ----- \n";
    iVec.clear();
    timeCount =  GetTickCount();//
    copy(iData ,iData+NUM ,back_inserter(iVec));
    cout << " timeCount = " << GetTickCount()-timeCount << "\n"; //
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";

    delete  iData;

    }
/*
//---条款6：当心 C++ 编译器最烦人的分析机制 ------------  
     cout << "---条款6：当心 C++ 编译器最烦人的分析机制 ----------" << endl;
    ifstream    fin("ints.txt");
    // ---没有加括号 istream_iterator<int>(fin) ，error C++ 编译器分析机制：函数声明
    // As : (declare  function)  int f(double d); ==(等价) int f(double (d) ); == int f(double);  ------
    // 1 . list<int>   iList( istream_iterator<int>(fin) ,istream_iterator<int>() );
    //--- 加括号  ( istream_iterator<int>(fin) )
    //list<int>   iList( (istream_iterator<int>(fin) ) ,istream_iterator<int>() );
    // 2 . or : ----------
    istream_iterator<int>   iBegin(fin) ,iEnd;
    list<int>   iList(iBegin ,iEnd);
    copy(iList.begin() ,iList.end() ,ostream_iterator<int>(cout ,"\n") );
    cout << endl;

//---条款7：如果容器包含了通过new 操作创建指针，切记在容器对象析构前将指针delete掉 -----
    {  
     cout << "---条款7：如果容器包含了通过new 操作创建指针，切记在容器对象析构前将指针delete掉 ----" << endl;
    deque<int*> PtrIntDeq;
    for(int i=0;i<10;i++)
        PtrIntDeq.push_back(new int(i)); 
    cout << " 1 . print PtrIntDeq to value ----------- \n";
    deque<int*>::const_iterator it  = PtrIntDeq.begin();
    for(int i=0;it!=PtrIntDeq.end();it++ ,i++)
        cout << " *PtrIntDeq[" << i << "] = " << **it << endl;
    //cout << " 2 . print PtrIntDeq to value ----------- \n";
    //for(int i=0;i<PtrIntDeq.size();i++)
        //cout << " *PtrIntDeq[" << i << "] = " << *PtrIntDeq[i] << endl;
    cout << " for_each(PtrIntDeq.begin() ,PtrIntDeq.end() ,DeletePtr() ) \n";
    for_each(PtrIntDeq.begin() ,PtrIntDeq.end() ,DeletePtr() );
    // ---or : transform(PtrIntDeq.begin() ,PtrIntDeq.end() ,PtrIntDeq.begin() ,DeletePtr());
    cout << " Print PtrIntDeq --------after destructor----  \n ";
    copy(PtrIntDeq.begin() ,PtrIntDeq.end() ,ostream_iterator<int*>(cout ," ") );
    cout << endl;
    }
//---条款8：切勿创建包含auto_ptr的容器对象 --------------
    {  // ------
    cout << "---条款8：切勿创建包含auto_ptr的容器对象 -----" <<endl;
    vector< auto_ptr<int> > APIntPtrVec; // Shouldn't Pass compiler but OK ! --Should avoid 
    for(int i=0;i<10;++i)
        APIntPtrVec.push_back( auto_ptr<int>(new int(rand()%100)) );
    cout << " vector< auto_ptr<int> > APIntPtrVec; ... rand ....\n";
    for_each(APIntPtrVec.begin() ,APIntPtrVec.end() ,
             APtrToRefPtint<int>() );  
    cout << endl;
    sort(APIntPtrVec.begin() ,APIntPtrVec.end() ,PtrToRefComp );
    cout << " APIntPtrVec --- sorted ---------\n";
    for_each(APIntPtrVec.begin() ,APIntPtrVec.end() ,
             APtrToRefPtint<int>() );    
    cout << endl;
    }          */
//---条款9：慎重选择删除元素的方法 -----------------------
    {
    cout << " ---条款9：慎重选择删除元素的方法 ------ \n";
    cout << " vector or string ,deque --- erase-remove/remove_if \n";
    vector<int> iVec(20 ,2000); // or string ,deque
    for(int i=0;i<5;i++)
        iVec[i+3] = 1999;

    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    iVec.erase(remove(iVec.begin(),iVec.end() ,1999) ,iVec.end());
    iVec.erase(remove_if(iVec.begin() ,iVec.end() ,badValue<2000>()) ,\
               iVec.end());
    //cout << " iVec.erase(remove(iVec.begin(),iVec.end() ,1999) ,iVec.end());\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";

    cout << " list<int>  --- erase or remove(perfect)/remove_if ---\n";
    list<int>   iList(20 ,2000); // or string ,deque
    for(int i=0;i<5;i++)
    {
        iList.push_front(1999);
        iList.push_back(2001);
    }
    copy(iList.begin() ,iList.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    iList.remove(1999);
    // Or : iList.remove_if(badValue<2000>());
    // Or : iList.erase(remove(iList.begin(),iList.end() ,1999) ,iList.end());
    // Or : iList.erase(remove_if(iList.begin(),iList.end() ,badValue<2000>()) ,iList.end());
    cout << " iList.erase(remove(iList.begin(),iList.end() ,1999) ,iList.end());\n";
    copy(iList.begin() ,iList.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    // ...写循环遍历 iList,根据条件badCheck,进行erase操作  ...
    list<int>::iterator iter = iList.begin();
    badValue<2001>  badCheck;
    for(;iter!=iList.end(); )
        if(badCheck(*iter))
            iter = iList.erase(iter);//后缀递增，否则it失效，注意了 ！！！vector,string,deque ... OK
            // Or : iList.erase(iter++);  //链式结构--OK,序列则 error 如 vector,string,deque ...
        else
            iter++;//
    cout << " 写循环遍历 iList,根据条件badCheck,进行操作 iList.erase(...); \n";
    copy(iList.begin() ,iList.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";


    cout << " multiset<int>  --- erase ---关联式容器 ---\n";
    multiset<int>   iMSet(iVec.begin() ,iVec.end() );
    for(int i=0;i<5;i++)
    {
        iMSet.insert(1999);
        iMSet.insert(1998);   
        iMSet.insert(2001);
    }
    copy(iMSet.begin() ,iMSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    iMSet.erase(1999);
    cout << " iMSet.erase(1999);\n";
    copy(iMSet.begin() ,iMSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    // ....需要 copy 所有不被删除元素 ...
    multiset<int>   goodValues;
    remove_copy_if(iMSet.begin() ,iMSet.end() ,inserter(goodValues ,goodValues.end()) ,
                   badValue<2000>() );
    iMSet.swap(goodValues);
    cout << " iMSet.remove_copy_if(...); iMSet.swap(...)\n";
    copy(iMSet.begin() ,iMSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    // ...写循环遍历 iMSet ，根据条件badCheck ，进行erase操作  ...
    multiset<int>::iterator it = iMSet.begin();
    //badValue<2001>  badCheck;
    for(;it!=iMSet.end(); )
        if(badCheck(*it))
            iMSet.erase(it++);//后缀递增 ，否则it失效，注意了 ！！！！
        else
            it++;//
    cout << " 写循环遍历 iMSet,根据条件badCheck进行操作 iMSet.erase(...); \n";
    copy(iMSet.begin() ,iMSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";



    }

//---条款10：了解分配子(allocator)的约定和限制 ---------

//---条款11：理解自定义分配子的合理用法 ----------------

//---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -------------------
/*
    {
     cout << "---条款12：切勿对 STL 容器的线程安全性有不且实际的依赖 -----" << endl;
    vector<int> iVec(10 ,999);
    {
        LockContainer< vector<int> > Lock(iVec);
        // ---   Lock Container-- iVec 
    }
    vector<HANDLE>       HandleVec;

    int     ThreadNum = 1;
    //vector<TTestThread*> TestThreadVec;
    //TTestThread< vector<int> >::c = iVec;
    for(int i=0;i<5;++i)
    {
       TTestThread< vector<int> > *TestThread = new TTestThread< vector<int> >(false ,iVec ,ThreadNum++ );
       HandleVec.push_back((void*)TestThread->Handle);
    }
    for(int i=0;i<HandleVec.size();++i)
    {
       //WaitForSingleObject(HandleVec[i] ,INFINITE);  // ---- 1 .
       //cout << " WaitForSingleObject(HandleVec[" << i << "] ,INFINITE) \n";
       ThreadRunOver->WaitFor(5000); // INFINITE // ----- or 2 .
       //cout << " TestThread[" << i << "] , Run Over -------\n";
    }
    cout << " All TestThread Run Over -------\n";
    }
//---条款13：vector 和 string 优先于动态分配数组 -------
    cout << " ---条款13：vector 和 string 优先于动态分配数组 ----\n";
//---条款14：使用reserve 来避免不必要的重新分配 --------
    cout << " ---条款14：使用reserve 来避免不必要的重新分配 -----\n";
    vector<int>    iVec1;
    for(int i=0;i<1000;i++)
    {
        if(iVec1.size()==iVec1.capacity())
            cout << " ---iVec1.size()==iVec1.capacity()==" << iVec1.size()
                 << " ,-->resize --" <<endl;
        iVec1.push_back(i);
    }
    cout << " now iVec1.capacity()==" << iVec1.capacity() << endl;
    vector<int>    iVec2;
    iVec2.reserve(1000);
    for(int i=0;i<1000;i++)
    {
        if(iVec2.size()==iVec2.capacity())
            cout << " ---iVec2.size()==iVec2.capacity()==" << iVec2.size()
                 << " ,--> resize --" <<endl;
        iVec2.push_back(i);
    }   
    cout << " now iVec2.capacity()==" << iVec2.capacity() << endl;
//---条款15：注意string 的多样性()实现多样性  ----------- 包含：
// 1 .大小---size ，2 .容量---capacity ，3 .分配子---alloctor ，4 .引用计数 ----
    cout << " ---条款15：注意string 的多样性()实现多样性  ----------- 包含：\n"  
	 << " 1 .大小---size ，2 .容量---capacity ，3 .分配子---alloctor ，4 .引用计数 ----\n";
    string  str("11111");
    int     strSize = sizeof(str);
    cout <<" string  str(\"11111\"); sizeof(str) = " << strSize << endl;
    cout << " print str as sizeof(str) character  :\n ";
    char*   pstr = &str[0];   
    for(;strSize>0;strSize--)
        cout << *pstr << ' ' ;
    cout << endl;   
//---条款16：了解如何把 vector 和 string 数据传给 就的API -----
// -----string::c_str() ,vector ,&Vec[0] ----------
    cout << " \n";

//---条款17：使用 “swap技巧”除去多余的容量 vector ,string --------------
    cout << " ---条款17：使用 “swap技巧”除去多余的容量 vector ,string -------\n";
    cout << " swap 技巧 去除 iVec1 多余的容量,即 vector<int> (iVec1).swap(iVec1)  " << endl;
    cout << " \n";
    cout << " before iVec1.capacity()==" << iVec1.capacity()
         << " , iVec1.size()==" << iVec1.size() << endl;
    vector<int> (iVec1).swap(iVec1);
    cout << " now iVec1.capacity()==" << iVec1.capacity()
         << " , iVec1.size()==" << iVec1.size() << endl;

//---条款18：避免使用 vector<bool> ，使用 deque<bool> ,bitset 替代 -----
    {
    cout << " ---条款18：避免使用 vector<bool> ，使用 deque<bool> ,bitset 替代 -----\n";
    vector<bool>    bVec;
    time_t  t;
    srand(time(&t));
    for(int i=0;i<10;i++)
        bVec.push_back(rand()%2);
    cout << " print bVec :" << boolalpha ;
    copy(bVec.begin() ,bVec.end() ,ostream_iterator<bool>(cout ," ") );// print bVec !!!!
    cout << endl;    
    //[C++ Error] E2034 Cannot convert '_Bit_reference *' to 'bool *'
    //bool    *pBool = &bVec[0];  //--- No error ----
    // ---- replace 1 : deque -----
    deque<bool>    bDeq;
    for(int i=0;i<10;i++)
        bDeq.push_back(rand()%2);
    cout << " print bDeq :" << boolalpha ;
    copy(bDeq.begin() ,bDeq.end() ,ostream_iterator<bool>(cout ," ") );// print bDeq !!!!
    cout << endl;
    bool    *pBool = &bDeq[0];
    cout << " bool *pBool = &bDeq[0];*pBool = " << *pBool << endl;
    // ---- replace 2 :  bitset -------    #include <bitset>
    bitset<10>    bSet; // --- test bitset  -----
    cout << "  bitset<10>    bSet; ---print bSet :\n";
    for(int i=0;i<bSet.size();i++)
        cout << " bSet[" << i <<"] = " << bSet[i] << endl;
    cout << endl;
    bSet.set(0 ,1);
    bSet.set(1 ,1);
    //cout << "bSet[0] = " << bSet[0] << endl;
    //cout << "bSet[1] = " << bSet[1] << endl;
    cout << "bSet.set(...) --0 ,1 ---print bSet :\n";
    for(int i=0;i<bSet.size();i++)
        cout << " bSet[" << i <<"] = " << bSet[i] << endl;
    cout << endl;
    }
/*
//---条款19：理解相等（equality）和等价（equivalence）的区别 ------
    cout << " ---条款19：理解相等（equality）和等价（equivalence）的区别 ------\n";
//---条款20：为包含指针的关联容器（亦其他容器）指定比较类型 ！-----
    {
    cout << " ---条款20：为包含指针的关联容器（亦其他容器）指定比较类型 ！-----\n";
    set<string*>    strSet;
    strSet.insert(new string("33333"));
    strSet.insert(new string("22222"));
    strSet.insert(new string("11111"));
    strSet.insert(new string("00000"));
    cout << " set<string*>    strSet; ----No DereferenceLess ,No Hope ----" << endl;
    set<string*>::const_iterator it=strSet.begin();
    for(int i=0;it!=strSet.end();it++ ,i++)
        cout << "strSet["<<i<<"] = " << **it <<endl; //--- No hoped sort !
    //copy(strSet.begin() ,strSet.end() ,ostream_iterator<string*>(cout ,"\n"));// ---print string address !!!
    //cout << endl;
    }
    {
    set<string* ,DereferenceLess>    strSet;
    strSet.insert(new string("33333"));
    strSet.insert(new string("22222"));
    strSet.insert(new string("11111"));
    strSet.insert(new string("00000"));
    cout << " set<string*,DereferenceLess>    strSet; ---- DereferenceLess ,OK ----" << endl;
    set<string*>::const_iterator it=strSet.begin();
    for(int i=0;it!=strSet.end();it++ ,i++)
        cout << "strSet["<<i<<"] = " << **it <<endl; //--- No hoped sort !
    //copy(strSet.begin() ,strSet.end() ,ostream_iterator<string*>(cout ,"\n"));// ---print string address !!!
    //cout << endl;
    }
//---条款21：总是让比较函数在等值情况下返回false ------------
//---比较函数的返回值表明的是按照改函数定义的排列顺序，一个值是否在另一个之前 ----
    cout << " ---条款21：总是让比较函数在等值情况下返回false --------\n" 
	 << " ---比较函数的返回值表明的是按照改函数定义的排列顺序，一个值是否在另一个之前 ----\n";
//---条款22：直接切勿修改set或是 multiset 中的键值 -----
    {
    cout << " ---条款22：直接切勿修改set或是 multiset 中的键值 -----\n";
    EmpIDSet    eis;
    eis.insert(Employee("hjk" ,"33333" ,333));
    eis.insert(Employee("hjk" ,"11111" ,222));
    eis.insert(Employee("hjk" ,"11111" ,111));
    cout << " set<Employee ,IDLess> eis; ----print ----" << endl;
    EmpIDSet::const_iterator it = eis.begin();
    for(int i=0;it!=eis.end();it++ ,i++)
        cout << "eis[" <<i<<"].getID() = " << (*it).getID()
             << " ,gettitle() = " << it->gettitle()<< endl;
    it = eis.find(Employee("hjk" ,"22222" ,222));
    if(it!=eis.end())
    {
        it->settitle("22222");
        //it->setID(444);  //-----No Modify ! destory set sort --------
        //(*it) = Employee("hjk" ,"22222" ,222);  //?????
        //[C++ Error] E2285 Could not find a match for 'Employee::operator =(Employee)'
    }
    cout << " set<Employee ,IDLess> eis; ----print after it->settitle(\"22222\");----" << endl;
    it = eis.begin();
    for(int i=0;it!=eis.end();it++ ,i++)         
        cout << "eis[" <<i<<"].getID() = " << (*it).getID()
             << " ,gettitle() = " << it->gettitle()<< endl;
    it = eis.find(Employee("hjk" ,"22222" ,222)); //
    if(it!=eis.end())
    {
        Employee    e("hjk" ,"44444" ,444);
        eis.erase(it++);
        eis.insert(it ,e);//-- perfect ,still set sort ------  
        cout << " set<Employee ,IDLess> eis; ----print after erase-insert ----" << endl;
        it = eis.begin();
        for(int i=0;it!=eis.end();it++ ,i++)
            cout << "eis[" <<i<<"].getID() = " << (*it).getID()
                 << " ,gettitle() = " << it->gettitle()<< endl;
    }  
    }
//---条款23：考虑用排序的vector替代关联容器 --------
    cout << " ---条款23：考虑用排序的vector替代关联容器 -------\n";
//---条款24：当效率至关重要时，请在map::operator[] 和 map::insert 之间谨慎做出选择-------
    cout << " ---条款24：当效率至关重要时，请在map::operator[] 和 map::insert 之间谨慎做出选择----\n";


//---条款25：熟悉非标准的哈希容器--hash_container ------------------
    cout << " ---条款25：熟悉非标准的哈希容器--hash_container ------\n";
/*
//---条款26：iterator 优先于const_iterator、reverse_iterator、以及const_reverse_iterator
// --- iterator -> (隐式转换)const_iterator
    cout << " ---条款26：iterator 优先于const_iterator、reverse_iterator、以及const_reverse_iterator\n" 
	 << " --- iterator -> (隐式转换)const_iterator\n";
//---条款27：使用 distence 和 advance 将容器的const_iterator转换 iterator
    {
    cout << " ---条款27：使用 distence 和 advance 将容器的const_iterator转换 iterator\n";
    typedef deque<int>  IntDeque;
    typedef IntDeque::iterator  Iter;   
    typedef IntDeque::const_iterator  ConstIter;
    IntDeque    iDeq(10 ,5);
    Iter    it = iDeq.begin();
    ConstIter   cit = iDeq.end();
    if(it==cit)
        cout << "it==cit" << endl;  
    if(cit==it)
        cout << "it==cit" << endl;
//[C++ Error] UnitMain.cpp(26): E2031 Cannot cast from '_Deque_iterator<int,_Const_traits<int> >' to '_Deque_iterator<int,_Nonconst_traits<int> >'
    //Iter itTemp(const_cast<Iter>(cit));// error
    iDeq[iDeq.size()-1] = 99999;
    cit--;
    cout << "*cit = " << *cit << endl;
    Iter itTemp(iDeq.begin());
    advance(itTemp ,distance<ConstIter>(itTemp ,cit));// --- perfect ------  
    cout << "*itTemp = " << *itTemp <<endl;
    }
//---条款28 :正确理解有 reverse_iterator 的 base()成员函数所产生的iterator的用法
    {
    cout << " ---条款28 :正确理解有 reverse_iterator 的 base()成员函数所产生的iterator的用法\n";
    vector<int> iVec;
    iVec.reserve(5);
    for(int i=0;i<5;i++)
        iVec.push_back(i);
    vector<int>::reverse_iterator rit = find(iVec.rbegin() ,iVec.rend() ,3);
    //iVec.erase(--rit.base()); //error  [C++ Error] : E2277 Lvalue required
    //iVec.erase(rit);// [C++ Error] E2285 Could not find a match for 'vector<int,allocator<int> >::erase(reverse_iterator<int *>)'
    iVec.erase((++rit).base());// 删除 rite 所指的元素 ----- OK
    cout << "iVec.erase((++rit).base()); ---- erase: 3 " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;  
    }
//---条款29 :对于逐个字符的输入请考虑使用 istreambuf_iterator ，对于逐个字符的输出请考虑使用 osstreambuf_iterator ，
    {
    cout << " ---条款29 :对于逐个字符的输入请考虑使用 istreambuf_iterator ，对于逐个字符的输出请考虑使用 osstreambuf_iterator \n";
    ifstream    fin("text.txt");
    //----检测格式化输入 ，增加读取流的时间开销 忽略空格， 回车 ，Tab ------
    //string  FileData((istream_iterator<char>(fin)) ,istream_iterator<char>());
    //cout << FileData <<endl;
    //------非格式化输入 ，高效 ，原样读取 ---------
    string  FileData_((istreambuf_iterator<char>(fin)) ,istreambuf_iterator<char>());// --- OK ,perfect !
    string  FileData_(istreambuf_iterator<char>(fin) ,istreambuf_iterator<char>()); // --- error
// ---条款6：当心 C++ 编译器烦人的分析机制 ！(istreambuf_iterator<char>(fin))加括号 ！-------
    //above ：[Linker Error] Unresolved external 'FileData_(_STL::istreambuf_iterator<char, _STL::char_traits<char> >, _STL::istreambuf_iterator<char, _STL::char_traits<char> > (*)())'
//referenced from F:\C++\EFFECTIVE STL\UNITMAIN.OBJ
    cout << FileData_ <<endl;

    }

/*
//---条款30：确保目标区间足够大 ----------------------
    {
    cout << "---条款30：确保目标区间足够大 ------" << endl;
    vector<int> iVec(3 ,1);
    cout << " vector<int> iVec(3 ,1); -----print -----" << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    transform(iVec.begin() ,iVec.end() ,back_inserter(iVec) ,transmogrify );
    cout << " After transform(iVec.begin() ,iVec.end() ,back_inserter(iVec) ,transmogrify );" << endl;
    cout << " Now print iVec : -----------\n ";
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;  
    transform(iVec.begin() ,iVec.end() ,inserter(iVec ,iVec.begin()+(iVec.size()/2)) ,transmogrify );
    cout << " After iVec.begin() ,iVec.end() ,inserter(iVec.begin()+iVec.size()/2) ,transmogrify );" << endl;
    cout << " Now print iVec : -----------\n ";
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    list<int>   iList;
    copy(iVec.begin() ,iVec.end() ,back_inserter(iList));
    cout << " copy(iVec.begin() ,iVec.end() ,front_inserter(iList)); -----" << endl;
    cout << " Now print iList : -----------\n ";
    copy(iList.begin() ,iList.end() ,outite );
    cout << endl;
    transform(iList.begin() ,iList.end() ,front_inserter(iList) ,transmogrify ); // ---结果奇怪 -----
    cout << " After transform(iList.begin() ,iList.end() ,front_inserter(iList) ,transmogrify );" << endl;
    cout << " Now print iList : -----------\n ";
    copy(iList.begin() ,iList.end() ,outite );
    cout << endl;
    iVec.clear();
    iVec.reserve(iList.size());
    cout << "iVec.clear(); iVec.reserve(iList.size()); iVec.size() = " << iVec.size() << endl;
    //transform(iList.rbegin() ,iList.rend() ,front_inserter(iVec) ,transmogrify );
    copy(iList.rbegin() ,iList.rend() ,back_inserter(iVec) );
    cout << " After copy(iList.rbegin() ,iList.rend() ,front_inserter(iVec) );" << endl;
    cout << " Now print iVec : -----------\n "; 
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;   
    } 
//---条款31：了解各种与排序有关的选择 ----------------
    {
     cout << "---条款31：了解各种与排序有关的选择 -----" << endl;
     vector<int>    iVec;
     for(int i=0;i<10;i++)
        iVec.push_back(rand()%100);
    cout << " rand 10 values (0~99)into iVec  -----print -----" << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    partial_sort(iVec.begin() ,iVec.begin()+iVec.size()/2 ,iVec.end());// ,less<int>()
    cout << " After partial_sort(iVec.begin() ,,iVec.begin()+iVec.size()/2 ,iVec.end()); \n"
         << "  -----print iVec ----- " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    
    random_shuffle(iVec.begin() ,iVec.end());
    cout << " random_shuffle(iVec.begin() ,iVec.end()); -------- " << endl;
    nth_element(iVec.begin() ,iVec.begin()+iVec.size()/2 ,iVec.end());// ,less<int>()
    cout << " After nth_element(iVec.begin() ,iVec.begin()+iVec.size()/2 ,iVec.end()); \n"
         << "  -----print iVec ----- " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    nth_element(iVec.begin() ,iVec.begin()+iVec.size()/2 ,iVec.end() ,greater<int>() );
    cout << " After nth_element(iVec.begin() ,iVec.begin()+iVec.size()/2 ,iVec.end() ,greater<int>()); \n"
         << "  -----print iVec ----- " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    random_shuffle(iVec.begin() ,iVec.end());
    cout << " random_shuffle(iVec.begin() ,iVec.end());\n"
         << "  -----print iVec ----- " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    vector<int>::const_iterator cit = partition(iVec.begin() ,iVec.end() ,PredIntTo50<int>() );
    cout << " After vector<int>::const_iterator cit = partition(iVec.begin() ,iVec.end(),PredIntTo50<int>() );  \n"
         << "  -----print iVec ----- " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    cout << " *cit = " << *cit << endl;

    }
//---条款32,33： 见上，测试过----------------------------------
/*
//---条款32：如果确实需要删除元素 ，则需要在remove这类算法之后调用 erase-----
    {
    cout << " ---条款32：如果确实需要删除元素 ，则需要在remove这类算法之后调用 erase---\n";
    //int     i = 0;
    vector<int> iVec;      // (10 ,i++)
    iVec.reserve(10);
    for(int i=0;i<10;++i)
        iVec.push_back(i);
    iVec[3] = iVec[5] = iVec[7] =  99;   
    cout << " iVec.size() : " << iVec.size() << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    //remove(iVec.begin() ,iVec.end() ,99);  --- No really remove 99
    iVec.erase(remove(iVec.begin() ,iVec.end() ,99) ,iVec.end());// eally erase(remove) 99
    cout << " iVec.size() : " << iVec.size() << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
//---条款33：对于包含指针的容器使用remove这类算法时要特别小心！ -----------
    cout << " ---条款33：对于包含指针的容器使用remove这类算法时要特别小心！ ----\n";
    time_t  t;
    srand(time(&t));
    vector<Widget*> WidgetVec;
    for(int i=0;i<10;i++)
    {
        WidgetVec.push_back(new Widget);
        if(!WidgetVec[i]->isCertified())
            cout << "WidgetVec["<< i << "]->isCertified() = false " << endl;
    }
    cout << " Before erase-remove :WidgetVec.size() = " << WidgetVec.size() <<endl;

    for_each(WidgetVec.begin() ,WidgetVec.end() ,DelAndNULLifyUncertified);//ptr_fun(...);
    WidgetVec.erase(remove(WidgetVec.begin() ,WidgetVec.end() ,static_cast<Widget*>(0)) ,
                    WidgetVec.end());
    
    cout << " After erase-remove :WidgetVec.size() = " << WidgetVec.size() <<endl;
    for(unsigned int i=0;i<WidgetVec.size();i++)
    {
        if(WidgetVec[i]->isCertified())
            cout << "WidgetVec["<< i << "]->isCertified() = true " << endl;
    }
    }   */

//---条款34：了解哪些STL算法要求使用排序区间作为参数 ----
// --- binary_search , lower_bound ,upper_bound ,equal_range ,
// --- set_union ,set_intersection ,set_difference ,set_symmetri_difference ,
// --- merge ,inplace_merge ,includes  ,--- 搭配运用  unique，unique_copy。
    {
    cout << "---条款34：了解哪些算法要求使用排序区间作为参数 ----\n"
         << " --- binary_search , lower_bound ,upper_bound ,equal_range ,\n"
         << " --- set_union ,set_intersection ,set_difference ,set_symmetri_difference ,\n"
         << " --- merge ,inplace_merge ,includes  ,--- 搭配运用  unique，unique_copy.\n" ;

    vector<int>    iVec;
    for(int i=0;i<10;i++)
        iVec.push_back(rand()%100);
    cout << " initialize : rand 10 values (0~99)into iVec  -----print -----" << endl;
    copy(iVec.begin() ,iVec.end() ,outite );// ostream_iterator<int>(cout ," ");
    cout << endl;
    sort(iVec.begin() ,iVec.end());// ,less<int>();
    cout << " sort(iVec.begin() ,iVec.end());//,less<int>();\n -----print iVec-----" << endl;
    copy(iVec.begin() ,iVec.end() ,outite );// ostream_iterator<int>(cout ," ");
    cout << endl;  
    sort(iVec.begin() ,iVec.end() ,greater<int>());//
    cout << " sort(iVec.begin() ,iVec.end(),greater<int>());\n -----print iVec-----" << endl;
    copy(iVec.begin() ,iVec.end() ,outite );// ostream_iterator<int>(cout ," ");
    cout << endl;
    cout << " 注意：sort 和 search 比较函数应该保持一直 示例如下：------\n";
    bool ValueExists = binary_search(iVec.begin() ,iVec.end() ,iVec[2] );//,less<int>()
    cout << " bool ValueExists = binary_search(iVec.begin() ,iVec.end() ,iVec[2])\n"
         << " //,less<int>()--- error: sort as greater<int>() ,but search as less<int> \n";
    cout << "binary_search(...) ,search "<< iVec[2] << " ,ValueExists = "
         << boolalpha << ValueExists << endl;
    ValueExists = binary_search(iVec.begin() ,iVec.end() ,iVec[2] ,greater<int>());
    cout << " ValueExists = binary_search(iVec.begin() ,iVec.end() ,iVec[2]greater<int>())\n"
         << " //--- OK: sort as greater<int>() ,and search as greater<int> \n";
    cout << "binary_search(...) ,search "<< iVec[2] << " ,ValueExists = "
         << boolalpha << ValueExists << endl; 
    }

/*
//---条款35：通过 mismatch 或 lexicographical_compare 实现简单的忽略大小写
//-----------字符串比较 ----------------------
    {
    cout << "---条款35：通过 mismatch 或 lexicographical_compare 实现简单的忽略大小写---" << endl;
    cout << " ciStringCompare(\"123456\" ,\"123455\") = " << ciStringCompare("123456" ,"123456") << endl;
    cout << " ciStringCompare(\"123455\" ,\"123456\") = " << ciStringCompare("123455" ,"123456") << endl;
    cout << " ciStringCompare(\"123456\" ,\"123455\") = " << ciStringCompare("123456" ,"123455") << endl;
    cout << boolalpha ;// cout bool value as true or false ----
    cout << " ciStringCompare_(\"123456\" ,\"123456\") = " << ciStringCompare_("123456" ,"123456") << endl;
    cout << " ciStringCompare_(\"123455\" ,\"123456\") = " << ciStringCompare_("123455" ,"123456") << endl;
    cout << " ciStringCompare_(\"123456\" ,\"123455\") = " << ciStringCompare_("123456" ,"123455") << endl;
    }

//---条款36：理解copy_if 算法的正确实现 ，STL没有包含copy_if的实现--------------
    {
    cout << "---条款36：理解copy_if 算法的正确实现 ，STL没有包含copy_if的实现-----" << endl;
    vector<int>    iVec;
    for(int i=0;i<10;i++)
        iVec.push_back(rand()%100);
    cout << " rand 10 values (0~99)into iVec  -----print -----" << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;
    cout << " copy_if(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," "),\n"
         << " PredIntTo50<int>() ); \n";
    copy_if(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," "),
            PredIntTo50<int>() );
    cout << endl; 
    cout << " copy_if(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," "),\n"
         << " PredIntTo50<int>() ); \n";
    copy_if_(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," "),
            PredIntTo50<int>() );
    cout << endl;

    }

//---条款37：使用accumulate 或是 for_each 进行区间统计 ---
    {
    cout << "---条款37：使用accumulate 或是 for_each 进行区间统计 ---" <<endl;
    double  dArray[] = { 0.1 ,0.2 ,0.3 ,0.4 ,0.5 ,0.6 ,0.7 ,0.8 ,0.9 ,1.0 };
    list<double>    dList(dArray ,dArray+sizeof(dArray)/sizeof(double));
    cout << " Initatile list<double> dList ----print ----" << endl;
    //cout.precision(3);
    copy(dList.begin() ,dList.end() ,ostream_iterator<double>(cout ," "));
    cout << endl;
    double  sum = accumulate(dList.begin() ,dList.end() ,0.0);
    cout << "double sum = accumulate(dList.begin() ,dList.end() ,0.0); sum = "
         << sum <<endl; 
    sum = accumulate(dList.begin() ,dList.end() ,0);
    cout << "   sum = accumulate(dList.begin() ,dList.end() ,0); sum = "
         << sum <<endl; 
    sum = accumulate(dList.begin() ,dList.end() ,1.0 ,multiplies<double>());
    cout << "   sum = accumulate(dList.begin() ,0.0 ,mutilplies<double>()); sum = "
         << sum <<endl;
         
    set<string> strSet;
    strSet.insert("11111");  
    strSet.insert("22222");
    strSet.insert("33333");
    cout << " Initatile set<string> strSet ----print strSet ----" << endl;
    copy(strSet.begin() ,strSet.end() ,ostream_iterator<string>(cout ," "));
    cout << endl;
    string::size_type   lengthSum = accumulate(strSet.begin() ,strSet.end(),
                                               string::size_type(0) ,stringLengthSum);
    cout << " string::size_type   lengthSum = accumulate(strSet.begin() ,strSet.end(),"
         << " string::size_type(0) ,stringLengthSum); \n ";
    cout << " lengthSum = " << lengthSum << endl;

    list<dPoint>    pList;
    for(int i=0;i<5;i++)
        pList.push_back(dPoint(1.1*i ,2.2*i));
    copy(pList.begin() ,pList.end() ,ostream_iterator<dPoint>(cout ," "));
    // --- 传给accumulate函数不允许有副作用 ，所以从技术上讲以下结果会是不可预料----
    //---- 1 ----？？？？？？？？？----------
    dPoint  avg = accumulate(pList.begin() ,pList.end() ,dPoint(0.0 ,0.0),PointAverage());
    cout << " dPoint  avg = accumulate(pList.begin() ,pList.end() ,dPoint(0.0 ,0.0),PointAverage());\n";
    cout << " avg = " << avg << endl;
    // --- 2 ------
    avg = for_each(pList.begin() ,pList.end() ,PointAverage_()).result();
    cout << " dPoint  avg = for_each(pList.begin() ,pList.end() ,PointAverage_()).result();\n";
    cout << " avg = " << avg << endl;  
    }
//---条款38：遵循按值传递的原则设计函数子类 ----
    cout << " ---条款38：遵循按值传递的原则设计函数子类 ----\n";
    BPFC1<int>  *bpfc1 = new BPFC1<int>() ;
    BPFC2<int>  *bpfc2 = new BPFC2<int>() ;
    vector<int> iVec(10 ,99);
    for_each(iVec.begin() ,iVec.end() ,GoodFunctor<int>(bpfc1) ); 
    for_each(iVec.begin() ,iVec.end() ,GoodFunctor<int>(bpfc2) );

//---条款39：确保判别式是“纯函数” ---
    {  
    cout << " ---条款39：确保判别式是“纯函数” ---反例 ：\n";
    vector<int> iVec;
    iVec.reserve(12);
    for(unsigned int i=0;i<iVec.capacity();i++)
        iVec.push_back(vector<int>::value_type(i) );
    cout << " --- print ivec -------------\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << endl;
    cout << " --- delete ivec[2] ,but delete ivec[2],ivec[5], error ---\n";
    iVec.erase(remove_if(iVec.begin() ,iVec.end() ,BadPredicate<int>() ) ,
                iVec.end() );
    cout << " --- print ivec -------------\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," "));
    cout << endl;
    }

//---条款40：若一个类是函数子，则应使它可配接 ----
    cout << " ---条款40：若一个类是函数子，则应使它可配接 ----\n";
//  template <typename T>
//  class Functor1 : public unary_function<T ,bool> {// ...}
//  template <typename T1 ,typename T2>
//  class Functor2 : public binary_function<T1 ,T2 ,bool> {// ...}

//---------------------------------------------------------------------------
//---条款41：理解ptr_fun ，mem_fun ，和mem_fun_ref的由来 ---
    cout << " ---条款41：理解ptr_fun ，mem_fun ，和mem_fun_ref的由来 ---\n";

//---------------------------------------------------------------------------
//---条款42：确保less<T> 与operator< 具有相同的语义 ---
    cout << " ---条款42：确保less<T> 与operator< 具有相同的语义 ---  \n";


//---------------------------------------------------------------------------
//---条款43：算法调用优先于手写算法  ---
    {
    cout << " ---条款43：算法调用优先于手写算法  ---\n";
    list<Widget>    lw(10 ,Widget());
    // for 循环 ----
    cout << " for 循环 ----\n";
    for(list<Widget>::iterator it = lw.begin();it!=lw.end();++it)
        it->reDraw();
    // 算法 for_each ----
    cout << " 算法 for_each ----\n";
    for_each(lw.begin() ,lw.end(),mem_fun_ref(&Widget::reDraw) );

    double  dData[] = { 1 ,2 ,3 ,4 ,5 ,6 ,7, 8 ,9 ,10 };
    const int   NUM = sizeof(dData)/sizeof(double);
    deque<double>   dDeq; // (dData ,dData+NUM);
    cout << " for 循环 ----\n";
    deque<double>::iterator insertIter = dDeq.begin();
    for(size_t i =0;i<NUM;++i)
    {
        insertIter = dDeq.insert(insertIter ,dData[i]+99);
        ++insertIter;
    }
    copy(dDeq.begin() ,dDeq.end() ,ostream_iterator<double>(cout ," ") );
    cout << " \n";
    dDeq.clear();
    cout << " 算法 transform() ----\n";
    transform(dData ,dData+NUM ,back_inserter(dDeq) ,bind2nd(plus<double>() ,99) );
    copy(dDeq.begin() ,dDeq.end() ,ostream_iterator<double>(cout ," ") );
    cout << " \n";
// ... 算法的名称比普通的循环更有意义，但是，要表明在一次迭代中完成什么工作 ，
//     则使用循环比起算法更为清晰 -----
    vector<int> iVec(dData ,dData+NUM);
    vector<int>::iterator it = iVec.begin();
    cout << " 循环查找 ----- for(...) \n";
    for(;it!=iVec.end();it++)
        if(*it>5 && *it<8)
            break;
    if(it!=iVec.end())
        cout << " find *it>5 && *it<8 : *it = " << *it;
    else          
        cout << " Not find *it>5 && *it<8 ";
    cout << "\n";      
    cout << " 1 . 算法查找 ----- find_if(...) \n";
    it = find_if(iVec.begin() ,iVec.end() ,
                 compose2(logical_and<bool>() ,
                          bind2nd(greater<int>() ,5) ,
                          bind2nd(less<int>() ,8) ) );
    if(it!=iVec.end())
        cout << " find *it>5 && *it<8 : *it = " << *it;
    else
        cout << " Not find *it>5 && *it<8 ";
    cout << "\n";
    cout << " 2 . 算法查找 ----- find_if(...) \n";
    it = find_if(iVec.begin() ,iVec.end() ,betweenValues<int>(5 ,8) );
    if(it!=iVec.end())
        cout << " find *it>5 && *it<8 : *it = " << *it;
    else          
        cout << " Not find *it>5 && *it<8 ";
    cout << "\n";


    }
//---------------------------------------------------------------------------
//---条款44：容器的成员函数优先于同名的算法 ----
    {
    cout << " ---条款44：容器的成员函数优先于同名的算法  ---\n";
    set<int>    iSet;
    for(int i=0;i<20;i++)
        iSet.insert( rand()%100);
    cout << " iSet .... : \n";
    copy(iSet.begin() ,iSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << " \n";
    int     findValue = *(--iSet.end());
    cout << " findValue : " << findValue << "\n";
    cout << " 成员函数 set<T>::find() --- good ---\n";
    set<int>::iterator it = iSet.find(findValue);
    if(it!=iSet.end())
        cout << " find findValue: " << *(iSet.find(findValue)) << "\n";
    else
        cout << " not find findValue \n";
    cout << " 算法 find() --- bad ----\n";
    it = find(iSet.begin() ,iSet.end() ,findValue);
    if(it!=iSet.end())
        cout << " find findValue: " << *(find(iSet.begin() ,iSet.end() ,findValue)) << "\n";
    else
        cout << " not find findValue \n";

    }
//---------------------------------------------------------------------------
//---条款45：正确区分 count ,find ,binary_search ,lower_bound ,upper_bound 和equal_range ----
    { //
    cout << " ---条款45：正确区分 count ,find ,binary_search ,lower_bound ,upper_bound 和equal_range ---\n";

    int  iData[] = { 1 ,2 ,2 ,3 ,3 ,3 ,4 ,5 ,6 ,7, 8 ,8 ,8 ,9 ,9 ,10 };
    const int   NUM = sizeof(iData)/sizeof(int);
    cout << " iData .... sorted  : \n";
    copy(iData ,iData+NUM ,ostream_iterator<int>(cout ," ") );
    cout << " \n";
    cout << " count(iData ,iData+NUM ,8) = " << count(iData ,iData+NUM ,8) << "\n";
    cout << " *find(iData ,iData+NUM ,8) = " << *find(iData ,iData+NUM ,8) << "\n"; 
    cout << " binary_search(iData ,iData+NUM ,8) = " << boolalpha
         << binary_search(iData ,iData+NUM ,8) << "\n";
    cout << " *lower_bound(iData ,iData+NUM ,8) = "
         << *lower_bound(iData ,iData+NUM ,8) << "\n"; 
    cout << " *upper_bound(iData ,iData+NUM ,8) = "
         << *upper_bound(iData ,iData+NUM ,8) << "\n";
    pair<int* ,int*>    iPtrPair = equal_range(iData ,iData+NUM ,8);
    if(iPtrPair.first==iPtrPair.second)
        cout << " *iPtrPair.first==*iPtrPair.second" << *iPtrPair.first << "\n";
    else
    {
        cout << " iPtrPair.first!=iPtrPair.second\n"
             << " *iPtrPair.first = " << *iPtrPair.first
             << " ,*iPtrPair.second = " << *iPtrPair.second << "\n";
    }
    cout << " distance(iPtrPair.first,iPtrPair.second) = "
         << distance(iPtrPair.first,iPtrPair.second) << "\n";
// 对于关联容器：set ,map ,multiset ,multimap 使用其成员函数
// :: cout ,find ,lower_bound ,upper_bound 和equal_range  ....

    }
//---------------------------------------------------------------------------
//---条款46：考虑实验函数对象而不是函数作为 STL算法的参数 ----
    {
    cout << " ---条款46：考虑实验函数对象而不是函数作为 STL算法的参数 ----\n"; 
    // --- sort(dVec.begin() ,dVec.end() ,greater<double>() ); ---
    ofstream    fout("doubleData.txt");
    for(int i=0;i<10000;i++)
    {
        for(int j=0;j<10;j++)
            fout << rand() << " ";
        //fout << "\n";
    }
    fout.close();
    ifstream    fin("doubleData.txt");
    vector<double>  dVec( (istream_iterator<double>(fin)) ,
                         istream_iterator<double>() );
    fin.close();
    cout << " dVec.size() = " << dVec.size() << "\n";
    long    timeCount = GetTickCount();
    sort(dVec.begin() ,dVec.end() ,greater<double>() ); 
    cout << " timeCount = " << (timeCount = GetTickCount()-timeCount) <<"\n";
    fout.open("doubleDataSorted.txt");
    copy(dVec.begin() ,dVec.end() ,ostream_iterator<double>(fout ," ") );

    // --- sort(dVec.begin() ,dVec.end() ,doubleGreater ); ---
    dVec.clear();
    fin.clear();
    fin.open("doubleData.txt");
    //fin.seekg(0,ios::beg);
    dVec.insert(dVec.end() ,istream_iterator<double>(fin) ,istream_iterator<double>() );
    //or : copy(istream_iterator<double>(fin) ,istream_iterator<double>() ,back_inserter(dVec) );
    fin.close();
    cout << " dVec.size() = " << dVec.size() << "\n"; 
    timeCount = GetTickCount();
    sort(dVec.begin() ,dVec.end() ,doubleGreater );
    cout << " timeCount = " << (timeCount = GetTickCount()-timeCount) <<"\n";
    //fout.open("doubleDataSorted.txt");
    //copy(dVec.begin() ,dVec.end() ,ostream_iterator<double>(fout ," ") );
    
    set<string> strSet;
    strSet.insert("11111");    strSet.insert("22222");
    strSet.insert("33333");    strSet.insert("44444");
    strSet.insert("55555");    strSet.insert("66666");
    transform(strSet.begin() ,strSet.end() ,ostream_iterator<string::size_type>(cout ," ") ,
              stringSize() ); // or : mem_fun_ref(&string::size)
    cout << " \n";
    }
//---------------------------------------------------------------------------
//---条款47：避免产生“直写型”（write-only）的代码 ----
    {
    cout << " ---条款47：避免产生“直写型”（write-only）的代码 ----\n";
    int  iData[] = { 1 ,10 ,2 ,9 ,8 ,8 ,9 ,8 ,3 ,4 ,5 ,6 ,2 ,3 ,3 ,7 };
    const int   NUM = sizeof(iData)/sizeof(int);
    // 删除iVec中所有其值小于 X的元素，但在最后一个其值不小于y的元素之前的所有
    // 元素都应该保留下来 ----
    vector<int> iVec(iData ,iData+NUM);
    cout << " iVec .... print :\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << " \n";
    int     x = 4 ,y = 8;
    cout << " 删除iVec中所有其值小于 4的元素，但在最后一个其值不小于8的元素之前的\n"
         << " 所有元素都应该保留下来 ---- \n";
    // --- write-only ,badlly ----
    cout << " --- write-only ,badlly ----\n";
    iVec.erase( remove_if(find_if(iVec.rbegin() ,iVec.rend() ,
                                  bind2nd(greater_equal<int>() ,y)).base() ,//finf_if
                          iVec.end() ,
                          bind2nd(less<int>() ,x)) ,
                iVec.end() // remove_if
              );//iVec.erase
    cout << " 1 .After iVec.erase(...) --- iVec :\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << " \n";
    // --- not write-only ,greatly ---
    cout << " --- not write-only ,greatly ---\n";
    iVec.clear();
    iVec.insert(iVec.end(), iData ,iData+NUM);
    typedef vector<int>::iterator   IVecIter;
    IVecIter    findIter = find_if(iVec.rbegin() ,iVec.rend() ,
                                  bind2nd(greater_equal<int>() ,y)).base();
    IVecIter    removeIter = remove_if(findIter ,iVec.end(),bind2nd(less<int>() ,x));
    iVec.erase(removeIter ,iVec.end());
    cout << " 2 .After iVec.erase(...) --- iVec :\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << " \n";   

    }

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

//---------------------------------------------------------------------------