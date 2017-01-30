#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_short(GRN+"A forest oasis"+NORM);
  set_long(GRN+"\
Tall red cherry trees tower over you, creating a natural\n\
circle surrounding you. Leaves and twigs crunch under your step\n\
as you gaze around the beautiful Japanese wilderness. Bamboo\n\
shoots up from the ground, weaving intricate patterns around\n\
the landscape.  A tall "+HIG+"dojo"+NORM+GRN+" stands to the east.\n"+NORM);
  set_light(1);
  dest_dir = ({
    ROOTDIR+"room/dojo_foyer","east",
    "players/mythos/aroom/shrinear3","west",});
}

query_no_fight(){ return 1; }

cmd_east()
{
  if(this_player()->query_guild_name() != "samurai") {
    write("You may not enter.\n");
    return 1;
  }
  return 0;
}

init()
{
  ::init();
  add_action("cmd_east","east");
}
