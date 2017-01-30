inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "East Hallway";
  long_desc = 
   "A set of heavy wooden doors opens on the south wall. On them are\n"+
   "inscribed myriad arcane symbols and figures from mythology. Opposite,\n"+
   "a single door stands on the north wall. The hall ends past the doors.\n";
  items = ({"figures",
            "You find it difficult to focus on the figures for any amount of time",
            "symbols",
            "You find it difficult to focus on the figures for any amount of time"});
  dest_dir = ({"players/bastion/isle/wiz/sitting", "north",
               "players/bastion/isle/wiz/games", "south",
               "players/bastion/isle/wiz/e_hall1", "west"});
  }
}
