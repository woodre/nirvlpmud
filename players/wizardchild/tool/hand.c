hand(str) {
  string who, what, blah;
  object w, ob;
  if(!str || sscanf(str, "%s %s", who, what) != 2) {
    write("Usage: hand <who> <filename>\n");
    return 1;
  }
  if(!(w = find_player(who))) {
    write("That player is not logged in.\n");
    return 1;
  }
  if(what[0] != '/') what = this_player()->get_path()+what;
  if(!sscanf(what, "%s.c", blah)) what += ".c";
  write("Cloning "+what+"...\n");
  ob = clone_object(what);
  /* prevent handing them too much */
  if(ob->query_weight() && !w->add_weight(ob->query_weight())) {
    write("That player cannot carry any more.\n");
    return 1;
  }
  write("You give "+ob->short()+" to "+capitalize(who)+".\n");
  tell_object(w, "You are given a gift by "+this_player()->query_name()+".\n");
  move_object(ob, w);
  return 1;
}
