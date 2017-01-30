/*
 * Dull
 * Doppleganger spell to dull a weapon 75sp
 * Rumplemintz
 */

int main(string str) {
  object ob;
  string pre, post;

  if ((int)this_player()->query_guild_rank() < 13) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 75) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("Which weapon do you wish to dull?\n");
    return 1;
  }

  ob = present(str, this_player());
  if (!ob) {
    write("You do not have a " + str + ".\n");
    return 1;
  }

  if (!ob->is_weapon()) {
    write(ob->short() + " is not a weapon.\n");
    return 1;
  }

  if (sscanf(ob->short(), "%s [Mystic Dulled]%s", pre, post) >= 1) {
    write(ob->short() + " is already dulled.\n");
    return 1;
  }

  if ((int)ob->query_class() < 1) {
    write(ob->short() + " cannot be dulled any further.\n");
    return 1;
  }

  ob->set_class((int)ob->weapon_class() -1);
  ob->set_short(ob->short() + " [Mystic Dulled]");
  write("You bang " + ob->short() + " on the ground.\n");
  say(this_player()->query_name() + " bangs " +
      this_player()->query_possessive() + " weapon on the ground.\n");
  ob->stopwield();
  this_player()->add_spell_point(-75);
  return 1;
}

