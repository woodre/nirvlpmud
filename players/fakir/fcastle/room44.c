inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Stable Stalls";
long_desc =
"   The stalls of the castle stable stretch in a row to the east\n"+
"and west.  Some are empty with the door or gate standing open.\n";

items = ({
"stable",   "The stable of the castle courtyard",
"stalls",   "Wooden stalls with rough hewn walls and straw floors",
"gate",     "Wooden gates with a rope latch",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room33.c", "stable",
});
}


