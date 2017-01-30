/*
  alchemist_lobby.c
*/

#define PAGESIZE  18
#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

object board;
int line_nbr, line_ctr;
object fangs, scroll, adv_guild_obj;
string str, where, what, at_in, new_title, guild_name;

init() {
  ::init();

  add_action("check_move",    "down");
  add_action("touch_stone",   "touch");
  add_action("launder_robes", "launder");
}

check_move() {
  if (!present("Alchemist Robes", this_player()) &&
      !this_player()->am_i_a_servant()) {
    say("A brilliant golden spark flashes in the doorway,\n"+
        "preventing "+this_player()->query_name()+"'s entry.\n");
    write("You feel, more than hear a deep voice rumble:\n\n");
    write("   "+NORM+HIB+"Do not try to enter here again unless you become a member!"+NORM+"\n");
    return 1;
  }
}

touch_stone(str) {
  if (!str) return;
  if (str != "stone") return;
  say(this_player()->query_name()+
        " touches the bright blue stone in the wall and pauses in thought.\n");
  write("\n                 Alchemist Guild Commands\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  cat(ALCHEMIST_HELP+"robes.hlp");
write(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  if (present("Alchemist Robes", this_player())) return 1;
write(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"~ To join this guild, find a member and have them induct you.            ~\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}

launder_robes(str) {
  object robes_obj;
  string player_name;

  if (!str || str != "robes") return;

  player_name=this_player()->query_real_name();
  if (!call_other(ALCHEMIST_CENTRAL, "query_member", this_player()->query_real_name())) {
    write("Forget it, you're not an Alchemist!\n");
    return 1;
  }

  robes_obj=present("Alchemist Robes", this_player());
  if (robes_obj) destruct(robes_obj);
  robes_obj=present("Alchemist Robes", this_player());
  if (robes_obj) destruct(robes_obj);
  robes_obj=present("Alchemist Robes", this_player());
  if (robes_obj) destruct(robes_obj);
  move_object(clone_object(ROBES), this_player());
  write("You now have the latest version of the Alchemist Guild's Robes.\n");
  return 1;
}

alchemist_sign(str) {
  if (call_other(ALCHEMIST_CENTRAL, "query_member", this_player()->query_real_name()))
    write("If you lose your guild status or need the newest version\n"+
          "of the guild robes, come here & type 'launder robes'.\n");
  else
    write("The sign is in a language unknown only to guild members.\n");
  return 1;
}

reset(arg) {
  if (arg) return;
    
  set_light(1);
  short_desc=("Alchemist's Guild Hall Lobby");
  no_castle_flag=1;
  long_desc=
    "The only noticable feature in this well lit room is a\n"+
    "bright blue stone set into the wall.  There is a pleasant\n"+
    "throbbing comming from the stone.  It almost makes you want to\n"+
    "touch it...\n"+
    "There is a sign here written in a strange language.\n\n";
  dest_dir=
    ({
      ALCHEMIST_ENTRANCE, "south",
      ALCHEMIST_CENTRAL, "down",
      ALCHEMIST_PUB, "west",
      ALCHEMIST_SHOP, "east",
    });
}

id(str) {
  if (str=="sign") {
    alchemist_sign("sign");
    return 1;
  }
}
