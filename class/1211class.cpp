// const 클래스

// #include <iostream>
// using namespace std;

// class SoSimple
// {
//     private:
//     int num;
//     public:
//     SoSimple(int n) : num(n)
//     { }
//     SoSimple &AddNum(int n)
//     {
//         num+=n;
//         return *this;
//     }
//     void SimpleFunc()
//     {
//         cout<<"SimpleFunc: "<<num<<endl;
//     }
//     void SimpleFunc() const
//     {
//         cout<<"const SimpleFunc: "<<num<<endl;
//     }
// };

// void YourFunc(const SoSimple &obj)
// {
//     obj.SimpleFunc();
// }

// int main(void)
// {
//     SoSimple obj1(2);
//     const SoSimple obj2(7);

//     obj1.SimpleFunc();
//     obj2.SimpleFunc();

//     YourFunc(obj1);
//     YourFunc(obj2);
//     return 0;
// }


// // static

// #include <iostream>
// using namespace std;

// class SoSimple
// {
//     private:
//     static int simObjCnt;
//     public:
//     SoSimple()
//     {
//         simObjCnt++;
//         cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
//     }
// };
// int SoSimple::simObjCnt=0;

// class SoComplex
// {
//     private:
//     static int cmxObjCnt;
//     public:
//     SoComplex()
//     {
//         cmxObjCnt++;
//         cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
//     }
//     SoComplex(SoComplex &copy)
//     {
//         cmxObjCnt++;
//         cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
//     }
// };

// int SoComplex::cmxObjCnt=0;

// int main(void)
// {
//     SoSimple sim1;
//     SoSimple sim2;

//     SoComplex cmx1;
//     SoComplex cmx2=cmx1;
//     SoComplex();
//     return 0;
// }


// // 상속 Inheritance

// #include <iostream>
// #include <cstring>
// using namespace std;

// class Person
// {
//     private:
//     int age;
//     char name[50];
//     public:
//     Person(int myage, char * myname) : age(myage)
//     {
//         strcpy(name, myname);
//     }
//     void WhatYourName() const
//     {
//         cout<<"My name is "<<name<<endl;
//     }
//     void HowOldAreYou() const
//     {
//         cout<<"I'm "<<age<<" years old"<<endl;
//     }
// };

// class UnivStudent : public Person
// {
//     private:
//     char major[50];
//     public:
//     UnivStudent(char * myname, int myage, char * mymajor)
//         : Person(myage, myname)
//     {
//         strcpy(major, mymajor);
//     }
//     void WhoAreYou() const
//     {
//         WhatYourName();
//         HowOldAreYou();
//         cout<<"My major is "<<major<<endl<<endl;
//     }
// };

// int main(void)
// {
//     UnivStudent ustd1("Lee", 22, "Computer eng.");
//     ustd1.WhoAreYou();

//     UnivStudent ustd2("Yoon", 21, "Electronic eng.");
//     ustd2.WhoAreYou();
//     return 0;
// };


// // 유도 클래스 객체의 소멸과정 -> 2번씩 호출

// #include <iostream>
// using namespace std;

// class SoBase
// {
//     private:
//     int baseNum;
//     public:
//     SoBase(int n) : baseNum(n)
//     {
//         cout << "SoBase() : "<<baseNum<<endl;
//     }
//     ~SoBase()
//     {
//         cout<<"~SoBase() : "<<baseNum<<endl;
//     }
// };

// class SoDerived : public SoBase
// {
//     private:
//     int derivNum;
//     public:
//     SoDerived(int n) : SoBase(n), derivNum(n)
//     {
//         cout<<"SoDerived() : "<<derivNum<<endl;
//     }
//     ~SoDerived()
//     {
//         cout<<"~SoDerived() : " << derivNum << endl;
//     }
// };

// int main(void)
// {
//     SoDerived drv1(15);
//     SoDerived drv2(27);
//     return 0;
// };


// // protected 상속

