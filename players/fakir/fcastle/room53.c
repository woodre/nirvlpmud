inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "East Tower Guestroom";
long_desc =
"   An open window in the west wall allows the sun to illuminate\n"+
"the room.  A messy bed with its covers on the floor shows the\n"+
"signs of having been well used for the night.  An oval braided\n"+
"rug is covered in rumpled clothing.\n";

items = ({
"window",   "A square window with clear glass panes",
"wall",     "The west wall of the guest bedroom in the east tower",
"sun",      "You can only see the sunlight",
"room",     "A guest bedroom of the east tower",
"sunlight", "Golden sunlight streaming in through the window",
"bed",      "A large four posted bed with its covers all messed and on the floor",
"rug",      "An oval rug braided from bits of cloth. It is very colorful",
"floor",    "The stone floor of the bedroom",
"pictures", "Landscapes mostly with a few portraits",
"clothing", "The cast off clothing of two lovers perhaps",


});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room90.c", "out",
   
});
}


