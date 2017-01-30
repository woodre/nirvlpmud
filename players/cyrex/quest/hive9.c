inherit	"room/room";

reset(arg) { 
 if(!present("trooper")) {
   move_object(clone_object("players/cyrex/quest/trooper"), this_object());
 }
  if(!arg) {
  set_light(0);
  short_desc = "Hive";
  long_desc = 
   "This is the dark and damp hive of the Invid Queen Regis. There are a lot\n"+
   "of huge honeycomb like structures molded into the wall.\n";
  no_exits = 1;
  property = ({"NT"});
  items = ({"honeycomb",
            "It looks like it has some sort of pod in it"});
  dest_dir = ({"players/cyrex/quest/hive10", "south",
               "players/cyrex/quest/hive8", "north",
               "players/cyrex/quest/hive9", "west",
               "players/cyrex/quest/hive3", "east"});
  }
}
