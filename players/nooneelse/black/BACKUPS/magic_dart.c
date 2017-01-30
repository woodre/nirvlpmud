/*
  magic_dart.c - range weapon created by vamp spell (only useable by vamps)
*/

#include "/players/nooneelse/color.h"

inherit "obj/treasure";

reset(arg) {
  set_weight(1);
  set_value(0);
  set_short(RED+"A blood red dart"+END);
  set_long(RED+"A blood red magical dart created by a vampire.\n"+END+
           "Use:  throw dart at <monster name>\n"+
           "      (You must be in the room with the monster so the\n"+
           "       darts know who to hit.\n");
  set_save_flag(1);
}

id(str) { return str=="magic dart" || str=="vampire dart" || str=="dart"; }

prevent_insert() { return 1; }

drop() { return 1; }

init() {
   add_action("throw", "throw");
}

throw(str) {
  string target_name;
  object target_obj;
  if (!str) return 0;
  sscanf(str, "dart at %s", target_name);
  if (!target_name) {
    write("Throw dart at who?\n");
    return 1;
  }
  target_obj=find_living(target_name);
  if (!target_obj) {
    write("The dart flys out of your hand, only to return a second later.\n"+
          "It can't seem to find "+capitalize(target_name)+".\n");
    return 1;
  }
if(!present(target_name,environment(this_player()))) {
    write("You must be in the same room as the target monster to use these!\n");
    return 1;
  }
  if (this_player()->query_level() < 21 && !target_obj->query_npc()) {
    write("You can't use these against players!\n");
    return 1;
  }
  if (target_obj->query_hp() > 10)
    target_obj->hit_player(10);
  else
  if (target_obj->query_hp() > 1)
    target_obj->hit_player(1, this_player());
  write("Woosh!  The dart flys at "+capitalize(target_name)+".\n");
  say("Unh!  "+this_player()->query_name()+" grunts as "+
      this_player()->query_pronoun()+" throws a blood red dart.\n");
  target_obj->attacked_by(this_player());
  this_player()->attacked_by(target_obj);
  this_player()->add_weight(- 1);
  destruct(this_object());
  return 1;
}
