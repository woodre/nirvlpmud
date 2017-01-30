/*
  alchemist_central.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"
#include "/bin/_finger.c"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

string str, player_name, player_name_period, str1, str2;
string *list_of_names;

init() {
  ::init();

  add_action("read_sign",      "read");
  add_action("read_sign",      "look");
  add_action("read_sign",      "examine");
  add_action("portal",         "portal");
  add_action("post",           "post");
  add_action("shop",           "shop");
  add_action("adv_guild",      "guild");
  add_action("church",         "church");
  add_action("lockers",        "lockers");
  add_action("hotel",          "hotel");
  add_action("forest",         "forest");
  add_action("daycare",        "daycare");
  add_action("read_plaque",    "read");
  add_action("add_name",       "add");
  add_action("remove_name",    "remove");
  add_action("find_member",    "find");
  add_action("make_dispenser", "make");
  add_action("cleanup_list",   "cleanup");
  check_membership(this_player());
}

read_sign(str) {
  if (str=="sign" || str=="at sign") {
    write(NORM+HIB+"  Some not-so-obvious exits are:\n"+NORM+
               HIC+"    'portal' --> go to the portal\n"+
                   "    'post'   --> go to the mud's post office\n"+
                   "    'shop'   --> go to the main shop\n"+
                   "    'guild'  --> go to the main adventurer's guild\n"+
                   "    'church' --> go to the church\n"+
                   "    'lockers'--> go to the lockers (Catwoman's area)\n"+
                   "    'hotel'  --> go to the lobby of the hotel\n"+
                   "    'forest' --> go to the entry of the forest (Nooneelse's area)\n"+
                   "    'daycare'--> go to the daycare\n"+NORM);
    return 1;
  }
}

portal() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("/players/saber/ryllian/portal", "???", 0);
  move_object(this_player(), "/players/saber/ryllian/portal");
  write("You fly to the portal.\n\n");
  command("look", this_player());
  return 1;
}

post() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("room/post", "???", 0);
  move_object(this_player(), "room/post");
  write("You fly to the post office.\n\n");
  command("look", this_player());
  return 1;
}

shop() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("room/shop", "???", 0);
  move_object(this_player(), "room/shop");
  write("You fly to the main shop.\n\n");
  command("look", this_player());
  return 1;
}

adv_guild(str) {
  if (str=="news") return 0;
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("room/adv_guild", "???", 0);
  move_object(this_player(), "room/adv_guild");
  write("You fly to the main adventurer's guild.\n\n");
  command("look", this_player());
  return 1;
}

church() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("room/church", "???", 0);
  move_object(this_player(), "room/church");
  write("You fly to the church.\n\n");
  command("look", this_player());
  return 1;
}

lockers() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("/players/catwoman/tl", "???", 0);
  move_object(this_player(), "/players/catwoman/tl");
  write("You fly to the main lockers.\n\n");
  command("look", this_player());
  return 1;
}

hotel() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("/players/boltar/hotel/hotel", "???", 0);
  move_object(this_player(), "/players/boltar/hotel/hotel");
  write("You fly to the hotel.\n\n");
  command("look", this_player());
  return 1;
}

forest() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("/players/nooneelse/entryforest/e_forest0", "???", 0);
  move_object(this_player(), "/players/nooneelse/entryforest/e_forest0");
  write("You fly to the main forest.\n\n");
  command("look", this_player());
  return 1;
}

daycare() {
  say("A mist envelops "+this_player()->query_name()+
      ".  When it clears, "+this_player()->query_name()+" is gone.\n");
  call_other("/players/boltar/sprooms/daycare", "???", 0);
  move_object(this_player(), "/players/boltar/sprooms/daycare");
  write("You fly to the daycare center.\n\n");
  command("look", this_player());
  return 1;
}

read_plaque(str) {
  if (!str) return;
  if (str != "sheet" && str != "floor" && str != "plaque") return;
  list_players();
  return 1;
}

add_name(player_name) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return;
  if (!player_name) {
    write("You must supply the name.\n");
    return 1;
  }
  if (file_size("/players/nooneelse/Alchemist/member/"+player_name)>0) {
    write(capitalize(player_name)+" is already a member!\n");
    return 1;
  }
  add_player(player_name);
  return 1;
}

remove_name(player_name) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return;
  if (!player_name) {
    write("You must supply the name.\n");
    return 1;
  }
  if (file_size("/players/nooneelse/Alchemist/member/"+player_name)<0) {
    write(capitalize(player_name)+" is not a member!\n");
    return 1;
  }
  delete_player(player_name);
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("Alchemist Guild's Main Hall");
  no_castle_flag=1;
  dest_dir=
    ({
      ALCHEMIST_LOBBY,     "up",
      ALCHEMIST_P_BOARD,   "west",
      ALCHEMIST_DONATION,  "east",
      ALCHEMIST_W_BOARD,   "south",
      ALCHEMIST_SHELF,     "southwest",
      ALCHEMIST_COMPONENT, "southeast",
    });
}

long(str) {
  if (str=="floor" || str=="plaque") return 0;
  write(
    "This is a clean, well lit intersection with six entrances.\n"+
    "The floor is one huge sheet of platinum with many words etched into it.\n"+
    "  The six obvious exits are: up, west, east, south, southwest, southeast\n\n");
  return 1;
}

/* -------------------------- show the list --------------------------- */
list_players(str) {
  write("Which list do you want to see? [a-z, <cr>=quit] ");
  input_to("floor_more");
  return 1;
}

