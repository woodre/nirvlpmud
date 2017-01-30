/*
 *    The spider dagger carried by the Priestess of Arate.
 */

#define tp this_player()->query_name()
#define CAP capitalize(attacker->query_name())
#define OBJ this_player()->query_objective()
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

int w;
object poison;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("spider dagger");
    set_alias("dagger");
    set_type("dagger");         /* set type added by Pavlik */
    set_short("A spider dagger of Arate");
    set_long("A cold steel dagger forged to resemble a spider.\n"+
             "It has eight legs, each of which descend into blades.\n"+
             "The dagger is covered with "+BOLD+"runes"+NORM+" of evocation.\n");
    set_read("The runes are of evocation.  They will make the dagger hit harder.\n");
    set_class(18);
    set_weight(2);
    set_value(1500);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(30);
   
   if(w< 1)  {
     write("\nYou feel a sharp pain as the dagger animates and "+
              HIM+"bites"+NORM+" you!\n\n");
     say(tp+"'s dagger animates and bites "+OBJ+".\n");
     poison = clone_object("/players/saber/closed/poison.c");
     move_object(poison, environment(this_object()));
        }
     
   if(w>20)    {
     write("You sink the 8 leg-blades of the spider dagger deep into "+CAP+".\n");
     say(tp+" sinks the 8 leg-blades of the spider dagger deep into "+CAP+".\n");
   if(w > 25)  {
     write("The spider animates and "+HIM+"bites"+NORM+" "+CAP+".\n");
     say("The spider animates and "+HIM+"bites"+NORM+" "+CAP+".\n");
               }

   if(w > 25) { return 8; } else { return 5; }
        }
          
      return;
        }
