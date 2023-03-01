#include <random>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>

class RandomGenerator{
public:
  RandomGenerator() : m_engine(m_device()){}

  float operator() (float l_min, float l_max) {
    return Generate(l_min, l_max);
  }
  int operator()(int l_min, int l_max){
    return Generate(l_min, l_max);
  }

private:
  std::random_device m_device;
  std::mt19937 m_engine;
  std::uniform_int_distribution<int> m_intDistribution;
  std::uniform_real_distribution<float> m_floatDistribution;
  sf::Mutex m_mutex;

  int Generate(int l_min, int l_max) {
    sf::Lock lock(m_mutex);
  }
};
