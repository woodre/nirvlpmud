#include "/players/catacomb/misc/ansi.h"
inherit "/obj/treasure.c";
#define TPN this_player()->query_name()
int casted;

reset (arg) {
	set_id("pole");
	set_short("A fishing pole");
	set_long(
      "  A long rod with a string attached to it for casting.  At\n"+
      "the end of the string is a hook used for catching the fish\n"+ 
      "of the lake.\n");
set_value(400);
set_weight(1);
casted = 0;
}

init(){
  ::init();
     add_action("castem", "cast");
     add_action("reelem", "reel");
  }

castem(str){
  if(casted == 0)
  {
  write(BOLD+"\n\tYou reach back with the rod, then quickly\n"+NORM);
  write(HIW+"\n\t   ZZZZZZZZIIIIIIIIINNNNNNNGGGGGGG\n"+NORM);
  write(BOLD+"\n\t      You let the hook fly.\n");
  say("\n"+TPN+" casts the hook out into the distance.\n");
  casted = 1;
  return 1; 
  }
  else 
  {
   write("\nYou have already casted try reeling it in.\n");
   return 1;
  }
}

reelem(str)
{
  if(casted == 0)
  {
    write("\nYou must cast first.\n");
    return 1;
  }
  else
  {
  if(random(10) == 10)
  {
    write("\nYou tug and pull at the pole and eventually you get to see what you've caught\n");
    write("\n      You show off the "+YEL+"WHOPPER"+NORM+" of a fish to everyone.\n");
    say("\n"+TPN+" shows off the "+RED+"HUGE"+NORM+" fish they caught for everyone to see.\n");
    casted = 0;
    return 1;
  }
  else 
  {
   if (random (5) <= 2)
   {
    write("\nYou tug and pull at the pole and eventually you get to see what you've caught\n");
    write("\n      You show off the "+HIB+"Minnow"+NORM+" of a fish to everyone.\n");
    say("\n"+TPN+" shows off the "+GRN+"little"+NORM+" minnow they caught for everyone to see.\n");
    casted = 0;
    return 1;
   }
   else
   {
    write("\nYou tug and pull at the pole and eventually you get to see what you've caught\n");
    write("\n      You frown in heartbreak seeing that you only caught a snag.\n");
    say("\n"+TPN+" whimpers in defeat.\n");
    casted = 0;
    return 1;
   }
  }
} 

