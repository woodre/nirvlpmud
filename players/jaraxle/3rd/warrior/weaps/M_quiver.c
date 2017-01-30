inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
int B, i;
reset(arg){
B =24;
set_weight(1);
  set_value(100);
}
short(){ return "A quiver of arrows "+HIY+"["+MAG+""+BOLD+""+B+""+HIY+"]"+NORM+""; }
long(){ write("This is a group of "+HIY+"["+MAG+""+BOLD+""+B+""+HIY+"]"+NORM+" arrows bound together by a vine-tie.\nThese are arrows from the "+HIY+"("+HIM+"Magical"+HIY+")"+NORM+" family.\n"); }
id(str){ return str == "quiver" || str == "M_quiver" || str == "arrows"; }
set_arrows(int i){
B += i;
if(B == 0){
write("You pull the last arrow from the "+HIM+"Ma"+HIY+"g"+HIM+"ical"+NORM+" quiver.\nThe "+HIG+"vine-tie"+NORM+" falls quietly to the ground.\n");
destruct(this_object());
return 1; }
}
query_save_flag(){      return 1;       }

