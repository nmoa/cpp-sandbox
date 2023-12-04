#ifndef _WEIGHTEDAVERAGECALCULATORTEMPLATE_H_
#define _WEIGHTEDAVERAGECALCULATORTEMPLATE_H_

#include <cstddef>

template<typename T, std::size_t N>
class CWeightedAverageCalculator {
public:
	CWeightedAverageCalculator() : m_data(), m_weight{(1.0f / N), (1.0f / N), (1.0f / N)} {}
	explicit CWeightedAverageCalculator(const float rv_weight[]) : m_data() {
		for(std::size_t i = 0; i < N; i++) {
			m_weight[i] = rv_weight[i];
		}
	}
	virtual ~CWeightedAverageCalculator() {}

public:
	void reset(T rv_initial_value = 0) {
		for(std::size_t i = 0; i < N; i++) {
			m_data[i] = rv_initial_value;
		}
	}
	virtual float calc(void) {
		float at_average = 0.0f;
		for(std::size_t i = 0; i < N; i++) {
			at_average += m_data[i] * m_weight[i];
		}
		return at_average;
	}
	void add(T rv_input) {
		for(std::size_t i = N - 1; i > 0; i--) {
			m_data[i] = m_data[i - 1];
		}
		m_data[0] = rv_input;
	}

protected:
	T     m_data[N];
	float m_weight[N];
};

template<typename T, std::size_t N>
class CInversedWeightedAverageCalculator : public CWeightedAverageCalculator<T, N> {
public:
	CInversedWeightedAverageCalculator() : CWeightedAverageCalculator<T, N>() {}
	explicit CInversedWeightedAverageCalculator(const float rv_weight[]) : CWeightedAverageCalculator<T, N>(rv_weight) {}

public:
	float calc(void) {
		float at_average = 0.0f;
		for(std::size_t i = 0; i < N; i++) {
			at_average += this->m_weight[i] / this->m_data[i];
		}
		return at_average;
	}
};


#endif /* _WEIGHTEDAVERAGECALCULATORTEMPLATE_H_ */
