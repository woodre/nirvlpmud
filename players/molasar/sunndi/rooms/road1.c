
/*
 * sunndi_road1.c
 *
 * Road to Sunndi
 *
 */


/* Inherit standard room */
inherit "/std/room";

/* Local include files */
#include "/players/molasar/sunndi/include/sunndi.h"
#include "/players/molasar/sunndi/include/filter_color.h"
#include "/players/molasar/sunndi/include/global_cmds.h"

#define MOBS 3

int align = 0;

init() {
   ::init();
   global_init();
}

reset(arg) {

   align = query_sunndi_alignment();
   if (query_sunndi_debug())
      log_debug("Sunndi Alignment: " + align);

   if(arg) {
      set_long(get_sunndi_long(align) + "\n");
      if (query_sunndi_debug())
         log_debug("Room Reset");
      return 1;
   }

   set_short(filter_color("Sunndi Road",HIC));
   set_long(get_sunndi_long(align) + "\n");
   set_light(1);
   set_dest_dir(
      ({
         "/players/molasar/sunndi/rooms/road2","south",
         "/room/sunalley2","north",
      })
   );

   /*
    * If sunndi_alignment >= 0, then we're controlled by the good guys.
    * Clone a guard post and guards.
    *
    */
    
   if (align >= 0) 
      setup_guards();
   else 
      setup_bandits();

}

setup_guards() {

   if(!present("guard post")) {
      object guardpost;
      guardpost = clone_object("/players/molasar/sunndi/obj/guard_post");
      move_object(guardpost, this_object());
   }

   /* Only clone a guard if the guard post is present */
   if(present("guard post") && !present("guard")) {
      object guard;
      int i;
      while(i < 3) {
         guard = clone_object("/players/molasar/sunndi/mob/guard");
         move_object(guard, this_object());
         i++;
      }
   }

}

setup_bandits() {
   /* Only clone a guard if the guard post is present */
   if(!present("bandit")) {
      object bandit;
      int i;
      while(i < 3) {
         bandit = clone_object("/players/molasar/sunndi/mob/bandit");
         move_object(bandit, this_object());
         i++;
      }
   }
}


get_sunndi_long(int arg) {

   if(arg >= 0) 
     return "Ponies and unicorns prance about the flower covered meadows.";
   else
     return "Bandits and politicians are mulling about kicking puppies.";

}


status move(string str) {
   int i;
   int player_align;

   if((i = member_array(query_verb(), dest_dir)) > -1) {
      if (query_verb() == "south") {
         if (present("guard", this_object())) {
            player_align = query_player_alignment((string)this_player()->query_real_name());
            if (player_align >= 0) {
               this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
               return 1;
            }
            say("A Sunndi Guard steps in front of " + 
               capitalize((string)this_player()->query_name()) + "and says, \"You may not" +
               "go south to the town. We don't want your kind disturbing the peace.\"",
               this_player());
            write("\nA Sunndi Guard steps if front of you and says, 'You may not go\n" +
               "south to the town. We don't want your kind disturbing the peace.'\n");
            return 1;
         }
      } 
      this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
      return 1;
   }
}


