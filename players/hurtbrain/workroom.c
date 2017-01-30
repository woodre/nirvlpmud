#define HEAL 500

inherit "room/room";
reset(arg) {
   if(arg) return;
   short_desc = "The Castle of Dreams";
   long_desc = "You see a beautiful room with a large balcony on a\n" +
   "wonderful hearth shaped swimming-pool. The fresh water\n" +
   "invite you to take a bath.If you want you can do it!\n" +
   "You see some red glowing objects on a ancient table;\n" +
   "all the other objects are glowing a brillant blue.\n" +
   "You would never exit from this room!!\n"; 
    dest_dir = ({ 
    "room/church", "church",
    "room/post"  , "post" ,
    "room/adv_guild" , "adv" ,
    "room/shop"  , "shop" ,
    "/players/gorgan/closed/guild/guild_room.c" , "guild",
    "players/hurtbrain/castello/entrance" , "castle" ,
    "players/hurtbrain/workroom2" , "west"
    });
   set_light(1);

}

init(){
    ::init();
        add_action("bath","bath");
        add_action("closet","closet");
}
closet()  {
       write("You enter a wardrobe.\n");
        say(this_player()->query_name() + " enters a wardrobe.\n");
        move_object(this_player(), "/players/hurtbrain/closet");
	say(this_player()->query_name() + " enters the room.\n");
      command("look",this_player());
      return 1;
}

bath() {

    int res,max;

    write ("You take a wonderful bath, the water is limpid and fresh.\n" +
    "Some beautiful girls are laying on the board of the swimmin-pool:\n" +
    "a real dream! You're somewhat healed from this.\n") ;
    say (this_player()->query_name() + " is taking a bath.\n");
if(this_player()->query_level() > 19)
    call_other(this_player(),"heal_self",HEAL);
    return 1;
}

realm(){return "NT";}
