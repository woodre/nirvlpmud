#include <ansi.h>

main(str)
{
  string who, where, blah;
  object w, env;
  if(!str || sscanf(str, "%s %s", who, where) != 2)
  {
    write("Usage: place <who> <where>\n");
    return 1;
  }
  if(!(w = find_player(who)))
  {
    write("That player is not logged in.\n");
    return 1;
  }
  /* allow filename assumptions */
  if(where[0] != '/') where = this_player()->get_path()+where;
  if(!sscanf(where, "%s.c", blah)) where += ".c";
  write("You place "+capitalize(who)+" in "+where->short()+".\n");
  tell_object(w, "Everything around you fades to black.\n");
  tell_object(w, "When light returns, you are in a new place.\n");
  env = environment(w);
  move_object(w, where);
  tell_room(env, capitalize(who)+" dissappears into darkness.\n");
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: place <who> <where>";
  return help;
}
