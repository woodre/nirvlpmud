#include "/players/fakir/color.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("circle");
   set_long(
   "   You can no longer see the circle of glass, but somehow, it\n"+
   "bonded itself to your very soul...and your eyes now gleam with\n"+
   "a pale-green lucent light.\n");
   set_weight(0);
   set_value(0);
   set_light(2);
}

extra_look() {
return this_player()->query_name()+"'s eyes "+BOLD+GREEN+"glow"+OFF+" with a pale gleam.\n";
}
drop(){
write("You cannot drop something that is bonded to your soul.\n"); 
return 1;
}