inherit "/players/vertebraker/closed/std/room";
#include <ansi.h>


reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"Inside a Cave"+NORM);
   set_long(
      "  The cave is formed of solid rock.  The skeletal remains of past\n"+
      "warriors lay all around.  Everything in the cave is covered with a\n"+
      "black soot.\n");
   add_item("cave","A dark cave....");
   add_item("soot","Thick black soot.");
   add_item("rocks","Sharp jagged rocks.");
   add_item("remains","Nothing but bones at this point.");
   add_item("bones","The remains of past warriors that have entered the cave.");
   add_item("skeleton","The remains of past warriors that have entered the cave.");
   add_item("skeletons","The remains of past warriors that have entered the cave."); 
   add_object("/players/fred/closed/templar/dragon.c");
   add_exit("/players/fred/closed/templar/r2.c","out");
}

init()
{
  ::init();
  add_action("out","out");
}

out()
{
  if(present("dragon", this_object()))
  {
    tell_object(this_player(),
      "The dragon swings it's massive tail blocking your exit.\n");
    return 1;
  }
  this_player()->move_player("out#players/fred/closed/templar/r2.c");
  return 1;
}
