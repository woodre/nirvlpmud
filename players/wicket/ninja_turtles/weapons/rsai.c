inherit "obj/weapon.c";

#include "/players/pestilence/ansi.h"
#define tp this_player()->query_name()
int w, i;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+HIR+"Raphael"+NORM+"'"+HIR+"s"+NORM+" Sai");
  set_alias("sai");
  set_short(""+HIR+"Raphael"+NORM+"'"+HIR+"s"+NORM+" Sai");
  set_long(
"This weapon is a well balanced, slender, sharp-pointed tip with a leather grip\n"
  );
  set_type("small");
  set_class(20);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
  message_hit=({
    ""+HIR+"EvIcErAtEd"+NORM+""," with the mighty sai", 
    ""+RED+"iMpAlEd"+NORM+"","'s lung with a mighty stab",
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
if(W>22)  {
  say(
 HIR+"Raphael"+NORM+"'"+HIR+"s"+NORM+" sai pierces through flesh spewing "+HIR+"blood"+NORM+" everywhere.\n");

  write( 
RED+"     |\\     (( ))       \n"+NORM+
RED+"     |:|     III        \n"+NORM+
RED+"     |:|     III        \n"+NORM+
RED+"     |:|     III        \n"+NORM+
RED+"     |:|   __III__      \n"+NORM+ 
RED+"     |:| /:-.___,-:\\    \n"+NORM+
RED+"     |:| \\]  |:|  [/    \n"+NORM+
RED+"     |:|     |:|        \n"+NORM+
RED+"     |:|     |:|        \n"+NORM+
RED+"     |:|     |:|        \n"+NORM+
RED+" /]  |:|  [\\ |:|        \n"+NORM+ 
RED+" \\:-<<>>`-:/ |:|        \n"+NORM+
RED+"     III     |:|        \n"+NORM+
RED+"     III     |:|        \n"+NORM+
RED+"     III     |:|        \n"+NORM+
RED+"     III     |:|        \n"+NORM+
RED+"    (( ))     \\| "+NORM+"J:F/J:L Krogg\n"+NORM+ 
       "\n");
  return (1+ random(3));
   }
return 0;
}

