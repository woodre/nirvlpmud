/* rock.c: a little rock */
string who;
reset(arg) {
  if(arg)
    return ;
  who = "Nobody";
}
short() { return "A little rock (from "+who+")"; }
long()  {
  write("You could probably throw it at someone...\n");
  return 1;
}
get()   { return 1; }  
id(str) { return str == "rock" || str == "little rock"; }
init()  {
  add_action("throw_rock", "throw");
}
throw_rock(str) {
  object them;
  string s,n;
  if(!str || sscanf(str, "%s at %s",s,n) < 2) {
    write("Usage: throw rock at <who>\n");
    return 1;
  }
  if(!id(s)) return 0;
  them = find_player(n);
  if(!them || them->query_invis() >= 100) {
    write("That player is not logged in.\n");
    return 1;
  }
  if(them->query_level() > 20 && them != find_player("wizardchild")) {
    write("You cannot throw this rock at a wizard.\n");
    return 1;
  }
  who = this_player()->query_name();
  write("You throw the rock at "+them->query_name()+".\n");
  say(this_player()->query_name()+" throws a rock at someone.\n");
  tell_object(them, this_player()->query_name()+" throws a rock at you. OUCH!!\n");
  move_object(this_object(), them);
  return 1;
}
