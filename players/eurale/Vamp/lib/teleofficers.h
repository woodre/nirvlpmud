/*
  telepathy.h
*/

#include "/players/eurale/defs.h"

/* -------- Telepathy - tell officers ---------- */
teleofficer(str) {
  int i;
  object stuff;
  string who, msg, player_list;

if(!str) {
  write("What did you want to say?\n");
  return 1; }

 if(TOP_FLOOR->find_officer(TPRN)!=MASTER &&
   TOP_FLOOR->find_officer(TPRN)!=ASSISTANT &&
   TOP_FLOOR->find_officer(TPRN)!=LIEUTENANT) {
 write("You cannot use the 'tel' command.\n");
  return 1; }

player_list = users();
for(i = 0; i < sizeof(player_list); i++) {
  stuff = present("vampire fangs", player_list[i]);
  if(stuff) {
    who = player_list[i]->query_real_name();
    if(TOP_FLOOR->find_officer(who) == MASTER ||
       TOP_FLOOR->find_officer(who) == ASSISTANT ||
       TOP_FLOOR->find_officer(who) == LIEUTENANT)
    tell_object(player_list[i], HIR+":[ "+capitalize(TPRN)+"-===>"+NORM+str+"\n");
  }
}
return 1;
  }
