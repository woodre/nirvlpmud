#define SPELL 320
#include "/players/feldegast/defines.h"
inherit "/obj/monster";
int sp, tox, heals;
int staff_charges, shielded;
tr(str) {
  tell_room(environment(),str);
}
reset(arg) {
  object staff;
  ::reset(arg);
  if(arg) return;
  set_name("Bedira the Watcher");
  set_alt_name("bedira");
  set_alias("watcher");
  set_short("Bedira the Watcher");
  set_long(
"Bedira is a kindly old man with an absentminded look to him\n"+
"but a quick smile when he actually gives you the time of day.\n"+
"He has a full head of snowy white hair, a beakish nose, and\n"+
"startlingly blue eyes.  He wears a fur-lined cloak over his\n"+
"dark brown robes.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(17);
  set_wc(10);
  set_ac(5);
  set_hp(274);
  set_al(500);
  set_aggressive(0); 
  set_dead_ob(this_object());
  if(!present("staff")) {
    staff=clone_object("/players/feldegast/wep/bstaff");
    move_object(staff,this_object());
    init_command("wield staff");
  }
  sp=SPELL;
  heals=10;
  staff_charges=6;
}

cast_heal() {
  hit_point+=random(50);
  sp-=50;
  tr(
"Bedira closes his eyes for a second and is surrounded in a healing glow.\n"
  );
}
drink_heal() {
  tr("Bedira reaches into his robes and takes a sip from a flask.\n");
  hit_point+=40;
  sp+=40;
  tox+=4;
  heals--;
}
cast_attack() {
  tr(
"\nBedira makes a series of smooth, complicated gestures with his hands.\n\n"+
"              A "+HIR+"wind of flame"+NORM+" sweeps across "+attacker_ob->query_name()+"!\n\n"
  ); 
  attacker_ob->hit_player(random(30)+15);
  sp-=30;
}
staff_attack() {
  tr(
"\nBedira points his ebony black staff at "+attacker_ob->query_name()+".\n\n"+
"A searing white flame shoots forth from Bedira's staff and strikes "+
  attacker_ob->query_objective()+".\n"
  );
  staff_charges--;
  attacker_ob->heal_self(-(random(30)+10));
}
cast_shield() {
  tr("\nBedira surrounds himself with a glowing azure aura, shielding him from harm.\n\n");
  shielded=1;
  sp-=40;
  call_out("remove_shield",5+random(20));
}
remove_shield() {
  tr("\nBedira's glowing azure aura fades.\n");
  shielded=0;
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob==this_object()) attacker_ob=0;
  if(attacker_ob && attacker_ob->query_real_name()=="feldegast")
  tr("*Bedira* HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Tox: "+tox+"\n");
  if(hit_point>0) {
    hit_point+=3;
    sp+=3;
    tox-=1;
    if(hit_point<100 && sp>100) 
      cast_heal();
    else
    if(hit_point<150 && heals>0 && tox<15)
      drink_heal();
    else
    if(attacker_ob && shielded==0 && sp>40)
      cast_shield();
    else
    if(hit_point<100 && sp>50)
      cast_heal();
    else
    if(attacker_ob && sp>100)
      cast_attack();
    else
    if(attacker_ob && staff_charges)
      staff_attack();

    if(hit_point>274) hit_point=274;
    if(sp>SPELL) sp=SPELL;
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