// #include <iostream>
// using namespace std;

// class Base
// {
//     private:
//     int num1;
//     protected:
//     int num2;
//     public:
//     int num3;

//     Base() : num1(1), num2(2), num3(3)
//     { }
// };

// class Derived : protected Base { };

// int main(void)
// {
//     Derived drv;
//     // cout << drv.num3<<endl;
//     return 0;
// }


// // 객체 포인터 변수 (하 또 포인터야)

// #include <iostream>
// using namespace std;

// class Person
// {
//     public:
//     void Sleep()
//     {
//         cout << "Sleep" << endl;
//     }
// };

// class Student : public Person
// {
//     public:
//     void Study()
//     {
//         cout << "Study" << endl;
//     }
// };

// class PartTimeStudent : public Student
// {
//     public:
//     void Work()
//     {
//         cout << "Work" << endl;
//     }
// };

// int main(void)
// {
//     Person * ptr1 = new Student();
//     Person * ptr2 = new PartTimeStudent();
//     Student * ptr3 = new PartTimeStudent();
//     ptr1->Sleep();
//     ptr2->Sleep();
//     ptr3->Study();
//     delete ptr1; delete ptr2; delete ptr3;
//     return 0;
// }


// #include <iostream>
// #include <cstring>
// using namespace std;

// class Employee
// {
//     private:
//     char name[100];
//     public:
//     Employee(char * name)
//     {
//         strcpy(this->name, name);
//     }
//     void ShowYourName() const
//     {
//         cout << "name: " << name << endl; 
//     }
// };

// class PermanentWorker : public Employee
// {
//     private:
//     int salary;
//     public:
//     PermanentWorker(char *name, int money)
//         : Employee(name), salary(money)
//     { }
//     int GetPay() const
//     {
//         return salary;
//     }
//     void ShowSalaryInfo() const
//     {
//         ShowYourName();
//         cout << "salary: " << GetPay() << endl << endl;
//     }
// };

// class EmployeeHandler
// {
//     private:
//     Employee *empList[50];
//     int empNum;
//     public:
//     EmployeeHandler() : empNum(0)
//     { }
//     void AddEmployee(Employee *emp)
//     {
//         empList[empNum++] = emp;
//     }
//     void ShowAllSalaryInfo() const
//     {
//         // for (int i = 0; i < empNum; i++)
//         // {
//         //     empList[i]->ShowSalaryInfo();
//         // }
//     }
//     void ShowTotalSalary() const
//     {
//         int sum=0;
//         // for (int i = 0; i < empNum; i++)
//         // {
//         //     sum+=empList[i]->GetPay();
//         // }
//         cout << "salary sum: " << sum << endl;
//     }
//     ~EmployeeHandler()
//     {
//         for (int i = 0; i < empNum; i++)
//         {
//             delete empList[i];
//         }
//         cout << "deleted empList!" << endl;
//     }
// };

// int main(void)
// {
//     // 객체생성
//     EmployeeHandler handler;

//     // 직원 등록
//     handler.AddEmployee(new PermanentWorker("KIM", 1000));
//     handler.AddEmployee(new PermanentWorker("LEE", 1500));
//     handler.AddEmployee(new PermanentWorker("JUN", 2000));
    
//     handler.ShowAllSalaryInfo();

//     handler.ShowTotalSalary();
//     return 0;
// }


// 가상함수

#include <iostream>
using namespace std;

class First
{
    public:
    virtual void MyFunc()
    {
        cout << "FirstFunc" << endl;
    }
};

class Second: public First
{
    public:
    void MyFunc()
    {
        cout << "SecondFunc" << endl;
    }
};

class Third: public Second
{
    public:
    void MyFunc()
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    Third *tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return 0;
}


// // 가상함수를 이용한 고용매니저 ver.4

// #include <iostream>
// #include <cstring>
// using namespace std;

