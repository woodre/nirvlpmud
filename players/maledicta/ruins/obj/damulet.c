#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("amulet");
set_short(""+BOLD+""+RED+"Amulet"+NORM+" [glowing]");
set_long(
  "  Upon closer look you see that the amulet is made from\n"+
  "some type of red crystal. Even from a distance you feel\n"+
  "evil seeping from it, as if clawing outward to try and\n"+
  "get to you.\n");

set_ac(1);
set_type("amulet");
set_weight(1);
set_value(50);
set_arm_light(1);
}

wear(str){
if(!present(this_object(), this_player())) return 0;
if(!id(str)) return 0;
  write("You attempt to wear the amulet....\n\n");
  write("A bright flash of light erupts from your mind as you place\n");
  write("it on your neck! You feel a "+RED+"Searing Heat"+NORM+" as the amulet\n");
  write("attempts to take over your mind!\n");
  move_object(this_object(), environment(this_player()));
  write("Luckily it was meant only for the "+BOLD+""+BLK+"ShadowManes"+NORM+" and");
  write(" is completely\n"+
        "incompatible to your race.\n");
  write("You drop the amulet to the ground, your neck now red from the burning heat.\n");
move_object(this_object(), environment(this_player()));
  this_player()->hit_player(20);
  return 1;
  }      	   
		
