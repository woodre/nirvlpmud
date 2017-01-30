inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Pantry";
long_desc =
"   Shelf upon shelf of foodstuffs and supplies line each wall.  An\n"+
"oil lamp, lit but burning low, hangs from a thick wire in the center\n"+
"of the room.  \n";

items = ({
"shelf",      "Just wooden shelves...nothing special",
"foodstuffs", "Flour, sugar, odd bags of this and that",
"supplies",   "All the stuff a kitchen has to have",
"wall",       "Its just a wall",
"lamp",       "A small brass lamp with a glass chimney",
"wire",       "A crude metal wire of brass and lead.",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room39.c", "kitchen",
});
}


