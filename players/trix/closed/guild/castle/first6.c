inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"The door opens with a loud whine from the hinges. The room is small and\n"+
"dirty. A large ornate bed sits in the back corner of the room. The\n"+
"bedding looks just made. A large ironclad chest sits on the floor next\n"+
"to the bed. A smaller golden altar to a similar god sits across the\n"+
"room from the bed. Religious ornaments are strewn about the floor.\n"+
"Someone seems to be praying here and pays no heed to you.\n"+
"To the South is the door in which you entered.\n";
    short_desc ="A bedroom";
    dest_dir = ({
                  "/players/trix/closed/guild/castle/first5.c","south"
                                                        });
    items=({ "altar","\nA huge and ornated marble altar that doesn't seem to be well firm on its base"});
}
init(){
 ::init();
     add_action("push","push");
     }
push(str)
{ if(str=="altar") {
   write("You push push the altar, that slowly slides off its base with squeaky sounds\n"+
         "revealing a secret passage. You waste no time and enter it as the altar goes\n"+
	 "back into its position on its own.\n");
   move_object(this_player(),"/players/trix/closed/guild/castle/first13");
   return 1;
   }
  return;
}
realm(){return "NT";}

