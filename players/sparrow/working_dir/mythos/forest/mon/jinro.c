#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
int hel;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("jinro");
  set_alias("servant");
  set_race("hunters");
  set_short("Jinro- Half man/ half beast");
  set_long("This is the Jinro.  The half man/ half beast.\n"+
           "He is a small man, but powerfully built.  Slender\n"+
           "and yet his yellow eyes gleam with power.  He wears\n"+
           "a close fitting tunic and his hair is tied back.\n"+
           "Legend says that to eat of his flesh is to be healed\n"+
           "and to eat of his heart is to be immortal.....\n");
  set_gender("male");
  set_hp(1500);
  set_level(25);
  set_al(-1000);
  set_wc(45);
  set_ac(17);
  set_wander();
  set_intel(18);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_a_chat_chance(4);
  load_a_chat("Jinro bellows!\n");
  load_a_chat("FEAR shakes you!\n"); 
  set_mass_chance(25);
  set_mass_dam(75);
  set_mass_spell(HIC+"    *   *     *  FLASH  *    *   *\n"+NORM); 
  set_mult(4);
  set_mult_chance(75);
  set_mult_dam1(1);
  set_mult_dam2(10);
  move_object(clone_object("/players/mythos/closed/guild/forest/armor/tunic.c"),this_object());
  hel = 0;
  call_out("grim",3);
}

grim() {
object spi;
int n;
  if(!ep) return 1;
hel = hel + 1;
  if(hel > 10) { this_object()->heal_self(10+random(10)); hel = 0; }
  if(this_object()->query_ac() < 17) { this_object()->set_ac(17); } 
  if(this_object()->query_wc() < 45) { this_object()->set_wc(45); }
  if(present("demon",ep)) { destruct(present("demon",ep)); }
  spi = all_inventory(ep);
  for(n=0;n<sizeof(spi);n++) {
    if(spi[n]->id("spirit") && (!(spi[n]->query_attack()) || 
      (spi[n]->query_attack() && !((spi[n]->query_attack())->id("jinro"))))) {
    spi[n]->attack_object(this_object()); }
    }
call_out("grim",3);
return 1;}

monster_died() {
  move_object(clone_object("/players/mythos/closed/guild/forest/misc/flesh.c"),ep);
return 0;}
