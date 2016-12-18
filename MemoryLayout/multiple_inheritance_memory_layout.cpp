class Base
{
public:
	int a;
	int b;
public:
	void CommonFunction();
	virtual void VirtualFunction();
};

class DerivedClass1 : public Base
{
public:
	int c;
public:
	void DerivedCommonFunction();
	virtual void VirtualFunction();
};


class DerivedClass2 : public Base
{
public:
	int d;
public:
	void DerivedCommonFunction();
	virtual void VirtualFunction();
};

/*
1>  class DerivedDerivedClass	size(36):
1>  	+---
1>   0	| +--- (base class DerivedClass1)
1>   0	| | +--- (base class Base)
1>   0	| | | {vfptr}
1>   4	| | | a
1>   8	| | | b
1>  	| | +---
1>  12	| | c
1>  	| +---
1>  16	| +--- (base class DerivedClass2)
1>  16	| | +--- (base class Base)
1>  16	| | | {vfptr}
1>  20	| | | a
1>  24	| | | b
1>  	| | +---
1>  28	| | d
1>  	| +---
1>  32	| e
1>  	+---
1>
1>  DerivedDerivedClass::$vftable@DerivedClass1@:
1>  	| &DerivedDerivedClass_meta
1>  	|  0
1>   0	| &DerivedDerivedClass::VirtualFunction
1>
1>  DerivedDerivedClass::$vftable@DerivedClass2@:
1>  	| -16
1>   0	| &thunk: this-=16; goto DerivedDerivedClass::VirtualFunction
1>
*/
class DerivedDerivedClass : public DerivedClass1, public DerivedClass2
{
	int e;
public:
	void DerivedDerivedCommonFunction();
	virtual void VirtualFunction();

};