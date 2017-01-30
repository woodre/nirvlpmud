/*
 * Enchant
 * Doppleganger spell to enchant a piece of armor for 80sp
 * Rumplemintz
 */

int main(string str) {
  object ob;
  string pre, post;

  if ((int)this_player()->query_guild_rank() < 12) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < 80) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str) {
    write("Which piece of armor do you wish to enchant?\n");
    return 1;
  }

  ob = present(str, this_player());
  if (!ob) {
    write("You do not have a " + str + ".\n");
    return 1;
  }

  if (!ob->armor_class() || !ob->query_type()) {
    write(ob->short() + " is not a piece of armor.\n");
    return 1;
  }

  if (sscanf(ob->short(), "%s [Mystic Enchanted]%s", pre, post) >= 1) {
    write(ob->short() + " is already enchanted.\n");
    return 1;
  }

  if ((int)ob->armor_class() > ((string)ob->query_type() == "armor" ? 4 : 2)) {
    write(ob->short() + " cannot be enchanted.\n");
    return 1;
  }

  ob->set_ac(ob->armor_class() + 1);
  ob->set_short(ob->short() + " [Mystic Enchanted]");
  call_out("disenchant_armor", 1800, ob);
  write("You concentrate on the armor and it begins to glow.\n");
  say(this_player()->query_name() + " recites some words and a piece of " +
      this_player()->query_possessive() + " armor begins to glow.\n");
  this_player()->add_spell_point(-80);
  return 1;
}

int disenchant_armor(object obj) {
  string pre, post;

  if (!obj) return 1;
  if (sscanf(obj->short(), "%s [Mystic Enchanted]%s", pre, post) != 2)
    return 1;
  obj->set_ac((int)obj->armor_class() - 1);
  obj->set_short(pre + post);
  tell_object(environment(obj),
              "The Mystic Enchantment on " + obj->short() + " fades.\n");
  return 1;
}

