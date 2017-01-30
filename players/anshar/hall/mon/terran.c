#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("terran");
  set_short("A large imposing man");
  set_alias("man");
  set_race("god");
  set_long("     Seven foot of tremendous physique, this man stands\n"+
           "with the appearance of a tensed coil. Dark hair falls to\n"+
           "broad shoulders and frames a sad face seemingly carved of\n"+
           "stone. Green eyes peer introspectively with the wisdom of\n"+
           "years and battles untold. In his hand is an imposing sword\n"+
           "which he wields with practiced ease.\n");
  set_hp(1000);
  set_level(25);
  set_al(-1000);
  move_object(clone_object("/players/anshar/hall/wep/deathmaster.c"),this_object());
  init_command("wield sword");
  set_wc(50);
  set_ac(15);
  set_aggressive(0);
  call_out("whip_ass",5);
  call_out("checkup",1);
  set_chance(40);
  set_spell_dam(100);
  set_spell_mess1("Terran blasts his foe with "+YEL+"golden flames"+NORM+"!\n");
  set_spell_mess2("Waves of "+YEL+"golden fire"+NORM+" Blast into you with the heat of suns.\n"+
    "Your flesh shrivels under the assault.\n");

}

whip_ass() {
object target;
object envto;
envto=environment(this_object());
  if(!query_attack()){ 
  target=first_inventory(envto);
    while(target) {
      if(target->is_player()) {
      this_object()->attack_object(target);
      remove_call_out("whip_ass");
      call_out("whip_ass",5);
      return 1;}
    target=next_inventory(target);
    }
  remove_call_out("whip_ass");
  call_out("whip_ass",5);
  return 1;}
}
checkup() {
  if(attacker_ob) {
    if(attacker_ob == TO) pissed();
  }
  if(TO->query_wc() < 60) pissed();
  remove_call_out("checkup");
  call_out("checkup",1);
  return 1;
}

pissed() {
    attacker_ob =0; alt_attacker_ob = 0;
    hunter = 0; hunted = 0; 
  TO->set_wc(80);
  TO->heal_self(1000);
  return 1;
}

