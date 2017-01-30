int
rsharpen(string str) {
  object who, weapon;
  if (!str)
    who = this_player();
  else
    who = find_player(str);
  if (!who) {
    notify_fail("Cannot find "+str+".\n");
    return 0;
  }
  weapon = (object)who->query_weapon();
  if (!weapon) {
    notify_fail(who->query_name()+" is not wielding a weapon.\n");
    return 0;
  }
  if ((int)weapon->query_broke() == 1) {
    notify_fail(who->query_name()+"'s weapon is broken.\n");
    return 0;
  }
  write("You sharpen "+who->query_name()+"'s weapon.\n");
  say(this_player()->query_name()+ " does some wizard stuff.\n");
  weapon->set_hits(1);
  weapon->set_misses(1);
  return 1;
}
