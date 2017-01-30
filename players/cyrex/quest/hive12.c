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
          "This particular honeycomb has NO pod in it. It looks\n"+
           "like there is something huge moving about on the other side.\n"+
            "You could probably just fit through to investigate"});
dest_dir = ({
               "players/cyrex/quest/hive6", "north",
               "players/cyrex/quest/hiventrance", "south",
               "players/cyrex/quest/hive4", "west",
               "players/cyrex/quest/hive8", "east"});
  }
}
