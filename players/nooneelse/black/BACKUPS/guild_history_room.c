/*
 guild_history_room.c
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

string str, player_name, player_name_period, str1, str2;
string list_of_names_a, list_of_names_b, list_of_names_c, list_of_names_d;
string list_of_names_e, list_of_names_f, list_of_names_g, list_of_names_h;
string list_of_names_i, list_of_names_j, list_of_names_k, list_of_names_l;
string list_of_names_m, list_of_names_n, list_of_names_o, list_of_names_p;
string list_of_names_q, list_of_names_r, list_of_names_s, list_of_names_t;
string list_of_names_u, list_of_names_v, list_of_names_w, list_of_names_x;
string list_of_names_y, list_of_names_z;

init() {
  ::init();

  add_action("read_plaque", "read");
  add_action("add_name",    "add");
  add_action("remove_name", "remove");
  add_action("find_member", "find");
  check_membership(this_player());
}


read_plaque(str) {
  if (!str) return;
  if (str != "sheet" && str != "floor" && str != "plaque") return;
  list_players();
  return 1;
}

add_name(player_name) {
  string this_guy;
  this_guy = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(this_guy)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(this_guy)!=GUILD_ASSISTANT)
    return;
  if (!player_name) {
    write("You must supply the name.\n");
    return 1;
  }
  add_player(player_name);
  return 1;
}


remove_name(player_name) {
  string this_guy;
  this_guy = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(this_guy)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(this_guy)!=GUILD_ASSISTANT)
    return;
  if (!player_name) {
    write("You must supply the name.\n");
    return 1;
  }
  delete_player(player_name);
  return 1;
}


reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Vampire Guild's Hall of History");
  no_castle_flag=1;
  dest_dir=
    ({
      "players/nooneelse/black/guild_coffin_room", "west",
    });
  restore_object("players/nooneelse/black/guild_history");
}

long(str) {
  if (str=="floor" || str=="plaque") return 0;
  write(
    "the Vampire Guild's Hall of History\n"+
    "This is a clean, well lit room.\n"+
    "The floor is one huge sheet of obsidian with many words etched into it.\n"+
    "  The four obvious exit is: west\n\n");
  return 1;
}

/* -------------------------- show the list --------------------------- */
list_players(str) {
  restore_object("players/nooneelse/black/guild_history");
  write("Which list do you want to see? [a-z, <cr>=quit] ");
  input_to("floor_more");
  return 1;
}

floor_more(answer) {
  answer = lower_case(answer);
  if (answer < "a" || answer > "z") return 1;
  write("\n\nEtched into the obsidian plaque are the names of the "+
        "Vampire Guild's Former Members.\n");
  if (answer=="a") write("\n"+list_of_names_a+"\n\n\n");
  if (answer=="b") write("\n"+list_of_names_b+"\n\n\n");
  if (answer=="c") write("\n"+list_of_names_c+"\n\n\n");
  if (answer=="d") write("\n"+list_of_names_d+"\n\n\n");
  if (answer=="e") write("\n"+list_of_names_e+"\n\n\n");
  if (answer=="f") write("\n"+list_of_names_f+"\n\n\n");
  if (answer=="g") write("\n"+list_of_names_g+"\n\n\n");
  if (answer=="h") write("\n"+list_of_names_h+"\n\n\n");
  if (answer=="i") write("\n"+list_of_names_i+"\n\n\n");
  if (answer=="j") write("\n"+list_of_names_j+"\n\n\n");
  if (answer=="k") write("\n"+list_of_names_k+"\n\n\n");
  if (answer=="l") write("\n"+list_of_names_l+"\n\n\n");
  if (answer=="m") write("\n"+list_of_names_m+"\n\n\n");
  if (answer=="n") write("\n"+list_of_names_n+"\n\n\n");
  if (answer=="o") write("\n"+list_of_names_o+"\n\n\n");
  if (answer=="p") write("\n"+list_of_names_p+"\n\n\n");
  if (answer=="q") write("\n"+list_of_names_q+"\n\n\n");
  if (answer=="r") write("\n"+list_of_names_r+"\n\n\n");
  if (answer=="s") write("\n"+list_of_names_s+"\n\n\n");
  if (answer=="t") write("\n"+list_of_names_t+"\n\n\n");
  if (answer=="u") write("\n"+list_of_names_u+"\n\n\n");
  if (answer=="v") write("\n"+list_of_names_v+"\n\n\n");
  if (answer=="w") write("\n"+list_of_names_w+"\n\n\n");
  if (answer=="x") write("\n"+list_of_names_x+"\n\n\n");
  if (answer=="y") write("\n"+list_of_names_y+"\n\n\n");
  if (answer=="z") write("\n"+list_of_names_z+"\n\n\n");
  write("Which list do you want to see? [a-z, <cr>=quit] ");
  input_to("floor_more");
  return 1;
}

