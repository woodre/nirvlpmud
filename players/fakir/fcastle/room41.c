inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Chapel";
long_desc =
"   Wooden pews face a raised platform and podium. Behind the podium,\n"+
"several wood carvings hang from the wall.  A door to the sanctuary is\n"+
"centered between the carvings. \n";

items = ({
"pews",     "High backed benches made of polished wood",
"platform", "A raised portion of the floor at the far end of the chapel",
"podium",   "A place to rest a book or tablet while speaking",
"carvings", "Religious reliefs",
"wall",     "A flat stone wall",
"door",     "Its a door you can walk through",
"sanctuary","The residence of the current cleric",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room42.c", "sanctuary",
   "/players/fakir/fcastle/room37.c", "west",
});
}


