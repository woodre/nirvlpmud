#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Ante Chamber";
long_desc=
"This tiny chamber is the entrance to the Master's Quarters.  The\n"+
"Masters of the Circle of Mages both live and teach from within\n"+
"these walls.  The aura of ancient and powerful spells permeates\n"+
"the stones of this hallway.  Master Calador's chambers are to\n"+
"the north.  There is a hallway to the west leading to the chambers\n"+
"of the other Masters.  It is best not to intrude upon the Masters\n"+
"unless you have good reason.\n";

dest_dir=({
 "/players/pavlik/guild/mages/rooms/masters_hall", "west",
 "/players/pavlik/guild/mages/rooms/advance_room2", "north",
 "/players/pavlik/guild/mages/rooms/guild_room4", "east",
});

   }
}

query_mguild(){ return "Ante Chamber"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("north","north");
  add_action("go2","go2");
  mage_check();
}

north() {
  if(present("mageobj2", this_player())) {
    this_player()->move_player("north#players/pavlik/guild/mages/rooms/advance_room2");
  }
  else {
    this_player()->move_player("north#players/pavlik/guild/mages/rooms/advance_room");
  }
  return 1;
}

go2() {
  if(("players/pavlik/guild/mages/mage-master.c")->is_gc()) {
    write("You enter the 2nd advance room...\n");
    this_player()->move_player("away#players/pavlik/guild/mages/rooms/advance_room2");
    return 1;
  }
  return 0;
}

