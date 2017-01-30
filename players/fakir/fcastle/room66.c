inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Barracks Hallway";
long_desc =
"   The damp stone walls glimmer in the flickering light from the smokey\n"+
"torches lining the hallway.  The floor is worn smooth by the passing of\n"+
"countless guards over the ages.  The barracks are just ahead to the north.\n";

items = ({
"walls",   "Stone set close without mortar or joint.  Drops of moisture\n"+
           "trickle down from above",
"torches", "Wood handled torches with cup like heads filled with wax and flax",
"hallway", "Very gloomy here near the barracks door and smokey from burning wax",
"floor",   "Stones worn smooth and almost slick from many boots",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room67.c", "north",
   "/players/fakir/fcastle/room65.c", "east",
});
}


