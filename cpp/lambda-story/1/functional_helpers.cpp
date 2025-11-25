// functional_helpers.cpp
#include <algorithm>
#include <functional>
#include <vector>

int main() {
  std::vector<int> v;
  for (int i=1; i!=10; ++i)
    v.push_back(i);
  const size_t smaller5 = std::count_if(v.begin(), v.end(),
					std::bind2nd(std::less<int>(), 5));
  return smaller5;  
}  
