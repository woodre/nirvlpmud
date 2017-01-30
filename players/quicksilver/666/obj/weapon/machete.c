#include "/players/quicksilver/666/include/std.h"

inherit WEAPON;

reset(arg) {
     ::reset(arg);
     if (arg) return;
     set_name("machete");
     set_alias("machete");
     set_short("a machete");
     set_long("It appears to be a standard machete.  Great for clearing vines and small trees.");
     set_class(5);
     set_weight(1);
     set_value(200);
}

init() {
     ::init();
     add_action("create_escape", "hack");
     add_action("try_other", "cut");
     add_action("try_other", "chop");
     add_action("try_other", "slice");
     add_action("try_other", "saw");
}

create_escape(str) {
     string bleh, what;
  object stuff,orb;
  int i;
 
     if(!wielded) {
          notify_fail("You will have to wield the machete first.\n");
          return;
     }
     if((sscanf(str, "%s %s", bleh, what) != 2) || (bleh != "at" && bleh != "on")) {
          notify_fail("Perhaps you should hack 'at' something.\n");
          return;
     }
     if((sscanf(file_name(environment(ENVTO)), ROOM_DIR + "forest_room%s", bleh) && !environment(ENVTO)->query_dest_dir()) &&
        ((what == "trees") || (what == "tree") || (what == "overgrowth"))) {
  stuff=all_inventory("players/quicksilver/workroom");
  for(i = 0; i <sizeof(stuff); i++)
        {
           if(stuff[i]->id("orb")) {
              orb=stuff[i];
              break;
           }
        }
          environment(ENVTO)->add_exit(orb->query_entry(), "out");
          wwrite(format("You hack your way through the overgrowth using your machete and discover a way out.\n", 75));
          wsay(format(capitalize(ENVTO->query_name()) + " hacks out a path through the overgrowth using " + 
               ENVTO->query_possessive() + " machete.\n", 75));
          return 1;
     }
     wsay(format(capitalize(ENVTO->query_name()) + " flails wildly at " + what + " with " + ENVTO->query_possessive() + " machete, but nothing happens.\n", 75));
     wwrite(format("You swing wildly at " + what + " for awhile, but nothing happens.\n", 75));
     return 1;
}

try_other(str) {
     if(!str) return;
     notify_fail("Perhaps you should try using the machete to 'hack' at something.\n");
     return;
}
