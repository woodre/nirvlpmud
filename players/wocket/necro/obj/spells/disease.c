/* disease object */
#include "../../defs.h"
int time,timelimit,dam;
id(str){ return str == "necro_disease"; }

hurtme(){
object ob;
string msg;
  if(time > timelimit){
    remove_call_out("hurtme");
    destruct(this_object());
    return; 
  }
  if(environment()) ob = environment();
  if(ob->is_npc()){
    ob->heal_self( -((dam/2)+random(dam/2)) );
    msg = get_msg(ob);
    tell_room(environment(ob),msg);
  }
  time++;
  call_out("hurtme",5);
}

get_msg(ob){
  switch(random(7)){
   case 0:  return ob->query_name()+" buckles in pain as the disease spreads through "+ob->query_possessive()+" skin.\n"+OFF;
   case 1:  return ob->query_name()+" begins to turn blue.\n"+OFF;
   case 2:  return ob->query_name()+" starts to vomit over "+ob->query_possessive()+" self.\n"+OFF;
   case 3:  return ob->query_name()+"'s face starts to turn very pale as "+ob->query_possessive()+" skin turns pasty.\n"+OFF;
   case 4:  return ob->query_name()+" looks very clammy.\n"+OFF;
   case 5:  return ob->query_name()+" coughs up blood as "+ob->query_possessive()+" skin begins to bubble.\n"+OFF;
   case 6:  return "Puss being to poor out of the pores of "+ob->query_name()+".\n"+OFF;
  }
}

set_disease(i,b){ time = 0; timelimit = i; dam = b; hurtme(); }

