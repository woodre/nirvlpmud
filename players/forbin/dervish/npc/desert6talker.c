/* 
 * Forbin
 * Created:   2003.08.28
 * Last edit: 2003.09.12 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

int tired;

id(str) { return (::id(str) || str == "13l107y504n55w1975"); }

reset(arg) {
  object gold;
  ::reset(arg);
  if(arg) return;
  
  set_level(1);
  set_hp(1000);
  set_wc(1500);
  set_wc(0);
  set_al(0);
  set_wc_bonus(0);
  set_ac_bonus(0);
  set_dead_ob(this_object());
  set_chat_chance(5);
    load_chat("A soft wind blows through the area.\n");
    load_chat("A soft wind blows through the area.\n");
    load_chat("You swear you just heard the a voice on the wind.\n");
    load_chat("The wind brushes close to you.\n");
    load_chat("A cool breeze blows by, then all is silent again.\n");
} 

