#include "../defs.h"

status main(string str, object gob, object player)
{
	int a, b, c;
	int free, cost;
	
  if((int)player->query_ghost()) return 0;
  
	if(!str)
	{
		tell_object(player,
		  "You may raise your combat, control, or creation skill.\n"+
		  "To do so, type 'raise <choice>'.\n");
		return 1;
	}
  if(str == "skill" || str == "skills")
  {
    tell_object(player,
      "You may raise your combat, control, or creation skill.\n"+
		  "To do so, type 'raise <choice>'.\n");
    return 1;	
  }  	
  if(member_array(str, VALIDSKILL) < 0)
  {
    tell_object(player,
      "That is not a valid choice.  "+
      "You may raise combat, control, or creation.\n");
    return 1;	
  }
  a = (int)gob->query_skill("combat");
  b = (int)gob->query_skill("control");
  c = (int)gob->query_skill("creation");
  if((a + b + c) >= 23)
  {
    tell_object(player,
      "You have already advanced your skills as far as possible.\n");
    return 1; 
  }
  a = (int)gob->query_skill(str);
  if(a >= 8)
  {
    tell_object(player,
      "You have raised your "+str+" skill to its maximum.\n");
    return 1;
  }
  if((int)gob->query_free_skill())
  {
      
  }
  if((int)gob->query_skill_prof(str) < (int)gob->query_prof_cost(str))
  {
    tell_object(player,
      "You are not proficient enough to raise your "+str+" skill.\n");
      return 1;  
  }    
  cost = (int)gob->query_skill_cost(a);  
  if((int)player->QEL < 1)
    free = (int)player->query_experience() - (int)call_other("room/adv_guild","get_next_exp",((int)player->QL - 1));
  if((int)player->QEL > 1)
    free = (int)player->query_experience() - (int)call_other("room/exlv_guild","get_next_exp",((int)player->QEL - 1));
  if(free < cost)
  {
    tell_object(player,
      "You do not have enough free experience to raise "+str+".\n"+
      "You need "+cost+" free experience in order to raise it.\n");
    return 1; 
  }
  player->add_exp(-cost);
  gob->add_skill(str, 1);
  gob->set_skill_prof(str, 0);
  gob->add_glevel(1);
  gob->add_guildexp(cost);
  gob->save_gob();
  player->save();
  player->reset(1);
  tell_object(player,
    "You increase your "+str+" skill to "+
    (int)gob->query_skill(str)+".\n");
  if((int)gob->query_skill(str) == 8)
    tell_object(player,
      "You have advanced your "+str+" skill to its maximum.\n");
  tell_object(player,
    "You are now a level "+(string)gob->print_glevel()+" Neo Symbiote.  Type 'link' for your powers.\n");      
  return 1;
}
