#include "../defs.h"

status main(string str, object gob, object player)
{
  object ob;
  string *validspheres;
  string one, two;
	
	if((int)gob->query_skill("creation") > 6)
    validspheres = ({ "attack", "bind", "creation", "heal", "transfer", });
  else
    validspheres = ({ "creation", });

  if((int)player->query_ghost()) 
    return 0;
  
  if((int)gob->query_skill("creation") < 4)
    return 0;
  
	if(!str)
	{
		if((int)gob->query_skill("creation") > 6)
   	  tell_object(player,
   	    "You may 'create sphere of <type>'.\n"+  
   	    "Valid types are: Attack, Bind, Creation, Heal, Transfer.\n");
   	else
   	  tell_object(player,
   	    "You may 'create sphere of creation'.\n");
		return 1;
	}
	
	else if(sscanf(str, "%s of %s", one, two) == 2)             
  {
  	if(one == "sphere")
  	{
      if(member_array(two, validspheres) > -1)
      {
        if((int)gob->query_mp() < 50)
        {
        	tell_object(player,
      	    "You do not have enough "+HIW+"Dark Matter"+NORM+" for that.\n");
        	return 1;
        }
        if((int)player->query_sp() < 50)
        {
        	tell_object(player,
      	    "You lack the energy to do that.\n");
        	return 1;
        }
        if(two != "attack" && 
           two != "bind" && 
           two != "creation" &&
           two != "heal" && 
           two != "transfer")
        {
        	tell_object(player,
      	    "You may 'create sphere of <type>'.\n"+ 
      	    "Type 'create' to view a listing of valid spheres.\n");
        	return 1;
        } 
        if(two == "creation")
        {
          
        }
        else 
        {
          ob = clone_object(OBJECTS+"sphere.c");
          ob->set_type(two);
          ob->set_creator(player->QRN);
          ob->set_color(PGC);
          move_object(ob, environment(player));
          gob->sub_mp(50);
          player->add_spell_point(-50);

          tell_object(player,
            "You place your palm on the ground...\n"+
            "A "+HIW+"Dark Matter Sphere"+NORM+" forms at your feet.\n");
          tell_room(environment(player),
            (string)player->QN+" kneels to the ground...\n"+
            CAP((string)player->PRO)+" forms a "+HIW+"Dark Matter Sphere"+NORM+" at "+
            (string)player->POS+" feet.\n", ({ player }));
          return 1;
        }
      }
      else
      {
        tell_object(player,
      	  "You may 'create sphere of <type>'.\n"+ 
      	  "Type 'create' to view a listing of valid spheres.\n");
        return 1;      
     	}
    }
    else
    {
      tell_object(player,
        "You may 'create sphere of <type>'.\n"+ 
        "Type 'create' to view a listing of valid spheres.\n");
      return 1;     
    }
  }
  else
  {
		tell_object(player,
      "You may 'create sphere of <type>'.\n"+ 
      "Type 'create' to view a listing of valid spheres.\n");
		return 1;  	
  }
}
