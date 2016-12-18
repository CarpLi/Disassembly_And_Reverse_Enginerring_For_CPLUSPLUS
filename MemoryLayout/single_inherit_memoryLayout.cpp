
/*
1>  class Base	size(12):
1>  	+---
1>   0	| {vfptr}
1>   4	| a
1>   8	| b
1>  	+---
1>
1>  Base::$vftable@:
1>  	| &Base_meta
1>  	|  0
1>   0	| &Base::VirtualFunction
*/
class Base
{
public:
	int a;
	int b;
public:
	void CommonFunction();
	virtual void VirtualFunction();
};

/*
1>
1>  class DerivedClass	size(16):
1>  	+---
1>   0	| +--- (base class Base)
1>   0	| | {vfptr}
1>   4	| | a
1>   8	| | b
1>  	| +---
1>  12	| c
1>  	+---
1>
1>  DerivedClass::$vftable@:
1>  	| &DerivedClass_meta
1>  	|  0
1>   0	| &DerivedClass::VirtualFunction
1>
*/
class DerivedClass :public Base
{
public:
	int c;

public:
	void DerivedCommonFunction();

	virtual void VirtualFunction();
};

/*
1>  class DerivedClass1	size(16):
1>  	+---
1>   0	| +--- (base class Base)
1>   0	| | {vfptr}
1>   4	| | a
1>   8	| | b
1>  	| +---
1>  12	| c
1>  	+---
1>
1>  DerivedClass1::$vftable@:
1>  	| &DerivedClass1_meta
1>  	|  0
1>   0	| &Base::VirtualFunction
1>   1	| &DerivedClass1::VirtualFunction2
1>
*/
class DerivedClass1 : public Base
{
public:
	int c;

public:
	void DerivedCommonFunction();
	virtual void VirtualFunction2();
};


/*
1>
1>  class DerivedClass2	size(16):
1>  	+---
1>   0	| +--- (base class Base)
1>   0	| | {vfptr}
1>   4	| | a
1>   8	| | b
1>  	| +---
1>  12	| c
1>  	+---
1>
1>  DerivedClass2::$vftable@:
1>  	| &DerivedClass2_meta
1>  	|  0
1>   0	| &DerivedClass2::VirtualFunction
1>   1	| &DerivedClass2::VirtualFunction2
1>
*/
class DerivedClass2 : public Base
{
public:
	int c;

public:
	void DerivedCommonFunction();
	virtual void VirtualFunction();
	virtual void VirtualFunction2();
};
