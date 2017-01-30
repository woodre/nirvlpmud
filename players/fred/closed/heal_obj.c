inherit "/obj/treasure.c";

#include <ansi.h>

id(str){ return str == "heal_regen_obj"; }

short(){ return "A Healing Pod"; }

get(){ return; }

heal_all()
{

  object *us;
  int s, amt;

  amt = 5+random(10);  

  s = sizeof(us = users());
 
  while(s--) 
  {
    if(us[s] && (int)us[s]->query_level() < 20)
      us[s]->heal_self(amt); 
  }
  /*
  if(find_player("fred"))
  {
    tell_object(find_player("fred"),
      "Heal amount is "+amt+".\n");
  }
  */
  remove_call_out("heal_all");
  call_out("heal_all", 1+random(4));
  return 1;
}

dismiss()
{
  object *us;
  int s;

  s = sizeof(us = users());

  while(s--)
  {
    if(us[s] && us[s]->query_level() < 20)
      tell_object(us[s], 
        "\n\n"+HIY+"Fred's healing blessing wears off."+NORM+"\n\n");
  }
  bye();
}


bye()
{
  destruct(this_object());
}
  

start()
{
  call_out("heal_all", 1+random(4));
  call_out("dismiss", 900);
}
