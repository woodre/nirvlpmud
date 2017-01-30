inherit "room/room";
reset(arg) {
   object altar;
   if(arg) return;
   set_light(0);
   long_desc =
              "You reached a tiny room with walls covered with graffitis showing scenes of \n"+
              "human sacrifices, offered to an evil and powerful God. A square stone sticks out\n"+
              "of the western wall. You notice a small altar in the middle of the room.\n";
    short_desc = "A lateral room";
    items=({ "stone","A smooth square stone sticking out of the western wall, it looks like it can\n"+
              "be moved"});
    altar=clone_object("/players/trix/castle/quest/monst/altar");
    move_object(altar,this_object());
}
init(){
 ::init();
     add_action("push","push");
     }
push(str)
{ if(str=="stone") {
   write("You pushes the stone and the walls starts trembling, then suddenly it turns\n"+
         "around itself dragging you in another room.\n");
   move_object(this_player(),"/players/trix/castle/quest/doc5");
   return 1;
   }
  return;
}
realm(){return "NT";}
