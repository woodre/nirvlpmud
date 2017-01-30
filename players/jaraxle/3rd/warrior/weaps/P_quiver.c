inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
int C, i;
reset(arg){
C =20;
set_weight(1);
  set_value(100);
}
short(){ return "A quiver of arrows "+HIW+"["+BLK+""+BOLD+""+C+""+HIW+"]"+NORM+""; }
long(){ write("This is a group of "+HIW+"["+BLK+""+C+""+HIW+"]"+NORM+" arrows bound together by a vine-tie.\nThese are arrows from the "+HIW+"("+BOLD+""+BLK+"Po"+HIR+"W"+BLK+""+BOLD+"er"+HIW+")"+NORM+" family.\n"); }
id(str){ return str == "quiver" || str == "P_quiver" || str == "arrows"; }
set_arrows(int i){
C += i;
if(C == 0){
write("You pull the last arrow from the "+BOLD+""+BLK+"Po"+HIR+"W"+BLK+""+BOLD+"er"+NORM+" quiver.\nThe "+HIG+"vine-tie"+NORM+" falls quietly to the ground.\n");
destruct(this_object());
return 1; }
}
query_save_flag(){      return 1;       }

