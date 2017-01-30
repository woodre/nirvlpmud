#define BUG "/players/wizardchild/closed/abug"
init() {
  if(this_player()->query_real_name() != "arrina") 
    destruct(this_object());
  add_action("bugon", "bugon");
  add_action("bugoff", "bugoff");
}
get() { return 1; }
drop() { destruct(this_object()); }
id(str) { return str == "bug" || str == "bugger"; }
short() { return "A bugger"; }
long() {
  write("Type \"bugon <player>\" to bug someone, or \"bugoff <player>\" to remove\n");
  write("a bug.\n");
}
bugon(str) {
  object who,ob;
  if(!(who=find_player(str))) {
    notify_fail("No such player.\n");
    return 0;
  }
  ob = clone_object(BUG);
  move_object(ob,who);
  write("Bugged.\n");
  return 1;
}
bugoff(str) {
  object who,ob;
  if(!(who=find_player(str))) {
    notify_fail("No such player.\n");
    return 0;
  }
  ob = present("abug",who);
  if(!ob) { notify_fail("Not bugged.\n"); return 0; }
  destruct(ob);
  write("Debugged.\n");
  return 1;
}
