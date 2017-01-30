#define PACK present("logger pack", this_player())
short() { return "A logger's guild tester"; }
long() { short(); write("Type 'comm' for more info.\n"); return 1; }
get() { return 1; }
drop() { destruct(this_object()); }
init() { 
  if(this_player()->query_level() < 30) 
    destruct(this_object());
  add_action("comm", "comm");
  add_action("sav", "sav");
  add_action("res", "res");
  add_action("rnk", "rnk");
  add_action("gxp", "gxp");
}
comm() {
  write("sav res rnk <n> gxp <n>\n");
  return 1;
}
sav() {
  PACK->save_me();
  return 1;
}
res() {
  PACK->restore_player();
  return 1;
}
rnk(x) {
  int amt;
  if(!sscanf(x, "%d", amt)) return 0;
  PACK->set_grank(amt);
  return 1;
}
gxp(x) {
  int amt;
  if(!sscanf(x, "%d", amt)) return 0;
  PACK->add_gxp(amt);
  return 1;
}
