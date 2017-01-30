#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ_PATH+"seal.c"),this_object());
  move_object(clone_object(ARM_PATH+"bplate.c"),this_object());
  init_command("wear plate");
  move_object(clone_object(ARM_PATH+"helmet.c"),this_object());
  init_command("wear helmet");
  move_object(clone_object(WEP_PATH+"wrath.c"),this_object());
  init_command("wield wrath");  
  set_name("reid");
  set_alias("lord");
  set_alt_name("knight");
  set_short("Lord Reid the High Knight");
  set_long(
"Sir Reid is a tall, broad-shouldered knight with a square jaw that\n"+
"inspires trust and confidence.  Sir Reid wears a white and red tabard\n"+
"over his armor, signifying his affiliation with the Order of the Wall,\n"+
"of which he is a prominent member.  Sir Reid is a swift, canny\n"+
"opponent, and well-favored by his god, Trelos.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(22);
  set_wc(40);
  set_ac(20);
  set_hp(800);
  set_al(950);
  set_chat_chance(4);
  load_chat("Sir Reid kneels before the altar and prays.\n");
  load_chat("Sir Reid mutters: It must be here, I'm sure of it.\n");
  load_spell(30,20,0,
    "Sir Reid sweeps your feet out from under you with the staff\n"+
    "of his weapon.\n",
    "Sir Reid sweeps the feet out from under #ATT#.\n");
  load_spell(40,20,0,
    "\nSir Reid strikes you a grievous blow with his morningstar!\n\n",
    "\nSir Reid strikes #ATT# a grievous blow with his morningstar!\n\n");
  load_spell(80,5,3,
    "Sir Reid summons...\n"+
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
  if(hit_point < (max_hp-50) && !random(20)) {
    tell_room(environment(),HIY+"Sir Reid presses his holy symbol to his lips and prays\n"+
          "to Trelos for healing.\n"+NORM);
    hit_point+=50;
    hp_bonus+=50;
    if(hit_point > max_hp) hit_point=max_hp;
  }
  if(!attacker_ob && !random(8)) {
    ob=first_inventory(environment());
    while(ob) {
      if(ob->is_player() && ob->query_alignment() < -500) {
        tell_room(environment(),"Sir Reid says: I sense your evil heart, "+(string)ob->query_name()+".\n");
        attack_object(ob);
        return;
      } else
      ob=next_inventory(ob);
    }
  }
}
