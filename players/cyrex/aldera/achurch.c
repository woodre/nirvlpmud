inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Church of Aldera";
  long_desc = 
   "You find yourself in a strange, far away place. A huge church is visible not\n"+
   "far from here. It has three towers with a bell in the middle tower. There is\n"+
   "not much else about the church that catches your attention except for maybe\n"+
   "the grand doors that seem to invite you in for a prayer. There is a road here\n"+
   "leading south to a main intersection.\n";
  no_exits = 1;
  property = ({"NF", "NT"});
  items = ({"bell",
            "A huge bell, one that you have never seen before.",
            "towers",
            "Three tall towers with a bell in the center tower."});
dest_dir = ({"players/cyrex/aldera/ainchurch", "church",
             "players/cyrex/aldera/amain", "south"});
  }
}
