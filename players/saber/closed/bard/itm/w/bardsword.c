/*
 *  A weapon for the Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()
#define ENV environment(this_object())
#define ATTACKER capitalize(attacker->query_real_name())

inherit "obj/weapon.c";

int w;

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("bardsword");
    set_alias("sword");
    set_alt_name("storm sword");
    set_short("A "+BOLD+"Storm-Crystal"+NORM+" Bardsword");
    set_long( "An translucent grey longsword of gleaming storm crystal.\n"+
              "It's weight is like the wind, and it has an edge like lightning.\n"+
              "On the hilt is both the "+BOLD+"Rune of Crysea"+NORM+" and the "+
              BOLD+"Bardic Rune"+NORM+".\n");
    set_read( "The blade was forged for the Bards Guild of Ryllian by Saber.\n");
    set_class(16);
    set_weight(2);
    set_value(1000);
    set_hit_func(this_object());
        }

weapon_hit(attacker){

  w=random(90);

  if(w < 30)  {

 if(this_player()->query_guild_name() == "bard")  {
    
      write("The Bardsword gleams with "+
            BOLD+"Stormfire"+NORM+" as it cleaves through your foe.\n");
     say(tp+"'s Bardsword gleams with "+BOLD+"Stormfire"+NORM+" as "+
         this_player()->query_pronoun()+" cleaves through "+
         this_player()->query_possessive()+" foe.\n");
 
     return 5;
        }
        }
        }
