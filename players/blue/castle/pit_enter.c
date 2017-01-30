inherit"room/room";

reset(arg) {

   if(!arg) {

   set_light(1);
   short_desc = "The Obsidian Abyss";
   long_desc =
"This is a dark room, almost too dark to see.  The walls are made of some\n"+
"kind of dark black stone, with a bright shine.  In the center of the room,\n"+
"carved in a perfect 10' circle into the floor, is an opening.  Below is\n"+
"utter blackness.\n";

dest_dir = ({
   "players/blue/castle/entrance","east"
   });

if(!present("warrior", this_object())) {
   object warrior;
   warrior = clone_object("players/blue/monster/plane_guardian");
   move_object(warrior, this_object());
   }

   }
}

init() {
  ::init();

  /*
  add_action("go_down","abyss");
   */

}

go_down() {
   if(present("warrior",this_object())) {
      write("You must kill the warrior first.\n");
      return 1;
   }
   call_other("players/blue/plane/plane_server","do_fall");
   return 1;
}

