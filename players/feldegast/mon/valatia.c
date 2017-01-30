/*
This monster borrows some from arien.c
*/

#include "defs.h"

#define SPELL 400

inherit "/obj/monster";

int sp, tox, heals;
int shielded;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Valatia");
  set_alias("valatia");
  set_alt_name("sorceress");
  set_short("Valatia the "+HIR+"Sorceress"+NORM);
  set_long(
    "Valatia is an accomplished sorceress and herbalist in the old\n"+
    "traditions of the elder magi.  She has the olive skin and violet\n"+
    "eyes of her majiri heritage.  She wears a crimson red dress and\n"+
    "ties back her dark black hair.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(21);
  set_wc(38);
  set_wc_bonus(12);
  set_ac(20);
  set_ac_bonus(10);
  set_hp(600);
  set_al(500);
  set_aggressive(0); 
  set_dead_ob(this_object());
  sp=SPELL;
  heals=10;
  add_money(5000+random(100));
  move_object(clone_object(OBJ_PATH+"crystal.c"),this_object());
}

cast_heal() {
  int h;
  h=25+random(25);
  hit_point+=h;
  hp_bonus+=h;
  sp-=50;
  say(name+" closes "+query_possessive()+" eyes for a second and is\n"+
      "surrounded by a "+HIY+"healing glow"+NORM+".\n"
  );
}

drink_heal() {
  say(name+" takes a sip from a flask at "+query_possessive()+" belt.\n");
  hit_point+=40;
  sp+=40;
  hp_bonus+=40;
  tox+=4;
  heals--;
}

cast_attack() {
  tell_object(attacker_ob,"\n"+name+" strikes you with a bolt of cerulean...\n\n\n"+
                          "\t\t\t"+HIB+"L I G H T N I N G"+NORM+"\n\n\n"); 
  tell_room(environment(),attacker_ob->query_name()+" is struck by a bolt of cerulean...\n\n\n"+
                          "\t\t\t"+HIB+"L I G H T N I N G"+NORM+"\n\n\n",({ attacker_ob })); 
  attacker_ob->hit_player(40+random(30));
  sp-=30;
}

cast_area_attack() {
  object ob,next;
  tell_room(environment(),"\n"+HIY+name+" throws back her head and lets loose an earsplitting shriek!\n\n"+NORM);
  ob=first_inventory(environment());
  while(ob) {
    next=next_inventory(ob);
    ob->hit_player(30+random(20));
    ob=next;
  }
  sp-=40;
}

cast_shield() {
  say("\n"+name+" surrounds herself with a "+HIB+"glowing azure aura"+NORM+",\n "+
      "shielding herself from her attackers.\n\n");
  shielded=1;
  sp-=40;
  call_out("remove_shield",5+random(20));
}

remove_shield() {
  say("\n"+name+"'s glowing aura fades.\n\n");
  shielded=0;
}

heart_beat() {
  ::heart_beat();
  if(!attacker_ob) return;
  if(attacker_ob==this_object()) attacker_ob=0;
  if(attacker_ob->query_real_name()=="feldegast")
    tell_object(attacker_ob,
      "*"+name+"*"+" HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Tox: "+tox+"\n");
  if(hit_point>0) {
    hit_point+=2;
    sp+=5;
    tox-=1;
    if(hit_point<200 && sp>100 && random(2)) 
      cast_heal();
    else
    if(hit_point<300 && heals>0 && tox<15 && random(2))
      drink_heal();
    else
    if(attacker_ob && shielded==0 && sp>40 && !random(5))
      cast_shield();
    else
    if(hit_point<160 && sp>50 && random(2))
      cast_heal();
    else
    if(attacker_ob && sp>100 && random(3))
      cast_attack();
    else
    if(attacker_ob && sp > 40)
      cast_area_attack();

    if(hit_point > max_hp) hit_point=max_hp;
    if(sp > SPELL) sp=SPELL;
    if(tox<0) tox=0;
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

monster_died(ob) {
 write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPRN+" killed Valtia\n");
}
