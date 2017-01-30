inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Guest Room";
long_desc =
"   A bed in some disarray waits to be made up, and the dresser\n"+
"next to it has several drawers extended.  A small bedtable holds\n"+
"a crystal lamp half full of an amber colored oil.  A suit of\n"+
"chainmail and a broadsword rest against the footboard of the bed.\n";

items = ({
"bed",   "A double size bed suitable for a single person",
"dresser","A four drawer wooden dresser with a polished top",
"drawers","They have been opened and left so",
"bedtable","A small nightstand holding a lamp",
"lamp",  "A crystal lamp with oil",
"oil",  "Amber in color, it is no doubt an animal extract of some kind",
"chainmail", "Armor meant to be worn, not left by a bed",
"broadsword", "A deadly weapon indeed, if held by the right hands",
"footboard",  "A wooden footboard. It helps hold the bed upright",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room88.c", "out",
   
});
}