floor_more(answer) {
  answer = lower_case(answer);
  if (answer < "a" || answer > "z") return 1;
  switch (answer) {
    case "a": list_of_names=get_dir("/players/nooneelse/Alchemist/member/a*"); break;
    case "b": list_of_names=get_dir("/players/nooneelse/Alchemist/member/b*"); break;
    case "c": list_of_names=get_dir("/players/nooneelse/Alchemist/member/c*"); break;
    case "d": list_of_names=get_dir("/players/nooneelse/Alchemist/member/d*"); break;
    case "e": list_of_names=get_dir("/players/nooneelse/Alchemist/member/e*"); break;
    case "f": list_of_names=get_dir("/players/nooneelse/Alchemist/member/f*"); break;
    case "g": list_of_names=get_dir("/players/nooneelse/Alchemist/member/g*"); break;
    case "h": list_of_names=get_dir("/players/nooneelse/Alchemist/member/h*"); break;
    case "i": list_of_names=get_dir("/players/nooneelse/Alchemist/member/i*"); break;
    case "j": list_of_names=get_dir("/players/nooneelse/Alchemist/member/j*"); break;
    case "k": list_of_names=get_dir("/players/nooneelse/Alchemist/member/k*"); break;
    case "l": list_of_names=get_dir("/players/nooneelse/Alchemist/member/l*"); break;
    case "m": list_of_names=get_dir("/players/nooneelse/Alchemist/member/m*"); break;
    case "n": list_of_names=get_dir("/players/nooneelse/Alchemist/member/n*"); break;
    case "o": list_of_names=get_dir("/players/nooneelse/Alchemist/member/o*"); break;
    case "p": list_of_names=get_dir("/players/nooneelse/Alchemist/member/p*"); break;
    case "q": list_of_names=get_dir("/players/nooneelse/Alchemist/member/q*"); break;
    case "r": list_of_names=get_dir("/players/nooneelse/Alchemist/member/r*"); break;
    case "s": list_of_names=get_dir("/players/nooneelse/Alchemist/member/s*"); break;
    case "t": list_of_names=get_dir("/players/nooneelse/Alchemist/member/t*"); break;
    case "u": list_of_names=get_dir("/players/nooneelse/Alchemist/member/u*"); break;
    case "v": list_of_names=get_dir("/players/nooneelse/Alchemist/member/v*"); break;
    case "w": list_of_names=get_dir("/players/nooneelse/Alchemist/member/w*"); break;
    case "x": list_of_names=get_dir("/players/nooneelse/Alchemist/member/x*"); break;
    case "y": list_of_names=get_dir("/players/nooneelse/Alchemist/member/y*"); break;
    case "z": list_of_names=get_dir("/players/nooneelse/Alchemist/member/z*"); break;
  }
  if (!list_of_names) {
    write("There are no former member's names starting with '"+answer+"'.\n");
    return 1;
  }
  write("\n\nEtched into the opal plaque are the names of the "+
        "Alchemist Guild's Members.\n");
  write(implode(list_of_names, ", ")+"\n\n");
  write("Which list do you want to see? [a-z, <cr>=quit] ");
  input_to("floor_more");
  return 1;
}

/* -------------------- add a player to the list ---------------------- */
add_player(player_name) {
  if (file_size("/players/nooneelse/Alchemist/member/"+player_name)>0) {
    write(capitalize(player_name)+" is already on the list.\n");
    return 1;
  }
  write_file("/players/nooneelse/Alchemist/member/"+player_name, ctime(time())+"\n");
  write_file("/players/nooneelse/Alchemist/member/"+player_name, "[J]\n");
  write(capitalize(player_name)+"'s name has been added to the list.\n");
  return 1;
}

/* -------------------- remove a player from the list ----------------- */
delete_player(player_name) {
  string date, code;

  if (file_size("/players/nooneelse/Alchemist/member/"+player_name)<0) {
    write(capitalize(player_name)+" is not a member.\n");
    return 1;
  }

  rm("/players/nooneelse/Alchemist/member/"+player_name);
  write_file("/players/nooneelse/Alchemist/prohibit/"+player_name, ctime(time())+"\n");
  write_file("/players/nooneelse/Alchemist/prohibit/"+player_name, "[Q]\n");
  write(player_name+"'s name has been removed from the list.\n");
  return 1;
}

/* -------------------- see if a player is on the list ---------------- */
query_member(player_name) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return 1;
  if (file_size("/players/nooneelse/Alchemist/member/"+player_name)>0) return 1;
  return 0;
}

find_member(player_name) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) {
    write(capitalize(player_name)+" is the Alchemist Guild's Master.\n");
    return 1;
  }
  if (file_size("/players/nooneelse/Alchemist/member/"+player_name)>0)
    write(capitalize(player_name)+" is an Alchemist\n");
  else
    write(capitalize(player_name)+" is not an Alchemist\n");
  return 1;
}

id(str) {
  str2=0;
  sscanf(str,"at %s", str2);
  if (str=="sheet" || str=="floor" || str=="plaque"||
      str2=="sheet" || str2=="floor" || str2=="plaque") {
    read_plaque("sheet");
    return 1;
  }
}

realm() { return "NT"; }
