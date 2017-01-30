/*
  alchemist_prohibit.c - list of players that quit or were expelled from the guild
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"
#include "/bin/_finger.c"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

string str, player_name, player_reason, str1, str2;
string *list_of_names;

init() {
  ::init();

  add_action("read_plaque",  "read");
  add_action("add_name",     "add");
  add_action("remove_name",  "remove");
  add_action("find_traitor", "find");
  check_membership(this_player());
}

read_plaque(str) {
  if (!str) return;
  if (str != "sheet" && str != "floor" && str != "plaque") return;
  list_players();
  return 1;
}

add_name(str) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return;
  if (!player_name) {
    write("You must supply the name.\n");
    return 1;
  }
  if (file_size("/players/nooneelse/Alchemist/prohibit/"+player_name)>0) {
    write(capitalize(player_name)+" is already on the prohibit list!\n");
    return 1;
  }
  if (sscanf(str, "%s %s", player_name, player_reason)!=2) {
    write("You must supply the reason.\n"+
          "Use: add <name> [E/CE/P/R/Q]\n"+
          "(E=expell, CE=council expell, P=prohibited, R=rejected, Q=quit)\n");
    return 1;
  }
  player_reason = capitalize(player_reason);
  if (player_reason!="E" &&
      player_reason!="CE" &&
      player_reason!="P" &&
      player_reason!="R" &&
      player_reason!="Q") {
    write("Invalid reason code.  "+
          "Use: add <name> [E/CE/P/R/Q]\n"+
          "(E=expell, CE=council expell, P=prohibited, R=rejected, Q=quit)\n");
    return 1;
  }
  add_player(player_name,player_reason);

  return 1;
}

remove_name(player_name) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return;
  if (!player_name) {
    write("You must supply the name.\n");
    return 1;
  }
  if (file_size("/players/nooneelse/Alchemist/prohibit/"+player_name)<0) {
    write(capitalize(player_name)+" is not on the prohibit list!\n");
    return 1;
  }
  delete_player(player_name);
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("Alchemist Guild's List of Former Members");
  no_castle_flag=1;
  dest_dir=
    ({
      ALCHEMIST_W_BOARD	, "north",
    });
}

long(str) {
  if (str=="floor" || str=="plaque") return 0;
  write(
    "This is a clean, well lit intersection with one entrance.\n"+
    "The floor is one huge sheet of opal with many words etched into it.\n"+
    "  The only obvious exit is: north\n\n");
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
    case "a": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/a*"); break;
    case "b": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/b*"); break;
    case "c": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/c*"); break;
    case "d": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/d*"); break;
    case "e": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/e*"); break;
    case "f": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/f*"); break;
    case "g": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/g*"); break;
    case "h": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/h*"); break;
    case "i": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/i*"); break;
    case "j": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/j*"); break;
    case "k": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/k*"); break;
    case "l": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/l*"); break;
    case "m": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/m*"); break;
    case "n": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/n*"); break;
    case "o": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/o*"); break;
    case "p": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/p*"); break;
    case "q": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/q*"); break;
    case "r": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/r*"); break;
    case "s": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/s*"); break;
    case "t": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/t*"); break;
    case "u": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/u*"); break;
    case "v": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/v*"); break;
    case "w": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/w*"); break;
    case "x": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/x*"); break;
    case "y": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/y*"); break;
    case "z": list_of_names=get_dir("/players/nooneelse/Alchemist/prohibit/z*"); break;
  }
  if (!list_of_names) {
    write("There are no former member's names starting with '"+answer+"'.\n");
    return 1;
  }
  write("\n\nEtched into the opal names of the "+
        "Alchemist Guild's Former Members.\n");
  write(implode(list_of_names, ", ")+"\n\n");
  write("Which list do you want to see? [a-z, <cr>=quit] ");
  input_to("floor_more");
  return 1;
}

/* -------------------- add a player to the list ---------------------- */
add_player(player_name,player_reason) {
  if (file_size("/players/nooneelse/Alchemist/prohibit/"+player_name)>0) {
    write(capitalize(player_name)+" is already on the list.\n");
    return 1;
  }
  write_file("/players/nooneelse/Alchemist/prohibit/"+player_name, ctime(time())+"\n");
  write_file("/players/nooneelse/Alchemist/prohibit/"+player_name,
             "["+capitalize(player_reason)+"]\n");
  write(capitalize(player_name)+"'s name has been added to the list.\n");
  return 1;
}

/* -------------------- remove a player from the list ----------------- */
delete_player(player_name) {
  string date, code;

  if (file_size("/players/nooneelse/Alchemist/prohibit/"+player_name)<0) {
    write(capitalize(player_name)+" is not on the prohibit list.\n");
    return 1;
  }
  rm("/players/nooneelse/Alchemist/prohibit/"+player_name);
  write(capitalize(player_name)+"'s name has been removed from the list.\n");
  return 1;
}

/* -------------------- see if a player is on the list ---------------- */
query_traitor(player_name) {
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) return 0;
  if (file_size("/players/nooneelse/Alchemist/prohibit/"+player_name)>0) return 1;
  return 0;
}

find_traitor(player_name) {
  string time, reason;

  if (file_size("/players/nooneelse/Alchemist/prohibit/"+player_name)>0) {
    write(capitalize(player_name)+" is not a former Alchemist\n");
    return 1;
  }
  time = read_file("/players/nooneelse/Alchemist/prohibit/"+player_name, 1, 1);
  reason = read_file("/players/nooneelse/Alchemist/prohibit/"+player_name, 2, 1);
  write(capitalize(player_name)+" is a former Alchemist "+time+"  ["+reason+"]\n");
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
