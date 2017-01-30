#include "../def.h"
int cnt;
inherit "/room/room";

reset(arg)
{
  if(!present("musashi")) {
    move_object(clone_object(OBJDIR+"musashi"), this_object());
  }
  if(arg) return;
  set_light(1);
  set_short("Dojo - Inner Sanctum");
  set_long("\
Dojo - Inner Sanctum\n\
The lair of Miyamoto Musashi, the great Samurai of the Edo\n\
era. An immaculately kept room, you notice two bamboo swords\n\
in the back, next to a simple potted bonsai.\n");
  dest_dir = ({
    ROOMDIR+"dojo_armory", "down",
  });
}

init() {
 ::init();
  if(this_player() && this_player()->is_player()) {
    ++cnt;
  }
}
exit(ob){
  if(present("musashi"))
    present("musashi")->heal_self(100000);
  if(ob->is_player())
  cnt --;
  return ::exit(ob);
}

query_cnt() { return cnt; }

realm() { return "NT"; }
