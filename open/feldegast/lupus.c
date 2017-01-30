#include "/players/feldegast/defines.h"
inherit "/obj/monster";

int sp;
int heals;
int tox;
int full;
tr(string str) {
  tell_room(environment(),str);
}
reset(arg) {
  object wep,armor;
  ::reset(arg);
  if(arg) return;
  set_name("Lupus Mortiferus");
  set_alt_name("lupus");
  set_alias("mortiferus");
  set_short(YEL+"Lupus Mortiferus"+NORM);
  set_long(
"Lupus Mortiferus towers above all but the tallest of men,\n"+
"standing at around 6'10\" and every inch of it wiry muscle.\n"+
"His quick reflexes and feral grin have earned him the\n"+
"nickname 'Wolf of Death' in the arena.\n"
);
  set_gender("male");
  set_race("human");
  set_level(19);
  set_hp(290);
  set_al(-50);
  set_heal(1,1);
  set_aggressive(0); 
  set_chat_chance(5);
  load_chat("Lupus practices an elaborate feinting maneuver with his gladius.\n");
  set_a_chat_chance(5);
  load_a_chat("Lupus grins evilly at you.\n");
  load_a_chat("Lupus slashes at your head and grins as you duck.\n");
  load_a_chat("Lupus says:  Thanks.  I needed the practice.\n");
  heals=15;
  sp=290;
  full=1;
  if(!present("armor")) {
    armor=clone_object("/players/feldegast/arena/equip/bronze_armor");
    move_object(armor,this_object());
    command("wear armor",this_object());
    wep=clone_object("/players/feldegast/arena/equip/gladius");
    move_object(wep,this_object());
    command("wield gladius",this_object());
  }
  set_ac(9);
  set_wc(19);
  call_out("decision_maker",1);
}
init() {
  if(!attacker_ob && !(this_player()->query_attack())) {
    tell_object(this_player(),
BOLD+"Seeing you unoccupied, Lupus Mortiferus decides\n\
to make you his prey!\n"+NORM);  
    attack_object(this_player());
  }
}
    
cast_heal() {
  hit_point+=random(50);
  sp-=50;
  tr("Lupus utters a prayer to the god of gladiators.\n"+
    "Suddenly, his wounds begin to heal.\n");
}
drink_heal() {
  tr("Lupus reaches down and takes a swig from a flask attached to his belt.\n");
  hit_point+=40;
  sp+=40;
  tox+=4;
  heals--;
}
cast_attack() {
  tell_object(attacker_ob,"Lupus hums a high pitched note as he points his blade at you.\n\n"+
  "Suddenly, a "+HIY+"wave of sound"+NORM+" washes over you, bursting your ears.\n\n"
  ); 
  attacker_ob->hit_player(random(50));
  sp-=25;
}
cast_detox() {
  tr("Lupus concentrates briefly.\n"+
     "A faint mist rises from him, then fades away.\n");
  sp-=50;
  tox-=12;
}
full_heal() {
  tr("Lupus takes a golden coin out of his pocket and mutters a few words.\n"+
     "He is surrounded in a "+HIY+"golden aura"+NORM+" of healing.\n"
  );
  hit_point=290;
  sp=290;
  full--;
}

heart_beat() {
  ::heart_beat();
  if(attacker_ob->query_real_name()=="feldegast")
  tr("*Lupus* HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Tox: "+tox+"\n");
  if (hit_point>0) {
    sp+=3;
    tox-=1;
    if(hit_point<50 && full)
      full_heal();
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
    if(attacker_ob && sp>100)
      cast_attack();
    else
    if(heals && tox>15 && sp >50)
      cast_detox();
    if(hit_point>290) hit_point=290;
    if(sp>290) sp=290;
    if(tox<0) tox=0;
  }
}

decision_maker() {
  int zit;
  if(!attacker_ob) {
    if(!random(7)) random_move();
    if(hit_point < 150 && heals && tox < 15)
      drink_heal();
    if(hit_point < 100) aggressive=0;
    else aggressive=1;
  }


  zit=random(60);
  if(attacker_ob && hit_point > 100 &&
     !present(attacker_ob,environment(this_object())) && 
     environment(attacker_ob)->query_grand_arena() &&
     (zit > attacker_ob->query_attrib("ste")) ) {

    say(name+" runs off in pursuit of his prey.\n");
    move_object(this_object(),environment(attacker_ob));
    say(name+" arrives to dispense death!\n");
    attack_object(attacker_ob);
  }
  else {
    attacker_ob=0;
    alt_attacker_ob=0;
  }

    
/* Bragging */
  if(hit_point > 150) {
    if(!random(50))
      command("arena I can see the fear in your eyes.",this_object());
    if(!random(50))
      command("arena I can smell your terror on the wind.",this_object());
    if(!random(80))
      command("arena Fools!  You cannot beat the Death Wolf!",this_object());
  }
  call_out("decision_maker",3);
}
monster_died(ob) {
  command("arena "+TPN+", I shall see you in the next life!\n",this_object());
}
query_attrib(str) {
  return 30;
}

