inherit	"room/room";

reset(arg) { 
 if(!present("alderan guard")) {
   move_object(clone_object("players/cyrex/aldera/aguard"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled path heading west and east. A castle can\n"+
   "be seen to your west. A huge forest can be seen to your north-east. Some\n"+
   "sort of shop can be seen to the south-west.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain", "west",
               "players/cyrex/aldera/amain3", "east"});
  }
}
