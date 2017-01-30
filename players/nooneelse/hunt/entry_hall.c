/*
  entry_hall.c - scavenger hunt entry hall
*/

inherit "room/room";

string list_of_names;

reset(arg) {
  set_light(1);
  short_desc="Scavenger Hunt Entry Hall";
  long_desc=
    "Scavenger Hunt Entry Hall\n"+
    "This the entry hall of the world famous Scavenger Hunt!  Go on up\n"+
    "and get your list!  There's a scroll displayed in a glass case.\n";
  dest_dir=
    ({
      "players/nooneelse/hunt/hunt_control", "up",
      "players/nooneelse/restaurant", "down",
    });
}

init() {
  ::init();

  add_action("read_scroll", "read");
  add_action("read_scroll", "examine");
  add_action("read_scroll", "look");
  add_action("open_case",   "open");
  add_action("open_case",   "break");
  add_action("open_case",   "get");
  add_action("open_case",   "take");
  add_action("add_name",    "add");
  add_action("remove_name", "remove");
  add_action("find_name",   "find");
}

read_scroll(str) {
  string str2, winner_entry, winner_name, winner_date;
  int player_found, i;
  if (!str) return 0;
  if (str=="at case" || str=="case" ||
      str=="at glass case" || str=="glass case") {
    write("It's a well constructed box of highly polished cherrywood, that\n"+
          "has clear, high quality, glass sides and top.  Through the glass\n"+
          "You can see a scroll that has been unrolled to let you read it.\n");
    return 1;
  }
  str2=0;
  sscanf(str,"at %s", str2);
  if (str != "scroll" && str2 != "scroll") return 0;
  write("Written on the scroll are the names of the winners of the Great"+
        " Scavenger Hunt.\n\n");
  i=1;
  player_found=0;
  winner_entry="x";
  while (winner_entry) {
    winner_entry=read_file("/players/nooneelse/hunt/winner_list", i);
    if (winner_entry=="" || winner_entry==0) winner_entry=0;
    if (winner_entry) {
      if (player_found) write(", ");
      sscanf(winner_entry, "%s#%s\n", winner_name, winner_date);
      if (winner_name) {
        player_found=1;
        write(capitalize(winner_name)+" "+winner_date+"\n");
      }
      i+=1;
    }
  }
  write("\n");
  if (!player_found) {
    write("Noone has won the Great Scavenger Hunt yet.  "+
          "You could be the first!\n");
  }
  return 1;
}

open_case(str) {
  if (!str) return 0;
  if (str=="case" || str=="glass case") {
    write("You can't do that.\n");
    return 1;
  }
  return 0;
}

add_name(player_entry) {
  string winner_name, winner_date;
  if (this_player()->query_level() < 32) return 0;
  if (!player_entry) {
    write("You must supply the name, date & time in the form\n"+
          "   Nooneelse#15 April 1993 13:32\n");
    return 1;
  }
  sscanf(player_entry, "%s#%s", winner_name, winner_date);
  if (!winner_name || !winner_date) {
    write("You must supply the name, date & time in the form\n"+
          "   Nooneelse#15 April 1993 13:32\n");
    return 1;
  }
  player_entry=player_entry+"\n";
  add_player(player_entry);
  return 1;
}

remove_name(player_entry) {
  string winner_name, winner_date;
  if (this_player()->query_level() < 32) return 0;
  if (!player_entry) {
    write("You must supply the name, date & time in the form\n"+
          "   Nooneelse#15 April 1993 13:32\n");
    return 1;
  }
  sscanf(player_entry, "%s#%s", winner_name, winner_date);
  if (!winner_name || !winner_date) {
    write("You must supply the name, date & time in the form\n"+
          "   Nooneelse#15 April 1993 13:32\n");
    return 1;
  }
  player_entry=player_entry+"\n";
  delete_player(player_entry);
  return 1;
}

