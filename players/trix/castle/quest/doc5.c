inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
              "A small room with smooth walls, except for a square stone that sticks out of\n"+
              "the eastern wall.\n";
    short_desc = "A lateral room";
    dest_dir = ({
                  "/players/trix/castle/quest/doc4","west",
                                                        });
    items=({ "stone","A smooth square stone sticking out of the eastern wall, it looks like it can\n"+
              "be moved"});
}
init(){
 ::init();
     add_action("push","push");
     }
push(str)
{ if(str=="stone") {
   write("You pushes the stone and the walls starts trembling, then suddenly it turns\n"+
         "around itself dragging you in another room.\n");
   move_object(this_player(),"/players/trix/castle/quest/doc6");
   return 1;
   }
  return;
}
realm(){return "NT";}

