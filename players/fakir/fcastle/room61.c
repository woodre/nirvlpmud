inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Tower Guestroom";
long_desc =
"   An open window in the west wall allows the sun to illuminate\n"+
"the room with warm sunlight.  An unmade bed shows the signs of\n"+
"having been well used for the night.  A braided rug covers the\n"+
"stone floor.\n";

items = ({
"window",   "A square window with clear glass panes",
"wall",     "The west wall of the guest bedroom in the west tower",
"sun",      "You can only see the sunlight",
"room",     "The guest bedroom of the west tower",
"sunlight", "Golden sunlight streaming in through the window",
"bed",      "A large four posted bed with its covers all messed",
"rug",      "An oval rug braided from bits of cloth. It is very colorful",
"floor",    "The stone floor of the bedroom",
"pictures", "Landscapes mostly, though one is of a very handsome lad",


});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room96.c", "out",
   
});
}


