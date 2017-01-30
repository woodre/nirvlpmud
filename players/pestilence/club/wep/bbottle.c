#define tp this_player()->query_name()
int w;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("broken beer bottle");
  set_alias("broken bottle");
  set_alt_name("beer bottle");
  set_short("Broken beer bottle");
  set_long(
"This is a broken beer bottle.  It has a very sharp edge on the one end.\n"+
"On the other end it still has the round part, which makes it very easy to\n"+
"hold.\n"
  );
  set_type("exotic");
  set_class(17);
  set_weight(2);
  set_value(3000);

  set_hit_func(this_object());

  message_hit=({
    ""+HIR+"gouged"+NORM+""," through the heart",  
    ""+RED+"eviscerated"+NORM+""," into small pieces",
    ""+HIK+"devastated"+NORM+""," into a pile of pulp",
    ""+HIK+"stabbed"+NORM+""," through the neck, causing "+HIR+"blood "+NORM+"to spew out",
    ""+HIK+"punctured"+NORM+"","'s right eye with the glass",
    ""+BLU+"slashed"+NORM+""," across the chest",
    ""+HIG+"skinned"+NORM+""," across the face",
  });
}

weapon_hit(attacker){
w = random(15);

if(w > 10){
write("You "+HIK+"visciously slash "+NORM+ attacker->query_name()+" into small pieces.\n");
say(tp+ ""+HIK+" visciously slashes "+NORM+ attacker->query_name()+" into small pieces.\n");
return 7;
}


}

id(str) { return str == "bottle" ||  str == "beer bottle" || str == "broken"  || str == "broken beer bottle" || str == "broken bottle"; } 
