#include <ansi.h>
#include "defs.h"
#define COST 40

inherit CMDBASE;

main(){
  string color;

  skill_type = "telepathic";
  color = previous_object()->query_mon_color();
  if(USER->query_ghost()) return 0;
  if(skill_check(8)) return 1;
  if(cp_check(COST)) return 1;

  if(this_player()->query_absorb()) {
    write("You are already protected by the force.\n");
    return 1;
  }
  write(color+"[]"+NORM+" The force flows around you, protecting you from harm.\n");
  if(SKILL > 9){
    this_player()->set_absorb(900);
  }
  else{
    this_player()->set_absorb(SKILL*60);
  }
  PO->adj_cp(-COST);
  this_player()->add_guild_exp(10*SKILL);
  return 1;
}
