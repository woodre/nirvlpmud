#include "/players/feldegast/defines.h"
inherit "/obj/monster";
object eagle,arrow;
int sp, tox, heals, arrows;
status bird;
tr(str) {
  tell_room(environment(),str);
}
reset(arg) {
  object bow,amulet;
  ::reset(arg);
  if(arg) return;
  if(!present("amulet of visions")) {
    amulet=clone_object("/players/feldegast/obj/vamulet");
    move_object(amulet,this_object());
    command("wear amulet",this_object());
  }
  if(!present("bow")) {
    bow=clone_object("/players/feldegast/wep/silvrbow");
    move_object(bow,this_object());
    command("wield bow",this_object());
  }
  set_name("Dana Silverhand");
  set_alt_name("dana");
  set_alias("elven archer");
  set_short("Dana Silverhand");
  set_long(
"Dana is a lovely blonde-haired elven maiden.  She wears\n"+
"leathers and a green cloak clasped with a silver brooch\n"+
"etched with a trifoil leaf.\n"
  );
  set_gender("female");
  set_race("elf");
  set_level(15);
  set_wc(18);
  set_ac(9);
  set_hp(258);
  set_al(250);
  set_aggressive(0); 
  set_dead_ob(this_object());
  sp=258;
  heals=10;
  bird=1;
  arrows=1;
}

cast_heal() {
  hit_point+=random(50);
  sp-=50;
  tr(
"Dana is bathed in "+HIW+"moonlight"+NORM+" as she utters a few healing words.\n"
  );
}
drink_heal() {
  tr("Dana reaches down and sips from a flask attached to her belt.\n");
  hit_point+=40;
  sp+=40;
  tox+=4;
  heals--;
}
moon_heal() {
  hit_point+=50;
  tr("Dana is bathed in a "+HIW+"moonlit"+NORM+" glow.\n");
}
moonbow_heal() {
  moon_heal();
  call_out("moon_heal",5);
  call_out("moon_heal",10);
  sp-=120;
}
cast_attack() {
  tr(
"\nDana's hands spark with "+HIB+"blue electricity"+NORM+" as she looses her arrow.\n\n"
  ); 
  attacker_ob->hit_player(random(40));
  sp-=20;
}
cast_fire() {
  tr(
"\nDana's eyes glow with an inner "+RED+"fire"+NORM+" as she looses her arrow.\n\n"+
"    The arrow bursts into flames in midflight as it flawlessly flies\n\n"+
"    into its target...\n\n"+
"                 ...and "+RED+"BURNS"+NORM+".\n"
  );
  arrow=clone_object("/players/feldegast/obj/fire_arrow");
  move_object(arrow,AT);
  sp-=30;
  arrows--;
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob && attacker_ob->query_real_name()=="feldegast")
  tr("*Dana* HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Tox: "+tox+"\n");
  if(hit_point>0) {
    hit_point+=3;
    sp+=3;
    tox-=1;
    if(bird) {
      eagle=clone_object("/players/feldegast/mon/eagle");
      move_object(eagle,environment());
      tell_room(environment(),
"A giant eagle swoops into the room.\n"
      );
      bird=0;
    }
    if(attacker_ob && eagle) {
      eagle->attacked_by(attacker_ob);
    }
/*
    if(eagle->query_attack() && !attacker_ob)
      attacker_ob=eagle->query_attack();
*/
    if(hit_point<120 && sp>120)
      moonbow_heal();
    else
    if(hit_point<100 && sp>100) 
      cast_heal();
    else
    if(hit_point<150 && heals>0 && tox<15)
      drink_heal();
    else
    if(hit_point<100 && sp>50)
      cast_heal();
    else
    if(attacker_ob && sp>50 && arrows)
      cast_fire();
    else
    if(attacker_ob && sp>100)
      cast_attack();

    if(hit_point>258) hit_point=258;
    if(sp>258) sp=258;
    if(tox<0) tox=0;
  }
}

