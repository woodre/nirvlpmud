inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
int A, i;
reset(arg){
A =36;
set_weight(1);
  set_value(100);
}
short(){ return "A quiver of arrows ["+A+"]"; }
long(){ write("This is a quiver of ["+A+"] arrows bound together by a vine-tie.\nThese are a normal quiver of arrows.\n"); }
id(str){ return str == "quiver" || str == "N_quiver" || str == "arrows"; }
set_arrows(int i){
A += i;
if(A == 0){
write("You pull the last arrow from the quiver.\nThe "+HIG+"vine-tie"+NORM+" falls quietly to the ground.\n");
destruct(this_object());
return 1; }
}
query_save_flag(){      return 1;       }

