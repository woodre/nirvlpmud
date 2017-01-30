/*
wc increase:      28-52    35
dmn_code          1:6 35   6
bug_trs (poison): 1:12     15

ac increase:      16-28    16

hp increase:  900 hps
*/
/*
// 2005.08.20 -Forbin
// Changes:
//  AC 14 -> 20
//  WC 30 -> 42
//  HP 1000 -> 1500
//  set_heal 2,1 -> 4,1
//  increased set_heals from 3,1 and 4,1 in life_check to
//    5,1 and 8,1 respectively
//  life_check amount changed from < 400 to < 600 in hb
// 2013.08.09 - Dragnar
//   Moved the set_level to BEFORE the set_wc set_ac
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int lives;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  lives = 4;
  set_name("bug storm");
  set_alias("storm");
  set_short("The bug storm");
  set_race("creature");
  set_gender("creature");
  set_long(
"What lies before you is a large mass of bugs.  Each of the bugs looks\n"+
"exactly the same, and most all of them are clinging to one another to\n"+
"form a gigantic mass of bugs.  Those that aren't attached are flying\n"+
"around it, making it look like a sort of storm.  The bugs are acting\n"+
"together, as one powerful creature.\n");
  set_level(22);
  set_wc(60);
  set_wc_bonus(10);
  set_ac(80);
/*  set_ac_bonus(16);  */
  set_hp(2200);
  set_hp_bonus(1300);
  set_aggressive(1);
  set_heal(4,1);
  set_al(-1000);
  set_dead_ob(TO);
  add_spell("ettin_spell",
    "A swarm of bugs flies around the room.\n"+
    "The bugs bite into your skin!\n",
    "A swarm of bugs flies around the room.\n"+
    "The bugs bite into #CTN#'s skin!\n",
    20, "50-70", "physical");   
   }
}

query_z_museum_mob() { return 1; }

damn_code(){
  int x;
  if(!AO) return;
  if(!present(AO, environment())) return;
  x = random(3);
  switch(x){
  case 0:
    tell_object(AO,"Bugs swarm all over your body!\n");
    break;
  case 1:
    tell_object(AO, "Tiny black bugs scamper across your flesh.\n");
    break;
  case 2:
    tell_object(AO, "You feel the tiny little bugs biting your flesh!\n");
    break;
  }
  AO->hit_player(35 + ((int)AO->query_extra_level() / 2));
}

life_check()
{
  if(!present(AO, environment())) return;
  lives--;
  if(lives == 2)
    set_heal(5,1);
  else if(lives == 1)
    set_heal(8,1);
  tell_room(environment(), 
    BOLD+BLK+"\nThe bug storm rebuilds itself!\n\n"+NORM);
  hit_point += 275+random(25);
  set_wc(query_wc()+7+random(7));
  set_ac(query_ac()+4+random(4));
}

aid()
{
  object bug;
  int a;
  if(!present(AO, environment())) return;
  for(a = 0; a < 1+random(2); a++)
  {
    bug = clone_object("/players/zeus/museum/NPC/bug.c");
    move_object(bug, environment(AO));
    bug->set_wc(30+random(30));
    bug->attack_object(AO);
  }
  if(!random(2))
  {
	  TR(environment(), "Bugs swarm around the room!\n");
  }
}


monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
	capitalize((string)TP->QRN)+" defeated The Bug Storm.\n");
 tell_room(environment(),
"As the storm is destroyed, a small ring is left in its place.\n");
  MO(CO("/players/zeus/museum/OBJ/bug_ring.c"), environment());
   "/players/zeus/museum/lounge.c"->npc7();
  if(corpse)
    destruct(corpse);
  emit_channel("junk","\n(junk) "+HIY+"["+HIW+"Museum Arena"+HIY+"]"+NORM+" "+
    capitalize((string)this_player()->query_real_name())+
    " has defeated The Bug Storm.\n\n"+NORM);     
  return 1; 
}

heart_beat(){
  ::heart_beat();
  if(!environment())
    return ;
  if(!attacker_ob)
    return ;
  if(attacker_ob == this_object())
  {
    stop_fight();
    stop_fight();
  }    
  if(lives && hit_point <= 600)
    life_check();
  if(!random(6)){  damn_code(); return; }
  if(!random(5)){  aid();       return; }
}
