#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("whistle");
  set_alias("chocowis");
  set_short(HIW+"Chocowis"+OFF);
set_long(
"This small, silver whistle was used to locate chicobos that might\n"+
"be hiding but is no longer used.  Chicobos would respond to the shrill\n"+
"peep of the whistle, thinking it was their mother.  Now the chicobos\n"+
"use it as a plaything.\n");
  set_value(400);
  set_weight(2);
}

init()
{
     add_action("blow_whistle","blow");
}

blow_whistle(str)
{
     if(str=="whistle")
     {
          write("You blow on the whistle but all that comes out is a little peep.\n");
          say(this_player()->query_name() + " peeps like a little chicobo!\n");
          return 1;
     }
     notify_fail("What are you trying to blow?\n");
}
