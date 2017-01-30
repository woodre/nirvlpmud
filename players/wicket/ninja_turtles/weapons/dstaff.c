inherit "obj/weapon.c";

#include "/players/pestilence/ansi.h"
#define tp this_player()->query_name()
int w, i;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+MAG+"Donatello"+NORM+"'"+MAG+"s"+NORM+" Bo Staff");
  set_alias("staff");
  set_short(""+MAG+"Donatello"+NORM+"'"+MAG+"s"+NORM+" Bo Staff");
  set_long(
"This weapon is a well balanced, slender, wooden polearm with with a leather grip\n"
  );
  set_type("blunt");
  set_class(20);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
  message_hit=({
    ""+HIR+"AnNHiLaTeS"+NORM+""," with the mighty bo staff", 
    ""+RED+"iMpAlEd"+NORM+"","'s lung with a mighty thrust",
    ""+HIK+"WhAcKeD"+NORM+"","with a heftly swing",
    ""+RED+"CrUsHeS"+NORM+""," in the chest",
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
 MAG+"Donatello"+NORM+"'"+MAG+"s"+NORM+" staff crushes through flesh and bone spewing "+HIR+"blood"+NORM+" everywhere.\n");

  write(
YEL+"\n  ())))))))))))))))))))))))))))"+WHT+"[///////]"+YEL+")))))))))))))))))))))))))))))            \n"+NORM+

   "\n");
  return (1+ random(3));
   }
return 0;
}

