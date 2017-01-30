inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "The Hall of Thoughts";
   long_desc="This the workroom of Trix, a newbie wiz , all Trix's thoughts fly around\n" + "the room and u think that now his head is absolutely empty!\n";
   set_light(1);
   dest_dir =
   ({
         "/room/church", "church",
         "/room/shop", "shop",
         "/players/grimm/closed/obj/badge_stuff/guild_pr", "guild",
         "room/post", "post",
    });
}
realm(){return "NT";}
