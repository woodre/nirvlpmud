/*
wc increase:      28-52    35
dmn_code          1:6 35   6
bug_trs (poison): 1:12     15

ac increase:      16-28    16

hp increase:  900 hps
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
  set_wc(30);
/*  set_wc_bonus(56); */
  set_ac(14);
/*  set_ac_bonus(16);  */
  set_level(22);
  set_hp(1000);
  set_hp_bonus(1200);
  set_aggressive(1);
  set_heal(2,1);
  set_al(-1000);
  set_dead_ob(TO);
  set_chance(15);
  set_spell_dam(60);
  set_spell_mess1("A swarm of bugs flies around the room!\n");
  set_spell_mess2("A swarm of bugs bites your skin!\n");
   }
}

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
    set_heal(3,1);
  else if(lives == 1)
    set_heal(4,1);
  tell_room(environment(), 
    BOLD+BLK+"\nThe bug storm rebuilds itself!\n\n"+NORM);
  hit_point += 275+random(25);
  weapon_class += 7+random(7);
  armor_class += 4+random(4);
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
  return 1; 
}

heart_beat(){
  ::heart_beat();
  if(!environment())
    return ;
  if(!attacker_ob)
    return ;
  if(lives && hit_point <= 400)
    life_check();
  if(!random(6)){  damn_code(); return; }
  if(!random(5)){  aid();       return; }
}
