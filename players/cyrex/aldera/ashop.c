inherit	"room/room";

reset(arg) { 
 if(!present("aldera guard")) {
   move_object(clone_object("players/cyrex/aldera/aguard"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Run-Down shop";
  long_desc = 
   "You are in a rather old shop that is no longer in business. The owner's are\n"+
   "nowhere to be seen. Nothing seems to be of value and not worth searching\n"+
   "and wasting anymore time here. Maybe when the owner's come back, the shop\n"+
   "will re-open.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain3", "north",
               "players/cyrex/aldera/acellar", "cellar"});
  }
}
