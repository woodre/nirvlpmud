/* Stop all fighting */
int tpstop() {
  object ob;

  ob = first_inventory(environment(this_player()));
  while(ob) {
    ob->stop_fight(); ob->stop_fight(); ob->stop_hunter();
    ob = next_inventory(ob);
  }
  return 1;
}
