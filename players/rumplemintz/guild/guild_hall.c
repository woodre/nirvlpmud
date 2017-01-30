#define FINAL 741070800
inherit "room/room";
object ob;
int count;
reset(arg) {
  if(arg) return;
  count=0;
  if(!present("fountain")) {
    move_object(clone_object("/players/rumplemintz/guild/obj/fountain"),this_object());
  }
  if(!present("board")) {
    move_object(clone_object("/players/rumplemintz/guild/guild_board"),this_object());
  }
  short_desc="Druid Guild Meeting Room";
  long_desc="This is the Druid's Meeting Room.  Only Druid's are allowed to\n"+
  "enter this room, so this is the place for you to mingle with your fellow\n"+
  "guildlings and spend some time away from the hassling of the mud.\n";
  dest_dir=({
    "/players/rumplemintz/guild/guild","northeast",
    "/room/church","church",
    "/room/shop","shop",
    "/room/adv_guild","adventurers",
    "/room/pub2","pub",
  });
}

init() {
  if((!present("Dguild",this_player()) && !this_player()->query_npc())) {
    write("YOU ARE NOT A DRUID!\nOnly they may enter this room!\n");
    say(capitalize(this_player()->query_real_name())+" tried to enter the room but gets rejected!\n");
    move_object(this_player(),"/players/rumplemintz/guild/guild");
    write("Join the guild before entering the guild's meeting room.\n");
    return 1;
  }
  add_action("list","list");
  add_action("northeast","northeast");
  add_action("south","south");
  add_action("shop","shop");
  add_action("church","church");
  add_action("pub","pub");
  add_action("advent","adventurers");
}

northeast() {
  this_player()->move_player("to the guild#/players/rumplemintz/guild/guild");
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

advent() {
  this_player()->move_player("to the adventurers guild#/room/adv_guild");
  return 1;
}

pub() {
  this_player()->move_player("to the main pub#/room/pub2");
  return 1;
}

south() {
  if(this_player()->query_guild_rank()<15) {
    write("You are not a Hierophant.\n");
    return 1;
  }
  this_player()->move_player("into hiding#/players/rumplemintz/guild/comm_hall");
  return 1;
}

list() {
  "/players/rumplemintz/guild/comm_hall"->list();
  return 1;
}
