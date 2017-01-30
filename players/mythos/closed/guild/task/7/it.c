#include "/players/mythos/closed/guild/def.h"
inherit "obj/monster";
object ob;
int z, nj;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("kjhasd");
  set_short("A blob");
  set_alias("it");
  set_race("kjashdkha");
  set_long("A formless blob of darkness.\n");
  set_hp(1200);
  set_level(19);
  set_al(-1000);
  set_wc(30);
  set_ac(15);
  set_aggressive(0);
  set_heal(3,10);
  set_dead_ob(this_object());
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Anger fills you!\n");
  set_chance(15);
  set_spell_dam(18);
  set_spell_mess1("Mist gathers.\n");
  set_spell_mess2("\nSOMETHING stings you.\n");
  call_out("changer",3);
}

changer() {
string namer;
switch(random(20)) {
  case 0: namer = "prince"; break;
  case 1: namer = "frog"; break;
  case 2: namer = "ryo"; break;
  case 3: namer = "kuh"; break;
  case 4: namer = "765sa"; break;
  case 5: namer = "kjhs"; break;
  case 6: namer = "anger"; break;
  case 7: namer = "blah"; break;
  case 8: namer = "bee"; break;
  case 9: namer = "missionary"; break;
  case 10: namer = "sheep"; break;
  case 11: namer = "snake"; break;
  case 12: namer = "cow"; break;
  case 13: namer = "house"; break;
  case 14: namer = "gym"; break;
  case 15: namer = "grinch"; break;
  case 16: namer = "demon"; break;
  case 17:  
  case 18:
  case 19: namer = crypt("it",0); break;
}
  this_object()->set_short("A "+namer);
  this_object()->set_wc(10+random(50));
  this_object()->set_ac(random(30));
  if(!environment(this_object()))
 return 1;
  if(random(3) == 0) { 
  nj = 0;
  ob=all_inventory(environment(this_object()));
  for(z=0;z<sizeof(ob);z++) {
  if(living(ob[z])) {
    if(ob[z]->query_attack()) { 
    (ob[z]->query_attack())->stop_fight();
    ob[z]->stop_fight(); nj = 1;} }
  } 
  if(nj) tell_room(environment(this_object()),"Something stops all fighting!\n");
  }
call_out("changer",3);
return 1;}

monster_died() {
  if(present(fear,this_object()->query_attack()) &&
    (this_object()->query_attack())->query_level() > 14 &&
    (this_object()->query_attack())->query_guild_rank() == 6) {
      if(present(fear,this_object()->query_attack())->query_fae() > 9) {
      tell_object(this_object()->query_attack(),"The Demon Keeper swallows you!\n");
        (this_object()->query_attack())->move_player("darkness#players/mythos/closed/guild/task/7/trans.c");
        tell_room(environment(this_object()),
        "Suddenly the room darkens and "+(this_object()->query_attack())->short()+
        " is wisked away!\n");
        } }
return 0;
}
