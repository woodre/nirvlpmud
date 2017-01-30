#include "../def.h"

int beats;

drop() { return 1; }

id(str){
 return str == "focus_object" || str =="generic_wc_bonus";
}

object atk;

init(){
  atk = ENV()->query_attack();
  if(!atk) return destruct(this_object());
  set_heart_beat(1);
}

gen_wc_bonus()
{
  return 0; /* Will be adding to gob tonight */
  return (int)ENV()->query_guild_rank() / 2;
}

heart_beat()
{
  if(!atk || !ENV()->query_attack() ||
     ++beats == ENV()->query_guild_rank() * 4)
  {
    tell_object(ENV(), "You lose your "+BOLD+"focus"+NORM+".\n");
    tell_room(ENV(ENV()),
      ENV()->QN+" loses "+possessive(ENV())+" "+BOLD+"focus"+NORM
      +".\n", ({ ENV() }));
    return destruct(this_object());
  }
}
