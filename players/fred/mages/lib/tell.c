/*********************************

   Mostly copied from /obj/player.c
   for legality checks...

*********************************/

#include "/players/fred/mages/defs.h"

cmd_tell(str) {
  string what;
  object who;
/* broken for titan.  not sure why.  disabling.  - illarion 3.11.11 */ return 0;
  if(!str){ write("Tell who what?\n");
  return 1; }
  if(!sscanf(str, "%s %s", str, what)) {
    write("Tell who what?\n");
  return 1; }
  who = find_player(str);
  if(!who){ write("That person isn't logged on. \n");  return 1; }
  if(interactive(who)){
  if(TP->query_level() < who->query_level() && who->query_invis() >= 39) {
    write("No player with that name.\n"); return 1; }
  if(in_editor(who)){
    write("That person is editing. Please try again later.\n"); return 1;
 }
  if(TP->query_level() < 21 && who->query_tellblock()) {
    write("That person is blocking tells. Please try again later.\n");
    return 1; }
  if(query_idle(who) > 120)
    tell_object(TP, who+" is idle at the moment. You may not get a response right away.\n");
  if(!who->query_npc() && !interactive(who))
    tell_object(TP, who+" is disconnected.\n");
  if(call_other(TO,"query_invis",0) > 0 && TP->query_level() < 21)
  {
  write("Don't be annoying.  Become visible before you talk to someone!\n" );
  return 1;
  }
  who->Replyer(TPRN);
  who->add_tellhistory(BOLD+BLK+capitalize(TPRN)+" tells you: "+NORM+what);
  what = format(what, 60);
  tell_object(who, 
    BOLD+BLK+capitalize(TPRN)+ " tells you: " +NORM+what);
  write("You tell "+capitalize(str)+": "+what+"\n");
  TP->add_spell_point(-1);
  return 1; }
}
