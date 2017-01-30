inherit "/players/vertebraker/closed/std/room";
#include <ansi.h>


reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_long("");
}

init()
{
  ::init();
  add_action("blind","look",1);
}

blind()
{
  write("Your vision is clouded here....\n");
  return 1;
}
