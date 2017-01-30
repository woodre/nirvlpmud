inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "East Castle Hallway";
long_desc =
"   The hallway is well lit and a red and blue carpet covers\n"+
"the floorway.  A marble bust of the royal Queen sits on a\n"+
"small table outside the door of the captain's quarters to\n"+
"the north.\n";

items = ({
"carpet",   "A fine imported carpet with a gold thread binding",
"hallway",  "The place in which you stand",
"floorway", "Stones worn smooth and almost slick from many boots",
"bust",     "A small statue of the royal Queen, in green marble",

});
if(!present("gaurd",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/cgaurd.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room70.c", "north",
   "/players/fakir/fcastle/room68.c", "west",
});
}


