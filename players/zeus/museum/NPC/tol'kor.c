/*  Special attack will move player to an adjacent room  */
/*  (?)  Only works in rooms that inherit /obj/room  (?) */
/*
push  1:8  wc 15
atk   1:8  wc 5
*/
/*
// 2005.08.20 -Forbin
// Changes:
//  AC 25 -> 28
//  WC 60 -> 80
//  HP 830 + r100 -> 1230 + r250
//  set_heal 1,1 -> 2,1
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#define OPPN TO->query_attack()->query_name()

object battle_axe;
int random_direction, i;
string who, where;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("tol'kor");
  set_short("Tol'kor the Warrior");
  set_alias("warrior");
  set_race("ogre");
  set_gender("male");
  set_long(
"Tol'kor is a mighty ogre warrior.  His bulging body is partially covered\n"+
"by a worn leather tunic and leather shorts.  He is also wearing a pair of\n"+
"large leather boots.  He is holding in both hands an immense battle axe.\n");
  set_level(21);
  set_ac(33);
  set_wc(104);
  set_wc_bonus(20);
  set_hp(1600+random(250));
  set_al(-90);
  set_heal(2,1);
  set_aggressive(1);   
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("Tol'kor says: Prepare to die.\n");
  load_chat("Tol'kor grins at you.\n");
  load_chat("Tol'kor looks you up and down.\n");
  load_chat("Tol'kor watches you closely.\n");
  load_chat("Tol'kor says: You should never have challenged me.\n");
  load_a_chat("Tol'kor dodges to the side.\n");
  set_dead_ob(TO);
   }
}

query_z_museum_mob() { return 1; }

crunch_special(){
  if(!present(AO, environment(TO))) return 0;
  TO->attack_object(AO);
  TR(environment(TO),
    "Tol'kor swings his battle axe over his head and down...\n"+
    "It bites into "+AO->QN+"'s chest with a horrible...\n"+
    "\n\n\t"+RED+" <  < <   C R U N C H   > >  >"+NORM+"\n\n\n"+
    AO->QN+" staggers backwards, blood pouring onto the ground....\n",
    ({ AO }));
  tell_object(AO,
    "Tol'kor swings his battle axe over his head and down...\n"+
    "It bites into your chest with a horrible...\n"+
    "\n\n\t"+RED+" <  < <   C R U N C H   > >  >"+NORM+"\n\n\n"+
    "You stagger backwards, blood pouring onto the ground....\n");
  AO->hit_player(70+random(45));
  return 1;
}



void catch_tell(string str) {
  if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
    call_out("movement", 2);
}

movement(){   call_other(TO, "init_command", where); }

push_special(){           /*  move player to an adjacent room  */
   string *the_dirs;
   string str;
   int i;
   i = 1;
   if(!present(AO, environment())) return 0;

   TR(environment(),
     "Tol'kor charges at "+OPPN+", knocking "+AO->OBJ+" back...\n", ({AO}));
   tell_object(AO, "Tol'kor charges at you, knocking you back...\n");
   AO->hit_player(10);
   the_dirs = (environment()->query_dest_dir());
   random_direction = random(sizeof(the_dirs)-1);
   i = random_direction / 2 * 2;
   str = the_dirs[i+1];
   str += "#";
   str += the_dirs[i];
   AO->MP(str);
   command("look",AO);
   call_out("crunch_special", 4);
}

attack_special(){
  int random_attack;
  if(!present(AO, environment())) return 0;
  random_attack = random(5);
  switch(random_attack)
  {
  case 0:
    TR(environment(),
      "Tol'kor swings his battle axe through the air...\n");
    break;
  case 1:
    tell_object(AO,  "Tol'kor hits you with a crushing blow!\n");
    TR(environment(),
      "Tol'kor hits "+AO->QN+" with a crushing blow!\n", ({AO}));
    AO->hit_player(15+random(20));
    break;
  case 2:
    tell_object(AO, 
      "Tol'kor dodges to the side and lunges at you!\n");
    TR(environment(),
      "Tol'kor doges to the side and lunges at "+AO->QN+"!\n", 
      ({AO}));
    AO->hit_player(10+random(20));
    break;
  case 3:
    TR(environment(),
      "Tol'kor pulls a small pouch from his waist...\n"+
      "Tol'kor throws a pinch of sand into the air...\n");
    hit_point += 20+random(20);
    break;
  case 4:
    tell_object(AO, "Tol'kor sweep kicks you off your feet!\n");
    TR(environment(),
      "Tol'kor sweep kicks "+AO->QN+" off "+AO->POS+" feet!\n", ({AO}));
    AO->hit_player(8+random(20));
    break;
  }
  return 1;
}


monster_died(){
  if(!environment()) return 0;
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
    capitalize((string)TP->QRN)+" defeated Tol'kor.\n");
  TR(environment(),
    "As Tol'kor falls to the ground, his weapon falls from his hands...\n");
  MO(CO("/players/zeus/museum/OBJ/battle_axe.c"), environment());
    "/players/zeus/museum/lounge.c"->npc1();
  emit_channel("junk","\n(junk) "+HIY+"["+HIW+"Museum Arena"+HIY+"]"+NORM+" "+
    capitalize((string)this_player()->query_real_name())+
    " has defeated Tol'kor the Warrior.\n\n"+NORM);     
  return 1;
}

heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return ;
  if(attacker_ob == this_object())
  {
    stop_fight();
    stop_fight();
  }
  if(weapon_class < 49)
        set_wc(50);
  if(!random(8)){   push_special();   return; }
  if(!random(8)){   attack_special();		  }
}
