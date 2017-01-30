inherit "room/room";
object ob;
int count;
reset(arg) {
  if(arg)
  return;
  count=0;
  if(!present("fountain")) {
    move_object(clone_object("/players/rumplemintz/guild/obj/fountain"),this_object());
  }
  if(!present("cboard")) {
    move_object(clone_object("/players/rumplemintz/guild/comm_board"),this_object());
  }
  short_desc="Hierophant's Hideout";
  long_desc="This is the hideout for Hierophant Druids only.\n";
  dest_dir=({
    "/players/rumplemintz/guild/guild","east",
    "/players/rumplemintz/guild/guild_hall", "north",
    "/room/church","church",
    "/room/shop","shop",
    "/room/adv_guild","adventurers",
    "/room/pub2","pub",
  });
}


init() {
  if((!present("Dguild",this_player()) && !this_player()->query_npc())) {
    write("YOU ARE NOT A DRUID!\nOnly members may enter this room!\n");
    say(capitalize(this_player()->query_real_name())+" tried to enter the room but gets kicked out!\n");
    move_object(this_player(),"/players/rumplemintz/guild/guild");
    write("Join the guild before entering the guild's meeting room.\n");
    return 1;
  }
  if((this_player()->query_guild_rank()<15 && !this_player()->query_npc())) {
    write("You are not a hierophant.\n");
    move_object(this_player(),"/players/rumplemintz/guild/guild_hall");
    return 1;
  }
  add_action("list","list");
  add_action("east","east");
  add_action("north","north");
  add_action("shop","shop");
  add_action("church","church");
  add_action("pub","pub");
  add_action("adventurers","adventurers");
}

east() {
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

adventurers() {
  this_player()->move_player("to the adventures guild#/room/adv_guild");
  return 1;
}

pub() {
  this_player()->move_player("to the main pub#/room/pub2");
  return 1;
}

north() {
  this_player()->move_player("to the meeting room#/players/rumplemintz/guild/guild_hall");
  return 1;
}

list() {
  write("Current guild commanders/leaders are:\n");
  write("   Guild Master:                    Rumplemintz\n");
  write("   Assistant Guild Master:          Dersharp\n");
  write("   Guild Wizzies:                   <none>\n");
  write("   Guild Hierophants:               <open>\n");
  write("   Grand Master Druid:              <open>\n");
  return 1;
}
