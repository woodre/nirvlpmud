#include "../../defs.h"

int Tick, Ticks;
object Targ, Gob, Play;

called_effects();

id(str){ return str == "forbin_dm_creeping_doom_object"; }

void setup(object x, object y, object z)
{ 
  Tick = 0; 
  Ticks = 10;
  Targ = x;
  Gob = y;
  Play = z;
  called_effects(); 
}

void called_effects()
{
  string msg;
  int base, dmg;

  if(!Targ)
    destruct(this_object());
  
  if(Tick > Ticks)
  {
    remove_call_out("called_effects");
    destruct(this_object());
    return; 
  }
  
  if(Tick < 1)
  {
  	Tick++;
    call_out("called_effects", 2);
    return;
  }

  base = 4 + (int)Gob->query_glevel() + ((int)Gob->query_fae() / 10);
  base += random(((int)Gob->query_glevel() * 2)); 
  base += random((1 + ((int)Gob->query_fae() / 2)));
  if(!((int)Gob->query_talent()))
    base += 5+random(5);
  if((object)Targ->query_attack() == Play)
    base += 15;
    
  switch(Tick)
  {
    case 2:  dmg = base; break;
    case 4:  dmg = base + 10 + random(20); break;
    case 6:  dmg = base + 20 + random(40); break;
    case 8:  dmg = base + 55 + random(70); break;
    case 10: dmg = base + 100 + random(110); break;
    default: dmg = 0; break;
  }    
      
  if((int)Targ->is_npc())
  {
    switch(random(10))
    {
      case 0: msg = GRN+"Bugs crawl from the ground, scurrying up "+
                    (string)Targ->QN+NORM+GRN+".\n"+NORM; break;
      case 1: msg = GRN+(string)Targ->QN+NORM+GRN+" is beseiged by swarms of insects.\n"+NORM; break;
      case 2: msg = GRN+"A swarm of bugs descend on "+
                    (string)Targ->QN+NORM+GRN+".\n"+
                    (string)Targ->QN+NORM+GRN+" screams in pain.\n"+NORM; break;
      case 3: msg = GRN+"Welps begin to form on "+
                    (string)Targ->QN+NORM+GRN+" from all the bug bites.\n"+NORM; break;
      case 4: msg = GRN+"Flesh is torn from "+
                    (string)Targ->QN+NORM+GRN+"'s skin as the insects devour "+
                    (string)Targ->QO+NORM+GRN+".\n"+NORM; break;
      case 5: msg = GRN+(string)Targ->QN+NORM+GRN+" screams as the bugs bite and sting "+
      	            (string)Targ->QO+NORM+GRN+".\n"+NORM; break;
      case 6..9: break;
    } 
         
    if(msg)
      tell_room(environment(Targ), msg);
    if(dmg && (string)Play->QRN == "forbin")
      tell_object(Play, HIR+"Damage = "+dmg+NORM+"\n");
        	
    if(dmg)
    {
    	if(dmg > ((int)Targ->query_hit_point() + 50))
    	  Targ->hit_player(((int)Targ->query_hit_point() - 50), "other|forbin");
    	else
        Targ->hit_player(dmg, "other|forbin");
    }
  }
  Tick++;
  call_out("called_effects", 2);
}
