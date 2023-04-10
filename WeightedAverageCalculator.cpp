#include <cstddef>

class CWeightedAverageCalculator {
public:
	static const int c_order = 3;

public:
	CWeightedAverageCalculator();
	explicit CWeightedAverageCalculator(const float rv_weight[]);
	~CWeightedAverageCalculator(){};

public:
	void  reset(int rv_initial_value = 0);
	float calc(int rv_input);

private:
	/* data */
	int   m_data[c_order];
	float m_weight[c_order];
};

CWeightedAverageCalculator::CWeightedAverageCalculator() :
    m_data(),
    m_weight({1.0f / static_cast<float>(c_order), 1.0f / static_cast<float>(c_order), 1.0f / static_cast<float>(c_order)}) {}

CWeightedAverageCalculator::CWeightedAverageCalculator(const float rv_weight[]) : m_data() {
	for(std::size_t i = 0; i < c_order; i++) {
		m_weight[i] = rv_weight[i];
	}
}

void CWeightedAverageCalculator::reset(int rv_initial_value = 0) {
	for(std::size_t i = 0; i < c_order; i++) {
		m_data[i] = rv_initial_value;
	}
}

float CWeightedAverageCalculator::calc(int rv_input) {
	for(std::size_t i = c_order - 1; i > 0; i--) {
		m_data[i] = m_data[i - 1];
	}
	m_data[0] = rv_input;

	float at_average = 0.0f;
	for(std::size_t i = 0; i < c_order; i++) {
		at_average += m_data[i] * m_weight[i];
	}
	return at_average;
}
