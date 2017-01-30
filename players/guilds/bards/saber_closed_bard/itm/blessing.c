/* 
 * Part of the Blessing spell of the Bards Guild of Ryllian.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

#include "/players/saber/closed/esc2.h"

#define RED ESC+"[31m"
#define NORM ESC+"[2;37;0m"

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("blessing_obj");
    call_out("heal_me", 30);
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

heal_me() {
object PLAYER;

say("check 1\n");

  if( (environment(this_object()->query_hp()) )
   <  (environment(this_object()->query_mhp() - 12) ) )  {
say("check 3\n");
    PLAYER = environment(this_object());
    
    tell_room(environment(PLAYER), "\n"+PLAYER->query_name()+
              "glows with a "+RED+"soft aura"+NORM+" of healing.\n\n");
    tell_object(PLAYER, "You feel the blessing of Crysea spread through your body.\n");
say("check 4\n");
    PLAYER->add_hit_point(12);
    remove_call_out("heal_me");
    destruct(this_object()); 
    return 1;
        }

say("check 2\n");
   call_out("heal_me", 30);
   return 1;

        }
