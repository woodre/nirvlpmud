short() { return "A inventory dester"; }
long() { write("Type 'destp <player> <item>'.\n"); return 1; }
get() { return 1; }
drop() { destruct(this_object()); }
id(str) { return str == "dester"; }
init() { add_action("destp", "destp"); }
destp(str) {
  string who, what;
  object ob;
  if(sscanf(str, "%s %s", who, what) != 2) return 0;
  if(!find_player(who)) {
    write("player not found.\n");
    return 1;
  }
  ob = present(what, find_player(who));
  if(!ob) {
    write("Object not present.\n");
    return 1;
  }
  destruct(ob);
  write("dumped.\n");
  tell_object(find_player(who), "Item dested.\n");
  return 1;
}
