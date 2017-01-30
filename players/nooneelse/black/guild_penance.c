/*
  guild_penance.c - a penance quest for wrongdoing vamps
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "obj/treasure";

string str, penance_clue, penance_room, monster_name;
int penance_nbr;

query_auto_load() {
  return "/players/nooneelse/black/guild_penance.c:" + penance_nbr;
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
  officer_level = GUILD_OFFICE_FLOOR_TOP->find_officer(my_name);
  if (officer_level!=GUILD_MASTER &&
      officer_level!=GUILD_ASSISTANT &&
      officer_level!=GUILD_LIEUTENANT &&
      this_player()->query_level() < 21)
    return 0;
  if (!officer_level && this_player()->query_level()>=21)
    officer_level="wizard";
  tell_object(environment(this_object()),
              "A "+capitalize(officer_level)+
              " has taken pity on you and released you from your penance.\n");
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
    write("You anger me!  You do not have the drop of blood!\n");
    return 1;
  }
  if (str2 != "players/nooneelse/black/guild_coffin_room") {
    write("You were told to take the drop of blood to the coffin room.\n");
    return 1;
  }
  write("Very well.  You have solved this task.  You are released "+
        "from your penance.\n");
  destruct(drop_obj);
  destruct(this_object());
  return 1;
}

set_penance(str) {
  object monster_obj, drop_obj;
  if (!str || !str=="penance") return;
  monster_obj=present(monster_name[penance_nbr], environment(this_player()));
  if (!monster_obj) {
    write("The creature that is to carry the drop of blood is not here.\n"+
          "Either it is already dead or this isn't where the correct\n"+
          "creature is supposed to be.\n");
    return 1;
  }
  drop_obj=present("drop of blood", monster_obj);
  if (!drop_obj) {
    move_object(clone_object("players/nooneelse/black/guild_drop_of_blood"),
                monster_obj);
  }
  write("It's set.\n");
  return 1;
}

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(1);
  fill_penance_clue();
}

short() { return "A Vampire Guild Penance Marker"; }

long() {
  write("\n"+short()+".\n\n"+
        "You have comitted an offense to the vampire guild!  To prove\n"+
        "yourself worthy to continue to remain in the guild, you must:\n\n"+
        "     Go alone to find the drop of blood and bring it to the\n"+
        "     coffin room.  Once there, type 'forgive me' to have\n"+
        "     the penance removed.  To find the drop of blood, look\n"+
        "     "+penance_clue[penance_nbr]+".\n\n"+
        "     (If the creature is there, but doesn't have the drop,\n"+
        "      type 'set penance' before attacking it.  If the creature\n"+
        "      is already dead, you'll just have to wait for a reset.)\n");
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
  penance_clue[2]  = "in the cellar of the mansion in the mist";
  monster_name[2]  = "earwig";
  penance_room[3]  = "/nooneelse/red/celler5";
  penance_clue[3]  = "in the cellar of the mansion in the mist";
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

id(str) { return (str=="vampire guild penance" ||
                  str=="vampire guild penance" ||
                  str=="vampire guild penance marker" ||
                  str=="vampire guild penance marker" ||
                  str=="penance marker" ||
                  str=="marker" ||
                  str=="penance");
}
