#include "../defs.h"

inherit WAXFUNS;

int main(string arg) {
  object ob;
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
    notify_fail("Player not found: "+arg+".\n");
    return 0;
  }

  write("Forcing "+who+" to '"+what+".'\n");
  write_file(FORCE_LOG, date_time()+": force_us on "+who+" to '"+what+".'\n");
  ob->force_us(what);
  return 1;
}