/* -------------------- add a player to the list ---------------------- */
add_player(new_entry) {
  string str1, str2;
  string old_entry, old_name, old_date, new_name, new_date;
  int i, player_found;
  sscanf(new_entry, "%s#%s\n", new_name, new_date);
  i=1;
  player_found=0;
  /* make a new file with the new winner inserted */
  write_file(
    "/players/nooneelse/hunt/winner_list", new_name+"#"+new_date+"\n");
  write(capitalize(new_name)+"'s name has been added to the list.\n");
  return 1;
}

/* -------------------- remove a player from the list ----------------- */
delete_player(new_entry) {
  string str1, str2;
  string old_entry, old_name, old_date, new_name, new_date;
  int i, player_found;
  sscanf(new_entry, "%s#%s\n", new_name, new_date);
  i=1;
  player_found=0;
  /* make a new file without the player */
  old_entry=read_file("/players/nooneelse/hunt/winner_list", i);
  if (old_entry=="" || !old_entry) old_entry=0;
  while (old_entry) {
    sscanf(old_entry, "%s#%s\n", old_name, old_date);
    if (new_name==old_name)
      player_found=1;
    else
      write_file(
        "/players/nooneelse/hunt/tmp_list", old_name+"#"+old_date+"\n");
    i+=1;
    old_entry=read_file("/players/nooneelse/hunt/winner_list", i);
    if (old_entry=="" || !old_entry) old_entry=0;
  }
  i=1;
  /* copy the new file over the old one */
  rm("/players/nooneelse/hunt/winner_list");
  new_entry=read_file("/players/nooneelse/hunt/tmp_list", i);
  if (new_entry=="" || !new_entry) new_entry=0;
  while (new_entry) {
    sscanf(new_entry, "%s#%s\n", new_name, new_date);
    write_file(
      "/players/nooneelse/hunt/winner_list", new_name+"#"+new_date+"\n");
    i+=1;
    new_entry=read_file("/players/nooneelse/hunt/tmp_list", i);
    if (new_entry=="" || !new_entry) new_entry=0;
  }
  rm("/players/nooneelse/hunt/tmp_list");
  if (!player_found)
    write(capitalize(new_name)+"'s name is not on the list.\n");
  else
    write(capitalize(new_name)+"'s name has been removed from the list.\n");
  return 1;
}

/* -------------------- see if a player is on the list ---------------- */
find_name(find_name) {
  string old_entry, old_name, old_date;
  int player_found, i;
  i=1;
  player_found=0;
  old_entry=read_file("/players/nooneelse/hunt/winner_list", i);
  if (old_entry=="" || !old_entry) old_entry=0;
  while (old_entry && !player_found) {
    sscanf(old_entry, "%s#%s\n", old_name, old_date);
    if (find_name==old_name)
      player_found=1;
    else {
      i+=1;
      old_entry=read_file("/players/nooneelse/hunt/winner_list", i);
      if (old_entry=="" || !old_entry) old_entry=0;
    }
  }
  if (player_found)
    write(capitalize(find_name)+" is a winner.\n");
  else
    write(capitalize(find_name)+" is a not winner.\n");
  return 1;
}

/* --------------- see if a player is on the list remotely ----------- */
int is_in_hunt(string find_name) {
  string old_entry, old_name, old_date;
  int player_found, i;
  i=1;
  player_found=0;
  old_entry=read_file("/players/nooneelse/hunt/winner_list", i);
  if (old_entry=="" || !old_entry) old_entry=0;
  while (old_entry && !player_found) {
    sscanf(old_entry, "%s#%s\n", old_name, old_date);
    if (find_name==old_name)
      player_found=1;
    else {
      i+=1;
      old_entry=read_file("/players/nooneelse/hunt/winner_list", i);
      if (old_entry=="" || !old_entry) old_entry=0;
    }
  }
  if (player_found) return 1;
  return 0;
}
