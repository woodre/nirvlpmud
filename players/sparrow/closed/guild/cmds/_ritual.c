#include <ansi.h>
status cmd_ritual(string str)
{
  object wep;
  object oldwep;
  object gob;

  gob=caller();

  if(!str) return 0;

  if(!(wep=present(str, this_player()))) return 0;

  if(!wep->is_weapon()) return 0;

  write("\nDark tendrils of shadow flow from your mouth to envelope "+wep->short()+"...\n"+
        "\t..."+wep->short()+" is twisted and pulled into your body!\n\n");
  say(HIK+"\nS"+HIW+"hadows"+NORM+" flow from "+this_player()->query_name()+"'s mouth to envelope "+wep->short()+"...\n"+
        "\t..."+wep->short()+" is twisted and pulled into "+possessive(this_player())+" body!\n\n");
  if(oldwep = (object)gob->queryDonorWep()) {
    destruct(oldwep);
  }

  move_object(wep, gob);
/* reduce weight to 0 to not cause inventory to be messed with */
  wep->set_weight(0);
  wep->set_silentwield(1); /* flag as silent wield for wep hit */
  gob->setDonorWep(wep);

  return 1;
}
