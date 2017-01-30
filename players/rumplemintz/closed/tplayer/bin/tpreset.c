/* Reset the current environment */
int tpreset() {
  object where;

  where = environment(this_player());
  where->reset(0);
  return 1;
}
