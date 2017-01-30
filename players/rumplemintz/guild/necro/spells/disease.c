/* Guild Level 5 - 
   casts a disease upon a monster..
   TotalCost - 107
   damage average 120-140
*/

#include "../defs.h"

cmd(str){
object ob,att;
  ob = GOB;
  if(!ob->checklev(5,10)) return 1;
  if(!str){
    if(tp->query_attack()) att = tp->query_attack();
    else{
      notify_fail("Who would you like to disease?\n");
      return 0; 
    } 
  }
  else{
    att = present(str, environment(tp)); 
  }
  if(!att){
    notify_fail("There is no "+str+" here to disease.\n"); 
    return 0; 
  }
  if(!att->is_npc() && !att->is_layer()){
    notify_fail("That is not something you can disease.\n");
    return 0;
  }
  if(tp->query_sp() < 45){
    notify_fail("You do not have the spell points available to disease someone.\n");
    return 0;
  }
  if(ob->query_heart() < 1 || ob->query_skin() < 4) {
    notify_fail("You do not have the components available for this spell.\n");
    return 0; 
  }
  if(present("necro_disease",att)){
    write(att->query_name()+" has already been diseased.\n");
    return 1;
  }
  write("As you quickly stitch together a blanket of decaying flesh you squeeze the\n"+
        "fresh blood from a rotten heart across it.\n");
  say(tp->query_name()+" quickly stitches together a blanket of decaying flesh and then \n"+
      "squeezes fresh blood from a rotten heart across it.\n");
  call_out("throwit1",3,({ tp,att}) );
  tp->add_spell_point(-45);
  ob->add_heart(-1);
  ob->add_skin(-4);
  return 1;
}

throwit1(arg){
object blanket;
  if(!arg[0] || !arg[1]) return;  /* verte */
  tell_object(arg[0],"\nAs you enchant the dead flesh, "+GRN+"maggots"+OFF+" begin to crawl across it\n"+
                 "with vigor.  "+GRN+"Disease"+OFF+" takes hold as you toss the blanket across\n"+arg[1]->query_name()+"'s torso.\n"+OFF);
  arg[0]->remote_say(arg[0]->query_name()+" enchants the dead flesh and tosses it across "+arg[1]->query_name()+"'s torso.\n"+OFF);
  blanket = clone_object(OBJ+"/spells/disease.c");
  move_object(blanket,arg[1]);
  blanket->set_disease((arg[0]->query_guild_rank()/3)+4,27);
  arg[0]->spell_object(arg[1],"disease",0,0,"","","");
  return 1;
}
