inherit "obj/treasure";
/* Adjusted by illarion 8/31/2010
 * fixed an error that kept the call_out from working
 * adjusted damage and cost (in VAMPIRES/lib/attack_damn.h) to be somewhat more legal
 */

#include <ansi.h>
 
#define DAMAGE 3 + random(8)
#define DELAY 5 + random(10)
#define TARGET environment()->query_name()

int duration, TOTAL;

id(str) { return str=="vamp_damn_obj"; }

reset(arg) 
{
}

set_time(int time)
{
  duration = time;
  call_out("bring_the_hurtin",2);
  environment()->RegisterArmor(this_object(), ({ "other|evil", 0, -20, 0 }));
}

init_arg(str) {  sscanf(str,"%d",duration); }

bring_the_hurtin()
{
  int x;
  string msg;
  if(!environment()) return;
  x = random(6);
  switch(x)
  {
    case 0:
      msg = TARGET+"'s soul writhes in agony...."; break;
    case 1:
      msg = "Demons ravage the mind of "+TARGET; break;
    case 2:
      msg = "Nightmares consume "+TARGET+"'s mind causing intense pain"; break;
    case 3:
      msg = "Wraith wolves invade the mind of "+TARGET; break;
    case 4:
      msg = TARGET+"'s eyes go hollow and dark..."; break;
    case 5:
      msg = TARGET+"'s limbs start to shrivel and wither."; break;
  }
  
  if(!environment() || !living(environment()))
  {
    silent_end();
    return;
  }

  if( environment(environment(this_object()))->query_ghost())
  {
    chatty_end();
    return;
  }

  if(environment() && living(environment()))
  {
    tell_room(environment(environment(this_object())),
      "     "+HIK+msg+NORM+"\n");

    environment()->hit_player(DAMAGE, "other|mental");
    
    duration--;
    
    if(duration <= 0)
    {
      chatty_end();
      return;
    }
    
    while(remove_call_out("bring_the_hurtin") != -1) { }
    call_out("bring_the_hurtin", random(DELAY));
  }
  return 1; 
}

silent_end()
{
  destruct(this_object());
}
chatty_end()
{
  if(environment() && environment(environment()))
    tell_room(environment(environment()),TARGET+" looks relieved as the demons depart.\n");
  destruct(this_object());
}

drop()  
{ 
  if(environment()->is_dieing())
    return 0;
  return 1; 
} 

get()   { return 0; } 

extra_look() {
  if(this_player() == environment()) return "You have been DAMNED";
  else return environment()->query_name() + " has been DAMNED";
}
