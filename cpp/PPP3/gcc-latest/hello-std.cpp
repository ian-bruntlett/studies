/* hello-std.cpp

  compile with:
  make hello-std

 Whilst Bjarne Stroustrup likes to use this in his examples:
   using namespace std;
   
 I prefer not to do so. This is because in medium-sized programmes
 and larger, this can cause name collisions and headaches so I have to
 prefix names from the standard library with std::
*/ 

import std;

int main()
{ 
  std::cout << "System  : " ;
  std::flush(std::cout);
  std::system ("hostname");
  std::cout << "FILE    : "  __FILE__ " " __DATE__  " " __TIME__ "\n";
  
  std::cout << "gcc     : "  << __GNUC__ << '.'
                            << __GNUC_MINOR__ << '.'
                            << __GNUC_PATCHLEVEL__
	    << '\n';
  
  std::cout << "standard: " <<  __cplusplus << '\n';  
}
