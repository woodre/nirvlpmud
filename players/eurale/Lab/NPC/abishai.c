/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster";
#define ETO environment(this_object())

reset(arg) {
  ::reset(arg);
  if(arg) return;

set_name("abishai");
set_alias("black abishai");
set_alt_name("demon"); /* added 2004.09.29 Forbin -abishai/bateezu are demons */
set_short(BOLD+"Black Abishai"+NORM);
set_long(
  "A strong, evil tempered member of the baatezu race, this black\n"+
  "abishai is said to be the most powerful of the pit fiends.  It\n"+
  "is thin and reptilian looking, much like a gothic gargoyle.  It\n"+
  "has great wings, a long prehensile tail and formidable claws.\n");

set_race("bateezu");
set_level(20);
set_hp(555 + random(50));
set_al(-random(200));
set_aggressive(1);
set_dead_ob(this_object());

set_wc(35);
set_ac(17);

set_chat_chance(3);
  load_chat("The abishai hisses.... \n");

set_chance(16);
set_spell_dam(random(40)+10);
set_spell_mess1(
  "The abishai SLASHES with wicked claws...\n");
set_spell_mess2(
  "You feel the Abishai's wicked claws GOUGE you...\n");

}

monster_died() {
  move_object(clone_object("/players/eurale/Lab/OBJ/claw.c"),ETO);
return 0; }
