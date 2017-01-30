#include "../defs.h"

inherit WAXFUNS;

int main(string arg) {
  object ob;
  object *fuckverte;
  int i;
  string who, what;

  if (!arg) {
    notify_fail("Syntax: force <player> <command>\n");
    return 0;
  }

  if (sscanf(arg, "%s %s", who, what) != 2) {
    notify_fail("Incorrect number of args.\nSyntax: force <player> <command>\n");
    return 0;
  }

  ob = find_player(who);

  if (!ob)
    ob = find_living(who);

  if (!ob) {
    i = sizeof(fuckverte = users());

    while(i--)
      if ((string)fuckverte[i]->query_real_name() == who)
        ob = fuckverte[i];
  }

  if (!ob) {
    notify_fail("Player not found: "+who+".\n");
    return 0;
  }

  if ((int)ob->query_level() > (int)this_player()->query_level())
    write("Forcing higher level wizards will no longer work, just so you know :)\n");


  write("FORCING "+who+" to '"+what+".'\n");
  write_file(FORCE_LOG, HIW+date_time()+": command() force on "+who+" to '"+what+".'\n"+NORM+NORM);
  command(what, ob);
  return 1;
}

void
alt_force(object from, object ob, string arg)
{
  tell_object(from,"ATTEMPTING ALTERNATE FORCE:"+command(arg, ob)+"\n");
}
