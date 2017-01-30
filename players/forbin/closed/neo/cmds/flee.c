#include "../defs.h"
#include "../specfuns.h"

status main(string str, object gob, object player)
{
	object ob, altob; 
	
  if((int)player->query_ghost()) return 0;
    
  ob = (object)player->query_attack();     
  altob = (object)player->query_alt_attack();

  if((int)player->query_sp() < 25)
  {
    tell_object(player,
      "Your symbiotic link is too weak for that.\n");
    return 1;
  }	
  
  if(!ob)
  {
    tell_object(player,
      "You can only do this in combat!\n");
    return 1; 
  }
 
  if(altob)
  {
    altob->stop_fight();    
    player->stop_fight();
    altob->stop_hunter();
    player->stop_hunter();
  }               
  
  if(ob)
  {        
    ob->stop_fight();
    player->stop_fight();   
    ob->stop_hunter();
    player->stop_hunter();
  }
  
  if(altob)
  {
    altob->stop_fight();    
    player->stop_fight();
    altob->stop_hunter();
    player->stop_hunter();
  }               
  
  if(ob)
  {        
    ob->stop_fight();
    player->stop_fight();   
    ob->stop_hunter();
    player->stop_hunter();
  }
  
  tell_object(player,
    "You turn and flee from combat!\n");
  tell_room(environment(player),
    (string)player->QN+" turns and flees from combat!\n", ({ player }) );
  player->add_spell_point(-25);
  return 1;
}

status help(object gob, object player)
{
  string title;
	
  title = "Flee";

  tell_object(player,"\n"+
	  HELPLINE+
	  HELPTITLE+
	  HELPLINE+"\n"+
    "    "+SGC+"Spell Point Cost:"+NORM+"      small\n"+
	  "    "+SGC+"Matter Point Cost:"+NORM+"     none\n"+
	  "\n"+
	  help_wrap("A holdover from your days as an original symbiote, you are still most concerned "+
  	"with the survival of both yourself and your symbiotic self.  If battle becomes too dangerous "+
  	"you can flee from battle and strategize a new attack plan.  Keep in mind that any other persons "+
  	"in battle with your attacker will continue to fight without you.\n")+
    "\n"+
  	"         Usage:  "+PGC+"flee"+NORM+"\n\n"+
	  HELPLINE);
 return 1;
}
