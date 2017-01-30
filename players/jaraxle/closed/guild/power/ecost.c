#include "/players/jaraxle/closed/guild/sdefine.h"
#include "/players/jaraxle/ansi.h"
main(string str, object gob, object player)
{
   
   if(!str){
      write("You must specify [1,2,3] as a cost.\n");
      write("\tCurrent Ecost Setting: "+HIR+"["+NORM+GOB->query_cost_toggle()+HIR+"]\n"+NORM);
      return 1; }
   
   if(USER->query_ghost()) return 0;
   
   if(str == "1"){ 
      if(GOB->query_cost_toggle() == 1){ write("Ecost already set to 1.\n"); return 1; }
      write(HIR+"[ "+HIC+"Ecost set to 11 hitpoints"+HIR+" ]\n"+NORM);
      GOB->set_cost_toggle(1);
      command("e_update",USER);
      return 1; }
   
   if(str == "2"){ 
      if(GOB->query_cost_toggle() == 2){ write("Ecost already set to 2.\n"); return 1; }
      GOB->set_cost_toggle(2);
      write(HIR+"[ "+HIC+"Ecost set to 11 spellpoints"+HIR+" ]\n"+NORM);
      command("e_update",USER);
      return 1; }
   
   if(str == "3"){ 
      if(GOB->query_cost_toggle() == 3){ write("Ecost already set to 3.\n"); return 1; }
      GOB->set_cost_toggle(3);
      write(HIR+"[ "+HIC+"Ecost set to 6 hitpoints & 6 spellpoints"+HIR+" ]\n"+NORM);
      command("e_update",USER);
      return 1; }
}

