#include "/players/wocket/closed/ansi.h"

move(str){
  write(get_emote());
  say("say->"+get_emote());
  return 7;
}

get_emote(){
string str;
 switch(7){
   case 0: str = "~*~ You sweep low slicing your enemy.\n"; break;
   case 1: str = "~*~ You sweep knocks your enemy to the ground.\n"; break;
   case 2: str = "~*~ You slice your enemies shine.\n"; break;
   case 3: str = "~*~ Pain flows as your sweep slice draws blood.\n"; break;
   case 4: str = "~*~ Your enemy falls as his leg can nolonger suppose his weight.\n"; break;
   case 5: str = "~*~ Blood runs down your enemies shines as a look of fear forms.\n"; break;
   case 6: str = "~*~ You twirl down slicing your enemies legs.\n"; break;
 }
  return str;
}
