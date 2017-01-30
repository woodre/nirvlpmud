#include "/players/catacomb/misc/ansi.h"
inherit "/obj/treasure.c";
#define TPN this_player()->query_name()

reset (arg) {
	set_id("disks");
	set_short("A set of spindle disks");
	set_long(
      "  A common toy of the Shamot elves.  A small set of disks\n"+
      "are wrapped with a string.  If one was so inclined one \n"+ 
      "could possibly 'spin' the disks and have some fun with\n"+
      "the toy.\n");
        set_value(550);
        set_weight(1);    
}

init()
{
  ::init();
     add_action("spinem", "spin");   
}

spinem(str)
{
  if(!str) { write("What would you like to spin?\n"); return 1; }
  if(str == "disks")
  {  
  write("\nYou quickly throw the disks extending the string to its end.\n");
  write("The disks sit suspended on the ground spinning but never returning.\n");
  write("Finally you give the string a jerk and the disks return to your hands.\n");
  write("You think to yourself,"+HIC+" DAMN I'M COOL!\n"+NORM);
  say("\nYou watch in awe as "+TPN+" spins the disks on the ground.\n");
  say(HIM+"      DAMN "+TPN+"'s COOL!!\n"+NORM);
  return 1; 
  }
}

