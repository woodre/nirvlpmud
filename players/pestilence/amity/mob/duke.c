#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
int i;
 
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
  set_wc(40);
/*
  set_wc_bonus(25);
*/
  set_ac(20);
  set_heal(3,3);
  set_hp(1000);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(500);
  load_chat("Mr. Duke says: if you find any ants, kill them and bring me the parts.\n");
  set_chat_chance(20);
  load_a_chat("Mr. Duke says: what have i done to deserve this?\n");
  load_a_chat("Mr. Duke says: please don't hit me.\n");
  set_a_chat_chance(15);
}

flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("Mr. Duke punches "+ATT_NAME+" in the mouth, causing all "+ATT_NAME+"'s teeth to be loose.\n");
attacker_ob->hit_player(40+random(80), "other|good");



}



heart_beat(){
 ::heart_beat();

if(attacker_ob){
i = random(20);
switch(i){


    case 0..5: flesh_tear();
  break;

    case 6..20: return 0;
  break;

    }
  }
}
