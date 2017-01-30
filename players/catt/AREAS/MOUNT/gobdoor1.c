#include "room.h"
#include "obj/door.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
   object sentry;
object key_obj, obj_1, obj_2;
   int i;
   i = 0;
   if(!present("sentry")) {
      while(i < 2) {
         i += 1;
       sentry = clone_object("players/catt/gobsentry");
         move_object(sentry, this_object());
                   }
               }
MAKE_DOORS("players/catt/mount/gobdoor1","south","players/catt/mount/level1_stairs_down","north","sophisticated","king","This is a blackened door or iron.\n",1,1,1)
call_other(obj_2,"set_door_long","This is a blackened door of iron.\n");
MAKE_KEY(key_obj, "grey","king")
move_object(key_obj, environment(obj_1));
   }
THREE_EXIT("players/catt/mount/level1_2","east",
           "players/catt/mount/level1_4","west",
         "players/catt/mount/level1_stairs_down","down",


          "goblin mountain... level1_3",
          "a set of stairs has been cut into the tunnel here leading down\n" +
          "you can hear muffled yells and curses coming from below.\n", 1)
