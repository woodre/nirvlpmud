#include "/players/catacomb/misc/ansi.h"
inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Kami's Lookout" ;
  long_desc =(
  " A lone palm tree sways in the breeze at the edge of the lookout.\n"+
  "The sun glistens off the fine white marble under foot.  Toward the\n"+
  "back of the lookout a portal glows a dark blue, leading to the \n"+
  "chamber of trials.\n"); 

  items = ({
    "tree",
    "The tree sways back and forth in the breeze",
    "sun",
    "Don't stare at the sun, you'll go blind!!",
    "marble",
    "Fancy white marble gives you your footing",
    "portal",
    "A dark blue portal leads into the chamber of trials"
       
  });

  dest_dir = ({
    "/players/catacomb/saiyan/lookout1.c","west" 
  });
  
}
init(){
  ::init();
  
      add_action("trials","enter");  
  }


trials(str)
{
  if (str != "portal")
  {
    write("Try 'enter portal'.\n");
    return 1;
  }
  if (str == "portal")
  {
    write("You boldly step into the portal ready to face the trial.\n");
    say(this_player()->query_name()+" steps through the portal bravely.\n");
    this_player()->move_player("enter#players/catacomb/saiyan/trial.c");
    return 1;
  }

}