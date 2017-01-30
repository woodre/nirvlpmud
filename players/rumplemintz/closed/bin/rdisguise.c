/* Don't use unless you know what you're doing - Rump */
int
rdisguise(string str) {
  object myshad, me;
  string actual_name;
  string disguise_name;
  string who;

  if (!str) return 0;

  if (sscanf(str, "%s %s", who, disguise_name) != 2) {
    notify_fail("You must supply a disguise name: rdisguise <who> <what>\n");
    return 0;
  }

  me = find_player(who);
  if (!who)
    me = this_player();
  
  write("You disguise " + me + " as " + disguise_name +".\n");
  say(me->query_name()+" disguises "+me->query_possessive()+" as "+
      disguise_name +".\n");
  actual_name = (string)me->query_real_name();
  myshad = clone_object("/players/rumplemintz/closed/myshad.c");
  myshad->set_actual_name(actual_name);
  myshad->set_disguise_name(disguise_name);
  myshad->set_decay((int)me->query_level() / 20);
  myshad->do_shadow(me);
  return 1;
}
