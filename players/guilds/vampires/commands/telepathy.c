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
  present("efangs",TP)->set_telepathy(1);
  write("Telepathy is now "+HIG+"ON"+NORM+".\n");
  return 1; }

if(str=="off") {
  present("efangs",TP)->set_telepathy(0);
  write("Telepathy is now "+HIR+"OFF"+NORM+".\n");
  return 1; }

if(TPBPTS < 1) {
  write("You lack the blood energy to do that.\n");
  return 1; }


PFANGS->add_BLOODPTS(-1);
player_list = users();
for(i = 0; i < sizeof(player_list); i++) {
  stuff = present("vampire fangs", player_list[i]);
    if (stuff && player_list[i]->query_level() <= 40000) {
      if (stuff->query_telepathy())
        if (TP->query_invis() > 0)
          tell_object(player_list[i],
            HIR+":[ Someone"+NORM+"=>>"+str+"\n");
        else
          tell_object(player_list[i],
            HIR+":[ "+capitalize(TPRN)+NORM+"=>>"+str+"\n");
    }
}
return 1;
}