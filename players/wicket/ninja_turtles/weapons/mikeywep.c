inherit "obj/weapon.c";

#include "/players/pestilence/ansi.h"
#define tp this_player()->query_name()
int w, i;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+YEL+"Michelangelo"+NORM+"'"+YEL+"s"+NORM+" Nunchakus");
  set_alias("nunchakus");
  set_short(""+YEL+"Michelangelo"+NORM+"'"+YEL+"s"+NORM+" Nunchakus");
  set_long(
"This weapon is a well balanced, chains hold the weapon together, they are very solid and deadly\n"
  );
  set_type("small");
  set_class(20);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
  message_hit=({
    ""+HIR+"AnNHiLaTeS"+NORM+""," with the mighty nunchakus", 
    ""+RED+"CrUsHeD"+NORM+"","'s lung with a mighty thrust",
    ""+HIK+"WhAcKeD"+NORM+"","with a heftly swing",
    ""+RED+"CrAcKs"+NORM+""," in the chest",
    ""+RED+"hItS"+NORM+""," with a decent blow",
    ""+BLU+"grazed"+NORM+""," with a slight attack",
    ""+BLU+"BoNkS"+NORM+""," with a pathetic attack",
  });
}

weapon_hit(attacker){
int W;
W = random(40);
if(W>22)  {
  say(
 YEL+"Michelangelo"+NORM+"'"+YEL+"s"+NORM+" nunchakus crushes through flesh and bone spewing "+HIR+"blood"+NORM+" everywhere.\n");

  write(
HIR+"\n                 C - R - A - C - K                                \n"+NORM+
YEL+"\n  ()))))))))))))"+HIK+"-O-o-O-o-O-"+NORM+YEL+")))))))))))))            \n"+NORM+
HIR+"\n                 W - O - O - S - H                                \n"+NORM+
YEL+"\n               ()))))))))))))"+HIK+"-O-o-O-o-O-"+NORM+YEL+")))))))))))))\n"+NORM+ 
HIR+"\n                 W - H - A - C - K                                \n"+NORM+

   "\n");
  return (1+ random(3));
   }
return 0;
}

