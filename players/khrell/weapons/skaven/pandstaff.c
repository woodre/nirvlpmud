#define tp this_player()->query_name()
int w;
#include "/players/khrell/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("pandemic staff");
  set_alias("staff");
  set_alt_name("pandemic");
  set_short(GRN+"Pand"+MAG+"emic "+YEL+"Staff"+NORM);
  set_long(
"  Seething with foul energies of pestilence, this staff, wielded by\n"+
"the favorite disciples of the Horned Rat, brings corruption and death\n"+
"to those unfortunate enough to be struck by it.\n");
  set_type("club");
  set_class(18);
  set_weight(4);
  set_value(4000);

  set_hit_func(this_object());

  message_hit=({
    ""+HIR+"S M A S H E D "+NORM+""," in the chest, breaking a few ribs",  
    ""+RED+"crushed"+NORM+""," cracking a few bones",
    ""+HIK+"bashed"+NORM+""," into a pile of pulp",
    ""+BLU+"bonked"+NORM+""," on the nose, drawing a trickle of "+HIR+"blood"+NORM+"",
    ""+HIB+"smacked"+NORM+""," upside the head",
    ""+GRN+"hit"+NORM+""," leaving a red mark",
    ""+HIG+"tapped"+NORM+""," on the shoulder",
  });
}

weapon_hit(attacker){
w = random(20);

   if(w > 8){
      write("You "+HIK+"violently beat "+NORM+ attacker->query_name()+" into a bloody pulply mess!\n");
      say(tp+ ""+HIK+" violently beats "+NORM+ attacker->query_name()+" into a bloody pulpy mess!\n");
   return 7;
   }
   
}   
