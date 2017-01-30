inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
              "This is a room dug in the rock, you can see again without using a torch. A \n"+
              "triangular stone sticks out of the northern wall, while a strange green glare\n"+
              "comes from southwest.\n";
    short_desc = "A room in the rock";
    dest_dir = ({
                  "/players/trix/castle/quest/doe2","southwest"
                                                        });
    items=({ "stone","A smooth triangular stone sticking out of the southern wall, it looks like it\n"+
              "can be moved"});
}
init(){
 ::init();
     add_action("push","push");
     }
push(str)
{ if(str=="stone") {
   write("You pushes the stone and the walls starts trembling, then suddenly it turns\n"+
         "around itself dragging you in another room.\n");
   move_object(this_player(),"/players/trix/castle/quest/doc3");
   return 1;
   }
  return;
}
