inherit	"room/room";

reset(arg) { 
 if(!present("monkey")) {
   move_object(clone_object("players/zone/monster/monkey.c"), this_object());
 }
 if(!present("monkey2")) {
   move_object(clone_object("players/zone/monster/monkey.c"), this_object());
 }
 if(!present("monkey3")) {
   move_object(clone_object("players/zone/monster/monkey.c"), this_object());
 }
 if(!present("monkey4")) {
   move_object(clone_object("players/zone/monster/monkey.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Monkey craigs";
  long_desc = 
"A rocky offshoot of the valley.  In the small trees and shrubs, monkeys\n"+
"gambool and play.  They eat the fruit that the plants bear, and lead a\n"+
"contented life.\n";
  dest_dir = ({"players/zone/rooms/monkeyking.c", "north",
               "players/zone/rooms/monkey.c", "east",
               "players/zone/rooms/rvalley.c", "south"});
  }
}
