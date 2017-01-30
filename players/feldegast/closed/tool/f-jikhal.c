#define LOGPATH "/players/feldegast/log/"
#include "/players/feldegast/defines.h"

inherit "/players/feldegast/std/play-mon.c";

object sword;

int sp;
int heals;
int tox;
int full;
int last_hp;
int energy;
int shield_energy;
int daggers;

/* Familiar vars */
  string log_file;
  string invited;
  object owner;
  object follow;
  int snooping;
  int invis;
  int muffled;

tr(string str) {
  tell_room(environment(),str);
}

reset(arg) {
  object shield;
  object armor;
  ::reset(arg);

  if(!present("shield")) {
    shield=clone_object("/players/feldegast/arena/equip/shield");
    move_object(shield,this_object());
/*    command("wear shield",this_object()); */
  }
  if(!present("armor")) {
    armor=clone_object("/players/feldegast/arena/equip/wyvern_armor");
    move_object(armor,this_object());
/*    command("wear armor",this_object()); */
  }
  if(!present("soulthief")) {
    sword=clone_object("/players/feldegast/arena/equip/soulthief");
    move_object(sword,this_object());
/*    command("wield soulthief",this_object()); */
  }

  if(arg) return;
  set_name("jikhal");
  set_alt_name("jikhal bloodsbane");
  set_alias("bloodsbane");
  set_short("Jikhal Bloodsbane");
  set_long(
"Jikhal stands approximately 1.8 meters tall and every inch of\n"+
"him appears to have some purpose in the dispensation of death.\n"+
"Jikhal is a coldblooded killer and mercenary who lives only for\n"+
"the thrill of battle.  He is a master of bladed weapons and he\n"+
"fights in the two-bladed style with a shield strapped to his arm.\n"
);
  set_gender("male");
  set_race("human");
  set_level(15);
  set_hp(258);
  set_al(-350);
  enable_commands();
  set_chat_chance(5);
  load_chat("Jikhal grumbles about stupid flaps trying to take his title.\n");
  load_chat("Jikhal yells: Bring 'em on!\n");
  set_a_chat_chance(5);
  load_a_chat("Jikhal grins evilly at you as he slashes with flashing swords.\n");
  heals=15;
  sp=290;
  full=1;
  daggers=5;
  energy=150;
  shield_energy=150;
  set_ac(9);
  set_wc(19);
  set_dead_ob(this_object());
/*  call_out("decision_maker",3); */
  snooping=0;
}
drink_heal() {
  tr("Jikhal reaches down and takes a swig from a flask attached to his belt.\n");
  hit_point+=40;
  sp+=40;
  tox+=4;
  heals--;
}
cast_attack() {
  tr(
"Jikhal levels his blade at his opponent and utters a few key phrases...\n\n"+
"\t\tA "+HIR+"gout of flame"+NORM+" engulfs his foe.\n"
  ); 
  attacker_ob->hit_player(16+random(25));
  sp-=30;
}
throw_dagger() {
  tr(
"Jikhal smoothly draws a throwing knife and tosses it at his opponent\n"+
"with breathtaking accuracy.\n");
  attacker_ob->hit_player(5+random(10));
  daggers--;
  sp-=10;
}
side_arm() {
  string side_msg;
  int side_dam;
  if(energy>0) {
    switch(random(9)) {
      case 0: side_dam=random(10);
              side_msg=TON+" slashes at you with his dagger.\n";
              break;
      case 1: side_dam=random(12);
              side_msg=TON+" nicks you with his dagger.\n";
              break;
      case 2: side_dam=random(15);
      case 3: side_dam=random(15);
              side_msg=TON+" gives you a flesh wound with his dagger.\n";
              break;
      case 4: side_dam=random(18);
      case 5: side_dam=random(18);
              side_msg=TON+" stabs you with his dagger.\n";
              break;
      case 6: side_dam=random(20);
              side_msg=TON+" gives you a nasty gash with his dagger.\n";
              break;
      case 7: side_dam=random(25);
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
  absorb=last_hp-hit_point;
  absorb=absorb/4;
  if(absorb>0) {
    hit_point+=absorb;
    say(TON+" blocks some of your attack with his shield.\n");
    shield_energy-=absorb;
  }
}
full_heal() {
  tr("Jikhal takes out an aged scroll and mutters a few key phrases...\n"+
     "He is surrounded in a "+HIY+"golden aura"+NORM+" of healing.\n"
  );
  hit_point=258;
  sp=258;
  full--;
}

heart_beat() {
  if(attacker_ob && attacker_ob->query_real_name()=="feldegast")
  say("*Jikhal* HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Full: "+full+"\n"+
    " Daggers: "+daggers+" Shield: "+shield_energy+" Sidearm: "+energy+"\n");
  ::heart_beat();
  if(hit_point<50 && full)
    full_heal();
  if (hit_point>0) {
    hit_point+=3;
    sp+=3;
    tox-=1;
    if(hit_point<150 && heals>0 && tox<15)
      drink_heal();
    else
    if(attacker_ob && sp>40)
      cast_attack();
    else
    if(attacker_ob && sp>10 && daggers)
      throw_dagger();
    else
    if(heals && tox>15 && sp >50)
      cast_detox();

    if(hit_point < 70)
      random_move();

    if(attacker_ob) {
      side_arm();
      shield();
    }
    if(hit_point>258) hit_point=258;
    if(sp>258) sp=258;
    if(tox<0) tox=0;
    last_hp=hit_point;
  }
}
decision_maker() {
  if(!attacker_ob) {
    if(!random(7)) random_move();
    if(hit_point < 150 && heals && tox < 15)
      drink_heal();
    if(hit_point < 100) aggressive=0;
    else aggressive=1;
  }
  if(hit_point > 150) {
    if(!random(50))
      command("arena Bring 'em on!",this_object());
    if(!random(50))
      command("arena :grumbles about a bunch of flaps trying to take his title.",this_object());
  }
  if(environment()->short()==GRN+"Forest"+NORM)
    command("set trap",this_object());
  call_out("decision_maker",3);
}
monster_died(ob) {
  tell_room(environment(this_object()),
  "With his dying breath, Jikhal breaks his sword across his knee rather than\n"+
  "allow it to fall into another's hands.\n");
  destruct(sword);
}
query_attrib(str) {
  return 30;
}

catch_tell(str) {
  out_put("~"+str);
}
set_owner(ob) {
  owner=ob;
}

set_snooping() {
  snooping=!snooping;
  write("Squawk "+(snooping?"on":"off")+"\n");
}
go_invis() {
  invis=!invis;
}

short() {
  if(invis) return 0;
  else return short_desc;
}
query_invis() {
  return invis;
}
init() {
  add_action("snoop");add_xverb("");
}
snoop(str) {
  if(snooping) {
    out_put("~"+TPN+"~"+str+"\n");
  }
}
set_follow(ob) {
  if(!ob) follow=0;
  follow=ob;
  call_out("follow",3);
}
follow() {
  if(!follow) return;
  if(follow && !present(follow,environment())) {
    move_object(this_object(),environment(follow));
    out_put("~"+environment()->short()+"\n");
  }
  call_out("follow",3);
}

set_muffle(int x) {
  muffled=!muffled;
  write("You "+(muffled?"ignore":"listen to")+" the gamemaster.\n");
}
set_file(str) {
  if(!str) log_file=0;
  else log_file=str;
}
out_put(str) {
  if(!owner) destruct(this_object());
  if(log_file) {
    write_file(LOGPATH+log_file,str);
  }
  if(!muffled) {
    tell_object(owner,str);
  }
}
query_pl_k() { return 3; }
