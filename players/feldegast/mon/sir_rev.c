#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"boots.c"),this_object());
  init_command("wear boots");  /* 100 */
  move_object(clone_object(ARM_PATH+"furcloak.c"),this_object());
  init_command("wear cloak");  /* 600 */
  move_object(clone_object(ARM_PATH+"chainmail.c"),this_object());
  init_command("wear mail"); /* 550 */
  move_object(clone_object(ARM_PATH+"silv_shield.c"),this_object());
  init_command("wear shield"); /* 1000 */
  move_object(clone_object(WEP_PATH+"reason.c"),this_object());
  init_command("wield axe"); /* 1000 */  
  add_money(1250+(random(10)*100));
  set_name("revanche");
  set_alias("sir");
  set_alt_name("knight");
  set_short("Sir Revanche, Knight of the Wall");
  set_long(
"Sir Revanche is an imposing figure, his long blonde hair streaming\n"+
"down his back over the pelt of a snow tiger.  His body is huge and\n"+
"muscular.  He easily carries a huge axe in just one hand.  His holy\n"+
"symbol is glowing.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(32);
  set_ac(10); /* 16 with armor */
  set_ac_bonus(6);
  set_hp(550);
  set_al(950);
  set_chat_chance(4);
  load_chat("Sir Revanche stares at the portal.\n");
  load_chat("Sir Revanche mutters: It must be a puzzle of some kind.\n");
  load_spell(30,20,0,
    "Sir Revanche raises his axe over his head and slashes at you!\n",
    "Sir Revanche raises his sword over his head and slashes at #ATT#!\n");
  load_spell(80,1,3,
    "Sir Revanche summons...\n"+
HIB+"\t*                                 *\n"+
"\t*                                 *\n"+
"\t*        "+HIY+"THE WRATH OF GOD"+HIB+"         *\n"+
"\t*                                 *\n"+
"\t*                                 *\n"+NORM,
    "");
  set_light(1);
}

heart_beat() {
  object ob;
  ::heart_beat();
  if(hit_point < (max_hp-50) && !random(40)) {
    tell_room(environment(),HIY+"Sir Revanche presses his holy symbol to his lips and prays\n"+
          "to Trelos for healing.\n"+NORM);
    hit_point+=50;
    hp_bonus+=50;
  }
  if(!attacker_ob && !random(8)) {
    ob=first_inventory(environment());
    while(ob) {
      if(ob->is_player() && ob->query_alignment() < -500) {
        tell_room(environment(),"Sir Revanche says: I sense your evil heart, "+(string)ob->query_name()+".\n");
        attack_object(ob);
        return;
      } else
      ob=next_inventory(ob);
    }
  }
}
