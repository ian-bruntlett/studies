// composing_functional_helpers.cpp

#include <algorithm>
#include <functional>
#include <vector>

int main() {
  using std::placeholders::_1;

  std::vector<int> v;
  for (int i=1; i!=10; ++i)
    v.push_back(i);

  const size_t val = std::count_if(v.begin(), v.end(),
				  std::bind(std::logical_and<bool>(),
					    std::bind(std::greater<int>(),_1,2),
					    std::bind(std::less_equal<int>(),_1, 6)));
  return val;
}
