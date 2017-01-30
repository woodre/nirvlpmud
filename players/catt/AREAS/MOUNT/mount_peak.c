#include "std.h"
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
  if(!arg) {
   object dragon;
   if(!present("dragon")) {
   dragon = clone_object(NPC+"ice_dragon");
     move_object(dragon, this_object());
    set_light(3);
}}}
init() {
   add_action("down","down");
   add_action("alcove","alcove");
       }
down() {
call_other(this_player(), "move_player",
        "down#"+MOUNT+"mount_crest3");
  return 1;
}
alcove() {
call_other(this_player(), "move_player",
        "alcove#"+MOUNT+"mount_alcove");
   return 1;
}
short() { return "mount_peak"; }
long() {
  write("This is the peak of the mountain, all covered in snow\n"+
        "ice. this desolate place is intriguing in its own way.\n"+
        "The very peak itself forms a small bowl where in the \n"+
        "middle is a large hole, the hole has a large white head\n"+
        "sticking out from it, an alcove is noticable and there\n"+
       "seems to bee something in it.\n"+
       "Obvious exits: alcove, down\n");
     }