// class Employee
// {
// private:
// 	char name[100];
// public:
// 	Employee(char * name)
// 	{
// 		strcpy(this->name, name);
// 	}
// 	void ShowYourName() const
// 	{
// 		cout<<"name: "<<name<<endl;
// 	}
// 	virtual int GetPay() const
// 	{
// 		return 0;
// 	}
// 	virtual void ShowSalaryInfo() const
// 	{  }
// };

// class PermanentWorker : public Employee
// {
// private:
// 	int salary;
// public:
// 	PermanentWorker(char * name, int money)
// 		: Employee(name), salary(money)
// 	{  }
// 	int GetPay() const
// 	{
// 		return salary;
// 	}
// 	void ShowSalaryInfo() const
// 	{
// 		ShowYourName();
// 		cout<<"salary: "<<GetPay()<<endl<<endl;
// 	}
// };

// class TemporaryWorker : public Employee
// {
// private:
// 	int workTime;
// 	int payPerHour;
// public:
// 	TemporaryWorker(char * name, int pay)
// 		: Employee(name), workTime(0), payPerHour(pay)
// 	{  }
// 	void AddWorkTime(int time)
// 	{
// 		workTime+=time;
// 	}
// 	int GetPay() const
// 	{
// 		return workTime*payPerHour;
// 	}
// 	void ShowSalaryInfo() const
// 	{
// 		ShowYourName();
// 		cout<<"salary: "<<GetPay()<<endl<<endl;
// 	}
// };

// class SalesWorker : public PermanentWorker
// {
// private:
// 	int salesResult;    // 월 판매실적
// 	double bonusRatio;    // 상여금 비율 
// public:
// 	SalesWorker(char * name, int money, double ratio)
// 		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
// 	{  }
// 	void AddSalesResult(int value)
// 	{
// 		salesResult+=value;
// 	}
// 	int GetPay() const
// 	{
// 		return PermanentWorker::GetPay()  
// 					+ (int)(salesResult*bonusRatio);
// 	}
// 	void ShowSalaryInfo() const
// 	{
// 		ShowYourName();
// 		cout<<"salary: "<<GetPay()<<endl<<endl;
// 	}
// };

// class EmployeeHandler
// {
// private:
// 	Employee* empList[50];
// 	int empNum;
// public:
// 	EmployeeHandler() : empNum(0) 
// 	{ }
// 	void AddEmployee(Employee* emp)
// 	{
// 		empList[empNum++]=emp;
// 	}
// 	void ShowAllSalaryInfo() const
// 	{
		
// 		for(int i=0; i<empNum; i++)
// 			empList[i]->ShowSalaryInfo();
		
// 	}
// 	void ShowTotalSalary() const
// 	{
// 		int sum=0;
		
// 		for(int i=0; i<empNum; i++)
// 			sum+=empList[i]->GetPay();
		
// 		cout<<"salary sum: "<<sum<<endl;
// 	}
// 	~EmployeeHandler()
// 	{
// 		for(int i=0; i<empNum; i++)
// 			delete empList[i];
// 	}
// };

// int main(void)
// {
// 	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
// 	EmployeeHandler handler;

// 	// 정규직 등록
// 	handler.AddEmployee(new PermanentWorker("KIM", 1000));
// 	handler.AddEmployee(new PermanentWorker("LEE", 1500));

// 	// 임시직 등록
// 	TemporaryWorker * alba=new TemporaryWorker("Jung", 700);
// 	alba->AddWorkTime(5);	// 5시간 일한결과 등록
// 	handler.AddEmployee(alba);

// 	// 영업직 등록
// 	SalesWorker * seller=new SalesWorker("Hong", 1000, 0.1);
// 	seller->AddSalesResult(7000);	// 영업실적 7000
// 	handler.AddEmployee(seller);

// 	// 이번 달에 지불해야 할 급여의 정보
// 	handler.ShowAllSalaryInfo();	

// 	// 이번 달에 지불해야 할 급여의 총합
// 	handler.ShowTotalSalary();
// 	return 0;
// }