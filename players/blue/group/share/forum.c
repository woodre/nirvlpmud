inherit"room/room.c";

reset(arg) {
   if(!arg) {
   
      if(!present("board", this_object())) 
         move_object(clone_object("/players/blue/group/share/board.c"),
              this_object());


   set_light(1);
   short_desc = "Group V";
   long_desc = "This is a forum for ideas and suggestions about the group.\n" +
      "I'll try to make this a little more interesting later!!!!\n";
   }
}

