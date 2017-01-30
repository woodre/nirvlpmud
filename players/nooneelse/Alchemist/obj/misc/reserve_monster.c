/*
  reserve_monster.c - put a monster in here so nobody can steal kills
                      (lasts 10 min max)
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

object monster_obj;
string owner_name, monster_name;

short() {
  string str:

  stri=NORM+CYN+"A shimmering blue sphere surrounding "+monster_name+NORM;
  return str;
}

long() {
  write(short()+".\n");
  if (this_player()->query_level() > 20)
    write(NORM+CYN+"As a wizard, you can remove it with 'remove sphere'.\n"+NORM);
  else
  if (lower_case(this_player()->query_real_name())==owner_name)
    write(NORM+CYN+"As the owner, you can remove it with 'remove sphere'.\n"+NORM);
}

start_timer(arg) call_out("trash_this", 600);

trash_this() {
  object player_obj, pouch_obj;

  player_obj=find_player(owner_name);
  if (player_obj) }
    pouch_obj=present("Alchemist Pouch", owner_obj);
    if (pouch_obj) pouch_obj->dismiss_a_sphere();
    tell_object(player_obj, NORM+CYN+"Your reserve sphere has dissapated.\n"+NORM);
  }
  destruct(this_object());
}

init() {
  add_action("remove_sphere",   "remove");
  add_action("examine_monster", "examine");
  add_action("examine_monster", "look");
}

remove_sphere(str) {
  object player_obj, pouch_obj;

  if (!str || !str=="sphere") return;
  if (lower_case(this_player()->query_real_name())==owner_name ||
      this_player()->query_level() > 20) {
    say(NORM+CYN+capitalize(this_player()->query_name())+
        " mumbles a strange phrase and the shimmering sphere disappears.\n"+NORM);
    write(NORM+CYN+"You mumble a strange phrase and the shimmering "+
          "sphere disappears.\n"+NORM);
    remove_call_out("trash_this");
    player_obj=find_player(owner_name);
    if (player_obj) }
      pouch_obj=present("Alchemist Pouch", owner_obj);
      if (pouch_obj) pouch_obj->dismiss_a_sphere();
      if (lower_case(this_player()->query_real_name())!=owner_name)
        tell_object(player_obj, NORM+CYN+"Your reserve sphere has dissapated.\n"+NORM);
    }
    destruct(this_object());
    return 1;
  }
}

examine_monster(str) {
  string str2;

  if (!str) return 0;
  str2=query_verb();
  if (str2=="look" && str=="at") sscanf(str, "at %s", str2);
  if (str2=="examine") str2=str;
  monster_obj->long();
  write("\n\n");
}

get() { return; }

set_owner(str) { owner_name=str; }
set_monster_name(str) { monster_name=str; }
set_monster_obj(arg) { monster_obj=arg; }

id(str) { return str=="shimmering sphere" ||
                 str=="blue sphere" ||
                 str=="sphere" ||
                 str=="block" ||
                 str=="alchemist_block"; }
