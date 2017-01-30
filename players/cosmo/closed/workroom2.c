#include "std.h"
#include "/players/cosmo/closed/ansi.h"
init() {
   add_action("post"); add_verb("post");
   add_action("guild"); add_verb("vampire");
   add_action("church"); add_verb("church");
  if (this_player()->query_name() == "emerald")
    set_light(0);
 }

/*
short() {return "Beyond "+MAG+"existence"+NORM;  }
*/
short() {return "Vast Emptiness";}
long() { write("\n\nExits exist to: church, post, vampire.\n");  }

church() {
  call_other(this_player(), "move_player", "church#room/church.c");
  return 1;
  }

guild() {
  call_other(this_player(), "move_player", "vampire#/players/nooneelse/black/guild_hall.c");
  return 1;
  }

post(){
  call_other(this_player(), "move_player", "post#room/post.c");
  return 1;
}
