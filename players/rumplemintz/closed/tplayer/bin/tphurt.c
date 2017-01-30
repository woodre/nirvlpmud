/* Cause severe damage to attacker */
int tphurt() {
  object who;
  int mhp;

  who = (object)this_player()->query_attack();
  if (!who) return 1;
  mhp = (int)who->query_mhp();
  who->add_hp(-mhp);
  write("Left: " + who->query_hp() + "\n");
  return 1;
}
