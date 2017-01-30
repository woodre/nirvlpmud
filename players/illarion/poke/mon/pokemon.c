/* 11/10/02 - added code to account for the damage added by spells, also added
   damage type to spells.  If damage type is non-physical, it's credited at 1.25
   damage as per /doc/build/RULES/monster.bonuses
 */

inherit "/obj/monster";
#include "/players/illarion/dfns.h"

int spchance;
string *spell_list;

void add_spell(string name,string damage,string mess_target,string mess_room,string damtype) {
  /*
  if(!spell_list) spell_list=({});
  if(!spells) spells=([]);
  spell_list+=({name});
  if(!damtype)
    damtype="physical";
  spells+=([name:({damage,mess_target,mess_room,damtype})]);
  recalc_wc();
  */
  ::add_spell(name,mess_target,mess_room,spchance,damage,damtype);
}
void set_spchance(int x) {
  spchance=x;
}
void create(int lev) {
  GUIDE->make_monster(lev,TO,25);
  /*
  set_level(lev);
  set_wc(GUIDE->wc_guide(lev));
  set_ac(GUIDE->ac_guide(lev));
  set_hp(GUIDE->hp_guide(lev));
  add_money(GUIDE->gold_guide(lev));
  */
}
