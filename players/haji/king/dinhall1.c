#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("sit","sit");
   }
  TWO_EXIT("players/haji/king/kitchen.c", "west",
           "players/haji/king/hall1.c", "east",

    "A dining hall",
      "This is a dining hall before you see \n" +
      "a table with many chairs you suddenly\n" +
      "get the urge to sit on one.\n" +
      "From the west you hear the sounds of a kitchen.\n" +
      "To the east you see a hallway.\n",1)
  realm(){return "harem";}
sit(str) {
string on1,onc;
  sscanf(str,"%s %s",on1,onc);
    if(on1!="on") {
      write("Try sitting ON chair.\n");
      return 1;
      }
    if(onc!="chair") {
       write("Try sitting on CHAIR.\n");
       return 1;
     }
  write("You sit on the chair,prop your legs up on the table,\n");
  write("and you feel really good about life right now.\n");
  return 1;
  }
