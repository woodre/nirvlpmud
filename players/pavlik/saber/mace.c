/*
 *    A mace carried by priests of Arate.
 */

#define tp this_player()->query_name()
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int w;

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("unholy mace");
    set_alias("mace");
    set_type("mace");         /* set type added by Pavlik */
    set_short("A dark iron mace");
    set_long("A large dark iron mace.\n"+
             "It is covered with runes of praise to Arate.\n");
    set_class(16);
    set_weight(3);
    set_value(500);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(20);
        
   if(w<4)  {
     write("The runes on the your mace glow dark "+HIM+"purple"+NORM+".\n");
     say("The runes on "+tp+"'s mace glow dark "+HIM+"purple"+NORM+".\n");
      return 9;
        }        
      return;
        }
