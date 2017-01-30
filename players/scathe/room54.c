inherit "room/room";
init(){
   ::init();
   add_action("go_west","west");
}
reset(arg) {
   if(arg) return;
   short_desc = "room54";
   long_desc = "This is the entrance to the level 4 newbie.\n"+
   "area. Level 1,2,3,4 players may go west, all others\n"+
   "must continue on.\n";
   set_light(1);
   dest_dir =
   ({
         "/players/sweetness/room/room57", "north",
         "/players/sweetness/room/room51", "south",
         "/players/sweetness/room/room55","west",
    });
}
go_west(){
   object who;
   if(this_player()->query_level() < 5){
      who = this_player();
      move_object(this_player(),"/players/sweetness/room/room55");
      command("look",who);
      return 1;
   }
   write("You must be level 1,2,3 or 4 to enter this area!\n");
   return 1;
}
