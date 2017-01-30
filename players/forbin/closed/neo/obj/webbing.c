#include "../defs.h"

object target;
int time;

web_person(object ob) 
{
  if(!ob) 
    return;
  target = ob;
  shadow(target, 1);
  return 1; 
}
  
int webbed() { return 1; }

void set_time(int x) { time = x; }

reset() { set_heart_beat(1); }

heart_beat() 
{
  time --;
  if(random(100) < 25)
     effect();
  if(time < 1)
    end();
}
 
status stop_con_shadow() 
{
  shadow(target, 0);
  destruct(this_object());
  return 1; 
}

move_player()
{
  tell_room(environment(target),
    (string)target->QN+" struggles to break free of the webbing!\n");
}

move_object()
{
  tell_room(environment(target),
    (string)target->QN+" struggles to break free of the webbing!\n");
}
  
run_away()
{
  tell_room(environment(target),
    (string)target->QN+" struggles to break free of the webbing!\n");
}

movement()
{
  tell_room(environment(target),
    (string)target->QN+" struggles to break free of the webbing!\n");
}

effect() 
{
  if(target && environment(target)) 
  {
    tell_room(environment(target),
      (string)target->QN+" struggles to break free of the webbing!\n");
    return 1; 
  }
  return; 
}

short() { return (string)target->short()+" "+HIW+" .xX WEBBED Xx."+NORM; }

end() 
{
  if(target && environment(target)) 
  {
    tell_room(environment(target),
      HIR+(string)target->query_name()+HIR+" manages to free themself from the webbing."+NORM+"\n");
    shadow(target, 0);
    destruct(this_object()); 
    return 1; 
  }
  return; 
}
