#define FINAL 741070800
inherit "room/room";
object ob;
int count;
reset(arg) {
   if(arg)
      return;
count=0;
if(!present("poker machine")) {
  move_object(clone_object("/players/grimm/closed/obj/poker"),this_object());
}
/*
if(!present("fountain")) {
  move_object(clone_object("/players/grimm/q/o/fountain"),this_object());
}
*/
/*
if(!present("box")) {
  move_object(clone_object("/players/grimm/closed/obj/badge_stuff/vbox"),this_object());
}
*/
if(!present("board")) {
  move_object(clone_object("/players/grimm/closed/obj/badge_stuff/board"),this_object());
  }
short_desc="Doppleganger's Guild Party Room";
long_desc="This is the Doppleganger's Party Room.  You are obviously in\n"+
"the guild so this is the place for you to mingle with everybody and spend\n"+
"some time away from the scum of the mud since only the chosen can enter this\n"+
"room.\n";
dest_dir=({
           "/players/grimm/closed/obj/badge_stuff/info_rm","west",
           "/players/grimm/guild","east",
           "/room/church","church",
           "/room/shop","shop",
           "/players/grimm/guild","guild",
           "/room/adv_guild","adventures",
           "/room/pub2","pub",
           });
}

init() {
  if((!present("badge",this_player()) && !this_player()->query_npc())
     || environment(this_player())->id("cloud")) {
    write("YOU ARE NOT A DOPPLEGANGER!\nOnly the chosen will be allowed to enter this room!\n");
    say(capitalize(this_player()->query_real_name())+" tried to enter the room but gets kicked out!\n");
    move_object(this_player(),"/players/grimm/guild");
    write("Join our guild before entering the guild's party room.\n");
    return 1;
  }
  add_action("list","list");
  add_action("west","west");
  add_action("east","east");
  add_action("south","south");
  add_action("east","guild");
  add_action("shop","shop");
  add_action("church","church");
  add_action("pub","pub");
  add_action("adventures","adventures");
}

east() {
  this_player()->move_player("to the guild#/players/grimm/guild");
 return 1;
}

shop() {
  this_player()->move_player("to the shop#/room/shop");
  return 1;
}

church() {
  this_player()->move_player("to the church#/room/church");
  return 1;
}


adventures() {
  this_player()->move_player("to the adventures guild#/room/adv_guild");
  return 1;
}

pub() {
  this_player()->move_player("to the main pub#/room/pub2");
  return 1;
}

south() {
  if(this_player()->query_guild_rank()<10) {
    write("You are not a guild commander.\n");
    return 1;
  }
  this_player()->move_player("into hiding#/players/grimm/closed/obj/badge_stuff/pr_comm");
  return 1;
}

list() {
  "/players/grimm/closed/obj/badge_stuff/pr_comm"->list();
  return 1;
}

west() {
  if(FINAL>time()) {
    write("That direction is blocked...try again Friday at Midnight.\n");
    return 1;
  }
  this_player()->move_player("west#/players/grimm/closed/obj/badge_stuff/info_rm");
  return 1;
}
