#define SPELL 350
#include "/players/feldegast/defines.h"
inherit "/obj/monster";
int sp, tox, heals;
int skeletons, shielded;
tr(str) {
  tell_room(environment(),str);
}
reset(arg) {
  object staff;
  ::reset(arg);
  if(arg) return;
  set_name("lich");
  set_alt_name("gardoron");
  set_alias("king");
  set_short("Gardoron the Lich King");
  set_long(
"Gardoron the Lich King's mummified form stands before you,\n"+
"swathed in rich purple robes, his glowing red eyes blazing\n"+
"with barely contained magical energies.  Gardoron was once\n"+
"a mighty wizard king whose holdings spread across a continent.\n"+
"His lust for power and his awesome mystic might allowed him\n"+
"to gain near immortality...But at a terrible price.\n"
  );
  set_gender("male");
  set_race("undead");
  set_level(20);
  set_wc(20);
  set_ac(12);
  set_hp(300);
  set_al(-1000);
  set_aggressive(0); 
  set_dead_ob(this_object());
  if(!present("scepter")) {
    staff=clone_object("/players/feldegast/wep/scepter");
    move_object(staff,this_object());
    init_command("wield scepter");
  }
  set_wc(20);
  sp=SPELL;
  heals=10;
  skeletons=3;
}

cast_heal() {
  hit_point+=random(50);
  sp-=50;
  tr(
short_desc+" radiates an aura of necromantic energy as he uses his\n"+
"\t\tunholy magic to heal his malignant form.\n"
  );
}
drink_heal() {
  tr(short_desc+" drink from an ornate decanter of some\n"+
    "vile and utterly black liquid.\n");
  hit_point+=40;
  sp+=40;
  tox+=4;
  heals--;
}
cast_attack() {
  tr(
"\n"+short_desc+" lightly brushes "+attacker_ob->query_name()+"'s flesh\n"+
"\tstealing a precious piece of life for his own.\n");
  attacker_ob->hit_player(random(30)+15);
  sp-=30;
}
raise_skeleton() {
  tr(
short_desc+" utters a guttural incantation and raises his scepter\n"+
"high above his head.\n"
  );
  call_out("raise_skeleton2",5);
  skeletons--;
  sp-=50;
}
raise_skeleton2() {
  object skeleton;
  tr("A skeleton warrior "+HIB+"rises from the ground"+NORM+" to do his master's bidding.\n");
  skeleton=clone_object("/players/feldegast/mon/skeleton");
  move_object(skeleton,environment());
  skeleton->attacked_by(attacker_ob);
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob==this_object()) attacker_ob=0;
  if(attacker_ob->query_real_name()=="feldegast")
  tr("*Lich King* HP: "+hit_point+" SP: "+sp+" Heals: "+heals+" Tox: "+tox+
  "\nSkeletons: "+skeletons+"\n");
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
    if(hit_point<100 && sp>50)
      cast_heal();
    else
    if(attacker_ob && sp>50 && skeletons && !random(5))
      raise_skeleton();
    else
    if(attacker_ob && sp>100)
      cast_attack();

    if(hit_point>274) hit_point=274;
    if(sp>SPELL) sp=SPELL;
    if(tox<0) tox=0;
  }
}
