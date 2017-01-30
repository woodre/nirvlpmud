#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Mr. Duke");
  set_alt_name("mr. duke");
  set_alias("duke");
  set_short("Mr. Duke");
  set_long("Mr. Duke is an average human male.  He stands about six feet tall,\n"+
           "with brown hair.  He looks friendly and eager to help you.\n");
  set_race("human");
  set_gender("male");
  set_level(15);
  set_wc(20);
  set_ac_bonus(25);
  set_ac(12);
  set_hp(1000);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(100);
  load_chat("Mr. Duke says: if you find any ants, kill them and bring me the parts.\n");
  set_chat_chance(20);
  load_a_chat("Mr. Duke says: what have i done to deserve this?\n");
  load_a_chat("Mr. Duke says: please don't hit me.\n");
  set_a_chat_chance(15);
}
