#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define attacker attacker_ob
#define TP this_player()
#define TO this_object()
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/pestilence/Cahara/wep/bclub.c"),
        this_object());
  command("wield club");
  set_name("King Kidema"); 
  set_alias("kidema");
  set_short("King Kidema");
  set_long("King Kidema is the leader of the cannibal tribe on Cahara Island.  He is\n"+
                 "a very large man.  He stands close to 7 feet tall, and is very muscular.\n"+
                 "It looks like he is very hungry and you are going to be his next meal!\n");
  set_race("human");
  set_gender("male");
  set_level(30);
  set_wc(60);
  set_ac(70);
  set_hp(2000);
  set_ac_bonus(3);
  set_wc_bonus(12);
  set_hp_bonus(250);
  set_heal(20,3);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-400);
  load_chat("King Kidema says: leave my island now.\n");
  load_chat("King Kidema says: Your skin will look nice on my kitchen table.\n");
  set_chat_chance(3);
  load_a_chat("King Kidema bites you to the "+HIW+"bone"+NORM+".\n");
  load_a_chat("King Kidema lunges at you.\n");
  set_a_chat_chance(2);

add_spell("smash",
"King Kidema smashes you with his bone club, leaving"+RED+" blood "+NORM+"flowing from your wound.\n",
"King Kidema smashes his opponent with his bone club leaving"+RED+" blood "+NORM+"flowing from the wound.\n",
30,15,0,0);
  add_spell("magic missile",
  "#MN# tears into your flesh.\n",
  "#MN# tears into #TP# flesh.\n",
   40,90,"other|magic",2);
set_multi_cast(1);

}


/*
heart_beat(){
int z;
  ::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){

z = random(60);
if(z>50){
   tell_room(environment(TO), 
    "King Kidema "+RED+"devastates"+NORM+" his attacker with wreckless abandon.\n");
call_other(attacker_ob,"hit_player",random(30)+5);
return;
}
}
}
*/

monster_died() {
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
        this_object());
  tell_room(environment(this_object()),
        "King Kidema makes a loud thump as his body splits, when it hits the ground.\n");
return 0; }
