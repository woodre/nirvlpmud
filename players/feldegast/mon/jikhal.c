#include "/players/beck/MortalKombat/MKQuestNPC.h"
/*
Jikhal Bloodsbane
A fairly intelligent monster with multiple attacks, defenses,
and healing capabilities.  These capabilities are managed in
the hb.
Change log:
  1/18/01 Darned insomnia...Added code so Jikhal remembers people.
  8/22/01 Added additional checking after complaints about hb loss.
*/
#define tr(x) if(environment()) tell_room(environment(),x);
#define MAX_SP 300
#define SAVE_FILE "players/feldegast/mon/jikhal"
#include "defs.h"

inherit MONSTER;

object shield;
int sp;
int heals;
int tox;
int full;
int last_hp;
int energy;
int shield_energy;
int daggers;

string *enemies; /* People who attack Jikhal are remembered and attacked. */

void save_me() {
  save_object(SAVE_FILE);
}

void restore_me() {
  restore_object(SAVE_FILE);
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  shield=clone_object(ARM_PATH+"shield.c");
  move_object(shield,this_object());
  move_object(clone_object(ARM_PATH+"redcloak.c"),this_object());
  move_object(clone_object(ARM_PATH+"wyvern_armor.c"),this_object());
  move_object(clone_object(WEP_PATH+"soulthief.c"),this_object());
  move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());

  init_command("wear shield");
  init_command("wear armor");
  init_command("wield soulthief");

  enemies=({ });
  restore_me();
  set_name("jikhal");
  set_alt_name("jikhal bloodsbane");
  set_alias("bloodsbane");
  set_short("Jikhal Bloodsbane");
  set_long(
    "Jikhal stands approximately 1.8 meters tall and every inch of\n"+
    "him appears to have some purpose in the dispensation of death.\n"+
    "Jikhal is a coldblooded killer and mercenary who lives only for\n"+
    "the thrill of battle.  He is a master of bladed weapons and he\n"+
    "fights in the two-bladed style with a shield strapped to his arm.\n"+
    "He is the captain of the mercenary company called the Bloody Eagles.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(21);
  set_hp(600);
  set_wc(34);
  set_wc_bonus(17);
  set_ac(19);
  set_al(-350);
  set_chat_chance(5);
  set_a_chat_chance(5);
  load_a_chat("Jikhal grins evilly at you as he slashes with his flashing sword.\n");
  heals=15;
  sp=MAX_SP;
  full=1;
  daggers=5;
  energy=150;
  shield_energy=150;
  set_dead_ob(this_object());
}

drink_heal() {
  tr("Jikhal reaches down and takes a swig from a flask attached to his belt.\n");
  hit_point+=50;
  sp+=50;
  tox+=4;
  heals--;
  hp_bonus+=40;
}

cast_attack() {
  if(!attacker_ob || !present(attacker_ob, environment())) return;
  tr("Jikhal levels his blade at his opponent and utters a few key phrases...\n\n"+
    "\t\tA "+HIR+"gout of flame"+NORM+" engulfs "+attacker_ob->query_name()+".\n\n"); 
  attacker_ob->hit_player(19+random(30));
  sp-=30;
}

throw_dagger() {
  if(!attacker_ob || !present(attacker_ob, environment())) return;
  tr("\nJikhal smoothly draws a throwing knife and tosses it at his opponent\n"+
     "with breathtaking accuracy.\n\n");
  attacker_ob->hit_player(25+random(30));
  daggers--;
  sp-=10;
}

