#include "../def.h"

int beats;

drop() { return 1; }

id(str){
 return str == "kiai_object" || str =="generic_wc_bonus";
}

object atk;

init(){
  atk = ENV()->query_attack();
  if(!atk) return destruct(this_object());
  set_heart_beat(1);
}

gen_wc_bonus()
{
  return 0; /* Will be putting into gob tonight */
  return (int)ENV()->query_guild_rank()/2;
}

heart_beat()
{
  if(!atk || !ENV()->query_attack() ||
     ++beats == ENV()->query_guild_rank() * 4)
  {
    tell_object(ENV(), "You feel less powerful.\n");
    tell_room(ENV(ENV()),
      ENV()->QN+" appears less powerful"
      +".\n", ({ ENV() }));
    return destruct(this_object());
  }
}
