inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Sanctuary";
long_desc =
"   A sleeping pallet and dresser are the only furniture in the\n"+
"room.  A few robes and a hooded traveling cloak hang from wooden\n"+
"pegs in the wall.  \n";

items = ({
"pallet",   "A tick (feather) matress supported by wooden slats",
"dresser",  "Four drawers high and about three feet wide",
"robes",    "Dark wool robes worn on the worship days",
"cloak",    "A finely made cloak and hood of close knit fiber",
"pegs",     "Round wooden pegs driven into holes bored in the stone wall",
"wall",     "Stones covered in a whitewash paint of some sort",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room41.c", "chapel",
});
}


