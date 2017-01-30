/*
 guild_plaque.c
*/

/*

  NOTE: For this to work, after you clone this, you MUST call the function
        init_list() via a patch or the 'initlist' command.

*/

inherit "obj/treasure";

string str, list_of_names, player_name, player_name_period, str1, str2;

get() { return; } /* no picking this up :) */

reset(arg) {
  if (arg) return;

  short_desc=("An obsidian plaque");
  long_desc=("It is a huge obsidian sheet with words etched into it.\n");
  set_value(0);
  set_weight(99);
  set_id("guild_plaque");
/* ----- crete a new list if there's not one already ------------------ */
  restore_object("players/nooneelse/obj/guild_plaque");
  if (!list_of_names) {
    list_of_names=".Nooneelse the Supreme Vampire.";
    save_object("players/nooneelse/obj/guild_plaque");
  }
}


/* -------------------------- show the list --------------------------- */
list_players(str) {
  if (this_player()->query_level() < 22) return;

  write("Contents of the plaque:\n\n");
  restore_object("players/nooneelse/obj/guild_plaque");
  if (!list_of_names) {
    write("There are no names on the list.\n");
    return 1;
  }
  write(list_of_names+"\n");
  return 1;
}

/* -------------------- add a player to the list ---------------------- */
add_player(player_name) {
  if (this_player()->query_level() < 22) return;

  if (!player_name) {                                        /* no arg? */
    write("Use: add <player name>\n");
    return 1;
  }
  restore_object("players/nooneelse/obj/guild_plaque");
  player_name_period=player_name+".";
  if (sscanf(list_of_names, "%s"+player_name_period+"%s", str1, str2) == 2) {
    write("That name's already on the list.\n");
  }
  else {
    list_of_names=list_of_names+player_name_period; /* add player to list */
    save_object("players/nooneelse/obj/guild_plaque");
    write(player_name+"'s name has been added to the plaque.\n");
  }
  return 1;
}

/* -------------------- remove a player from the list ----------------- */
delete_player(player_name) {
  if (this_player()->query_level() < 22) return;

  if (!player_name) {                                        /* no arg? */
    write("Use: delete <player name>\n");
    return 1;
  }
  restore_object("players/nooneelse/obj/guild_plaque");
  player_name_period=player_name+".";
  if (sscanf(list_of_names, "%s"+player_name_period+"%s", str1, str2) == 2) {
    list_of_names = str1 + str2;
    save_object("players/nooneelse/obj/guild_plaque");
    write(player_name+"'s name has been removed from the plaque.\n");
  }
  else {
    write("That name's not on the list.\n");
  }
  return 1;
}
