inherit	"room/room";

reset(arg) { 
 if(!present("royal guard")) {
   move_object(clone_object("players/cyrex/aldera/arguard"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Castle Entrance";
  long_desc = 
   "You are standing right at below the castle entrance. You can see a tremendous\n"+
   "layout of the castle to your west. A road south from here leads further into\n"+
   "the castle.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain1", "east",
               "players/cyrex/aldera/acourtyard", "west"});
  }
}
