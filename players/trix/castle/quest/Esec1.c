inherit "room/room";
reset(arg) {
   object guard;
   if(arg) return;
   set_light(1);
   long_desc =
              "A small narrow room, ancient graffiti cover the walls, you are curious about\n"+
              "them, and wonder about what they could mean. Maybe looking at them...\n";
    short_desc = "Graffitis room";
    dest_dir = ({
                  "/players/trix/castle/quest/sec2","east",
		"/players/trix/castle/quest/seg4","south"
                                                        });
    items=({ "graffiti","You examine the graffiti and notice three scenes, in the first you see a man\n"+
             "pushing himself against a square, in the second the same man shakes his head at\n"+
             "a circle and in the third the man pushes himself against a triangle"}); 
    guard=clone_object("/players/trix/castle/quest/monst/Eagguard");
    move_object(guard,this_object());
}
realm(){return "NT";}

init() {
  ::init();
  add_action("south","south");
}

south() {
if(present("guard")) {
  write("The guard whispers, 'That area is restricted, sorry!'\n");
  return 1; }
else {
  this_player()->move_player("south#players/trix/castle/quest/seg4.c");
  return 1; }
}
