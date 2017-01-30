/*
 * Aggress
 * Doppleganger spell has a chance to make a monster aggressive for 20sp
 * Rumplemintz
 */

int main(string str) {
  object target;
  string temp;

  if ((int)this_player()->query_guild_rank() < 14) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("What do you want to turn aggressive?\n");
    return 1;
  }

  target = present(str, environment(this_player()));

  if (!target) {
    write("That is not here.\n");
    return 1;
  }

  if (!target->query_npc()) {
    write("You cannot make that aggressive.\n");
    return 1;
  }

  if (sscanf(object_name(environment(this_player())), "room/%s", temp) == 1) {
    write("You cannot do that this close to town.\n");
    return 1;
  }

  if (random(100) < 21) {
    write("The spell fails!\n");
    say(this_player()->query_name() + " tries to make " +
        target->short() + " aggressive, but just pisses " +
        target->query_pronoun() + " off!\n");
    this_player()->add_spell_point(-20);
    target->attack_object(this_player());
    return 1;
  }

  write("You turn " + target->short() + " aggressive.\n");
  say(this_player()->query_name() + " turns " + target->short() +
      " aggressive.\n");
  target->set_aggressive(1);
  this_player()->add_spell_point(-20);
  return 1;
}

