inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
int D, i;
reset(arg){
D =40;
set_weight(1);
  set_value(100);
}
short(){ return "A quiver of arrows "+HIW+"["+HBYEL+""+HIW+""+D+""+NORM+""+HIW+"]"+NORM+""; }
long(){ write("This is a group of "+HIW+"["+HBYEL+""+HIW+""+D+""+NORM+""+HIW+"]"+NORM+" arrows bound together by a vine-tie.\nThese are arrows from the "+HIW+"("+HBYEL+""+BLINK+"Speed"+NORM+""+HIW+")"+NORM+" family.\n"); }
id(str){ return str == "quiver" || str == "S_quiver" || str == "arrows"; }
set_arrows(int i){
D += i;
if(D == 0){
write("You pull the last arrow from the "+HBYEL+""+BLINK+"Speed"+NORM+" quiver.\nThe "+HIG+"vine-tie"+NORM+" falls quietly to the ground.\n");
destruct(this_object());
return 1; }
}
query_save_flag(){      return 1;       }

