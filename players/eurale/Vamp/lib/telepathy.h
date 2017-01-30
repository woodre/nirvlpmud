/*
  telepathy.h
*/

#include "/players/eurale/defs.h"

/* -------- Telepathy - tell all vampires ---------- */
telepathy(str) {
  int i;
  object stuff;
  string who, player_list;

if(!str) {
  write("What did you want to say?\n");
  return 1; }

if(TPL < 4) {
  write("You have lost your ability to use the vamp channel.\n");
  return 1; }


if(str == "on") {
  EFANGS->set_telepathy(1);
  write("Telepathy is now "+HIG+"ON"+NORM+".\n");
  return 1; }

if(str=="off") {
  EFANGS->set_telepathy(0);
  write("Telepathy is now "+HIR+"OFF"+NORM+".\n");
  return 1; }


player_list = users();
for(i = 0; i < sizeof(player_list); i++) {
  stuff = present("vampire fangs", player_list[i]);
    if (stuff && player_list[i]->query_level() <= 100) {
      if (stuff->query_telepathy())
        if (TP->query_invis() > 0)
          tell_object(player_list[i],
            BOLD+":["+NORM+" Someone =>> "+str+"\n");
        else
          tell_object(player_list[i],
            BOLD+":["+NORM+" "+capitalize(TPRN)+" =>> "+str+"\n");
    }
}
return 1;
}
