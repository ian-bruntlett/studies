/* hello-ppp3.cpp
   Programme to use some of PPP3's code - in this case,
   a checked string which will complain at runtime when
   abused.

  compile with:
  make hello-ppp3
   
   
 Bjarne Stroustrup likes to use this in PPP.h:
   using namespace PPP;
   using namespace std;
   
 This makes code easier for a novice reader.

 I prefer not to do so. This is because in medium-sized programmes
 and larger, this can cause name collisions and headaches.

 However, PPP.h is used by this program which means I can write
 cout instead of std::cout. 
*/


#include "PPP.h" // Use Bjarne's PPP3 tutorial module

int main()
{
  cout << "Hello from : "  __FILE__ "\n";

  // this line use's Bjarne's PPP::Checked_string because
  // PPP.h does this preprocessor trickery:
  // #define string Checked_string

  string astring="Hello\n";

  cout << astring;
  cout << "About to get a deliberate runtime error\n";
  // get a runtime error, to show that PPP::Checked_string is working.
  astring[100]='!'; // bang! deliberately exceed the string's text
}
