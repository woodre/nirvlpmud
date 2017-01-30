#define tp this_player()->query_name()
#include "/players/eurale/closed/ansi.h"

inherit "obj/treasure";


reset(arg)  {
   if (arg) return;
   set_id("portal");
set_short("A shimmering "+BOLD+CYN+"blue portal"+NORM);
set_long(
  "This shimmering blue portal provides a way to see where players \n"+
  "are on the mud.  All you have to do is [stare <player>] to see \n"+
  "the room and it's contents...\n");
   set_weight(100);
   set_value(0);
}

init()  {
   add_action("stare","stare");  }

stare(str)  {
object ob;
string there;
if(!str) { write("Who would you stare at?\n"); return 1; }

ob = find_player(str);
  if(!ob)  ob = find_living(str);
    if(!ob || ob->query_invis() > 17) {
      write("The portal remains hazy.\n");
      return 1;
        }
write("You stare into the shimmering portal and see and image of:\n");
there = call_other(ob,"look");
say(tp+" stares into the shimmering blue portal.\n");
  return 1;
}

get() { return 0; }
