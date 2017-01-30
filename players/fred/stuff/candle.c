#include "/players/fred/ansi.h"
  
#define USER this_player()
#define NAME USER->query_name()
int use;
 
id(str)
{
  return str == "candle"; 
}

short()
{
  return "A large candle"; 
}

long()
{
  write("I said it's a large candle! What you never seen a friggin'\n"+
        "candle before?\n"); 
}
    
query_value()
{
  return (1);
}

reset(arg)
{
 if(arg) return;
}
  
init()
{
  add_action("FIREINTHEHOLE","burn");
  add_action("FIREINTHEHOLE","light");
}
  
   
FIREINTHEHOLE(str)
{
  if(!str){ write("Burn what?\n"); }
  if(str == "candle")
  {      
    write("You light the candle and it starts to give off a soft glow.\n"+
          "You feel yourself start to relax.\n");
    call_out("destme", 160);
    call_out("BURNBABYBURNDISCOINFERNO" , 10+random(20));
    return 1; 
  }
}

BURNBABYBURNDISCOINFERNO()
{
  if(!environment()) return;
  tell_room(environment(),
    "A small glob of wax falls to the ground as the candle burns.\n");
  call_out("BURNBABYBURNDISCOINFERNO" , 10+random(20));
  return 1;
}

destme(){ destruct(this_object());}

query_weight(){ return 1; }	

get(){ return 1; }

