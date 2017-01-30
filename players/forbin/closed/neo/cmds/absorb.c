#include "../defs.h"
#include "../specfuns.h"

status main(string str, object gob, object player)
{

  object ob;
  int value;
  string what, extra;

  if((int)player->query_ghost()) 
    return 0;
  
  if(!str)
  {
    what = "corpse";
    ob = present(what, environment(player));
    if(!ob)
      ob = present(what, player);
    if(ob && environment(ob) == player)
    {
    	tell_object(player,
    	  "You must drop the "+what+" first.\n");
    	 return 1;
    }
    if(!ob)
    {
      tell_object(player,
        "There is no "+what+".\n");
      return 1;
    }
  }
  else
  {
    what = str; 
    ob = present(what, environment(player));
    if(!ob)
    {
      ob = present(what, player);
      if(environment(ob) == player)
      {
    	  tell_object(player,
    	    "You must drop the "+what+" first.\n");
    	  return 1;
      }
    }
  }
  if(!ob) 
  {
    tell_object(player,
      "There is no "+what+".\n");
    return 1;
  }
  
  if(!((int)ob->is_corpse()) && (int)gob->query_skill("control") < 4)
  {
    tell_object(player,
      "Your symbiotic control is not great enough to absorb items.\n");  
    return 1;
  }  

  if(!((int)ob->is_corpse()))
  {      
  	if(living(ob))
  	{
  		tell_object(player,
  		  "You cannot absorb living things.\n");
  		return 1;
  	}
    if(!(ob->get()) || ob->query_weight() > 15 || 
      ob->query_value() < 1)
    {
      tell_object(player,
       "You cannot absorb that.\n");
      return 1;
    }
  }
  
  if((int)ob->is_corpse())
  {  
    if((int)ob->query_corpse_level() < 1)
    {
      tell_object(player,
        "You cannot absorb that corpse, it is useless.\n");
      return 1;
    }
    if(sscanf(file_name(ob),"obj/corpse%s",extra) != 1) return 1;
    
    value = (int)ob->query_corpse_level() / 2;
    value += random((int)ob->query_corpse_level() / 3);
    value += random((int)gob->query_skill("control"));
    value += 1;
  }
  else
  {
    value = (int)ob->query_weight();
    if(value > (int)gob->query_skill("control"))
      value = (int)gob->query_skill("control");
    value += random(((int)gob->query_skill("control") * 2 / 3));
    value += 1;
  }
  switch(random(3))
  {
  	case 0:
      tell_object(player,"\n"+
        PGC+"<<"+SGC+"*"+PGC+">>"+NORM+" You lean over the "+what+" and place your hand over it...\n"+
        "      Tentacles lash out and absorb it, leaving no trace of the "+what+".\n");
      tell_room(environment(player),
        (string)player->QN+" leans over the "+what+" and places "+(string)player->POS+" hand over it...\n"+
        "Tentalces lash out and absorb it, leaving no trace of the "+what+".\n", ({ player }));
      break;
  	case 1:
      tell_object(player,"\n"+
        PGC+"<<"+SGC+"*"+PGC+">>"+NORM+" You lean over the "+what+" and place your hand over it...\n"+
        "      "+HIW+"Dark Matter"+NORM+" covers the "+what+", then oozes back into your hand.\n"+
        "      There is no trace of the "+what+" left.\n");
      tell_room(environment(player),
        (string)player->QN+" leans over the "+what+" and places "+(string)player->POS+" hand over it...\n"+
        HIW+"Dark Matter"+NORM+" covers the "+what+", then oozes back into "+
        (string)player->QN+"'s hand.\n"+
        "There is no trace of the "+what+" left.\n", ({ player }));
      break;
  	case 2:
      tell_object(player,"\n"+
        PGC+"<<"+SGC+"*"+PGC+">>"+HIW+" Dark Matter"+NORM+
        " seeps from your feet and flows over the "+what+"...\n"+
        "      As the ooze recedes, the "+what+" is gone.\n");
      tell_room(environment(player),
        HIW+"Dark Matter"+NORM+" seeps from "+(string)player->QN+
        "'s feet  and flows over the "+what+"...\n"+
        "As the ooze recedes, the "+what+" is gone.\n", ({ player }));
      break;
  }            

  if((int)gob->query_mp() == (int)gob->query_maxmp())
  {
    player->heal_self(value / 2);
    tell_object(player,
      "      You feel stronger.\n");
  }

  else
    gob->add_mp(value);

  if((int)gob->valid_wiz((string)player->query_real_name()))
    tell_object(player, 
      HIR+"Absorb value: "+value+".\n"+NORM);
      
  move_object(ob, "/room/void");
  destruct(ob);
  return 1;
}

status help(object gob, object player)
{
	string title;
	
	title = "Absorb";
	if((int)gob->query_skill("control") >= 4)
	{
	  tell_object(player,"\n"+
	    HELPLINE+
	    HELPTITLE+
	    HELPLINE+"\n"+
  	  "    "+SGC+"Spell Point Cost:"+NORM+"      none\n"+
	    "    "+SGC+"Matter Point Cost:"+NORM+"     none\n"+
	    "\n"+
	    help_wrap("A great majority of the neo symbiotes' powers are derived by a combination of spell "+
	    "points and dark matter.  It is through the absorbtion of corpses and other items that a neo "+
	    "symbiote can build a reserve of dark matter points.  The amount of matter gain is tied to the "+
	    "neo symbiote's level of control.  The size of the corpse or the weight of the item also plays "+
	    "a significant role.\n")+
      "\n"+
  	  "         Usage:  "+PGC+"absorb"+NORM+" -"+PGC+"or"+NORM+"- "+PGC+"absorb corpse"+NORM+"\n"+
	    "                 "+PGC+"absorb "+SGC+"<"+HIW+"item"+SGC+">"+NORM+"\n\n"+
	    HELPLINE);
  	return 1;
	}
  else
	{
	  tell_object(player,"\n"+
	    HELPLINE+
	    HELPTITLE+
	    HELPLINE+"\n"+
  	  "    "+SGC+"Spell Point Cost:"+NORM+"      none\n"+
	    "    "+SGC+"Matter Point Cost:"+NORM+"     none\n"+
	    "\n"+
	    help_wrap("A great majority of the neo symbiotes' powers are derived by a combination of spell "+
	    "points and dark matter.  It is through the absorbtion of that a neo symbiote can build a reserve "+
	    "of dark matter points.  The amount of matter gain is tied to both the neo symbiote's level of "+
	    "symbiotic control and the size of the corpse.\n")+
	    "\n"+
  	  "         Usage:  "+PGC+"absorb"+NORM+" -"+PGC+"or"+NORM+"- "+PGC+"absorb corpse"+NORM+"\n\n"+
	    HELPLINE);
	  return 1;
	}  	
}