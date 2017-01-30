/*
 guild_hall.c
*/

#define PAGESIZE  18
#define TP this_player()

inherit "room/room";
#include "lib/defs.h"

object board;
int line_nbr, line_ctr;
object fangs, scroll, adv_guild_obj;

string str, where, what, at_in, new_title, guild_name;

/*
init() {
  ::init();

  add_action("check_move",    "down");
  add_action("touch_stone",   "touch");
  add_action("up","up");
  add_action("sharpen_fangs", "sharpen");
  add_action("abandon_guild", "abandon");
}
*/

check_move() {
  if (!present("vampire fangs", this_player()) &&
      !this_player()->am_i_a_servant()) {
    say("A brilliant black spark flashes in the doorway,\n"+
        "preventing "+this_player()->query_name()+"'s entry.\n");
    write("You feel, more than hear a deep voice rumble:\n\n");
    write("   Do not try to enter here again unless you become a member!\n");
    return 1;
  }
}

touch_stone(str) {
  string help_directory;
  help_directory="/players/nooneelse/black/hlp/";
  if (!str) return;
  if (str != "stone") return;
  say(this_player()->query_name()+
        " touches the blood red stone in the wall and pauses in thought.\n");
  write("\n                 Vampire Guild Commands\n");
  cat(help_directory+"fangs.hlp");
  if (present("vampire fangs", this_player())) return 1;
write(
"~ To join this guild, find a member and have them induct you.             ~\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@
write(
"~ or drink the blood from the vial you now have.                         ~\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  if (!present("vial of blood", this_player()))
    move_object(clone_object("players/nooneelse/black/vial_of_blood"),
                this_player());
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
  return 1;
}

sharpen_fangs(str) {
  object fangs;
  string player_name;
  if (!str || str != "fangs") return;

  write("You cannot do that here anymore. See a Vampire Guild Lieutenant.\n");
  return 1;

  player_name=this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(player_name)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(player_name)!=GUILD_ASSISTANT) {
    if (this_player()->query_guild_name() != "vampire" &&
        this_player()->query_guild_name() != "vampires") {
      write("Forget it, you're not a vampire!\n");
      return 1;
    }
  }
  fangs=present("vampire fangs", this_player());
  if (fangs) destruct(fangs);
  fangs=present("vampire fangs", this_player());
  if (fangs) destruct(fangs);
  fangs=present("vampire fangs", this_player());
  if (fangs) destruct(fangs);
  move_object(clone_object("/players/nooneelse/black/vampire_fangs"),
              this_player());
  write("You now have the latest version of the vampire guild's fangs.\n");
  return 1;
}

vampire_sign(str) {
  if (call_other("players/nooneelse/black/guild_lower_hall", "query_member",
      this_player()->query_real_name()))
    write("If you lose your guild status or need the newest version\n"+
          "of the guild fangs, come here & type 'sharpen fangs'.\n");
  else
    write("The sign is in a language unknown only to guild members.\n");
  return 1;
}


abandon_guild(str) {
  int i;

  if (!str || str != "guild") return 0;

  i=this_player()->query_guild_rank();
  this_player()->add_guild_rank(-i);
  i=this_player()->query_guild_exp();
  this_player()->add_guild_exp(-i);
  this_player()->set_guild_file(0);
  this_player()->set_guild_name(0);
  write("Your guild settings are cleared.\n");
  return 1;
}

reset(arg) {
  if (arg) return;
    
  set_light(1);
  short_desc=("the Vampire Guild's Hall");
  no_castle_flag=1;
  long_desc=
    "The only noticable feature in this well lit, black room is a\n"+
    "dark blood red stone set into the wall.  There is a pleasant\n"+
    "throbbing comming from the stone.  It almost makes you want to\n"+
    "touch it...\n"+
    "There is a sign here written in a strange language.\n\n";
/*
    "If you are the member of a defunct guild and want to clear your\n"+
    "guild settings so you can join another guild, type 'abandon guild'.\n"+
    "DO NOT type this just to see what happens!  If you didn't really want\n"+
    "to leave your guild, it WILL screw you up!!!\n";
*/
  dest_dir=
    ({
/*
      "players/nooneelse/blackentry", "east",
      "players/nooneelse/guildent", "south",
      "players/nooneelse/black/guild_office_floor_1", "up",
*/
  "players/eurale/VAMPIRES/RMS/vgent","west",
    });
  if (!present("board", this_object())) {
    board = clone_object("players/nooneelse/black/guild_recruit_board");
    move_object(board, this_object());
  }
}

id(str) {
  if (str=="sign") {
    vampire_sign("sign");
    return 1;
  }
}

up() {
if(TP->query_real_name() != "magus") {
    write("An invisible force stops you from going that way!\n");
    return 1; }
else {
  TP->move_player("up#players/nooneelse/black/guild_office_floor_1");
    return 1; }
}