/* -------------------- add a player to the list ---------------------- */
add_player(player_name) {
  restore_object("players/nooneelse/black/guild_history");
  player_name_period=player_name+".";
  if (sscanf(list_of_names_a, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_b, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_c, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_d, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_e, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_f, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_g, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_h, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_i, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_j, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_k, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_l, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_m, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_n, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_o, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_p, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_q, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_r, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_s, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_t, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_u, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_v, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_w, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_x, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_y, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_z, "%s"+player_name_period+"%s", str1, str2)==2) {
    write("That name's already on the list.\n");
  }
  else {
    if (extract(player_name_period, 0, 0)=="a")
      list_of_names_a=list_of_names_a+player_name_period;
    if (extract(player_name_period, 0, 0)=="b")
      list_of_names_b=list_of_names_b+player_name_period;
    if (extract(player_name_period, 0, 0)=="c")
      list_of_names_c=list_of_names_c+player_name_period;
    if (extract(player_name_period, 0, 0)=="d")
      list_of_names_d=list_of_names_d+player_name_period;
    if (extract(player_name_period, 0, 0)=="e")
      list_of_names_e=list_of_names_e+player_name_period;
    if (extract(player_name_period, 0, 0)=="f")
      list_of_names_f=list_of_names_f+player_name_period;
    if (extract(player_name_period, 0, 0)=="g")
      list_of_names_g=list_of_names_g+player_name_period;
    if (extract(player_name_period, 0, 0)=="h")
      list_of_names_h=list_of_names_h+player_name_period;
    if (extract(player_name_period, 0, 0)=="i")
      list_of_names_i=list_of_names_i+player_name_period;
    if (extract(player_name_period, 0, 0)=="j")
      list_of_names_j=list_of_names_j+player_name_period;
    if (extract(player_name_period, 0, 0)=="k")
      list_of_names_k=list_of_names_k+player_name_period;
    if (extract(player_name_period, 0, 0)=="l")
      list_of_names_l=list_of_names_l+player_name_period;
    if (extract(player_name_period, 0, 0)=="m")
      list_of_names_m=list_of_names_m+player_name_period;
    if (extract(player_name_period, 0, 0)=="n")
      list_of_names_n=list_of_names_n+player_name_period;
    if (extract(player_name_period, 0, 0)=="o")
      list_of_names_o=list_of_names_o+player_name_period;
    if (extract(player_name_period, 0, 0)=="p")
      list_of_names_p=list_of_names_p+player_name_period;
    if (extract(player_name_period, 0, 0)=="q")
      list_of_names_q=list_of_names_q+player_name_period;
    if (extract(player_name_period, 0, 0)=="r")
      list_of_names_r=list_of_names_r+player_name_period;
    if (extract(player_name_period, 0, 0)=="s")
      list_of_names_s=list_of_names_s+player_name_period;
    if (extract(player_name_period, 0, 0)=="t")
      list_of_names_t=list_of_names_t+player_name_period;
    if (extract(player_name_period, 0, 0)=="u")
      list_of_names_u=list_of_names_u+player_name_period;
    if (extract(player_name_period, 0, 0)=="v")
      list_of_names_v=list_of_names_v+player_name_period;
    if (extract(player_name_period, 0, 0)=="w")
      list_of_names_w=list_of_names_w+player_name_period;
    if (extract(player_name_period, 0, 0)=="x")
      list_of_names_x=list_of_names_x+player_name_period;
    if (extract(player_name_period, 0, 0)=="y")
      list_of_names_y=list_of_names_y+player_name_period;
    if (extract(player_name_period, 0, 0)=="z")
      list_of_names_z=list_of_names_z+player_name_period;
    save_object("players/nooneelse/black/guild_history");
    write(player_name+"'s name has been added to the list.\n");
  }
  return 1;
}

/* -------------------- remove a player from the list ----------------- */
delete_player(player_name) {
  int i;
  restore_object("players/nooneelse/black/guild_history");
  player_name_period=player_name+".";
  i=0;
  if (sscanf(list_of_names_a, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_a=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_b, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_b=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_c, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_c=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_d, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_d=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_e, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_e=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_f, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_f=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_g, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_g=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_h, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_h=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_i, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_i=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_j, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_j=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_k, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_k=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_l, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_l=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_m, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_m=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_n, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_n=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_o, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_o=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_p, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_p=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_q, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_q=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_r, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_r=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_s, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_s=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_t, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_t=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_u, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_u=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_v, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_v=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_w, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_w=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_x, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_x=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_y, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_y=str1+str2;
    i=1;
  }
  if (sscanf(list_of_names_z, "%s"+player_name_period+"%s", str1, str2)==2) {
    list_of_names_z=str1+str2;
    i=1;
  }
  if (i) {
    save_object("players/nooneelse/black/guild_history");
    write(player_name+"'s name has been removed from the list.\n");
  }
  else {
    write("That name's not on the list.\n");
  }
  return 1;
}

/* -------------------- see if a player is on the list ---------------- */
query_member(player_name) {
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(player_name)==GUILD_MASTER ||
      GUILD_OFFICE_FLOOR_TOP->find_officer(player_name)==GUILD_ASSISTANT ||
      GUILD_OFFICE_FLOOR_TOP->find_officer(player_name)==GUILD_LIEUTENANT)
    return 1;
  restore_object("players/nooneelse/black/guild_history");
  player_name_period=player_name+".";
  if (sscanf(list_of_names_a, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_b, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_c, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_d, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_e, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_f, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_g, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_h, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_i, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_j, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_k, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_l, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_m, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_n, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_o, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_p, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_q, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_r, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_s, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_t, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_u, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_v, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_w, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_x, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_y, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_z, "%s"+player_name_period+"%s", str1, str2)==2)
    return 1;
  else
    return 0;
}

find_member(player_name) {
  restore_object("players/nooneelse/black/guild_history");
  player_name_period=player_name+".";
  if (sscanf(list_of_names_a, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_b, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_c, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_d, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_e, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_f, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_g, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_h, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_i, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_j, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_k, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_l, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_m, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_n, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_o, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_p, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_q, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_r, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_s, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_t, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_u, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_v, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_w, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_x, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_y, "%s"+player_name_period+"%s", str1, str2)==2 ||
      sscanf(list_of_names_z, "%s"+player_name_period+"%s", str1, str2)==2)
    write(capitalize(player_name)+" is a vampire\n");
  else
    write(capitalize(player_name)+" is not a vampire\n");
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
