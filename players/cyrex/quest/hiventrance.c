inherit	"room/room";

reset(arg) { 
  if(arg) return;
  set_light(0);
  short_desc = "Hive Entrance";
  long_desc = 
   "This is the dark and damp hive of the Invid Queen Regis. There are a lot\n"+
   "of huge honeycomb like structures molded into the wall.\n";
  no_exits = 1;
  property = ({"NT"});
  items = ({"honeycomb",
           "It looks like it has some sort of pod in it"});
  dest_dir = ({"players/cyrex/quest/hive1", "west",
               "players/cyrex/quest/hive11", "east",
               "players/cyrex/quest/hive6", "south",
               "players/cyrex/quest/hiventrance", "north",
               "players/cyrex/quest/rchamber", "exit"});
}
