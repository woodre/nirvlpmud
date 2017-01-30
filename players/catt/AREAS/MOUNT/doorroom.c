#include "std.h"
#include "obj/door.h"
reset(arg) {
  if(!arg) {
MAKE_DOORS("players/catt/mount/doorroom","south","players/catt/mount/level1_stairs_down","north","sophisticated","king","This is a blackened door of iron.\n",1,1,1)
call_other(obj_2, "set_door_long", "This is the door to the goblin king.\n");
MAKE_KEY(key_obj, "grey","king")
move_object(key_obj, environment(obj_1));
}
}
init() {
  add_action("search","search");
}
search() {
   write("you see the outline of a trap door under the floor matting\n"+
         "you may go "door" to see what is down there.\n");
   return 1;
          }
