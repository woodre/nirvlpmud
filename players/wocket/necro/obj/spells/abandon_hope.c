/* abaondon hope object */
#include "../../defs.h"
int time,timelimit,dam;
id(str){ return str == "necro_abandon_hope"; }

abandon_hope(){
object ob;
string msg;
  if(time > timelimit){
    remove_call_out("abandon_hope");
    destruct(this_object());
    return; 
  }
  if(environment()) ob = environment();
  if(ob->is_npc()){
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_hunter();
    ob->stop_hunter();
    msg = get_msg(ob);
    tell_room(environment(ob),msg);
  }
  time++;
  call_out("abandon_hope",0);
}

get_msg(ob){
  switch(random(7)){
   case 0:  return ob->query_name()+BOLD+BLK+" kneels to the ground as depression sets in.\n"+OFF;
   case 1:  return ob->query_name()+BOLD+BLK+" lowers "+ob->query_possessive()+" weapon.\n"+OFF;
   case 2:  return ob->query_name()+BOLD+BLK+" is over come by past memories of sadness.\n"+OFF;
   case 3:  return ob->query_name()+BOLD+BLK+" lowers "+ob->query_possessive()+" head, giving up the fight.\n"+OFF;
   case 4:  return ob->query_name()+BOLD+BLK+" looks very depressed.\n"+OFF;
   case 5:  return ob->query_name()+BOLD+BLK+" tries to attack you but fails as "+ob->query_pronoun()+" abandons all hope.\n"+OFF;
   case 6:  return BOLD+BLK+"Gloom hovers above "+OFF+ob->query_name()+BOLD+BLK+" as the will to fight leaves "+ob->query_possessive()+".\n"+OFF;
  }
}

set_abandon(i){ time = 0; timelimit = i; abandon_hope(); }

