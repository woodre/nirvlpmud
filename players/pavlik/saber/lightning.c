/*
 *    The lightning bolt carried by the lightning elemental.
 *
 */

#define tp this_player()->query_name()
#define CAP capitalize(attacker->query_name())
#define POSS this_player()->query_possessive()
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int w;

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("lightning");
    set_alias("bolt");
    set_type("lightning");         /* set type added by Pavlik */
    set_short("A Bolt of Lightning");
    set_long("A softly "+HIY+"glowing"+NORM+" bolt of lightning.\n"+
             "It looks like it would make an incredible weapon.\n");
    set_class(21);
    set_weight(1);
    set_value(3000);
    set_save_flag(1);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(20);
   
   if(w< 1)  {
     write("You feel a shock as the bolt of lightning surges out of control!\n");
     say(tp+" is shocked by backlash from "+POSS+" bolt of lightning.\n");
     this_player()->heal_self(-random(6));
        }
     
   if(w>14)  {
     write("You shock your foe with a mightly bolt of lightning.\n"+
       ""+CAP+" is covered in a raging storm of "+HIY+"electric"+NORM+" currents.\n");
     say(tp+" fries "+CAP+" with a mighty bolt of bright white lightning.\n"+
       ""+CAP+" is covered in a raging storm of "+HIY+"electric"+NORM+" currents.\n");
      return 6;
        }
          
      return;
        }

quest_ob()  { return 1; }
