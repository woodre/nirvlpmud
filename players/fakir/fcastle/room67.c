inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Barracks";
long_desc =
"   Bunks racked four high stand in rows along two walls.  Storage\n"+
"cabinets cover another wall, and neatly stacked footlockers rest\n"+
"end to end in the center of the room.  Each bunk has its woolen\n"+
"blanket stretched tight and tucked at the sides.  A secret door\n"+
"to the tower is open to the east for fast access.\n";

items = ({
"bunks",       "Wooden bunk beds racked four high. Each has a thin cotton mattress",
"rows",        "Four rows per wall, or a total of 32 bunks",
"walls",       "The walls within the barracks of the castle",
"cabinets",    "Floor to ceiling, they hold the personal effects of the soldiers",
"footlockers", "About the size of a suitcase, with a hasp and lock on each",
"room",        "The barracks of the castle",
"blanket",     "A thin woolen blanket dyed a deep green",


});
if(!present("guard",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/cguard.c"),this_object());
if(!present("guard",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/cguard.c"),this_object());
if(!present("guard",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/cguard.c"),this_object());
if(!present("guard",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/cguard.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room55.c", "east",
   "/players/fakir/fcastle/room66.c", "south",
});
}


