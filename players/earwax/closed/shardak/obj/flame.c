/*
* Flame for the LIGHT spell
*/
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/ansi.h"
inherit OBJECT;

void
create()
{
   ::create();
   set_name("flame");
   set_long(
      "A dark, burning, twisted flame.  It flickers constantly and\n"+
      "will eventually go out.  It seems to glow around your right\n"+
      "fist and is not snuffed out by water.\n");
   set_light(1 + random(2));
}

status
drop(int silently)
{
   if (!silently && environment())
      tell_object(environment(), "The flame dies as you drop it.\n");
   destruct(this_object());
   return 1;
}

void
die()
{
   object env;
   
   if (env = environment()) {
      tell_object(env, "Your flame dwindles and dies.\n");
      /* if light is 1 it will be 0 after self-destruct */
         if ((env = environment(env)) && set_light(0) <= 1)
         tell_room(env, "The room goes dark.\n");
   }
   destruct(this_object());
}

string
extra_look()
{
   if (this_player() == environment())
      return "You are carrying a "+BOLD+BLK+"Dark Flame"+NORM+" in the palm of your hand";
   else
      return environment()->query_name() +
   " is carrying a "+BOLD+BLK+"Dark Flame"+NORM+" in the palm of " +
   environment()->query_possessive() + " hand";
}

void
move(mixed dest)
{
   move_object(this_object(), dest);
   call_out("die", 600);
}

status
id(string arg) { return (::id(arg) || arg == "flame_obj"); }
