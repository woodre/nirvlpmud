#include <ansi.h>

main(str)
{
  string who, what, blah;
  int silent;
  object w, ob;
  silent = 1;
  if(!str || sscanf(str, "%s %s", who, what) != 2) {
    write("Usage: hand <who> <filename>\n");
    return 1;
  }
  if(!(w = find_player(who))) {
    write("That player is not logged in.\n");
    return 1;
  }
  if(what[0..5] == "silent")
  {
    string temp;
    write("Silent hand off.\n");
    silent = 0;
    sscanf(what, "%s %s", temp, what);
  }
  if(what[0] != '/') what = this_player()->get_path()+what;
  if(!sscanf(what, "%s.c", blah)) what += ".c";
  write("Cloning "+what+"...\n");
  /* next line by verte */
  if(catch(ob=clone_object(what))) return (write("Bad file error.\n"), 1);
  /* prevent handing them too much */
  if(ob->query_weight() && !w->add_weight(ob->query_weight())) {
    write("That player cannot carry any more.\n");
    return 1;
  }
  write("You give "+ob->short()+" to "+capitalize(who)+".\n");
  if(silent) tell_object(w, "You are given a gift by " +
    this_player()->query_name() + ".\n");
  move_object(ob, w);
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: hand <who> [silent] <what>";
  return help;
}