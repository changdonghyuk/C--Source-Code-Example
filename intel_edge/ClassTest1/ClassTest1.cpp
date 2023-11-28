#include <iostream>
class AAA
{
private:
	int a1;
protected:
	int a2;
public: 
	int a3;
	
	AAA() { printf(" A \n"); }
	~AAA() { printf(" ~A \n"); }
		

	void name()
	{
		printf(" 클래스 이름 = AAA \n");
	}
};

class BBB : public AAA
{

public:

	int b1;
	int b2;
	int b3;
	
	BBB() { printf(" B\n"); a3 = 10; }  // 메인 출력이 되고
	~BBB() { printf(" ~B\n"); } // 메인 출력 printf( "B"); 출력이 되는순간 ,  ~BBB 소멸자가 바로 실행된다 
	

	//void test() { printf("a1 = %d a2 = %d a3 = %d \n", a1, a2, a3); }
void name()
	{
		printf(" 클래스 이름 = BBB \n");
	}
};

class C
{
public:
	C() 
	{ 
		printf("_C_\n");
	}
	
	virtual void func() const=0
	{}
};

class C1 : public C
{
public:
		C1()
	{
		printf("_C1_\n");
	}

	virtual void func() const=0
	{
		printf("Func in c1\n");
	}

};
void func1()
{
	printf("호출 함수 시작\n");
	
	AAA *a = new AAA();
	a->name();

//	BBB *b = new BBB();
	//b->name();
	
	//((AAA*)b)->name();
	
	BBB* b = (BBB*)a;  //강제 캐스팅 으로 상위 a 클래스에 상속받은 b클래스를 잡고 2개의 함수 오버로딩으로 선택 클래스 a-> 를 name 으로 설정으로하고 //  49행 위 문법과 같은 값으로 출력 ( 이런방법 저런방법)
	b->name();

	{ printf("b1=%d\n",((BBB*)a)->b1); }  // 강제 캐스팅으로 a-> 가르킨 걸 ((AAA*)b)-> a3 을 출력 
	printf("호출 함수 종료\n");
	delete a;
	//delete b;

}

void func()
{
	printf("호출 함수 시작\n");

	//AAA *a = new AAA();


	BBB* b = new BBB();
	b->name();

	//((AAA*)b)->name();

	AAA* a = (AAA*)b;  //a클래스의  //  49행 위 문법과 같은 값으로 출력 ( 이런방법 저런방법)
	a->name();

	{ printf("a1 = %d a2 = %d a3 = %d \n", ((AAA*)b)->a3); }  // 강제 캐스팅으로 a-> 가르킨 걸 ((AAA*)b)-> a3 을 출력 
	printf("호출 함수 종료\n");
	//delete a;
	delete b;
}
void showN()
{}

int main()
{
//	printf("프 로 그 램 시_작\n");
//	//AAA a ;// 클래스 AAA  메인변수 a  뒤 printf( "A" ); 호출됨 
//	BBB b ;
//	func();
////	func1();
//	/*AAA p_a = new AAA;
//	p_a->showN();
//	 delete p_a;*/
//	printf(" 프 로 그 램 종_료\n");
//	/*a.name();
//	b.name();*/
//

	C c;
	C1 c1;
	c1 .func();


}
