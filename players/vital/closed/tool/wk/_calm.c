#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main() {
  object ob, nob;
  ob = first_inventory(environment(this_player()));
  say(this_player()->query_name()+" forces peace upon this room.\n");
  write("You force peace upon this room.\n");
  while(ob) {
    nob = next_inventory(ob);
    if(living(ob) && ob->query_attack()) {
      say(ob->query_name()+" stops fighting.\n");
      ob->stop_fight();
      ob->stop_fight();
    }
    ob = nob;
  }
  write("Done.\n");
  return 1;
}

get_help()
{
  string help;
  help = "Cycles through room and stops combat";
  return help;
}