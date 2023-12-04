#ifndef _SAMPLECONCRETE_H_
#define _SAMPLECONCRETE_H_

#include "ISample.h"

class SampleConcrete : public ISample {
	// class SampleConcrete {
public:
	SampleConcrete();
	~SampleConcrete();
	int        SampleMethod1(int lhs);
	int        SampleMethod2(int lhs, int rhs);
	static int StaticMethod(int lhs);
};


#endif /* _SAMPLECONCRETE_H_ */
