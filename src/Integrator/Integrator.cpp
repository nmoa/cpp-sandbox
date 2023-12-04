#include "Integrator.h"

void Integrator::reset(void) {
	m_itg = 0.0f;
}

float Integrator::calc(float rv_input) {
	m_itg += rv_input;
	return m_itg;
}

void Integrator::setValue(float rv_value) {
	m_itg = rv_value;
}
