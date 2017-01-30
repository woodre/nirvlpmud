inherit "obj/monster.c";
#include "/players/beck/MortalKombat/MKQuestNPC.h"
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon,scar;
      weapon = clone_object("players/sandman/WEAPONS/justice_swd");
     scar = clone_object("/players/dragnar/MKScar/scar");
      move_object(weapon, this_object());
     move_object(scar, this_object());
      set_name("Baldar the Brave");
     set_alt_name("baldar");
      set_alias("baldar the brave");
      set_short("Baldar the Brave");
      set_long("The powerful god of all that is just and good!\n");
      set_aggressive(1);
      set_ac(16);
      set_wc(28);
      set_race("immortal");
      set_level(19);
      set_hp(475);
      set_al(1000);
      set_chance(15);
      set_spell_mess1("Baldar belows: Leave my sanctum at once!\n");
      set_spell_mess2("Baldar cleaves you with his shinning sword!\n");
      set_spell_dam(40);
   }
}
