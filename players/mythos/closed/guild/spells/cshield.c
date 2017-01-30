#include "/players/mythos/closed/guild/def.h"
int damage, need;

id(str) { return str == "chill_factor"; }

drop() {return 1;}

set_dam(n) { damage = n;}
set_need(nd) { need = nd;}

reset(arg) { 
  if(arg || root()) return;
  call_out("check",3);
}

init() {
  add_action("off","cshield_off");
}

off() {
  write("You cloak the cold within you.\n");
  tell_room(environment(tp),"The room warms up suddenly.\n");
  destruct(this_object());
  return 1;
}
  
check()
{
  if(ep)
  {
    if(present(fear,ep)->query_sacrifice() < need)
    { 
      tell_room(environment(ep),"The room warms up suddenly.\n");
      tell_object(ep,"The darkness needs more sacrifice.  The cold without vanishes.\n");
      destruct(this_object());
      return 1;
    }
    if( ep->query_sp() < -10)
    {
      tell_room(environment(ep),"The room warms up suddenly.\n");
      tell_object(ep,"You need more energy. The cold without vanishes.\n");
      destruct(this_object());
      return 1;
    }
    if(ep->query_attack())
    {
      if((ep->query_attack())->is_player() && !epp)
      {
        call_out("check",3);
        return 1;
      }
      if(ep->query_attack())
      {
        if(0==random(13))
          tell_room(environment(ep),"The room is chilly.\n");
        if(ep->query_attack()->query_hp() > 2*damage)
        {
          (ep->query_attack())->heal_self(-random(2 * damage));  
          ep->add_spell_point(-damage);
          present(fear,ep)->add_sacrifice(-1);
        }
      }
    }
  }
  call_out("check",3);
}
  
query_shatter_proof() { return 1;}
