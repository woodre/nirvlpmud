inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "You reached the dead end of the gallery, many rocks have been piled up to bar\n"+
		"the way.  Can they be unpiled?\n";
    short_desc = "Dead end";
    dest_dir = ({
                  "/players/trix/castle/quest/dof3","east"
                                                        });
}
realm(){return "NT";}

init() {
  ::init();
  add_action("unpile","unpile");
}

unpile(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "rocks") {
  write("With great effort you begin to unpile the rocks when suddenly..\n"+
	"you fall through to hidden room on the other side...\n");
  this_player()->move_player("falling#players/trix/castle/quest/Edof1.c");
  return 1; }
}
