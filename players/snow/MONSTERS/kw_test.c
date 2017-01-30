/*
A vicious Killer Whale.
*/
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("killer whale");
     set_short("A Killer Whale");
     set_race("whale");
     set_alias("orca");
     set_long(
"A huge creature with razor-sharp teeth. Beware the hungry Orca in the surf!\n");
     set_level(18);
     set_ac(6);
     set_wc(random(15)+20);
     set_hp(random(80)+250);
     set_heal(1,1);
     set_al(0);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("The Killer Whale swims rapidly around you!\n");
     load_a_chat("The water churns with slashing teeth!\n");
set_chance(15);
set_spell_mess1("The Killer Whale smashes with its tail!\n");
set_spell_mess2("The Killer Whale smashes you with its tail!\n");
set_spell_dam(30);
   }
}
