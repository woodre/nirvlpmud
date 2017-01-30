/*
 * Coat
 * Apply a poison to a weapon for 75 sps
 * Wears off in 60 minutes
 */

status main(string str) {
  int was;
  object ob;
  string pre, post;

  if (this_player()->query_guild_rank() < 6) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_sp() < 75) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str) {
    write("What weapon do you want to coat?\n");
    return 1;
  }
  ob = present(str, this_player());
  if (!ob) {
    write("You do not have one of those.\n");
    return 1;
  }
  was = (int)ob->weapon_class();
  if (!was) {
    write("That is not a weapon.\n");
    return 1;
  }
  if (was >= 20) {
    write("The poison just slides off that finely crafted weapon.\n");
    return 1;
  }
  if (sscanf(ob->short(), "%s [Poison tipped]%s", pre, post) == 2) {
    write("That weapon is already coated in poison.\n");
    return 1;
  }
  ob->set_short(ob->short() + " [Poison tipped]");
  call_out("remove_poison", 1800, ob);
  this_player()->add_spell_point(-75);
  ob->set_class(was + 1);
  write("You coat the weapon with poison.\n");
  write("Be sure to wield your weapon again.\n");
  ob->stopwield();
  say(this_player()->query_name() + " coats " +
      this_player()->query_possessive() + " weapon with poison.\n");
  return 1;
}

int remove_poison(object obj) {
  string pre, post;

  if (!obj) return 1;
  if (sscanf(obj->short(), "%s [Poison tipped]%s", pre, post) != 2)
    return 1;
  obj->set_class((int)obj->weapon_class() - 1);
  obj->set_short(pre + post);
  tell_object(environment(obj),
              "The poison on " + obj->short() + " wears off.\n");
  obj->stopwield();
  return 1;
}
