inherit	"room/room";

reset(arg) { 
 if(!present("dice")) {
   move_object(clone_object("players/zone/obj/dice.c"), this_object());
 }
 if(!present("bandit")) {
   move_object(clone_object("players/zone/obj/bandit.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Casino";
  long_desc = 
   "A little room where the storekeeper has gambling paraphenalia.\n";
  dest_dir = ({"players/zone/rooms/shop.c", "west"});
  }
}
