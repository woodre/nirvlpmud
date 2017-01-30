#include <ansi.h>
#include "defs.h"
#define COST 40

inherit CMDBASE;

main(){
  string color;

  skill_type = "telepathy";
  color = previous_object()->query_mon_color();
  if(USER->query_ghost()) return 0;
  if(skill_check(8)) return 1;
  if(cp_check(COST)) return 1;

  if(PO->query_rage()) {
    write("You are already filled with anger and hate.\n");
    return 1;
  }
  write( BOLD + BLK +"You concentrate on the Darkside of the Force and are filled with "+HIR+"Anger.\n" +NORM );
  write("SKILL: "+SKILL+"\n");
  say(BOLD + BLK + "Dragnar's face contorts with utter "+HIR+"rage!\n" +NORM );
  if(SKILL > 9){
    PO->set_rage(20);
  }
  else{
    PO->set_rage(SKILL*5);
  }
  PO->adj_cp(-COST);
  PO->adj_goodness_pool(SKILL*-1);
  this_player()->add_guild_exp(10*SKILL);
  return 1;
}
