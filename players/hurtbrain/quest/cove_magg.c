inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "A Dream";
   long_desc = "This is Hurtbrain's second workroom.Only few people can\n" +
      "enter it. You see many stranges box. Each one contain\n" +
      "something but from here You can't see what it is.\n"; 
      set_light(1);
   dest_dir =
   ({
         "/room/church", "church",
         "/room/shop", "shop",
         "/room/adv_guild", "adv",
    "/players/grimm/guild" , "guild",
         "room/post", "post",
         "/players/hurtbrain/castello/entrance", "castle",
         "/players/hurtbrain/workroom", "east"
    });
    items = ({"box",
    "You tremble in fear! You see a brain in this box!\n" });
}

realm(){return "NT";}
