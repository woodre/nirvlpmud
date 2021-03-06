#include <ansi.h>

int loaded;

void extra_look()
{
  if(environment()==this_player())
  {
    write("You have a "+CYN+"minor Blessing"+NORM+" of "+HIR+"Vulcan"+NORM+", the smith god.\n");
  }
  else
  {
    write((string)environment()->query_name()+" is "+HIR+"glowing"+NORM+".\n");
  }
}

int get() { return 1; }
int drop() { return 1; }

string query_auto_load()
{
  return "/players/vertebraker/prizes/krillgeta:0";
}

status id(string str)
{
  return (str=="krillgeta_prize");
}

void init()
{
  if(environment() && (string)environment()->query_real_name() != "krillgeta")
    return destruct(this_object());
  else if(environment() && !loaded)
  {
    call_out("refresh_weps", 2);
    loaded = 1;
  }
}

void refresh_weps()
{
  object wep, mygob;
  if(!environment()) return destruct(this_object());
  
  mygob = present("dervish_tattoo", environment());
  
  if(wep=(object)environment()->query_weapon())
  {
    wep->set_hits(1);
    wep->set_misses(1);
    
    if(!random(100))
    {
      tell_object(environment(),
"You feel the power of "+HIR+"Vulcan"+NORM+" coursing through you.\n");
      environment()->heal_self(2);
    }
  }
  
  if(wep=(object)environment()->query_second_weapon())
  {
    wep->set_hits(1);
    wep->set_misses(1);
  }
  
  if(wep=(object)mygob->query_offwep())
  {
	  wep->set_hits(1);
	  wep->set_misses(1);
  }
  
  call_out("refresh_weps", 2);
}
