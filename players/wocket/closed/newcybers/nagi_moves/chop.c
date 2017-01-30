#include "/players/wocket/closed/ansi.h"

move(belt,str,sta){
int ret;
 ret = (str)+(sta/2);
 ret = random(ret);
 ret = (belt+ret)/2;
 ret = random(ret); 
 return ret;
}

get_emote(i){
string str;
switch(i){
  case 1..2:   str = "~*~ You chop down with your naginata.\n"; break;
  case 3..6:   str = "~*~ You chop, knocking your enemy to the ground.\n"; break;
  case 7..8:   str = "~*~ You chop your enemies shin.\n"; break;
  case 9..10:  str = "~*~ Pain flows as your chop slice draws blood.\n"; break;
  case 11..12: str = "~*~ Your enemy falls as his leg can no longer suppose his weight.\n"; break;
  case 13..14: str = "~*~ Blood runs down your enemies shines as a look of fear forms.\n"; break;
  case 15..16: str = "~*~ You twirl down slicing your enemies legs.\n"; break;
}
return str;
}
