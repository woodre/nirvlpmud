#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
extra_init() {
      add_action("trekkie","trekkie");
 }
 
trekkie() {
   object ob;
   ob=clone_object("obj/quest_obj");
   call_other(ob,"set_name","trekkie");
   call_other(ob,"set_hint","find the ultimate trekkie and get the videotape\n" +
              "`The Lost Episodes of Star Trek'\n" +
              "find the jeffries tube and throw the videotape.\n");
   move_object(ob,"room/quest_room");
   return 1;
}
 
 
ONE_EXIT("players/rich/workroom", "west",
    "a room",
    "a room",
    1)
