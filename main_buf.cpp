
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
//---����1������ѡ���������� ----------------

//---����2����Ҫ��ͼ��д�������������͵Ĵ��� --------------

//---����3��ȷ�������еĶ��󿽱���ȷ����Ч ------------

//---����4������empty() �����Ǽ��size()�Ƿ�Ϊ 0 --------

//---����5�������Ա������������֮���ڵĵ�Ԫ�س�Ա���� ----
    {
    // 1.   ���䴴�� -- container::container(InputIterator begin ,InputIterator end);
    // 2.   ������� -- container::inserst(iterator position ,InputIterator begin ,InputIterator end);
    // 3.   ����ɾ�� -- iterator/void container::erase(iterator begin ,Iiterator end);
    // 4.   ���丳ֵ -- void container::assign(InputIterator begin ,InputIterator end);
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
//---����6������ C++ ��������˵ķ������� ------------  
     cout << "---����6������ C++ ��������˵ķ������� ----------" << endl;
    ifstream    fin("ints.txt");
    // ---û�м����� istream_iterator<int>(fin) ��error C++ �������������ƣ���������
    // As : (declare  function)  int f(double d); ==(�ȼ�) int f(double (d) ); == int f(double);  ------
    // 1 . list<int>   iList( istream_iterator<int>(fin) ,istream_iterator<int>() );
    //--- ������  ( istream_iterator<int>(fin) )
    //list<int>   iList( (istream_iterator<int>(fin) ) ,istream_iterator<int>() );
    // 2 . or : ----------
    istream_iterator<int>   iBegin(fin) ,iEnd;
    list<int>   iList(iBegin ,iEnd);
    copy(iList.begin() ,iList.end() ,ostream_iterator<int>(cout ,"\n") );
    cout << endl;

//---����7���������������ͨ��new ��������ָ�룬�м���������������ǰ��ָ��delete�� -----
    {  
     cout << "---����7���������������ͨ��new ��������ָ�룬�м���������������ǰ��ָ��delete�� ----" << endl;
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
//---����8�����𴴽�����auto_ptr���������� --------------
    {  // ------
    cout << "---����8�����𴴽�����auto_ptr���������� -----" <<endl;
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
//---����9������ѡ��ɾ��Ԫ�صķ��� -----------------------
    {
    cout << " ---����9������ѡ��ɾ��Ԫ�صķ��� ------ \n";
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
    // ...дѭ������ iList,��������badCheck,����erase����  ...
    list<int>::iterator iter = iList.begin();
    badValue<2001>  badCheck;
    for(;iter!=iList.end(); )
        if(badCheck(*iter))
            iter = iList.erase(iter);//��׺����������itʧЧ��ע���� ������vector,string,deque ... OK
            // Or : iList.erase(iter++);  //��ʽ�ṹ--OK,������ error �� vector,string,deque ...
        else
            iter++;//
    cout << " дѭ������ iList,��������badCheck,���в��� iList.erase(...); \n";
    copy(iList.begin() ,iList.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";


    cout << " multiset<int>  --- erase ---����ʽ���� ---\n";
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
    // ....��Ҫ copy ���в���ɾ��Ԫ�� ...
    multiset<int>   goodValues;
    remove_copy_if(iMSet.begin() ,iMSet.end() ,inserter(goodValues ,goodValues.end()) ,
                   badValue<2000>() );
    iMSet.swap(goodValues);
    cout << " iMSet.remove_copy_if(...); iMSet.swap(...)\n";
    copy(iMSet.begin() ,iMSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";
    // ...дѭ������ iMSet ����������badCheck ������erase����  ...
    multiset<int>::iterator it = iMSet.begin();
    //badValue<2001>  badCheck;
    for(;it!=iMSet.end(); )
        if(badCheck(*it))
            iMSet.erase(it++);//��׺���� ������itʧЧ��ע���� ��������
        else
            it++;//
    cout << " дѭ������ iMSet,��������badCheck���в��� iMSet.erase(...); \n";
    copy(iMSet.begin() ,iMSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << "\n";



    }

//---����10���˽������(allocator)��Լ�������� ---------

//---����11������Զ�������ӵĺ����÷� ----------------

//---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -------------------
/*
    {
     cout << "---����12������� STL �������̰߳�ȫ���в���ʵ�ʵ����� -----" << endl;
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
//---����13��vector �� string �����ڶ�̬�������� -------
    cout << " ---����13��vector �� string �����ڶ�̬�������� ----\n";
//---����14��ʹ��reserve �����ⲻ��Ҫ�����·��� --------
    cout << " ---����14��ʹ��reserve �����ⲻ��Ҫ�����·��� -----\n";
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
//---����15��ע��string �Ķ�����()ʵ�ֶ�����  ----------- ������
// 1 .��С---size ��2 .����---capacity ��3 .������---alloctor ��4 .���ü��� ----
    cout << " ---����15��ע��string �Ķ�����()ʵ�ֶ�����  ----------- ������\n"  
	 << " 1 .��С---size ��2 .����---capacity ��3 .������---alloctor ��4 .���ü��� ----\n";
    string  str("11111");
    int     strSize = sizeof(str);
    cout <<" string  str(\"11111\"); sizeof(str) = " << strSize << endl;
    cout << " print str as sizeof(str) character  :\n ";
    char*   pstr = &str[0];   
    for(;strSize>0;strSize--)
        cout << *pstr << ' ' ;
    cout << endl;   
//---����16���˽���ΰ� vector �� string ���ݴ��� �͵�API -----
// -----string::c_str() ,vector ,&Vec[0] ----------
    cout << " \n";

//---����17��ʹ�� ��swap���ɡ���ȥ��������� vector ,string --------------
    cout << " ---����17��ʹ�� ��swap���ɡ���ȥ��������� vector ,string -------\n";
    cout << " swap ���� ȥ�� iVec1 ���������,�� vector<int> (iVec1).swap(iVec1)  " << endl;
    cout << " \n";
    cout << " before iVec1.capacity()==" << iVec1.capacity()
         << " , iVec1.size()==" << iVec1.size() << endl;
    vector<int> (iVec1).swap(iVec1);
    cout << " now iVec1.capacity()==" << iVec1.capacity()
         << " , iVec1.size()==" << iVec1.size() << endl;

//---����18������ʹ�� vector<bool> ��ʹ�� deque<bool> ,bitset ��� -----
    {
    cout << " ---����18������ʹ�� vector<bool> ��ʹ�� deque<bool> ,bitset ��� -----\n";
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
//---����19�������ȣ�equality���͵ȼۣ�equivalence�������� ------
    cout << " ---����19�������ȣ�equality���͵ȼۣ�equivalence�������� ------\n";
//---����20��Ϊ����ָ��Ĺ���������������������ָ���Ƚ����� ��-----
    {
    cout << " ---����20��Ϊ����ָ��Ĺ���������������������ָ���Ƚ����� ��-----\n";
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
//---����21�������ñȽϺ����ڵ�ֵ����·���false ------------
//---�ȽϺ����ķ���ֵ�������ǰ��ոĺ������������˳��һ��ֵ�Ƿ�����һ��֮ǰ ----
    cout << " ---����21�������ñȽϺ����ڵ�ֵ����·���false --------\n" 
	 << " ---�ȽϺ����ķ���ֵ�������ǰ��ոĺ������������˳��һ��ֵ�Ƿ�����һ��֮ǰ ----\n";
//---����22��ֱ�������޸�set���� multiset �еļ�ֵ -----
    {
    cout << " ---����22��ֱ�������޸�set���� multiset �еļ�ֵ -----\n";
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
//---����23�������������vector����������� --------
    cout << " ---����23�������������vector����������� -------\n";
//---����24����Ч��������Ҫʱ������map::operator[] �� map::insert ֮���������ѡ��-------
    cout << " ---����24����Ч��������Ҫʱ������map::operator[] �� map::insert ֮���������ѡ��----\n";


//---����25����Ϥ�Ǳ�׼�Ĺ�ϣ����--hash_container ------------------
    cout << " ---����25����Ϥ�Ǳ�׼�Ĺ�ϣ����--hash_container ------\n";
/*
//---����26��iterator ������const_iterator��reverse_iterator���Լ�const_reverse_iterator
// --- iterator -> (��ʽת��)const_iterator
    cout << " ---����26��iterator ������const_iterator��reverse_iterator���Լ�const_reverse_iterator\n" 
	 << " --- iterator -> (��ʽת��)const_iterator\n";
//---����27��ʹ�� distence �� advance ��������const_iteratorת�� iterator
    {
    cout << " ---����27��ʹ�� distence �� advance ��������const_iteratorת�� iterator\n";
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
//---����28 :��ȷ����� reverse_iterator �� base()��Ա������������iterator���÷�
    {
    cout << " ---����28 :��ȷ����� reverse_iterator �� base()��Ա������������iterator���÷�\n";
    vector<int> iVec;
    iVec.reserve(5);
    for(int i=0;i<5;i++)
        iVec.push_back(i);
    vector<int>::reverse_iterator rit = find(iVec.rbegin() ,iVec.rend() ,3);
    //iVec.erase(--rit.base()); //error  [C++ Error] : E2277 Lvalue required
    //iVec.erase(rit);// [C++ Error] E2285 Could not find a match for 'vector<int,allocator<int> >::erase(reverse_iterator<int *>)'
    iVec.erase((++rit).base());// ɾ�� rite ��ָ��Ԫ�� ----- OK
    cout << "iVec.erase((++rit).base()); ---- erase: 3 " << endl;
    copy(iVec.begin() ,iVec.end() ,outite );
    cout << endl;  
    }
//---����29 :��������ַ��������뿼��ʹ�� istreambuf_iterator ����������ַ�������뿼��ʹ�� osstreambuf_iterator ��
    {
    cout << " ---����29 :��������ַ��������뿼��ʹ�� istreambuf_iterator ����������ַ�������뿼��ʹ�� osstreambuf_iterator \n";
    ifstream    fin("text.txt");
    //----����ʽ������ �����Ӷ�ȡ����ʱ�俪�� ���Կո� �س� ��Tab ------
    //string  FileData((istream_iterator<char>(fin)) ,istream_iterator<char>());
    //cout << FileData <<endl;
    //------�Ǹ�ʽ������ ����Ч ��ԭ����ȡ ---------
    string  FileData_((istreambuf_iterator<char>(fin)) ,istreambuf_iterator<char>());// --- OK ,perfect !
    string  FileData_(istreambuf_iterator<char>(fin) ,istreambuf_iterator<char>()); // --- error
// ---����6������ C++ ���������˵ķ������� ��(istreambuf_iterator<char>(fin))������ ��-------
    //above ��[Linker Error] Unresolved external 'FileData_(_STL::istreambuf_iterator<char, _STL::char_traits<char> >, _STL::istreambuf_iterator<char, _STL::char_traits<char> > (*)())'
//referenced from F:\C++\EFFECTIVE STL\UNITMAIN.OBJ
    cout << FileData_ <<endl;

    }

/*
//---����30��ȷ��Ŀ�������㹻�� ----------------------
    {
    cout << "---����30��ȷ��Ŀ�������㹻�� ------" << endl;
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
    transform(iList.begin() ,iList.end() ,front_inserter(iList) ,transmogrify ); // ---������ -----
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
//---����31���˽�����������йص�ѡ�� ----------------
    {
     cout << "---����31���˽�����������йص�ѡ�� -----" << endl;
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
//---����32,33�� ���ϣ����Թ�----------------------------------
/*
//---����32�����ȷʵ��Ҫɾ��Ԫ�� ������Ҫ��remove�����㷨֮����� erase-----
    {
    cout << " ---����32�����ȷʵ��Ҫɾ��Ԫ�� ������Ҫ��remove�����㷨֮����� erase---\n";
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
//---����33�����ڰ���ָ�������ʹ��remove�����㷨ʱҪ�ر�С�ģ� -----------
    cout << " ---����33�����ڰ���ָ�������ʹ��remove�����㷨ʱҪ�ر�С�ģ� ----\n";
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

//---����34���˽���ЩSTL�㷨Ҫ��ʹ������������Ϊ���� ----
// --- binary_search , lower_bound ,upper_bound ,equal_range ,
// --- set_union ,set_intersection ,set_difference ,set_symmetri_difference ,
// --- merge ,inplace_merge ,includes  ,--- ��������  unique��unique_copy��
    {
    cout << "---����34���˽���Щ�㷨Ҫ��ʹ������������Ϊ���� ----\n"
         << " --- binary_search , lower_bound ,upper_bound ,equal_range ,\n"
         << " --- set_union ,set_intersection ,set_difference ,set_symmetri_difference ,\n"
         << " --- merge ,inplace_merge ,includes  ,--- ��������  unique��unique_copy.\n" ;

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
    cout << " ע�⣺sort �� search �ȽϺ���Ӧ�ñ���һֱ ʾ�����£�------\n";
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
//---����35��ͨ�� mismatch �� lexicographical_compare ʵ�ּ򵥵ĺ��Դ�Сд
//-----------�ַ����Ƚ� ----------------------
    {
    cout << "---����35��ͨ�� mismatch �� lexicographical_compare ʵ�ּ򵥵ĺ��Դ�Сд---" << endl;
    cout << " ciStringCompare(\"123456\" ,\"123455\") = " << ciStringCompare("123456" ,"123456") << endl;
    cout << " ciStringCompare(\"123455\" ,\"123456\") = " << ciStringCompare("123455" ,"123456") << endl;
    cout << " ciStringCompare(\"123456\" ,\"123455\") = " << ciStringCompare("123456" ,"123455") << endl;
    cout << boolalpha ;// cout bool value as true or false ----
    cout << " ciStringCompare_(\"123456\" ,\"123456\") = " << ciStringCompare_("123456" ,"123456") << endl;
    cout << " ciStringCompare_(\"123455\" ,\"123456\") = " << ciStringCompare_("123455" ,"123456") << endl;
    cout << " ciStringCompare_(\"123456\" ,\"123455\") = " << ciStringCompare_("123456" ,"123455") << endl;
    }

//---����36�����copy_if �㷨����ȷʵ�� ��STLû�а���copy_if��ʵ��--------------
    {
    cout << "---����36�����copy_if �㷨����ȷʵ�� ��STLû�а���copy_if��ʵ��-----" << endl;
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

//---����37��ʹ��accumulate ���� for_each ��������ͳ�� ---
    {
    cout << "---����37��ʹ��accumulate ���� for_each ��������ͳ�� ---" <<endl;
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
    // --- ����accumulate�����������и����� �����ԴӼ����Ͻ����½�����ǲ���Ԥ��----
    //---- 1 ----������������������----------
    dPoint  avg = accumulate(pList.begin() ,pList.end() ,dPoint(0.0 ,0.0),PointAverage());
    cout << " dPoint  avg = accumulate(pList.begin() ,pList.end() ,dPoint(0.0 ,0.0),PointAverage());\n";
    cout << " avg = " << avg << endl;
    // --- 2 ------
    avg = for_each(pList.begin() ,pList.end() ,PointAverage_()).result();
    cout << " dPoint  avg = for_each(pList.begin() ,pList.end() ,PointAverage_()).result();\n";
    cout << " avg = " << avg << endl;  
    }
//---����38����ѭ��ֵ���ݵ�ԭ����ƺ������� ----
    cout << " ---����38����ѭ��ֵ���ݵ�ԭ����ƺ������� ----\n";
    BPFC1<int>  *bpfc1 = new BPFC1<int>() ;
    BPFC2<int>  *bpfc2 = new BPFC2<int>() ;
    vector<int> iVec(10 ,99);
    for_each(iVec.begin() ,iVec.end() ,GoodFunctor<int>(bpfc1) ); 
    for_each(iVec.begin() ,iVec.end() ,GoodFunctor<int>(bpfc2) );

//---����39��ȷ���б�ʽ�ǡ��������� ---
    {  
    cout << " ---����39��ȷ���б�ʽ�ǡ��������� ---���� ��\n";
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

//---����40����һ�����Ǻ����ӣ���Ӧʹ������� ----
    cout << " ---����40����һ�����Ǻ����ӣ���Ӧʹ������� ----\n";
//  template <typename T>
//  class Functor1 : public unary_function<T ,bool> {// ...}
//  template <typename T1 ,typename T2>
//  class Functor2 : public binary_function<T1 ,T2 ,bool> {// ...}

//---------------------------------------------------------------------------
//---����41�����ptr_fun ��mem_fun ����mem_fun_ref������ ---
    cout << " ---����41�����ptr_fun ��mem_fun ����mem_fun_ref������ ---\n";

//---------------------------------------------------------------------------
//---����42��ȷ��less<T> ��operator< ������ͬ������ ---
    cout << " ---����42��ȷ��less<T> ��operator< ������ͬ������ ---  \n";


//---------------------------------------------------------------------------
//---����43���㷨������������д�㷨  ---
    {
    cout << " ---����43���㷨������������д�㷨  ---\n";
    list<Widget>    lw(10 ,Widget());
    // for ѭ�� ----
    cout << " for ѭ�� ----\n";
    for(list<Widget>::iterator it = lw.begin();it!=lw.end();++it)
        it->reDraw();
    // �㷨 for_each ----
    cout << " �㷨 for_each ----\n";
    for_each(lw.begin() ,lw.end(),mem_fun_ref(&Widget::reDraw) );

    double  dData[] = { 1 ,2 ,3 ,4 ,5 ,6 ,7, 8 ,9 ,10 };
    const int   NUM = sizeof(dData)/sizeof(double);
    deque<double>   dDeq; // (dData ,dData+NUM);
    cout << " for ѭ�� ----\n";
    deque<double>::iterator insertIter = dDeq.begin();
    for(size_t i =0;i<NUM;++i)
    {
        insertIter = dDeq.insert(insertIter ,dData[i]+99);
        ++insertIter;
    }
    copy(dDeq.begin() ,dDeq.end() ,ostream_iterator<double>(cout ," ") );
    cout << " \n";
    dDeq.clear();
    cout << " �㷨 transform() ----\n";
    transform(dData ,dData+NUM ,back_inserter(dDeq) ,bind2nd(plus<double>() ,99) );
    copy(dDeq.begin() ,dDeq.end() ,ostream_iterator<double>(cout ," ") );
    cout << " \n";
// ... �㷨�����Ʊ���ͨ��ѭ���������壬���ǣ�Ҫ������һ�ε��������ʲô���� ��
//     ��ʹ��ѭ�������㷨��Ϊ���� -----
    vector<int> iVec(dData ,dData+NUM);
    vector<int>::iterator it = iVec.begin();
    cout << " ѭ������ ----- for(...) \n";
    for(;it!=iVec.end();it++)
        if(*it>5 && *it<8)
            break;
    if(it!=iVec.end())
        cout << " find *it>5 && *it<8 : *it = " << *it;
    else          
        cout << " Not find *it>5 && *it<8 ";
    cout << "\n";      
    cout << " 1 . �㷨���� ----- find_if(...) \n";
    it = find_if(iVec.begin() ,iVec.end() ,
                 compose2(logical_and<bool>() ,
                          bind2nd(greater<int>() ,5) ,
                          bind2nd(less<int>() ,8) ) );
    if(it!=iVec.end())
        cout << " find *it>5 && *it<8 : *it = " << *it;
    else
        cout << " Not find *it>5 && *it<8 ";
    cout << "\n";
    cout << " 2 . �㷨���� ----- find_if(...) \n";
    it = find_if(iVec.begin() ,iVec.end() ,betweenValues<int>(5 ,8) );
    if(it!=iVec.end())
        cout << " find *it>5 && *it<8 : *it = " << *it;
    else          
        cout << " Not find *it>5 && *it<8 ";
    cout << "\n";


    }
//---------------------------------------------------------------------------
//---����44�������ĳ�Ա����������ͬ�����㷨 ----
    {
    cout << " ---����44�������ĳ�Ա����������ͬ�����㷨  ---\n";
    set<int>    iSet;
    for(int i=0;i<20;i++)
        iSet.insert( rand()%100);
    cout << " iSet .... : \n";
    copy(iSet.begin() ,iSet.end() ,ostream_iterator<int>(cout ," ") );
    cout << " \n";
    int     findValue = *(--iSet.end());
    cout << " findValue : " << findValue << "\n";
    cout << " ��Ա���� set<T>::find() --- good ---\n";
    set<int>::iterator it = iSet.find(findValue);
    if(it!=iSet.end())
        cout << " find findValue: " << *(iSet.find(findValue)) << "\n";
    else
        cout << " not find findValue \n";
    cout << " �㷨 find() --- bad ----\n";
    it = find(iSet.begin() ,iSet.end() ,findValue);
    if(it!=iSet.end())
        cout << " find findValue: " << *(find(iSet.begin() ,iSet.end() ,findValue)) << "\n";
    else
        cout << " not find findValue \n";

    }
//---------------------------------------------------------------------------
//---����45����ȷ���� count ,find ,binary_search ,lower_bound ,upper_bound ��equal_range ----
    { //
    cout << " ---����45����ȷ���� count ,find ,binary_search ,lower_bound ,upper_bound ��equal_range ---\n";

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
// ���ڹ���������set ,map ,multiset ,multimap ʹ�����Ա����
// :: cout ,find ,lower_bound ,upper_bound ��equal_range  ....

    }
//---------------------------------------------------------------------------
//---����46������ʵ�麯����������Ǻ�����Ϊ STL�㷨�Ĳ��� ----
    {
    cout << " ---����46������ʵ�麯����������Ǻ�����Ϊ STL�㷨�Ĳ��� ----\n"; 
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
//---����47�����������ֱд�͡���write-only���Ĵ��� ----
    {
    cout << " ---����47�����������ֱд�͡���write-only���Ĵ��� ----\n";
    int  iData[] = { 1 ,10 ,2 ,9 ,8 ,8 ,9 ,8 ,3 ,4 ,5 ,6 ,2 ,3 ,3 ,7 };
    const int   NUM = sizeof(iData)/sizeof(int);
    // ɾ��iVec��������ֵС�� X��Ԫ�أ��������һ����ֵ��С��y��Ԫ��֮ǰ������
    // Ԫ�ض�Ӧ�ñ������� ----
    vector<int> iVec(iData ,iData+NUM);
    cout << " iVec .... print :\n";
    copy(iVec.begin() ,iVec.end() ,ostream_iterator<int>(cout ," ") );
    cout << " \n";
    int     x = 4 ,y = 8;
    cout << " ɾ��iVec��������ֵС�� 4��Ԫ�أ��������һ����ֵ��С��8��Ԫ��֮ǰ��\n"
         << " ����Ԫ�ض�Ӧ�ñ������� ---- \n";
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

//---------------------------------------------------------------------------