inherit "/obj/treasure.c";

#include <ansi.h>

id(str){ return str == "detox_obj"; }

short(){ return "A Detoxing Pod"; }

get(){ return; }

detox_all()
{

  object *us;
  int s, amt;

  amt = 5+random(6);

  s = sizeof(us = users());
 
  while(s--) 
  {
    if(us[s] && (int)us[s]->query_level() < 20)
      us[s]->add_soaked(-amt);
      us[s]->add_stuffed(-amt); 
  }
  /*
  if(find_player("fred"))
  {
    tell_object(find_player("fred"),
      "Detox amount is "+amt+".\n");
  }
  */
  remove_call_out("detox_all");
  call_out("detox_all", 1+random(4));
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
        "\n\n"+HIY+"Fred's detoxing blessing wears off."+NORM+"\n\n");
  }
  bye();
}


bye()
{
  destruct(this_object());
}
  

start()
{
  call_out("detox_all", 1+random(4));
  call_out("dismiss", 900);
}
