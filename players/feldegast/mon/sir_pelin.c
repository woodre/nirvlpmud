#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"boots.c"),this_object());
  init_command("wear boots");  /* 100 */
  move_object(clone_object(ARM_PATH+"bplate.c"),this_object());
  init_command("wear plate"); /* 1000 */
  move_object(clone_object(ARM_PATH+"silv_shield.c"),this_object());
  init_command("wear shield"); /* 1000 */
  move_object(clone_object(WEP_PATH+"fortitude.c"),this_object());
  init_command("wield sword"); /* 1000 */  
  add_money(1400+(random(10)*100));
  set_name("pelin");
  set_alias("sir");
  set_alt_name("knight");
  set_short("Sir Pelin, Knight of the Wall");
  set_long(
"Sir Pelin is a stern looking knight bearing the red and white colors\n"+
"of his order.  He stands six and a half feet tall, and affects\n"+
"the close-cropped hair of a monk.  He has devoted his life to the\n"+
"defense of others, and he takes his task extremely seriously.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(32);
  set_ac(16); /* 22 with armor */
  set_ac_bonus(6); /* For armor */
  set_hp(520);
  set_al(950);
  set_chat_chance(4);
  load_chat("Sir Pelin looks out into the desert.\n");
  load_chat("Sir Pelin mutters a prayer for those who once occupied this castle.\n");
  load_spell(30,20,0,
    "Sir Pelin raises his sword over his head and slashes at you!\n",
    "Sir Pelin raises his sword over his head and slashes at #ATT#!\n");
  load_spell(80,1,3,
    "Sir Pelin summons...\n"+
HIB+"\t*                                 *\n"+
"\t*                                 *\n"+
"\t*        "+HIY+"THE WRATH OF GOD"+HIB+"         *\n"+
"\t*                                 *\n"+
"\t*                                 *\n"+NORM,
    "");
}

heart_beat() {
  object ob;
  ::heart_beat();
  if(hit_point < (max_hp-50) && !random(40)) {
    tell_room(environment(),HIY+"Sir Pelin presses his holy symbol to his lips and prays\n"+
          "to Trelos for healing.\n"+NORM);
    hit_point+=50;
    hp_bonus+=50;
  }
  if(!attacker_ob && !random(8)) {
    ob=first_inventory(environment());
    while(ob) {
      if(ob->is_player() && ob->query_alignment() < -500) {
        tell_room(environment(),"Sir Pelin says: I sense your evil heart, "+(string)ob->query_name()+".\n");
        attack_object(ob);
        return;
      } else
      ob=next_inventory(ob);
    }
  }
}
