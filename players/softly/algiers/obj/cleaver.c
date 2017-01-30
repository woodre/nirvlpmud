#include "/players/softly/closed/ansi.h"
 inherit "/obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("meat cleaver");
    set_alias("cleaver");
    set_short("A meat cleaver");
    set_long("A wood handled well-worn meat cleaver with a strong blade,\n"+
             "the handle is grooved from years of being held by generations\n"+
	     "of strong church ladies.  The blade is 4 inches wide.\n");
    set_type("knife");
    set_class(15);
    set_weight(2);
    set_value(500);
    set_hit_func(this_object());

  message_hit=({
    "ripped","",   
    "hacked","",
    "gored","",
    "slashed","",
    "tore","",
    "sliced","",
    "cut","",
  });
  return;
}

weapon_hit(attacker){

int X;
  X = random(8);
  if(X > 5){
    say  ("The cleaver easily glides through you. "+HIR+" Bloody"+NORM+"\n"+
          "pieces of your flesh fly through the room.\n");
    write("The cleaver slips through flesh and"+HIR+" bloody"+NORM+" bits\n"+
          "of flesh fly in all directions.\n");
   return 3;
  }
}
