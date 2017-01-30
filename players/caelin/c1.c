#include "../define.h"
int x;
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short("A dark cavern");
   set_long(
"     In the mouth of the dark cavern, you notice an odd and peculiar\n"+
"reddish stain on the floor.  A large hole is in the left wall of the\n"+ 
"cavern.  It is very dimly lit in here and you can't even make out\n"+
"your own shadow.\n");
   add_property("PK");
   add_property("NT");
   add_item("stain",
      "This reddish stain was caused perhaps by ..\n"+
      " bloodshed? .. Hmm");
   add_item("hole",
      "The large hole seems to be hiding something behind it....");
   add_exit(ROOMS+"c2","south");
   add_exit(ROOMS+"c3","east");
   add_exit(ROOMS+"s37","out");
   add_item("wall",
      "The large stone wall on your left has a large hole\n"+
      "in the middle of it.\n");
}

cmd_search(str) {
   if(str == "hole" || str == "wall" || str == "large hole") {
      if(x) {
         write("There is nothing else in the hole...\n");
         return 1; }
      write("You search the hole behind the wall...\n\n"+
         " You discover a human.. skull?!\n");
      say(TPN+" searches behind the wall.\n");
      MO(CO(OBJ_DIR+"skull"),TO);
      x = 1;
      return 1; }
   ::cmd_search(str);
   return 1;
}

okay_follow() { return 1; }
