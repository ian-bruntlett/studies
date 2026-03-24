/* greetings.cpp
   
   compile with:
   make greetings

Sources:
https://en.cppreference.com/w/cpp/utility/source_location.html
https://en.cppreference.com/w/cpp/io/println.html

 Whilst Bjarne Stroustrup likes to use this in his examples:
   using namespace std;
   
 I prefer not to do so. This is because in medium-sized programmes
 and larger, this can cause name collisions and headaches so I have to
 prefix names from the standard library with std::
*/ 

import std;

int main()
{ 
  std::source_location here = std::source_location::current();
  std::println("Greetings from {}, function {} @ {}:{}",
	       here.file_name(), 
	       here.function_name(),
	       here.line(),
	       here.column()
	       );  
}
