#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("bow","bow");
   }
  ONE_EXIT("players/haji/quest/lev30.c", "west",

    "A windy room full of webs.",
      "This is a room full of webs with wind coming from the west.\n",1)
  realm(){return "harem";}
bow(str) {
string on1,onc;
      if(str==0) {
         write("Try bowing to something.\n");
         return 1;
          }
  sscanf(str,"%s %s",on1,onc);
    if(on1!="to") {
      write("Try bowing TO god.\n");
      return 1;
      }
    if(onc!="god") {
       write("Try bowing to GOD.\n");
       return 1;
     }
   write("You bow before god and see blades slice over you.\n");
     move_object(this_player(),"players/haji/quest/lev32.c");
  return 1;
  }
