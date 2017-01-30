/*
 * Ascension, by Dune and Snow
 * Combat daemon
 */
#include "../def.h"


begin_round(object ob) {
  call_out("check_alignment", 0, ob);
  call_out("add_helpers", 0, ob);
  }


check_alignment(object ob) {
  /* stop fight if in combat against good alignment */
  object att;
  int att_align;
  att   = ((object)ob->query_attack());
  att_align = ((int)att->query_alignment());
  if(att_align > 0) {
      tell_object(ob, "Good beings cannot be attacked!\n");
      att->stop_fight();
      att->stop_hunter();
      att->stop_fight();
      ob->stop_fight();
      ob->stop_hunter();
      ob->stop_fight();
      }
}


add_helpers(object ob) {
  /* check chance for summoning, clone monsters */
  string being, skin;
  int glev, i, helper_num, chance;

  /* do not summon if legion master is not in room */
  if(!present(ob->query_real_name()+"_spirit_legion",
    environment(ob))) return;

  glev  = IPOB->query_setting(CLASS);
  being = LEVELD->get_being(glev);
  skin  = LEVELD->get_skin(glev);
  helper_num = SUMMONC->number_of_helpers();
  for(i = 0; i < helper_num; i++) {
    chance = SUMMONC->summon_chance(i, being, skin);
    if(random(chance) == 1) {
      SUMMONC->clone_spirit_helper(i, ob);
      i = helper_num; /* exit loop */
      }
    }
}
