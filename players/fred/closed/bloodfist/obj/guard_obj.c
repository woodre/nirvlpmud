#include "ansi.h"
object who, gob, nmy, a;
int msg, timah;

reset(arg){
  if(arg) return;

  timah = 10;
  set_heart_beat(1);
}

short(){ return 0; }
id(str){ return str == "bf_guard_ob"; }

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

extra_look(){
  if(environment() && living(environment()) && who)
    return environment()->query_name()+
    " is being guarded by "+who->query_name();
}

void init(){
  add_action("stop_guarding", "stop");
  add_action("hmmwhy", "aethethoeahgpghaepgh");
}

hmmwhy()
{
  if(!who || !gob) return;
  if(environment()->is_player())
  {
    tell_object(environment(), HIG+
      "Do you want "+who->query_name()+" to guard you? <y/n>\n"+NORM);
    input_to("answer");
  }
  else if(living(environment()))
    gob->set_guard(environment());
  return 1;
}

void set_owner(object a, object b)
{ 
  who = a; 
  gob = b;
  /*
  if(environment()->is_player())
  {
    tell_object(environment(),
      "Do you want "+who->query_name()+" to guard you?  y/n\ny/n>");
    input_to("answer");
  }
  else if(living(environment()))
    gob->set_guard(environment());
  */
}

void answer(string str)
{
  if(str == "y")
  {
    tell_object(environment(), "You allow "+who->query_name()+
      " to guard you.\n"+
      "Type 'stop guarding' to end it at any time.\n");
    tell_object(who, environment()->query_name()+" allows you to guard "+
      environment()->query_objective()+".\n");
    gob->set_guard(environment());
    gob->toggle_guarding();
    timah = -1;
  }
  else {
    tell_object(environment(), "You deny "+who->query_name()+
      "'s request to guard you.\n");
    tell_object(who, environment()->query_name()+" denies your request "+
      "to guard "+environment()->query_objective()+".\n");
    gob->toggle_guarding();
    destruct(this_object());
  }
}

guard_check()
{
  if(!who) return 0;
  if(!environment()
    || !living(environment())
    || !find_player((string)who->query_real_name())
    || !((a = present("bloodfist_gob", who)->query_guard()) 
    && a == environment()) && timah < 0)
  {
    tell_object(find_player("fred"), "t2\n");
    if(who && find_player((string)who->query_real_name()))
      gob->set_guard(0);
    destruct(this_object());
    return 1;
  }
  return 0;
}

void end()
{
  tell_object(environment(), who->query_name()+
    " is no longer guarding you.\n");
  destruct(this_object());
}

status stop_guarding(string str)
{
  if(str != "guarding") return 0;
  guard_check();
  write("You have "+who->query_name()+" stop guarding you.\n");
  tell_object(who, environment()->query_name()+" has stopped you "+
      "from guarding "+environment()->query_objective()+".\n");
  gob->set_guard(0);
  destruct(this_object());
  return 1;
}

heart_beat()
{
  if(timah > 0)
  {
    timah--;
    if(timah == 0)
    {
      tell_object(environment(), "\nYou deny "+who->query_name()+
        "'s request to guard you.\n");
      tell_object(who, environment()->query_name()+" denies your request "+
        "to guard "+environment()->query_objective()+" (timed out).\n");
      if(gob)
        gob->toggle_guarding();
      destruct(this_object());
      return;
    }
  }
  if(guard_check()) return;
  if((nmy = environment()->query_attack()))
  {
    if(nmy->query_attack() == environment()
      && present(nmy, environment(environment())))
    {
      if(present(who, environment(environment())))
      {
        tell_room(environment(who), who->query_name()+
          " jumps in to protect "+environment()->query_name()+".\n");
        who->attack_object(nmy);
        nmy->attack_object(who);
        environment()->stop_fight();
        environment()->stop_fight();
        environment()->stop_hunter();
      }
      else {
        if(msg <= 0)
        {
          tell_object(who, HIR+"\n"+environment()->query_name()+
            " is being attacked by "+nmy->query_name()+"!\n\n"+NORM);
          msg = 4;
        }
        else
          msg--;
      }
    }
  }
}


