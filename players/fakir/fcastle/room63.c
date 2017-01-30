inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Tower Room";
long_desc =
"   An open window in the far wall allows the sun to illuminate\n"+
"the room with warm sunlight.  A well made bed is centered under\n"+
"the window, and a braided rug covers the floor.  A few pictures\n"+
"hang from the walls, mostly of country landscapes.\n";

items = ({
"window",   "A square window with clear glass panes",
"wall",     "The north wall of the guest bedroom in the west tower",
"sun",      "You can only see the sunlight",
"room",     "The guest bedroom of the west tower",
"sunlight", "Golden sunlight streaming in through the window",
"bed",      "A large four posted bed",
"rug",      "A oval rug braided from bits of cloth. It is very colorful",
"floor",    "The stone floor of the bedroom",
"pictures", "Landscapes mostly, done in watercolors from native plants",


});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room94.c", "out",
   
});
}


