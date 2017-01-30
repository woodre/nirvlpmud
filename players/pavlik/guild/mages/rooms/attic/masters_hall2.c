#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Master's Hallway";
long_desc=
"This small hallway leads to master's quarters.  A door to the\n"+
"north leads to Master Jhavostrahd's chambers.\n"+
 "The hallway runs eastward past the master's chambers\n"+
"and back to the Tower of Mages.\n";

dest_dir=({
 "/players/pavlik/guild/mages/rooms/jhavostrahd_room", "north",
 "/players/pavlik/guild/mages/rooms/masters_hall", "east",
});

   }
}

query_mguild(){ return "Masters Hallway"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}
