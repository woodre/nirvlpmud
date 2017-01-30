inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("hermit");
  set_short("A hermit");
  set_race("spirit");
  set_long(
"This is a small figure, only about four feet tall.  He is completely\n"+
"hidden within his large hooded robe.  He is moving very little, and\n"+
"almost looks dead, however he can be heard breathing from within his\n"+
"clothes.  He is a hermit who just wishes to be left alone.\n");
  set_level(19);
  set_ac(15);
  set_wc(26);
  set_hp(600);
  set_al(-555);
  set_aggressive(0);
  set_chat_chance(3);
  add_money(2000);
  load_chat("The hermit stands still...\n");
  load_chat("The hermit breathes slowly...\n");
  load_chat("The hermit stares at the ground...\n");
  set_chance(5);
  set_spell_dam(5);
  set_spell_mess1("The hermit hits you with a crushing blow!\n");
  set_spell_mess2("The hermit hits you with a crushing blow!\n");
  set_dead_ob(TO);
}  }

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
 write(
"As the hermit falls to the ground, his body vanishes, leaving only\n"+
"his large robe behind.\n");
  MO(CO("/players/zeus/realm/OBJ/hermit_robe.c"), environment());
  if(corpse)
    destruct(corpse);
return 1; }
