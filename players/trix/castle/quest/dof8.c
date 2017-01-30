inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"  You're in a circular room.  It has nothing particular in it except\n"+
"for a crystal sphere put on a pedestal in the middle of the floor.\n";
    short_desc = "A room";
    dest_dir = ({
                  "/players/trix/castle/quest/dof7","west"});
    items=({"sphere","A crystal sphere, it's very dusty and it needs to be polished"});

}
init(){
 ::init();
   add_action("polish","polish");
}
polish(str)
 { if(str=="sphere") {write("Polish sphere with what?\n"); return 1;}
   if(str=="sphere with cloak") {  if(!present("trixcloak",this_player())) 
                                 write("You have nothing to polish the sphere with!\n");
           else { write("You polish the sphere with the cloak, the sphere starts emitting light, and in\n"+
                        "a flash you are transported to the presence of Melko, can you take the last\n"+
                        "challenge?\n");
                 move_object(this_player(),"/players/trix/castle/quest/melroom");
                 command("look",this_player());}
                 return 1;}
   return; 
}
realm(){return "NT";}
