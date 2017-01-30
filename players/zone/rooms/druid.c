inherit	"room/room";

reset(arg) { 
 if(!present("druid")) {
   move_object(clone_object("players/zone/monster/druid.c"), this_object());
 }
 if(!present("druid2")) {
   move_object(clone_object("players/zone/monster/druid.c"), this_object());
 }
 if(!present("druid3")) {
   move_object(clone_object("players/zone/monster/druid.c"), this_object());
 }
 if(!present("druid4")) {
   move_object(clone_object("players/zone/monster/druid.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Druid circle";
  long_desc = 
"Here is a clearing.  It seems well used, and the trees well cared for.\n"+
"It has a still quality that comes when a place is highly revered.\n";
  dest_dir = ({"players/zone/rooms/druid.c", "west",
               "players/zone/rooms/stream1.c", "east"});
  }
}
