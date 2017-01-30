inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Kitchen";
long_desc =
"   Kettles, pots, pans, and all sorts of other cooking paraphernalia\n"+
"hang from every wall, and racks of fresh baked breads stand cooling\n"+
"in the far corner of the room.  Huge ovens over burning fire boxes\n"+
"belch steam as they cook poultry and wild game.  Cooks scurry about\n"+
"in haste preparing for the evening banquet.\n";

items = ({
"kettles",       "Mostly made of copper with long handles",
"pots",          "Some are of copper, others of a clay like material glazed white",
"pans",          "Shallow cooking pans with long wooden handles",
"paraphernalia", "Spoons, forks, knifes, etc.",
"wall",          "Its a wall",
"racks",         "Wooden racks with shelves about five feet tall",
"breads",        "Large loaves of wheat and rye",
"ovens",         "Cast iron with short support legs and tall smoke pipes",
"boxes",         "The firebox of the oven where the wood burns for heat",
"steam",         "Hot water vapor from the cooking food",
"cooks",         "They work at every stove and counter, sweating profusely",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room40.c", "pantry",
   "/players/fakir/fcastle/room37.c", "east",
});
}


