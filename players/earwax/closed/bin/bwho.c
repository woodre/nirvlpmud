main(arg) {
  object *peeps, ob;
  int lvl, i, siz;

  siz = sizeof(peeps = users());
  for (i = 0; i < siz; i++)
  {
    lvl = peeps[i]->query_level();
/*
    if (lvl < 20 && lvl > 0) {
      write(pad(lvl, 7));
*/
    if (lvl > 0) {
      write(pad(peeps[i]->query_nrpoints(), 7));
      write(pad((query_idle(peeps[i])/60), 5));
      write(pad(capitalize(peeps[i]->query_real_name()),15));
      write(pad((lvl == 19 ? "19+"+peeps[i]->query_extra_level() : lvl), 8));
      if (lvl > 19)
        write("\n");
      else
        write("/players/earwax/housing/sort_daemon.c"->comma_number(peeps[i]->query_bank_balance()+"")+"\n");
    }
  }

  return 1;
}
