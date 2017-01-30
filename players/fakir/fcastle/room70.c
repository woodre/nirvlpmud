inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Captain's Quarters";
long_desc =
"   An austere room with little in the way of furnishings.  A well\n"+
"made bed and a small chest are the only items of interest.  Three\n"+
"pair of boots, all well kept, rest beside the chest.  A well worn\n"+
"breastplate of hammered silver bearing the rank of captain hangs\n"+
"between two doors, and a matching silver helm sits on the floor\n"+
"beneath it.\n";

items = ({
"furnishings",   "A bed and a chest are the only furnishings in the room",
"bed",           "A simple bed with a wooden headboard and frame",
"chest",         "Banded in leather straps that buckle and lock, it would\n"+
                 "hold up well in a campaign or as a traveling chest",
"boots",         "One pair is soft leather for riding.  The other two\n"+
                 "are hard leather. One pair has a set of spurs attached",
"breastplate",   "Armor designed to protect the upper body",
"doors",         "The door to the hall south, and the secret door to the\n"+
                 "main room of the east tower (west)",
"helm",          "A helmet of silver with a silk scarf tied to the guard",
"floor",         "The cold stone floor of the captain's quarters",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room69.c", "south",
   "/players/fakir/fcastle/room45.c", "west",
});
}


