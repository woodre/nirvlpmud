inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Barracks Hallway";
long_desc =
"   The damp stone walls reflect the glow from low-burning torches set in\n"+
"the walls, as well as the muted light from the gate house.  The stone floor\n"+
"is worn smooth by the passing of countless guards over the ages.  The hall\n"+
"continues, or you can return to the gate house.\n";

items = ({
"walls",   "Stone set close without mortar or joint.  Drops of moisture\n"+
           "trickle down from above",
"torches", "Wood handled torches with cup like heads filled with wax and flax",
"hallway", "It is rather gloomy and full of the smell of burning torches",
"floor",   "Stones worn smooth and almost slick from many boots",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room29.c", "east",
   "/players/fakir/fcastle/room66.c", "west",
});
}


