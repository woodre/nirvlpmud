/*
  alchemist_penance_mark.c - a penance quest for wrongdoing vamps
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "obj/treasure";

string str, penance_clue, penance_room, monster_name;
int penance_nbr;

query_auto_load() {
  return "/players/nooneelse/Alchemist/alchemist_penance_mark.c:" + penance_nbr;
}

start(obj) { move_object(this_object(), obj); }

init_arg(arg) { sscanf(arg, "%d", penance_nbr); }

get() { return 1; }

drop() { return 1; }

init() {
  ::init();

  add_action("remove_penance", "remove");
  add_action("forgive_me",     "forgive");
  add_action("set_penance",    "set");
}

remove_penance() {
  string my_name, officer_level;

  my_name = this_player()->query_real_name();
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) {
    write(NORM+CYN+"You can't do that.\n"+NORM);
    return 1;
  }
  tell_object(environment(this_object()),
    NORM+CYN+"The Guild Master has taken pity on you and\n"+
    "released you from your penance.\n"+NORM);
  destruct(this_object());
  return 1;
}

forgive_me(str) {
  string str1, str2, str3;
  object drop_obj;
  if (!str || !str=="me") return;
  str1=file_name(environment(this_player()));
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
  drop_obj=present("drop of blood", this_player());
  if (!drop_obj) {
    write(NORM+CYN+"You anger me!  You cannot drop the penance mark!\n"+NORM);
    return 1;
  }
  if (str2 != "players/nooneelse/Alchemist/donation") {
    write(NORM+CYN+"You were told to take the penance mark to the Donation Room.\n"+NORM);
    return 1;
  }
  write(NORM+CYN+"Very well.  You have solved this task.  You are released "+
        "from your penance.\n"+NORM);
  destruct(drop_obj);
  destruct(this_object());
  return 1;
}

set_penance(str) {
  object monster_obj, drop_obj;

  if (!str || !str=="penance") return;
  monster_obj=present(monster_name[penance_nbr], environment(this_player()));
  if (!monster_obj) {
    write(NORM+CYN+"The creature that is to carry the drop of blood is not here.\n"+
          "Either it is already dead or this isn't where the correct\n"+
          "creature is supposed to be.\n"+NORM);
    return 1;
  }
  drop_obj=present("drop of blood", monster_obj);
  if (!drop_obj) {
    move_object(clone_object("players/nooneelse/black/guild_drop_of_blood"),
                monster_obj);
  }
  write(NORM+CYN+"It's set.\n"+NORM);
  return 1;
}

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(1);
  fill_penance_clue();
}

short() { return NORM+CYN+"An Alchemist Guild Penance Mark"+NORM; }

long() {
  write(NORM+CYN+"\n"+short()+".\n\n"+
        "You have comitted an offense to the alchemist guild!  To prove\n"+
        "yourself worthy to continue to remain in the guild, you must:\n\n"+
        "     Go alone to find the drop of blood and bring it to the\n"+
        "     Donation Room.  Once there, type 'forgive me' to have\n"+
        "     the penance removed.  To find the drop of blood, look\n"+
        "     "+penance_clue[penance_nbr]+".\n\n"+
        "     (If the creature is there, but doesn't have the drop,\n"+
        "      type 'set penance' before attacking it.  If the creature\n"+
        "      is already dead, you'll just have to wait for a reset.)\n\n"+
        "The only guild abilities you can use while under penance are:\n"+
		"  ahelp, alevels, anews, assess, cpr, dismiss, fellows, launder,"+
		"  light, peace, process, refine, reserve, resign, road,\n"+
        "  sanctuary, sew, skin corpse, stone skin\n\n"
        NORM);
  return 1;
}

fill_penance_clue() {
  penance_room = allocate(10);
  penance_clue = allocate(10);
  monster_name = allocate(10);

  penance_room[0]  = "/room/ruins";
  penance_clue[0]  = "in the ruins";
  monster_name[0]  = "frog";
  penance_room[1]  = "/room/plains4";
  penance_clue[1]  = "in the plains";
  monster_name[1]  = "wolf";
  penance_room[2]  = "/nooneelse/red/cellar1";
  penance_clue[2]  = "in the cellar of the mansion within the mist";
  monster_name[2]  = "earwig";
  penance_room[3]  = "/nooneelse/red/celler5";
  penance_clue[3]  = "in the cellar of the mansion within the mist";
  monster_name[3]  = "scorpion";
  penance_room[4]  = "/room/sea_bottom";
  penance_clue[4]  = "in the water";
  monster_name[4]  = "octopus";
  penance_room[5]  = "/players/bastion/isle/rocky1";
  penance_clue[5]  = "on the rocky shore of a small island";
  monster_name[5]  = "seagull";
  penance_room[6]  = "/players/mistress/child/blue";
  penance_clue[6]  = "in the library";
  monster_name[6]  = "the blue boy";
  penance_room[7]  = "/room/mine/tunnel_room";
  penance_clue[7]  = "for the big guy in the mountain";
  monster_name[7]  = "hobgoblin";
  penance_room[8]  = "/room/mine/tunnel16";
  penance_clue[8]  = "for the little guy under the mountain";
  monster_name[8]  = "dwarf";
  penance_room[9]  = "/nooneelse/sea/nautilus_bridge";
  penance_clue[9]  = "for the steel ship's captain";
  monster_name[9]  = "nimo";
}

set_penance_nbr(arg) {
  penance_nbr=arg;
  return penance_nbr;
}

id(str) { return str=="alchemist_penance_mark"; }
