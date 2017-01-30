/*
 *  A weapon for the Bardic Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/weapon.c";

#include "/players/saber/closed/esc2.h"
#define BOLD ESC+"[1m"
#define NORM ESC+"[2;37;0m"

reset(arg) {
    ::reset();
    if (arg) return;

    set_name("storm dagger");
    set_alias("dagger");
    set_short("A "+BOLD+"storm"+NORM+" dagger");
    set_long("A translucent gray dagger of gleaming storm crystal.\n"+
             "It's weight is like the wind, and it has an edge like lightning.\n"+
              "On the hilt are both the "+BOLD+"Rune of Crysea"+NORM+" and the "+
              BOLD+"Bardic Rune"+NORM+".\n");
    set_class(13);
    set_weight(0);
    set_value(100);
    set_hit_func(this_object());

        }

weapon_hit(attacker){
  if(this_player()->query_guild_name() == "bards")  {
    if(this_player()->query_attrib("mag") > random (40))  {
      say("The storm dagger flashes with lightning.\n");
      write("The storm dagger flashes with lightning.\n");
    return 3;
        }
        }
    return;
        }
