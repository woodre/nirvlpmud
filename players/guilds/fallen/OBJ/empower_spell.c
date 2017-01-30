inherit "/obj/treasure.c";
#include "../all.h"
#define NPC environment(this_object())
int empowered, wc, ac, counter; 

reset(arg) {
   if (arg) return;
   empowered = 0;
   counter = 1350;
   set_heart_beat(1);
}

id(str){ return str == "ruby_red_gem_damn"; }
query_value(){ return 0; }
query_weight(){ return 0; }
dest_func(){ destruct(this_object()); }
get(){ return 0; }

query_empowered(){ return empowered; }
set_empowered(int x){ 
  empowered = x;
  wc = NPC->query_wc();
  ac = NPC->query_ac();
  NPC->set_ac(NPC->query_ac() + 3);
  NPC->set_wc(NPC->query_wc() + 6);
}

extra_look()
{
  if(ENV->is_npc())
    return BOLD+BLK+ENV->QN+" is empowered by the shadows"+NORM; 
}

cdest_func(){
  tell_room(environment(NPC), BOLD+BLK+
    "A dark shadow is lifted from "+environment(TO)->QN+".\n\n"+NORM);
  NPC->set_ac(ac);
  NPC->set_wc(wc);
  destruct(this_object());
  return 1;
}

msgs(){
  int a;
  string msg;
  a = random(6);
  switch(a){
  case 0:
    msg = "Shadows seem to linger around "+environment()->query_name();
    break;
  case 1:
    msg = "A dark shadow dances around "+environment()->query_name();
    break;
  case 2:
    msg = environment()->query_name()+" appears to be cloaked in a shadow";
    break;
  case 3:
    msg = "Shadowy tendrils cling to "+environment()->query_name();
    break;
  case 4:
    msg = environment()->query_name()+" exudes an aura of power";
    break;
  case 5:
    msg = "A whispy shadow is visible around "+environment()->query_name();
    break;
  }
  tell_room(environment(environment()), BOLD+BLK+msg+".\n"+NORM);
}
    

heart_beat(){
  if(!environment())
    return ;
  if(!environment()->is_npc())
  {
    destruct(this_object());
    return;
  }
  if(environment()->is_npc() && empowered)
  {
    counter--;
    if(environment()->query_hp() < environment()->query_mhp())
      environment()->heal_self(random(2));
    if(!random(170))
      msgs();
  }
  if(counter <= 0)
  {
    cdest_func();
    return;
  }
}
