/*
 * Reforge
 * Doppleganger command to fix a broken weapon
 * Rumplemintz
 */

int main(string str) {
  object ob;

  if ((int)this_player()->query_guild_rank() < 12) {
    write("You are not high enough guild level for that.\n");
    return 1;
  }

  if (!str) {
    write("What do you want to reforge?\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  ob = present(str, this_player());
  if (!ob) ob = present(str, environment(this_player()));
  if (!ob) {
    write("There is no " + str + " present.\n");
    return 1;
  }

  if (!ob->weapon_class()) {
    write(ob->short() + " is not a weapon.\n");
    return 1;
  }

  if (!ob->query_broke()) {
    write(ob->short() + " is not broken.\n");
    return 1;
  }
  
  ob->fix_weapon();
  write("You reforge " + ob->short() + ".\n");
  say(this_player()->query_name() + " reforges " + ob->short() + "\n");
  this_player()->add_spell_point(-40);
  return 1;
}

