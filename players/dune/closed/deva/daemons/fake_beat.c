/*
 * Ascension, by Dune and Snow
 * Fake heart beat
 */
#include "../def.h"


fake_beat(object ob)
{
  object att, legion_ob;
  int align;
  align = ((int)ob->query_alignment());
  /* temporarily commented out for playtesting
  if((align < 1000) && (!IPOB->query_setting(DISGRACE))) {
    tell_object(ob, "Your level of faith disgraces you.\n");
    IPOB->set_setting(DISGRACE, 1);
    IPOB->save_me();
    move_object(IPOB, ob);
    return 1;
    }
  */
  att = ((object)ob->query_attack());
  if(att)
  {
    /* check to see if fighting good creatures */
    /* check chance for monster summoning */
    COMBATD->begin_round(ob);

    /* coordinate spirit legion combat */
    /* remove spirits when no longer in combat and destruct */
    if(!IPOB->query_legion())
    {
      legion_ob = clone_object(SUMMONDIR+"legion.c");
      move_object(legion_ob, environment(ob));
      legion_ob->begin_war(ob, ob->query_real_name());
      IPOB->set_legion(1);
      }
    }
  return 1;
}
