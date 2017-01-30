/*
  keep_sales_office.c - sell player's personal keeps (castles)
*/

#define KEEP_COST 30000

inherit "room/room";
inherit "/players/nooneelse/closed/keep/keep_common";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc="Rainbow Inn Keep Sales Office";
  dest_dir =
    ({
      "/players/nooneelse/souvenir_shop", "north",
    });
}

long(str) {
  write("Rainbow Inn Keep Sales Office.\n"+
        "Here, you can buy a private Keep (castle) for 30,000 gold.\n"+
        "Only you may enter your private keep and the keep is yours\n"+
        "permanently, unless it's destroyed in combat.  Each keep\n"+
        "can be staffed with up to 10 soldiers to defend the keep\n"+
        "and to fire the cannon.  You can recruit soldiers in the\n"+
        "Rainbow Inn.\n"+
        "Use:  buy keep\n"+
        " or:  renew deed  (if you own one & lost the deed)\n");
  if (this_player()->query_level() >= 32)
    write("As a wizard, you can also, 'list keeps' that exist.\n");
}

init() {
  ::init();

  add_action("list_keeps",   "list");
  add_action("buy_keep",     "buy");
  add_action("renew_deed",   "renew");
}

/* --------------- see if a player is on the list remotely ----------- */
list_keeps(str) {
  string keep_entry, keep_owner;
  int keep_soldiers, keep_damage, keep_found, i;
  if (this_player()->query_level() < 32) return 0;
  i=1;
  keep_found=0;
  keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  if (keep_entry) write("\nkeep owner (# soldiers:damage)\n");
  while (keep_entry) {
    write(keep_entry);
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  return 1;
}

/* -------------------- add a keep to the list ---------------------- */
add_keep(player_name) {
  string str1, str2, keep_entry, keep_owner;
  int keep_soldiers, keep_damage, i, keep_found;
  i=1;
  keep_found=0;
  /* make a new file with the new keep inserted if none are on file */
  keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
  if (keep_entry=="" || !keep_entry) {
    keep_entry=0;
    keep_soldiers=0;
    keep_damage=0;
    write_file("/players/nooneelse/closed/keep/list_of_keeps",
               player_name+" (0:0)\n");
    write(capitalize(player_name)+" has been added to the "+
          "list of keep owners.\n");
    return 1;
  }
  while (keep_entry) {
    sscanf(keep_entry, "%s (%d:%d)\n", keep_owner, keep_soldiers, keep_damage);
    if (!keep_found) {
      if (keep_owner > player_name) {
        write_file("/players/nooneelse/closed/keep/tmp_list",
                   player_name+" (0:0)\n");
        keep_found=1;
      }
    }
    write_file("/players/nooneelse/closed/keep/tmp_list",
               keep_owner+" ("+keep_soldiers+":"+keep_damage+")\n");
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  if (!keep_found) {
    write_file("/players/nooneelse/closed/keep/tmp_list",
               player_name+" (0:0)\n");
    keep_found=1;
  }
  i=1;
  /* copy the new file over the old one */
  rm("/players/nooneelse/closed/keep/list_of_keeps");
  keep_entry=read_file("/players/nooneelse/closed/keep/tmp_list", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  while (keep_entry) {
    sscanf(keep_entry, "%s (%d:%d)\n", keep_owner, keep_soldiers, keep_damage);
    write_file("/players/nooneelse/closed/keep/list_of_keeps",
               keep_owner+" ("+keep_soldiers+":"+keep_damage+")\n");
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/tmp_list", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  rm("/players/nooneelse/closed/keep/tmp_list");
  write(capitalize(player_name)+" has been added to the "+
        "list of keep owners.\n");
  return 1;
}

/* --------------- see if a player is on the list remotely ----------- */
string owns_a_keep(string player_name) {
  string keep_entry, keep_owner, return_keep;
  int keep_soldiers, keep_damage, keep_found, i;
  i=1;
  keep_found=0;
  keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  while (keep_entry && !keep_found) {
    sscanf(keep_entry, "%s (%d:%d)\n", keep_owner, keep_soldiers, keep_damage);
    if (keep_owner==player_name)
      keep_found=1;
    else {
      i+=1;
      keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
      if (keep_entry=="" || !keep_entry) keep_entry=0;
    }
  }
  if (keep_found) {
    sscanf(keep_entry, "%s\n", return_keep);
    return return_keep;
  }
  else
    return " ";
}

buy_keep(str) {
  string str1, str2, keep_entry, keep_owner, save_keep_entry;
  int keep_soldiers, keep_damage, keep_size;
  object keep_obj, deed_obj;
  if (!str || str!="keep") return 0;
  if (this_player()->query_money("gold") < KEEP_COST) {
    write("They cost "+KEEP_COST+" gold, which you don't have.\n");
    return 1;
  }
  save_keep_entry=owns_a_keep(lower_case(this_player()->query_real_name()));
  if (save_keep_entry != " ") {
    write("You already own one.\n");
    return 1;
  }
  deed_obj=clone_object("/players/nooneelse/closed/keep/keep_deed");
  deed_obj->set_owner_name(keep_owner);
  deed_obj->set_owner_id(keep_owner);
  deed_obj->set_keep_size(keep_size);
  deed_obj->set_keep_soldiers(keep_soldiers);
  deed_obj->set_keep_damage(keep_damage);
  deed_obj->set_keep_obj(keep_obj);
  move_object(deed_obj, this_player());
  write("\nHere's the deed to your new keep.\n");
write(">>> right now they're free.\n");
/*
  this_player()->add_money(- KEEP_COST);
*/
  add_keep(lower_case(this_player()->query_real_name()));
  return 1;
}

renew_deed(str) {
  string str1, str2, keep_entry, keep_owner, save_keep_entry;
  int keep_soldiers, keep_damage, keep_size;
  object keep_obj, deed_obj;
  if (!str || str!="deed") return 0;
  save_keep_entry=owns_a_keep(lower_case(this_player()->query_real_name()));
  if (save_keep_entry==" ") {
    write("You don't own one.\n");
    return 1;
  }
  if (present("keep deed", this_player()))
    destruct(present("keep deed", this_player()));
  if (present("keep deed", this_player()))
    destruct(present("keep deed", this_player()));
  if (present("keep deed", this_player()))
    destruct(present("keep deed", this_player()));
  sscanf(save_keep_entry, "%s (%d:%d)\n",
         keep_owner, keep_soldiers, keep_damage);
  deed_obj=clone_object("/players/nooneelse/closed/keep/keep_deed");
  deed_obj->set_owner_name(keep_owner);
  deed_obj->set_owner_id(keep_owner);
  deed_obj->set_keep_size(keep_size);
  deed_obj->set_keep_soldiers(keep_soldiers);
  deed_obj->set_keep_damage(keep_damage);
  deed_obj->set_keep_obj(keep_obj);
  move_object(deed_obj, this_player());
  write("\nHere's the replacement deed to your keep.\n");
  return 1;
}

/* ------------ set a keep's soldiers # or damage # -------------- */
set_keep(str) {
  string str1, str2, player_name, keep_entry, keep_owner;
  string new_name;
  int setting_soldiers, setting_damage, amt, keep_soldiers;
  int i, keep_found;
  if (!str) return 0;
  player_name=0;
  setting_soldiers=0;
  setting_damage=0;
  if (sscanf(str, "%s soldiers %d", player_name, amt)==2) setting_soldiers=1;
  else
  if (sscanf(str, "%s damage %d", player_name, amt)==2) setting_damage=1;
  if (!setting_soldiers && !setting_damage) return 0;
  i=1;
  keep_found=0;
  /* make a new file with the player's new soldiers */
  keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  while (keep_entry) {
    sscanf(keep_entry, "%s (%d:%d)\n", keep_owner, keep_soldiers, keep_damage);
    if (keep_owner==player_name) {
      keep_found=1;
      if (setting_soldiers)
        write_file("/players/nooneelse/closed/keep/tmp_list",
                   player_name+" ("+amt+":"+keep_damage+")\n");
      if (setting_damage)
        write_file("/players/nooneelse/closed/keep/tmp_list",
                   player_name+" ("+keep_soldiers+":"+amt+")\n");
    }
    else
    write_file("/players/nooneelse/closed/keep/tmp_list",
               player_name+" ("+keep_soldiers+":"+keep_damage+")\n");
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  i=1;
  /* copy the new file over the old one */
  rm("/players/nooneelse/closed/keep/list_of_keeps");
  keep_entry=read_file("/players/nooneelse/closed/keep/tmp_list", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  while (keep_entry) {
    sscanf(keep_entry, "%s (%d:%d)\n", player_name, keep_soldiers, keep_damage);
    write_file("/players/nooneelse/closed/keep/list_of_keeps",
               player_name+" ("+keep_soldiers+":"+keep_damage+")\n");
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/tmp_list", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  rm("/players/nooneelse/closed/keep/tmp_list");
  if (!keep_found)
    write(capitalize(player_name)+"'s name is not on the list.\n");
  else
    write(capitalize(player_name)+
          "'s # of soldiers has been changed to "+amt+".\n");
  return 1;
}

/* -------------------- remove a keep from the list ----------------- */
destroy_keep(player_name) {
  string str1, str2, keep_entry, keep_owner;
  int keep_soldiers, keep_damage, i, keep_found;
  i=1;
  keep_found=0;
  /* make a new file without the player */
  keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  while (keep_entry) {
    sscanf(keep_entry, "%s (%d:%d)\n", player_name, keep_soldiers, keep_damage);
    if (keep_owner==player_name)
      keep_found=1;
    else
      write_file("/players/nooneelse/closed/keep/tmp_list",
                 player_name+" ("+keep_soldiers+":"+keep_damage+")\n");
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/list_of_keeps", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  i=1;
  /* copy the new file over the old one */
  rm("/players/nooneelse/closed/keep/list_of_keeps");
  keep_entry=read_file("/players/nooneelse/closed/keep/tmp_list", i);
  if (keep_entry=="" || !keep_entry) keep_entry=0;
  while (keep_entry) {
    sscanf(keep_entry, "%s (%d:%d)\n", player_name, keep_soldiers, keep_damage);
    write_file("/players/nooneelse/closed/keep/list_of_keeps",
               player_name+" ("+keep_soldiers+":"+keep_damage+")\n");
    i+=1;
    keep_entry=read_file("/players/nooneelse/closed/keep/tmp_list", i);
    if (keep_entry=="" || !keep_entry) keep_entry=0;
  }
  rm("/players/nooneelse/closed/keep/tmp_list");
  if (!keep_found)
    write(capitalize(player_name)+"'s name is not on the list.\n");
  else
    write(capitalize(player_name)+"'s name has been removed from the list.\n");
  return 1;
}
