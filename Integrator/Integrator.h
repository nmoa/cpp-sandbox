#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

class Integrator {
public:
	Integrator() : m_itg(0){};
	void  reset(void);
	float calc(float rv_input);
	void  setValue(float rv_value);

private:
	float m_itg;
};

#endif /* _INTEGRATOR_H_ */
