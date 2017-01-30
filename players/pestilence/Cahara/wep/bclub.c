#define tp this_player()->query_name()
int w, i;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+WHT+"bone"+NORM+" club");
  set_alias("bone");
  set_short("a "+WHT+"Bone"+NORM+" club ");
  set_long(
"This is a "+WHT+"bone"+NORM+" club made from a human femor bone.\n"
  );
  set_type("club");
  set_class(18);
  set_weight(5);
  set_value(2500);
  set_hit_func(this_object());
  message_hit=({
    ""+HIR+"evicerated"+NORM+"","",   
    ""+RED+"destroyed"+NORM+"","",
    ""+HIK+"devastated"+NORM+"","",
    ""+HIK+"smashed"+NORM+"","",
    ""+HIK+"crunched"+NORM+"","",
    ""+BLU+"grazed"+NORM+"","",
    ""+BLU+"skinned"+NORM+"","",
  });
}

weapon_hit(attacker){
int W;
W = random(40);
if(W>30)  {
  say(
  "A "+WHT+"Bone"+NORM+" club rips through flesh and "+WHT+"bone"+NORM+" spewing "+HIR+"blood"+NORM+" everywhere.\n");

  write(
  "You swing the "+WHT+"Bone"+NORM+" club ripping through flesh and "+WHT+"bone"+NORM+" spewing "+HIR+"blood"+NORM+" everywhere. \n");
  return (1+ random(3));
   }
return 0;
}