side_arm() {
  string side_msg;
  int side_dam;
  if(energy > 0 && attacker_ob && present(attacker_ob, environment())) {
    switch(random(9)) {
      case 0: side_dam=random(10);
              side_msg=TON+" slashes at you with his dagger.\n";
              break;
      case 1: side_dam=random(12);
              side_msg=TON+" nicks you with his dagger.\n";
              break;
      case 2: 
      case 3: side_dam=random(15);
              side_msg=TON+" gives you a flesh wound with his dagger.\n";
              break;
      case 4: 
      case 5: side_dam=random(22);
              side_msg=TON+" stabs you with his dagger.\n";
              break;
      case 6: side_dam=random(30);
              side_msg=TON+" gives you a nasty gash with his dagger.\n";
              break;
      case 7: side_dam=random(35);
              side_msg=TON+" plunges his dagger into your flesh.\n";
              break;
      default: side_dam=0;
               side_msg=TON+" misses you with his dagger.\n";
    }
    energy-=side_dam;
    attacker_ob->hit_player(side_dam);
    tell_object(attacker_ob,side_msg);
  }
}

shield() {
  int absorb;
  if(!shield) return;
  absorb=last_hp-hit_point;
  absorb=absorb/4;
  if(absorb > 0)
  {
    hit_point+=absorb;
    say(TON+" blocks some of your attack with his shield.\n");
    shield_energy-=absorb;
    if(shield_energy <= 0) {
      tr("Jikhal's shield shatters under your blow!\n");
      command("remove shield", this_object());
      destruct(shield);
    }
  }
}

full_heal() {
  tr("Jikhal takes out an aged scroll and mutters a few key phrases...\n"+
     "He is surrounded in a "+HIY+"golden aura"+NORM+" of healing.\n"
  );
  hp_bonus+=max_hp-hit_point;
  hit_point=max_hp;
  sp=MAX_SP;
  full--;
}

heart_beat() {
  if(attacker_ob && attacker_ob->query_real_name()=="feldegast")
    say("*Jikhal* HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Full: "+full+"\n"+
        " Daggers: "+daggers+" Shield: "+shield_energy+" Sidearm: "+energy+"\n");
  ::heart_beat();
  if(attacker_ob == this_object()) {
    tr("Jikhal shakes himself.\n"+
       "\"Your mind tricks won't work on ME.\"\n");
    attacker_ob=0;
  }
  if(hit_point < 50 && full)
    full_heal();
  if(hit_point > 0 && attacker_ob) {
    hit_point+=3;
    sp+=3;
    tox-=1;
    if(hit_point < 150 && heals > 0 && tox < 15)
      drink_heal();
    else if(attacker_ob && sp>40)
      cast_attack();
    else if(attacker_ob && sp>10 && daggers)
      throw_dagger();
    else if(heals && tox > 15 && sp > 50)
      cast_detox();

    if(hit_point < 70 && !random(5))
      random_move();

    if(attacker_ob) {
      side_arm();
      shield();
    }
    if(hit_point > max_hp) hit_point=max_hp;
    if(sp > MAX_SP) sp=MAX_SP;
    if(tox < 0) tox=0;
    last_hp=hit_point;
  }
}

query_attrib(str) {
  return 30;
}


monster_died() {
  if(this_player())
    write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPN+" killed Jikhal\n");
}

void long(string str) {
  int i;
  ::long(str);
  write(CYN);
  for(i=0; i < heals; i++)
    write("*");
  if(full) write(HIY+"*"+NORM);
  write("\n");
}

void add_enemy(string str) {
  if(member_array(str,enemies)==-1) {
    tell_room(environment(),
      "Jikhal says: '"+capitalize(str)+"', eh?  I'm gonna remember that name.\n");
    enemies+=({ str });
    save_me();
  }
}

hit_player(x) {
  if(this_player() && this_player()->is_player() && !random(10))
    add_enemy(this_player()->query_real_name());
  return ::hit_player(x);
}

void init() {
  ::init();
  if(this_player() && this_player()->is_player() && !attacker_ob &&
     member_array(this_player()->query_real_name(),enemies)!=-1) {
    tell_room(environment(),"Jikhal looks at "+TPN+".\n"+
                            "Jikhal says: "+BOLD+"I remember "+HIR+"YOU"+NORM+".\n"+
                            "Jikhal grins evilly as he draws his sword and attacks!\n");
    kill_ob=this_player(); /* Delay the attack a little while they read. */
  }
}
