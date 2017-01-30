/* silencer for my ftell */

#include "/players/forbin/define.h"

status id(string str) { return str == "please_leave_me_the_FuCK_AlONe" || str == "silencer"; }

string short() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) 
  return HIW+"=~= BLISSFUL SILENCE =~="+NORM;
}
