/* Heal the hp to max */
int tphp() {
  int mhp;

  mhp = (int)this_player()->query_mhp();
  this_player()->add_hit_point(mhp);
  return 1;
}
