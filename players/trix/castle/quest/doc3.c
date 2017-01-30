inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   long_desc =
              "A small room with smooth walls, except for a triangular stone that sticks out\n"+
              "of the southern wall.\n";
    short_desc = "A lateral room";
    dest_dir = ({
                  "/players/trix/castle/quest/doc4","east",
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
   move_object(this_player(),"/players/trix/castle/quest/dod3");
   return 1;
   }
  return;
}
realm(){return "NT";}
