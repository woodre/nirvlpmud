#include "../def.h"
reset(x) { if(!x) set_light(1); }

short() { return "Above the pit"; }

init()
{
    add_action("cmd_pit", "pit");
}

cmd_pit()
{
  return (this_player()->move_player("down#" + ARENA + "vpit"), 1);
}
