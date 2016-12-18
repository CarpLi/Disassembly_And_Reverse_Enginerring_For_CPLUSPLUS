
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
1>  class DerivedClass1	size(20):
1>  	+---
1>   0	| {vbptr}
1>   4	| c
1>  	+---
1>  	+--- (virtual base Base)
1>   8	| {vfptr}
1>  12	| a
1>  16	| b
1>  	+---
1>
1>  DerivedClass1::$vbtable@:
1>   0	| 0
1>   1	| 8 (DerivedClass1d(DerivedClass1+0)Base)
1>
1>  DerivedClass1::$vftable@:
1>  	| -8
1>   0	| &DerivedClass1::VirtualFunction
1>
1>  DerivedClass1::VirtualFunction this adjustor: 8
1>  vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>              Base       8       0       4 0
*/
class DerivedClass1 : virtual public Base
{
	int c;
public:
	void DerivedCommonFunction();
	virtual void VirtualFunction();
};

/*
1>
1>  class DerivedClass2	size(20):
1>  	+---
1>   0	| {vbptr}
1>   4	| c
1>  	+---
1>  	+--- (virtual base Base)
1>   8	| {vfptr}
1>  12	| a
1>  16	| b
1>  	+---
1>
1>  DerivedClass2::$vbtable@:
1>   0	| 0
1>   1	| 8 (DerivedClass2d(DerivedClass2+0)Base)
1>
1>  DerivedClass2::$vftable@:
1>  	| -8
1>   0	| &DerivedClass2::VirtualFunction
1>
1>  DerivedClass2::VirtualFunction this adjustor: 8
1>  vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>              Base       8       0       4 0
1>
*/
class DerivedClass2 : virtual public Base
{
	int c;
public:
	void DerivedCommonFunction();
	virtual void VirtualFunction();
};


/*
1>
1>  class DerivedDerivedClass	size(32):
1>  	+---
1>   0	| +--- (base class DerivedClass1)
1>   0	| | {vbptr}
1>   4	| | c
1>  	| +---
1>   8	| +--- (base class DerivedClass2)
1>   8	| | {vbptr}
1>  12	| | c
1>  	| +---
1>  16	| e
1>  	+---
1>  	+--- (virtual base Base)
1>  20	| {vfptr}
1>  24	| a
1>  28	| b
1>  	+---
1>
1>  DerivedDerivedClass::$vbtable@DerivedClass1@:
1>   0	| 0
1>   1	| 20 (DerivedDerivedClassd(DerivedClass1+0)Base)
1>
1>  DerivedDerivedClass::$vbtable@DerivedClass2@:
1>   0	| 0
1>   1	| 12 (DerivedDerivedClassd(DerivedClass2+0)Base)
1>
1>  DerivedDerivedClass::$vftable@:
1>  	| -20
1>   0	| &DerivedDerivedClass::VirtualFunction
1>
1>  DerivedDerivedClass::VirtualFunction this adjustor: 20
1>  vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>              Base      20       0       4 0
*/
class DerivedDerivedClass : public DerivedClass1, public DerivedClass2
{
	int e;
public:
	void DerivedDerivedCommonFunction();
	virtual void VirtualFunction();
};