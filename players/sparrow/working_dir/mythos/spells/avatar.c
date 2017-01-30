#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("fear");
  set_alias("fear_avatar");
  set_race("avatar");
  set_short(BOLD+"The Avatar: FEAR"+NORM);
  set_long("A naked beautiful woman with great "+HIB+"RAVEN"+NORM+" wings\n"+
           "standing out from her back- a "+BOLD+"DARK ANGEL"+NORM+".\n");
  set_hp(250);
  set_level(30);
  set_al(-1000);
  set_wc(20);
  set_ac(2);
  set_exx(0);
  set_heal(3,9);
  set_can_kill(1);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_a_chat_chance(2);
  load_a_chat("FEAR smiles....you shiver....\n");   
  set_chance(50);
  set_spell_dam(50);
  set_spell_mess1(HIB+">>>>>>>>>>>>>>>>>>>>>>>>    **    FEAR\n"+NORM);
  set_spell_mess2(HIB+">>>>>>>>>>>>>>>>>>>>>>>>    **    FEAR\n"+NORM);
  
  set_mult(3);
  set_mult_chance(30);
  set_mult_dam1(5);
  set_mult_dam2(5);
}

catch_tell(str) {
int jj;
object ob;
ob = users();
for(jj = 0; jj<sizeof(ob); jj++) {
  if(present("spr_hear",ob[jj])) {
  tell_object(ob[jj],"AVATAR: "+str+"\n");
  }
}
return;
}

monster_died() {
int jj;
object ob;
ob = users();
for(jj = 0; jj<sizeof(ob); jj++) {
  if(present("spr_hear",ob[jj])) {
  ob[jj]->heal_self(-10000);
  tell_object(ob[jj],"You feel a deep pain as the avatar dies!\n");
  destruct(present("spr_hear",ob[jj]));
  if(present("spirit_con",ob[jj])) { destruct(present("spirit_con",ob[jj])); }
  } }
return 0;}

off() {
int jj;
object ob;
ob = users();
for(jj = 0; jj<sizeof(ob); jj++) {
  if(present("spr_hear",ob[jj])) {
  tell_object(ob[jj],"You feel a deep pain as the avatar dies!\n");
  destruct(present("spr_hear",ob[jj]));
  if(present("spirit_con",ob[jj])) { destruct(present("spirit_con",ob[jj])); }
  } } 
  destruct(this_object());
return 1;}

look() {
  environment(this_object())->long(); 
return 1;}
