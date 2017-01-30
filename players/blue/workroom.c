inherit "room/room";

reset(arg){

   object board;
   if(!arg) {
     set_light(1);
     short_desc = "A Sea of Joy";
     long_desc = 
"You are on an island in a sea of pleasre and pain.\n"+
"This is where Blue lives.\n";

   board = clone_object("players/grimm/closed/obj/badge_stuff/board");
   move_object( board, this_object());

dest_dir = ( {
     "/players/grimm/closed/obj/badge_stuff/guild_pr" , "guild",
     "/players/grimm/closed/obj/badge_stuff/pr_comm" , "hide",
    "/room/church" , "church",
      "/players/blue/closed/shadow/rooms/guild_enter","shadow",
    "/room/shop" , "shop"
});


   }
}

heart_beat() {
  object ob;
  ob=first_inventory(this_object());
  while(ob) {
   ob->add_hit_points(10);
    ob=next_inventory(ob);
  }
  ::heart_beat();
}
