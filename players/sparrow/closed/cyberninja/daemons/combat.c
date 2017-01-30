#include "../DEFS.h"

valid_attack(object defender, object attacker) {
  if (defender->query_ghost()) return 0;
  if (defender->is_player()) {
    if ( attacker->query_real_name() == "guest") return 0;
    if (!defender->query_interactive()) return 0;
    if ( defender->query_level() > 19)  return 0;
    if( defender == attacker ) return 0;  /*added by wocket*/
    if(environment(defender)->query_no_fight()) return 0;

    /* player vs. player guild spells enabled in guild */
    if( valid_pk(defender,attacker) == 2 ) return 1;
    else return 0;

  }
  if (attacker == defender->query_attack()) return 1;
  if (defender->query_npc()) return 1;
  return 0;
}


status valid_pk(object defender, object attacker) {
  if(!environment(attacker)) return 0;
  if(environment(defender)->CN_PK()) return 2;
  if(defender->query_pl_k() && attacker->query_pl_k()) return 2;
  if((string)defender->query_fight_area() == 
     file_name(environment(attacker))) return 2;
  return 0;
}
