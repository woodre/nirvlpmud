#define tp this_player()->query_name()
int w, i;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+BLU+"Leonardo's"+NORM+" katana");
  set_alias("katana");
  set_short(""+BLU+"Leonardo's"+NORM+" katana");
  set_long(
"This weapon is a curved, slender, single-edged blade with a squared guard\n"
  );
  set_type("katana");
  set_class(20);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
  message_hit=({
    ""+HIR+"EvIcErAtEd"+NORM+""," with the might katana", 
    ""+RED+"iMpAlEd"+NORM+"","'s lung with a mighty thrust"
    ""+HIK+"SlIcEd"+NORM+"","with a heftly slash",
    ""+RED+"sTaBbEd"+NORM+""," in the chest",
    ""+RED+"hItS"+NORM+""," with a decent blow",
    ""+BLU+"grazed"+NORM+""," with a slight attack",
    ""+BLU+"nicks"+NORM+""," with a pathetic attack",
  });
}

weapon_hit(attacker){
int W;
W = random(40);
if(W>30)  {
  say(
 BLU+"Leonardo's"+NORM+" katana rips through flesh spewing "+HIR+"blood"+NORM+" everywhere.\n");

  write(
YEL+"\n              .-.\n"+
YEL+"              | |"+NORM+HIK+"____________________________________________________\n"+NORM+
YEL+" _ _ _ _ _ _ _| |"+NORM+"                                                  "+HIR+".'`.\n"+NORM+
YEL+"|_|_|_|_|_|_|_| |"+NORM+HIK+"-mbfh-------------------------------------------"+HIR+".'****"+HIK+">\n"+NORM+
YEL+"              | |"+NORM+HIK+"_______________________________________________"+HIR+".'***.'\n"+NORM+
YEL+"              | |                                              "+HIR+" `**'\n"+NORM+
YEL+"              `-'                                             "+HIR+" .'*`.\n"+NORM+
"                                                              "+HIR+" `._.' .\n"+NORM+
"                                                             "+HIR+"  .   .'*`.\n"+NORM+
"                                                            "+HIR+" .'*`. `._.'\n"+NORM+
   "\n");
  return (1+ random(3));
   }
return 0;
}

