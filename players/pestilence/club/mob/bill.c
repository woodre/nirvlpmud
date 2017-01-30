#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bill"); 
  set_alias("bartender");
  set_short("Bill the bartender");
  set_long("Bill the bartender is an average male.  He has normal features, and\n"+
           "he fades into the background, rarely sticking out.  He is one person\n"+
           "you WOULD NOT want to attack.\n");
  set_race("human");
  set_gender("male");
  set_level(25);
  set_wc(50);
  set_ac(30);
  set_hp(500);
/*
  set_wc_bonus(50);
[What the fuck? (Jaraxle, 11/12/02)]
*/
  set_heal( 30, 3);
  add_money(0);
  set_aggressive(0);
  set_al(200);
  load_chat("Bill says: would you like something to drink?\n");
  set_chat_chance(20);
  load_a_chat("Bill says: Wow, you are dumber than you look.\n");
  load_a_chat("Bill beats you into a "+RED+"bloody pulp"+NORM+".\n");
  set_a_chat_chance(30);
  set_spell_mess2("Bill slashes you with a broken bottle drawing "+RED+"blood"+NORM+".\n");
  set_spell_mess1("Bill slashes his attacker with a broken bottle drawing "+RED+"blood"+NORM+".\n");
  set_chance(30);
  set_spell_dam(30);
}

heart_beat(){
int a,i;
::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){
i = 1;
for(a=0;a<i;a++){
    already_fight = 0;
    this_object()->attack(attacker_ob);
}
}
}
