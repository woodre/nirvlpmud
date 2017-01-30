#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dread");
  set_alias("dread");
  set_race("dread");
  set_short("Dread");
  set_long("A dread.  A creatuure made from the stuff of anti-life.\n"+
           "A beast of gigantic proportions and horrendous features.\n");
  set_hp(4000);
  set_level(60);
  set_heal(30,5);
  set_al(-1000);
  set_wc(100);
  set_ac(27);
  set_aggressive(0);
  set_chance(90);
  set_spell_dam(100);
  set_spell_mess1("A claw lashes out!\n");
  set_spell_mess2("A massive claw tears into you!\n"); 
  set_mult(3);
  set_mult_dam1(10);
  set_mult_dam2(20);
  set_mult_chance(70);
}

init() { 
  ::init();
  add_action("ddest","dest");
  add_action("ddest","destruct");
} 
 
ddest(str) {
  if(!str) return 0;
  if(str == "dread") {
     present("tarrant",environment(this_object()))->task9();
     destruct(this_object());
  return 1;}
write("What?\n");
return 1;}
