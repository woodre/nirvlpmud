inherit "room/room";

reset(arg){
   if(!arg) {
     set_light(1);
     short_desc = "A Sea of Joy";
     long_desc = 
"You are on an island in a sea of pleasre and pain.\n"+
"This is where Blue lives.\n";

dest_dir = ( {
     "/players/grimm/closed/obj/badge_stuff/guild_pr" , "guild",
     "/players/grimm/closed/obj/badge_stuff/pr_comm" , "hide",
    "/room/church" , "church",
    "/room/shop" , "shop"
});
   }
}

