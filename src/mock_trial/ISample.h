#ifndef _ISAMPLE_H_
#define _ISAMPLE_H_

class ISample {
public:
	virtual int SampleMethod1(int lhs)          = 0;
	virtual int SampleMethod2(int lhs, int rhs) = 0;
};


#endif /* _ISAMPLE_H_ */
