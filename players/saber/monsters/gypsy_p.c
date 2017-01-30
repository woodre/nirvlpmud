inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
if (!arg){
     set_name("gypsies");
     set_short("A group of gypsies");
     set_race( "human");
     set_alias("group");
     set_long("A group of gypsies with dark skin and bright eyes.\n"+
       "Each has a silver medallion around their neck.\n");
     set_level(17);
     set_ac(14);
     set_wc(24);
     set_hp(425);
     set_al(500);
     set_aggressive(0);
     set_spell_mess1("The gypsies curse their foe.\n");
     set_spell_mess2("The gypsies curse you!\nYou feel strange.");
 set_chance(10);
 set_spell_dam(15);
   }

}
