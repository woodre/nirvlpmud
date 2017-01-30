/*
File: arien.c
Date: ??/??/97 (One of my earlier mobs)
Revised: 10-22-01
Description:
  The Mistress of Ravens.  Has quite a few tricks up her sleaves.
*/

#define HEALTH 600
#define SPELL 320
#include "/players/feldegast/defines.h"

inherit "/obj/monster";

int sp, tox, heals;
int reserve_sp, shielded;

tr(str) {
  tell_room(environment(),str);
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Mistress of Ravens");
  set_alt_name("mistress");
  set_alias("arien");
  set_short("Mistress of Ravens");
  set_long(
    "The Mistress of Ravens is a sorceress of deceptive power, using her\n"+
    "wiles to get whatever she wishes and her magic to hold what she has.\n"+
    "Her angelic face is framed by silky black hair which cascades down\n"+
    "her back.  Her voloptuous curves are clad in a pair of black leather\n"+
    "pants and a vest which leaves her stomach bare.  Her vivid green\n"+
    "eyes exhibit a keen intellect and a passionate soul.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(21);
  set_wc(30);
  set_ac(16);
  set_hp(HEALTH);
  set_al(500);
  set_aggressive(0); 
  sp=SPELL;
  reserve_sp=1000;
  heals=10;
  move_object(clone_object(ARM_PATH+"midnight.c"), this_object());
  init_command("wear cloak", this_object());
}

cast_heal() {
  int amt;
  amt = random(50);
  hit_point += amt;
  hp_bonus += amt;
  sp -= amt;
  tr(
    name+" closes "+query_possessive()+" eyes for a second and is\n"+
    "surrounded by a "+HIY+"healing glow"+".\n"
  );
}

regain_sps() {
  int amt;
  amt = random(100);
  sp += amt;
  reserve_sp -= amt;
  tr("\nThe Mistress of Ravens draws mystical energy from some other source.\n\n");
}

drink_heal() {
  tr(name+" takes a sip from a flask.\n");
  hit_point+=40;
  sp+=40;
  tox+=4;
  hp_bonus += 40;
  heals--;
}

cast_attack() {
  tr(
    "\n"+name+" strikes you with a bolt of cerulean...\n\n\n"+
    "\t\t\t"+HIB+"L I G H T N I N G"+NORM+"\n\n\n"
  ); 
  attacker_ob->hit_player(15+random(30));
  sp-=30;
}

cast_shield() {
  tr("\n"+name+" surrounds herself with a "+BLU+"glowing azure aura"+NORM+",\n"+
     "shielding her from her attackers.\n\n");
  shielded=1;
  sp-=40;
  call_out("remove_shield",5+random(20));
}

remove_shield() {
  tr("\n"+name+"'s glowing azure aura fades.\n\n");
  shielded=0;
}

heart_beat() {
  ::heart_beat();

  if(attacker_ob)
  {
    if(attacker_ob==this_object()) attacker_ob=0;
    if(attacker_ob->query_real_name()=="feldegast")
      tr("*"+name+"*"+" HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Tox: "+tox+"\n");
  }

  if(hit_point > 0) {
    hit_point+=3;
    sp+=3;
    tox-=1;

    if(hit_point > HEALTH) hit_point = HEALTH;
    if(sp        > SPELL)  sp        = SPELL;
    if(tox < 0) tox=0;

    /* Decision tree. */
    if(hit_point < 100 && sp > 100) 
      cast_heal();
    else if(hit_point < 150 && heals > 0 && tox < 15)
      drink_heal();
    else if(sp < 100 && reserve_sp > 100)
      regain_sps();
    else if(attacker_ob && shielded == 0 && sp > 40 && !random(3))
      cast_shield();
    else if(hit_point < 100 && sp > 50)
      cast_heal();
    else if(attacker_ob && sp > 100)
      cast_attack();

  }
}

hit_player(arg) {
  if(shielded) return 0;
  else return ::hit_player(arg);
}

heal_self(arg) {
  if(arg<0 && shielded) return 0;
  else return ::heal_self(arg);
}

do_damage(arg, arg2) {
  if(shielded) return 0;
  else return ::do_damage(arg, arg2);
}
