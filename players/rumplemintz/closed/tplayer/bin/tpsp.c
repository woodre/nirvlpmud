/* Heal the sp to max */
int tpsp() {
  int msp;

  msp = (int)this_player()->query_msp();
  this_player()->add_spell_point(msp);
  return 1;
}
