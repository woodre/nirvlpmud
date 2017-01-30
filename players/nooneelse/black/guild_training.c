/*
 guild_training.c
*/

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

#include "lib/defs.h"

object board;
string str, new_title, male_title_str, fem_title_str, neut_title_str, my_gender;
int i, player_level;

init() {
  ::init();

  add_action("east",        "east");
  add_action("read",        "read");
/*
  add_action("fix_title",   "fix");
  add_action("show_titles", "show");
*/
  check_membership(this_player());
}

east() {
  string this_guy;
  this_guy = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(this_guy)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(this_guy)!=GUILD_ASSISTANT) {
    say (this_player()->query_name()+
         " tries to pass the shimmering to the east and fails.\n");
    return 1;
  }
  move_object(this_player(), "/players/nooneelse/black/guild_prohibit");
  command("glance", this_player());
  return 1;
}

read(str) {
  if (!str && str != "plaque") return;
  command("look at plaque", this_player());
  say (this_player()->query_name()+" examines the gold plaque on the wall.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc =
    "The Vampire Guild's Bulletin Board Room\n";
  no_castle_flag=1;
  long_desc =
    "You can leave messages here on our private board.\n"+
    "There is a gold plaque with writing on it fastened to the wall.\n";
/*
    "\nYou can fix your title by comming here and typing: fix title\n"+
    "Or see the titles for your gender by typing:       show titles\n";
*/
  items =
    ({
     "wall",
     "It looks like there's an opening that's blocked by the shimmering",
     "shimmering",
     "It looks like the shimmering is blocking an opening",
     "opening", "A doorway",
     "plaque",
       "   ................... Vampire Guild Rules ...................\n"+
       "   :                                                         :\n"+
       "   : > No biting anyone unless they want you to              :\n"+
       "   :                                                         :\n"+
       "   : > Three different vampires must bite the prospective    :\n"+
       "   :   member                                                :\n"+
       "   :                                                         :\n"+
       "   : > One of the members who recruited the new vampire      :\n"+
       "   :   show him/her/it how to use the abilities and how to   :\n"+
       "   :   get to the guild rooms                                :\n"+
       "   :                                                         :\n"+
       "   : > These guild abilities are to help you, the players,   :\n"+
       "   :   have fun, not to take advantage of other players      :\n"+
       "   :   and/or bugs.  If you do this, you will be removed     :\n"+
       "   :   from the guild & reported to the gods.                :\n"+
       "   :                                                         :\n"+
       "   : > If you, the members want to see some new rules or     :\n"+
       "   :   abilities or if there are problems with the           :\n"+
       "   :   abilities, leave a note on the board.                 :\n"+
       "   ..........................................................",
    });
  dest_dir =
    ({
      "players/nooneelse/black/guild_lower_hall", "west",
      "players/nooneelse/black/guild_history_hall", "north",
  "players/eurale/Vamp/RMS/titles.c","south",
    });
  if (!present("board", this_object())) {
    board = clone_object("players/nooneelse/black/guild_board");
    move_object(board, this_object());
  }
}

/* -------- Fix this player's title ---------- */
fix_title(str) {
  if (!str || !str=="title") return;
  new_title=get_new_title();
  this_player()->set_title(new_title);
  return 1;
}

/*  return the player's title for his/her/it's level */
get_new_title(player_level) {
  if (!male_title_str) fill_title_tables();
  if (this_player()->query_real_name()=="nooneelse") {
    this_player()->set_title("the Supreme Vampire");
    return 1;
  }
  if (this_player()->query_real_name()=="nancy") {
    this_player()->set_title("the Assistant Supreme Vampire");
    return 1;
  }
  if (this_player()->query_real_name()=="magus") {
    this_player()->set_title("the Assistant Supreme Vampire");
    return 1;
  }
  player_level = this_player()->query_level();
  if (player_level > 19) {
    write("You're a wizard, so I'm not going to change your title.\n");
    return 1;
  }
  if (!this_player() || this_player()->query_gender()=="creature")
    return neut_title_str[player_level];
  if (this_player()->query_gender() == "male")
    return male_title_str[player_level];
  if (this_player()->query_gender() == "female")
    return fem_title_str[player_level];
}

/* get new title remotely */
remote_get_title(player_level, my_gender) {
  if (!male_title_str) fill_title_tables();
  if (player_level > 19) return;
  if (my_gender=="male") return male_title_str[player_level];
  if (my_gender=="female") return fem_title_str[player_level];
  if (my_gender=="creature") return neut_title_str[player_level];
  return;
}

fill_title_tables() {
  male_title_str = allocate(21);

  male_title_str[20]    ="the vampire high guild master";
  male_title_str[19]    ="the vampire guild master";
  male_title_str[18]    ="the grand master sorcerer";
  male_title_str[17]    ="the master sorcerer";
  male_title_str[16]    ="the apprentice sorcerer";
  male_title_str[15]    ="the master of illusions";
  male_title_str[14]    ="the initiate of illusions";
  male_title_str[13]    ="the master of the elements";
  male_title_str[12]    ="the master of darkness";
  male_title_str[11]    ="the initiate of darkness";
  male_title_str[10]    ="the master of mists";
  male_title_str[9]     ="the initiate of mists";
  male_title_str[8]     ="the master of shadows";
  male_title_str[7]     ="the initiate of shadows";
  male_title_str[6]     ="the master of domination";
  male_title_str[5]     ="the initiate of domination";
  male_title_str[4]     ="the brother";
  male_title_str[3]     ="the disciple";
  male_title_str[2]     ="the initiate";
  male_title_str[1]     ="the watcher";
  male_title_str[0]     ="the utter novice";

  fem_title_str = allocate(21);

  fem_title_str[20]     ="the vampire high guild mistress";
  fem_title_str[19]     ="the vampire guild mistress";
  fem_title_str[18]     ="the grand mistress of sorcery";
  fem_title_str[17]     ="the mistress of sorcery";
  fem_title_str[16]     ="the apprentice sorceress";
  fem_title_str[15]     ="the mistress of illusions";
  fem_title_str[14]     ="the initiate of illusions";
  fem_title_str[13]     ="the mistress of the elements";
  fem_title_str[12]     ="the mistress of darkness";
  fem_title_str[11]     ="the initiate of darkness";
  fem_title_str[10]     ="the mistress of mists";
  fem_title_str[9]      ="the initiate of mists";
  fem_title_str[8]      ="the mistress of shadows";
  fem_title_str[7]      ="the initiate of shadows";
  fem_title_str[6]      ="the mistress of domination";
  fem_title_str[5]      ="the initiate of domination";
  fem_title_str[4]      ="the sister";
  fem_title_str[3]      ="the disciple";
  fem_title_str[2]      ="the initiate";
  fem_title_str[1]      ="the watcher";
  fem_title_str[0]      ="the utter novice";

  neut_title_str = allocate(21);

  neut_title_str[20]    ="the vampire high guild master";
  neut_title_str[19]    ="the vampire guild master";
  neut_title_str[18]    ="the grand sage of sorcery";
  neut_title_str[17]    ="the sage of sorcery";
  neut_title_str[16]    ="the apprentice sorcerer";
  neut_title_str[15]    ="the sage of illusions";
  neut_title_str[14]    ="the initiate of illusions";
  neut_title_str[13]    ="the sage of the elements";
  neut_title_str[12]    ="the sage of darkness";
  neut_title_str[11]    ="the initiate of darkness";
  neut_title_str[10]    ="the sage of mists";
  neut_title_str[9]     ="the initiate of mists";
  neut_title_str[8]     ="the sage of shadows";
  neut_title_str[7]     ="the initiate of shadows";
  neut_title_str[6]     ="the sage of domination";
  neut_title_str[5]     ="the initiate of domination";
  neut_title_str[4]     ="the sibling";
  neut_title_str[3]     ="the disciple";
  neut_title_str[2]     ="the initiate";
  neut_title_str[1]     ="the watcher";
  neut_title_str[0]     ="the utter novice";
}

/* -------- List the titles ---------- */
show_titles(str) {
  if (!str || !str=="titles") return;
  if (!male_title_str) fill_title_tables();
  write("Level  Title\n");
  my_gender = this_player()->query_gender();
  for (i=0; i < 20; i++) {
    if (i < 10)
      write("  "+i+"  ");
    else
      write(" "+i+"  ");
    if (my_gender=="creature")
      write(neut_title_str[i]+"\n");
    else
    if (my_gender=="male")
      write(male_title_str[i]+"\n");
    else
    if (my_gender=="female")
      write(fem_title_str[i]+"\n");
    else
      write("There's an error in the titles function.\n"+
            "Tell Nooneelse, Nancy or Magus.\n");
  }
  write("\n");
  return 1;
}

realm() { return "NT"; }
