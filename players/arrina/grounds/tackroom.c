  inherit "room/room";
  reset(arg){
   if(!present("groom")) {
 move_object(clone_object("/players/arrina/monsters/groom.c"),this_object());
 }
    if(!arg){
    set_light(0);
    short_desc="Tackroom";
   long_desc=
  "You have entered the tackroom, which is musty and dank. There\n" +
  "are old saddles on racks and harnesses hang from hooks on the\n" +
  "walls. The smell of fine leather and saddlesoap lingers, although\n" +
  "nothing in here has been used for a very long time.\n";
     items=({
   "harnesses", "These beautiful harnesses have cracked with age and\n"+
            "lack of care, and the brass buckles are tarnished",
   "saddles","The beautiful saddles are dusty and filthy",
  });
   dest_dir=({
  "/players/arrina/grounds/stable.c","east",
   });
  }
}
   init()  {
  ::init();
   add_action("search_room","search");
         }
  search_room() {
   write("You search through the room but find nothing.\n");
 say (this_player()->query_name() +" searches the room but finds nothing.\n");
   return 1;         }
